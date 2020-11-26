/***********************************************************************
* FILENAME    :   FileDownloader.cpp
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Implementation of FileDownloader.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#include <iostream>
#include <functional>

/**********************************************************************/
/**********************************************************************/

#include "Downloader.h"
#include "FileDownloader.h"

/**********************************************************************/
/**********************************************************************/

using namespace downloader::downloadfiles;

/**********************************************************************/
/**********************************************************************/

/**********************************************************************/
/** FileDownloader kind of factory constructor                        */
/**********************************************************************/
std::shared_ptr<FileDownloader>
downloader::downloadfiles::createFileDownloader()
{

    std::shared_ptr<Downloader> downloader = std::make_shared<Downloader>();
    std::shared_ptr<FileDownloader> ptrFileDownloader =
                               std::make_shared<FileDownloader>(downloader);

    return ptrFileDownloader;
}

/**********************************************************************/
/** FileDownloader Constructor                                        */
/**********************************************************************/
FileDownloader::FileDownloader( std::shared_ptr<Downloader>& ptrDownloader ) :
downLoader(ptrDownloader)
{
    notifyControl.downNotifyCB = std::bind( &FileDownloader::notifyDownload,
                                            this, std::placeholders::_1 );
}

/**********************************************************************/
/** FileDownloader Destructor                                         */
/**********************************************************************/
FileDownloader::~FileDownloader( void )
{
}

/**********************************************************************/
/** Move/Own the Download attributes and pass notify callback         */
/** to create Downloader configuration.                               */
/**********************************************************************/
bool FileDownloader::setAttributes( std::vector<DownloadAttrib>&& filesData )
{
    bool returnVal = false;

    filesDownload = std::move( filesData );

    returnVal = downLoader->dCreate( notifyControl, filesDownload );

    return returnVal;
}

/**********************************************************************/
/**  Pass Control to Start to Downloader                              */
/**********************************************************************/
bool FileDownloader::startDownload( uint8_t id )
{
    bool returnVal = false;

    returnVal = downLoader->dStart( id );

    return returnVal;
}

/**********************************************************************/
/**  Pass Control to Pause to Downloader                              */
/**********************************************************************/
bool FileDownloader::pauseDownload( uint8_t id )
{
    bool returnVal = false;

    returnVal = downLoader->dPause( id );

    return returnVal;
}

/**********************************************************************/
/**  Pass Control to Stop to Downloader                               */
/**********************************************************************/
bool FileDownloader::stopDownload( uint8_t id )
{
    bool returnVal = false;

    returnVal = downLoader->dStop( id );

    return returnVal;
}

/**********************************************************************/
/**  Pass local path to Downloader                                    */
/**********************************************************************/
bool FileDownloader::setDownloadPath( std::string downloadPath )
{
    bool returnVal = false;

    returnVal = downLoader->dSetDownloadPath( downloadPath );

    return returnVal;
}

/**********************************************************************/
/** get download data notified by notifyDownload callback             */
/**********************************************************************/
std::vector<DownloadAttrib> FileDownloader::getAttributes( void )
{
    return filesDownload;
}

/**********************************************************************/
/** Callback passed to Downloader Handler to notify downloading data  */
/**********************************************************************/
bool FileDownloader::notifyDownload( DownloadAttrib& attrib )
{
    bool returnVal = false;

    filesDownload[attrib.id] = attrib;

    return returnVal;
}
