/***********************************************************************
* FILENAME    :   MainCtrl.cpp
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Implementation of MainCtrl.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**********************************************************************/
/**********************************************************************/

#include "MainCtrl.h"
#include "DownloadHandler.h"
#include "libparson.h"

/**********************************************************************/
/**********************************************************************/

using namespace downloader::downloadfiles;

/**********************************************************************/
/**********************************************************************/

/**********************************************************************/
/** MainCtrl Constructor                                              */
/**********************************************************************/
MainCtrl::MainCtrl( std::shared_ptr<FileDownloader>& ptrFileDownloader ) :
shptr_fileDownloader(ptrFileDownloader)
{
}

/**********************************************************************/
/** MainCtrl Destructor                                               */
/**********************************************************************/
MainCtrl::~MainCtrl( void )
{
}

/**********************************************************************/
/** get and parse Json Config file                                    */
/**********************************************************************/
bool MainCtrl::getConfig( void )
{
    bool returnVal = false;

    JSON_Value *root_value = NULL;
    JSON_Object *config = NULL;

    root_value = json_parse_file("./config/config.json");

    if( root_value )
    {
        if (json_value_get_type(root_value) == JSONObject )
        {
            config = json_value_get_object(root_value);
            localPath = json_object_get_string(config, "defaul_path");
            endPointUrl = json_object_get_string(config, "json_file");
            returnVal = true;
        }
        json_value_free(root_value);
    }

    return returnVal;
}

/**********************************************************************/
/** get and parse Json file List from End Point                       */
/**********************************************************************/
bool MainCtrl::getEndPointFiles( void )
{
    bool returnVal = false;

    /*Download attributes for Json End Point*/
    DownloadAttrib jsonAttrib;
    jsonAttrib.fileName = "files";
    jsonAttrib.fileType = "json";
    jsonAttrib.fileSource = endPointUrl;
    jsonAttrib.localPath = "./config";
    jsonAttrib.downType = WebURLSource;
    jsonAttrib.status = Starting;
    jsonAttrib.fileLen = -1;
    jsonAttrib.id = -1;
    std::function<bool( DownloadAttrib& attrib )> f = [](DownloadAttrib& attrib) {return false;};
    DownloadHandler GetHandler( &jsonAttrib, f );
    /*Downloading Json*/
    if ( GetHandler.downloadStart() ){
        JSON_Value *root_value = NULL;
        JSON_Array *array = NULL;
        JSON_Object *value = NULL;

        std::string jsonFile = jsonAttrib.localPath + "/" + jsonAttrib.fileName + "." + jsonAttrib.fileType;

        root_value = json_parse_file(jsonFile.c_str());

        if( root_value ){
            if ( json_value_get_type(root_value) == JSONArray )
            {
                array = json_value_get_array(root_value);
                if (array != NULL)
                {
                    for ( uint8_t i = 0; i < json_array_get_count(array); ++i)
                    {
                        value = json_array_get_object(array, i);
                        DownloadAttrib attrib;
                        attrib.id = i;
                        attrib.fileName = json_object_get_string(value, "FileName");
                        attrib.fileLen = static_cast<uint32_t>(std::stoul(json_object_get_string(value, "Length")));
                        attrib.fileType = json_object_get_string(value, "BlobType");
                        attrib.fileSource = json_object_get_string(value, "DownloadURI");
                        attrib.localPath = localPath;
                        attrib.downType = WebURLSource;
                        attrib.status = Idle;
                        filesToDownload.push_back( attrib );
                    }
                    returnVal = true;
                }
            }
            json_value_free(root_value);
        }
    }

    return returnVal;
}

/**********************************************************************/
/** Move data list to File Downloader                                 */
/**********************************************************************/
bool MainCtrl::setList( void )
{
    bool returnVal = false;

    returnVal = shptr_fileDownloader->setAttributes( std::move( filesToDownload ) );

    return returnVal;
}

/**********************************************************************/
/** Pass Control to Start to File Downloader                          */
/**********************************************************************/
bool MainCtrl::startDownload( uint8_t id )
{
    bool returnVal = false;

    returnVal = shptr_fileDownloader->startDownload( id );

    return returnVal;
}

/**********************************************************************/
/** Pass Control to Pause to File Downloader                          */
/**********************************************************************/
bool MainCtrl::pauseDownload( uint8_t id )
{
    bool returnVal = false;

    returnVal = shptr_fileDownloader->pauseDownload(id);

    return returnVal;
}

/**********************************************************************/
/** Pass Control to Stop to File Downloader                          */
/**********************************************************************/
bool MainCtrl::stopDownload( uint8_t id )
{
    bool returnVal = false;

    returnVal = shptr_fileDownloader->stopDownload(id);

    return returnVal;
}

/**********************************************************************/
/** Pass local path to File Downloader                                */
/**********************************************************************/
bool MainCtrl::setDownloadPath( std::string downloadPath )
{
    bool returnVal = false;

    shptr_fileDownloader->setDownloadPath(downloadPath);
    returnVal = checkPath( downloadPath );

    return returnVal;
}

/**********************************************************************/
/** Get downloaded data reported from File Downloader trough callback */
/**********************************************************************/
std::vector<DownloadAttrib> MainCtrl::getDownloadStatus( void )
{
    return shptr_fileDownloader->getAttributes();
}

/**********************************************************************/
/** Get data in MainCtrl, ideally to use before
 *  setList (move memory to File Downloader), just for UI pre config. */
/**********************************************************************/
std::vector<DownloadAttrib> MainCtrl::getFilesAttrib( void )
{
    return filesToDownload;
}

/**********************************************************************/
/** Get file size in path                                             */
/**********************************************************************/
int MainCtrl::getPathSize( std::string path )
{
    struct stat info;
    if( stat( path.c_str(), &info ) != 0 )
    {
        //Can not access
        return 0;
    }
    else if( info.st_mode )
    {
        return  info.st_size;
    }

    return 0;
}

/**********************************************************************/
/**********************************************************************/

/**********************************************************************/
/** Helper to check a valid Path
 *
 * @param path: path to check
 *
 * @return true success, false otherwise
 */
bool MainCtrl::checkPath( std::string path )
{
    struct stat info;
    if( stat( path.c_str(), &info ) != 0 )
    {
        //Can not access
        return false;
    }
    else if( info.st_mode & S_IFDIR )
    {
        //Directory
        if (access(path.c_str(), W_OK) == 0)
        {
            //have Write access
            return true;
        }
        //No permissions
    }

    return false;
}
