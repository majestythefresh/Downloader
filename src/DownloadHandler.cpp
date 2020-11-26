/***********************************************************************
* FILENAME    :   DownloadHandler.cpp
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Implementation of Downloader.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#include <iostream>
//#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>

/**********************************************************************/
/**********************************************************************/

#include "DownloadHandler.h"

/**********************************************************************/
/**********************************************************************/

using namespace downloader::download;

/**********************************************************************/
/**********************************************************************/

/**********************************************************************/
/** Static function to report progress of download in CURL calls      */
/**********************************************************************/
static int progressHandler(void *pBar, double totalToDownload, double downloaded)
{
    int returnVal = -1;

    struct dataCB *data = static_cast<struct dataCB*>(pBar);
    if( !( ( (int)(downloaded/totalToDownload*100 ) ) % 1 ) )
    {
        //printf("[DownloadHandler::progressHandler] Status[%d] Progress %lf Percent in [%s] \n",
          //     data->downAttrib->status, (downloaded/totalToDownload*100 ), data->downAttrib->fileName.c_str());

        //printf("[DownloadHandler::progressHandler] Downloaded in Time [%lf] / [%d] \n",
        //        (data->dataDownloaded + downloaded), data->downAttrib->fileLen);

        data->downAttrib->percentDownloaded = ((data->dataDownloaded + downloaded)/data->downAttrib->fileLen*100 );
        data->downAttrib->bytesDownloaded = downloaded;
        if( data->downAttrib->status == Started )
        {
            curl_easy_pause(data->curl, CURLPAUSE_CONT);
            returnVal = 0;
        }
        else if( data->downAttrib->status == Paused )
        {
            curl_easy_pause(data->curl, CURLPAUSE_ALL);
            returnVal = 0;
        }
        else{
            returnVal = -1;
        }

        if(data->callBack)
        {
            data->callBack( *(data->downAttrib) );
        }
    }
    return returnVal;
}

/**********************************************************************/
/** DownloadHandler Constructor                                       */
/**********************************************************************/
DownloadHandler::DownloadHandler( DownloadAttrib* attrib, NotifyDownloadCB& handlerCB ) :
downAttrib(attrib),
callBack(handlerCB)
{
   output_file = downAttrib->localPath + "/" + downAttrib->fileName + "." + downAttrib->fileType;
}

/**********************************************************************/
/** DownloadHandler Destructor                                        */
/**********************************************************************/
DownloadHandler::~DownloadHandler( void )
{
}

/**********************************************************************/
/** start downloading the attribute                                   */
/**********************************************************************/
bool DownloadHandler::downloadStart( void )
{
    bool returnVal = false;

    if ( isMethodSupported() )
    {
        switch( downAttrib->downType )
        {
            case WebURLSource:
                if ( getWebURLFile() == 0 )
                {
                    returnVal = true;
                }
            break;
            default:
            break;
        }
    }

    return returnVal;
}


/**********************************************************************/
/**********************************************************************/

/**********************************************************************/
/** Check if method to download the attribute is valid                */
/**********************************************************************/
bool DownloadHandler::isMethodSupported( void )
{
    bool returnVal = false;

    switch( downAttrib->downType )
    {
        case WebURLSource:
            returnVal = true;
        break;
        default:
        break;
    }

    return returnVal;
}

/**********************************************************************/
/**   Get file from URL in attribute                                  */
/**********************************************************************/
int DownloadHandler::getWebURLFile( void )
{
    int returnVal = -1;

    returnVal = processDownload();

    return returnVal;
}

/**********************************************************************/
/** method to download a Web File using CURL                          */
/**********************************************************************/
int DownloadHandler::processDownload( void )
{

    int returnVal = -1;
    uint32_t downloadedFile = 0;

    if (  downAttrib->status == Starting )
    {
        curl_download = curl_easy_init();

        downAttrib->status = Started;
        std::string bytes;
        if (downAttrib->fileLen > 0)
        {
            std::string filePath = downAttrib->localPath+"/"+downAttrib->fileName+"."+downAttrib->fileType;
            struct stat info;
            if( stat( filePath.c_str(), &info ) != 0 )
            {
                downloadedFile = 0;
            }
            else if( info.st_mode )
            {
                downloadedFile = info.st_size;
            }
            bytes = std::to_string(downloadedFile) + "-" +  std::to_string(downAttrib->fileLen);
        }

        /*Data to pass to progress function*/
        struct dataCB data;
        data.downAttrib = downAttrib;
        data.curl = curl_download;
        data.callBack = callBack;
        data.dataDownloaded = downloadedFile;

        if (downAttrib->fileLen != -1 && downloadedFile > 10240)
          fp = fopen(output_file.c_str(),"a");
        else
          fp = fopen(output_file.c_str(),"wb");
        if (fp){
            curl_easy_setopt(curl_download, CURLOPT_URL, downAttrib->fileSource.c_str());
            if (downAttrib->fileLen != -1)
              curl_easy_setopt(curl_download, CURLOPT_RANGE, bytes.c_str());
            curl_easy_setopt(curl_download, CURLOPT_WRITEFUNCTION, NULL);
            curl_easy_setopt(curl_download, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl_download, CURLOPT_NOPROGRESS, 0L);
            curl_easy_setopt(curl_download, CURLOPT_PROGRESSDATA, &data);
            curl_easy_setopt(curl_download, CURLOPT_PROGRESSFUNCTION, progressHandler);
            curl_easy_setopt(curl_download, CURLOPT_INFILESIZE, downAttrib->fileLen);

            res = curl_easy_perform(curl_download);

            fclose(fp);
        }
        else
        {
            downAttrib->status =  Error;
        }
    }

    if(res == CURLE_OK)
    {
        if ( ((uint32_t) downAttrib->bytesDownloaded + downloadedFile) == downAttrib->fileLen ||
            downAttrib->fileLen == -1)
        {
            /*Completed*/
            downAttrib->status = Completed;
            returnVal = 0;
        }
        else
        {
            /*Completed But Error*/
            downAttrib->status = Error;
        }
    }
    else
    {
        if (downAttrib->status !=  Stopped)
        {
            /*Error*/
            downAttrib->status =  Error;
        }
    }

    callBack( *(downAttrib) );

    if( downAttrib->status ==  Error )
    {
        downAttrib->percentDownloaded = 0;
    }

    return returnVal;
}
