/***********************************************************************
* FILENAME    :   Downloader.cpp
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Implementation of Downloader.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#include <iostream>

/**********************************************************************/
/**********************************************************************/

#include "Downloader.h"
#include "DownloadHandler.h"

/**********************************************************************/
/**********************************************************************/

using namespace downloader::download;

/**********************************************************************/
/**********************************************************************/

/**********************************************************************/
/** Downloader Constructor                                            */
/**********************************************************************/
Downloader::Downloader( void )
{
}

/**********************************************************************/
/** Downloader Destructor                                             */
/**********************************************************************/
Downloader::~Downloader( void )
{
}

/**********************************************************************/
/** Create all the Thread objects and pass handler to download files,
 *  Also bind notify Download callback.                               */
/**********************************************************************/
bool Downloader::dCreate( NotifyCBs& notifyCB, std::vector<DownloadAttrib>& downCtrl )
{
    bool returnVal = false;

    downloadControl = downCtrl;
    notifyDownloadCB = notifyCB.downNotifyCB;

    downHandler = std::bind( &Downloader::downloadHandler, this, std::placeholders::_1 );

    downloadThread.reserve( downloadControl.size() );
    for( int i = 0 ; i < downloadControl.size(); ++i)
    {
        downloadControl[i].status = Idle;
        downloadControl[i].percentDownloaded = 0;
        downloadControl[i].bytesDownloaded = 0;
        downloadThread.push_back( DownloadThread( i, downHandler ) );
    }

    return returnVal;
}

/**********************************************************************/
/** Pass Control to Start to Downloader Handler                       */
/**********************************************************************/
bool Downloader::dStart( uint8_t id )
{
    bool returnVal = false;

    if ( downloadControl[id].status != Started )
    {
        if ( downloadControl[id].status == Paused )
        {
            downloadControl[id].status = Started;
        }
        else
        { //Starting
            if ( downloadThread.size() > 0 )
            {
                downloadControl[id].status = Starting;
                returnVal = downloadThread[id].start();
            }
        }
    }

    return returnVal;
}

/**********************************************************************/
/** Pass Control to Pause to Downloader Handler                       */
/**********************************************************************/
bool Downloader::dPause( uint8_t id )
{
    bool returnVal = false;

    downloadControl[id].status = Paused;

    return returnVal;
}

/**********************************************************************/
/** Pass Control to Stop to Downloader Handler                        */
/**********************************************************************/
bool Downloader::dStop( uint8_t id )
{
    bool returnVal = false;

    downloadControl[id].status = Stopped;

    return returnVal;
}

/**********************************************************************/
/** Pass local path to Downloader Handler                             */
/**********************************************************************/
bool Downloader::dSetDownloadPath( std::string downloadPath )
{
    bool returnVal = false;

    for( int i = 0 ; i < downloadControl.size(); ++i)
    {
        downloadControl[i].localPath = downloadPath;
        downloadControl[i].status = Starting;
        downloadControl[i].percentDownloaded = 0;
    }

    return returnVal;
}

/**********************************************************************/
/** Handler that is executed inside of Download Thread                */
/**********************************************************************/
void Downloader::downloadHandler( uint8_t id )
{
    DownloadHandler GetHandler( &downloadControl[id], notifyDownloadCB );
    GetHandler.downloadStart();
}
