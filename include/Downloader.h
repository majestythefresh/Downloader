/***********************************************************************
* FILENAME    :   Downloader.h
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Declaration of Downloader.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <vector>
#include <functional>

/**********************************************************************/
/**********************************************************************/

#include "DownloadThread.h"

/**********************************************************************/
/**********************************************************************/

namespace downloader{
namespace download{

/*download states*/
enum DownloadState {
    Idle,
    Starting,
    Started,
    Paused,
    Stopped,
    Completed,
    Error
};

/*Supported types to download*/
enum DownloadType {
    WebURLSource
};

/*download attributes*/
struct DownloadAttrib {
    uint8_t id = -1;
    std::string fileName;
    uint32_t fileLen = -1;
    std::string fileType;
    std::string fileSource;
    std::string localPath;
    DownloadState status;
    double percentDownloaded = 0;
    double bytesDownloaded = 0;
    DownloadType downType;
};

/*Typedef of notify callback*/
typedef std::function<bool( DownloadAttrib& attrib )> NotifyDownloadCB;

/*set of callbacks to pass*/
struct NotifyCBs {
    NotifyDownloadCB downNotifyCB;
};

/**********************************************************************/
/**********************************************************************/

class Downloader
{
private:
    NotifyDownloadCB notifyDownloadCB;
    std::vector<DownloadAttrib> downloadControl;
    std::vector<DownloadThread> downloadThread;
    std::function<void(uint8_t)> downHandler;
public:

    /**********************************************************************/
    /** Downloader Constructor
     *
     */
    Downloader( void );

    /**********************************************************************/
    /** Downloader Destructor
     *
     */
    ~Downloader( void );

    /**********************************************************************/
    /** Create all the Thread objects and pass handler to download files,
     *  Also bind notify Download callback.
     *
     * @param notifyCB: notify callback
     * @param downCtrl: download Control attributes with initial configuration
     *
     * @return true success, false otherwise
     */
    bool dCreate( NotifyCBs& notifyCB, std::vector<DownloadAttrib>& downCtrl );

    /**********************************************************************/
    /** Pass Control to Start to Downloader Handler
     *
     * @param id: id of element/file in data list
     *
     * @return true success, false otherwise
     */
    bool dStart( uint8_t id );

    /**********************************************************************/
    /** Pass Control to Pause to Downloader Handler
     *
     * @param id: id of element/file in data list
     *
     * @return true success, false otherwise
     */
    bool dPause( uint8_t id );

    /**********************************************************************/
    /** Pass Control to Stop to Downloader Handler
     *
     * @param id: id of element/file in data list
     *
     * @return true success, false otherwise
     */
    bool dStop( uint8_t id );

    /**********************************************************************/
    /** Pass local path to Downloader Handler
     *
     * @param downloadPath: path to download the files
     *
     * @return true success, false otherwise
     */
    bool dSetDownloadPath( std::string downloadPath );

    /**********************************************************************/
    /** Handler that is executed inside of Download Thread
     *
     * @param id: id of element/file in data list
     *
     */
    void downloadHandler( uint8_t id );
};

}
}

#endif /* End of DOWNLOADER_H */
