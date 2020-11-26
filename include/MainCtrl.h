/***********************************************************************
* FILENAME    :   MainCtrl.h
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Declaration of MainCtrl.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#ifndef MAIN_CTRL_H
#define MAIN_CTRL_H

#include "IDownload.h"
#include "Downloader.h"
#include "FileDownloader.h"

/**********************************************************************/
/**********************************************************************/

using namespace downloader::download;

/**********************************************************************/
/**********************************************************************/

namespace downloader{
namespace downloadfiles{

class MainCtrl : public IDownload
{
private:
    std::string localPath;
    std::string endPointUrl;
    std::vector<DownloadAttrib> filesToDownload;
    std::shared_ptr<FileDownloader> shptr_fileDownloader;

    /**********************************************************************/
    /** Helper to check a valid Path
     *
     * @param path: path to check
     *
     * @return true success, false otherwise
     */
    bool checkPath( std::string path );

public:

    /**********************************************************************/
    /** MainCtrl Constructor
     *
     * @param ptrFileDownloader: File Downloader shared pointer reference
     *
     */
    MainCtrl( std::shared_ptr<FileDownloader>& ptrFileDownloader );

    /**********************************************************************/
    /** MainCtrl Destructor
     *
     */
    ~MainCtrl( void );

    /**********************************************************************/
    /** get and parse Json Config file
     *
     * @return true success, false otherwise
     */
    bool getConfig( void );

    /**********************************************************************/
    /** get and parse Json file List from End Point
     *
     * @return true success, false otherwise
     */
    bool getEndPointFiles( void );

    /**********************************************************************/
    /** Move data list to File Downloader
     *
     * @return true success, false otherwise
     */
    bool setList( void );

    /**********************************************************************/
    /** Pass Control to Start to File Downloader
     *
     * @param id: id of element/file in data list
     *
     * @return true success, false otherwise
     */
    bool startDownload( uint8_t id );

    /**********************************************************************/
    /** Pass Control to Stop to File Downloader
     *
     * @param id: id of element/file in data list
     *
     * @return true success, false otherwise
     */
    bool stopDownload( uint8_t id );

    /**********************************************************************/
    /** Pass Control to Pause to File Downloader
     *
     * @param id: id of element/file in data list
     *
     * @return true success, false otherwise
     */
    bool pauseDownload( uint8_t id );

    /**********************************************************************/
    /** Pass local path to File Downloader
     *
     * @param downloadPath: path to download the files
     *
     * @return true success, false otherwise
     */
    bool setDownloadPath( std::string downloadPath );

    /**********************************************************************/
    /** Get downloaded data reported from Downloader trough callback
     *
     * @return downloaded data at moment
     */
    std::vector<DownloadAttrib> getDownloadStatus( void );

    /**********************************************************************/
    /** Get data in MainCtrl, ideally to use before
     *  setList (move memory to File Downloader), just for UI pre config.
     *
     * @return downloaded data at moment
     */
    std::vector<DownloadAttrib> getFilesAttrib( void );

    /**********************************************************************/
    /** Get file size in path
     *
     * @return size of file
     */
    int getPathSize( std::string path );
};

}
}

#endif /* End of MAIN_CTRL_H */
