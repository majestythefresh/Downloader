/***********************************************************************
* FILENAME    :   DownloadThread.cpp
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Implementation of DownloadThread.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#include <iostream>

/**********************************************************************/
/**********************************************************************/

#include "DownloadThread.h"

/**********************************************************************/
/**********************************************************************/

using namespace downloader::download;

/**********************************************************************/
/**********************************************************************/

/**********************************************************************/
/** DownloadThread Constructor                                        */
/**********************************************************************/
DownloadThread::DownloadThread( uint8_t idThread, std::function<void(uint8_t)>& handlerFunc ) :
id(idThread),
handlerCB(handlerFunc)
{
}

/**********************************************************************/
/** DownloadThread Destructor                                         */
/**********************************************************************/
DownloadThread::~DownloadThread( void )
{

}

/**********************************************************************/
/** Start Thread to execute downloadHandler                           */
/**********************************************************************/
bool DownloadThread::start( void )
{
    bool returnVal = false;

    std::thread handlerDownload(&DownloadThread::downloadHandler, this, id );

    handlerDownload.detach();

    return returnVal;
}

/**********************************************************************/
/** Handler to execute download for specific ID                       */
/**********************************************************************/
void DownloadThread::downloadHandler( uint8_t id )
{
    handlerCB( id );
}
