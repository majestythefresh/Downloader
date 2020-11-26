/***********************************************************************
* FILENAME    :   FileDownloader.h
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Declaration FileDownloader.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include "IDownload.h"
#include "Downloader.h"

/**********************************************************************/
/**********************************************************************/

using namespace downloader::download;

/**********************************************************************/
/**********************************************************************/

namespace downloader{
namespace downloadfiles{

class FileDownloader : public IDownload
{
private:
    std::vector<DownloadAttrib> filesDownload;
    NotifyCBs notifyControl;
    std::shared_ptr<Downloader> downLoader;
public:

    /**********************************************************************/
    /** FileDownloader Constructor
     *
     * @param ptrDownloader: Downloader shared pointer
     */
    FileDownloader( std::shared_ptr<Downloader>& ptrDownloader );

    /**********************************************************************/
    /** FileDownloader Destructor
     *
     */
    ~FileDownloader( void );

    /**********************************************************************/
    /** Move/Own the Download attributes and pass notify callback
     *  to create Downloader configuration,
     *
     * @param filesData: Download attributes
     *
     * @return true success, false otherwise
     */
    bool setAttributes( std::vector<DownloadAttrib>&& filesData );

    /**********************************************************************/
    /** Pass Control to Start to Downloader
     *
     * @param id: id of element/file in data list
     *
     * @return true success, false otherwise
     */
    bool startDownload(uint8_t id);

    /**********************************************************************/
    /** Pass Control to Pause to Downloader
     *
     * @param id: id of element/file in data list
     *
     * @return true success, false otherwise
     */
    bool pauseDownload(uint8_t id);

    /**********************************************************************/
    /** Pass Control to Stop to Downloader
     *
     * @param id: id of element/file in data list
     *
     * @return true success, false otherwise
     */
    bool stopDownload(uint8_t id);

    /**********************************************************************/
    /** Pass local path to Downloader
     *
     * @param downloadPath: path to download the files
     *
     * @return true success, false otherwise
     */
    bool setDownloadPath( std::string downloadPath );

    /**********************************************************************/
    /** get download data notified by notifyDownload callback
     *
     * @return Download Attributes
     */
    std::vector<DownloadAttrib> getAttributes( void );

    /**********************************************************************/
    /** Callback passed to Downloader Handler to notify downloading data
     *
     * @param attrib: download attribute to notify while downloading
     *
     * @return true success, false otherwise
     */
    bool notifyDownload(DownloadAttrib& attrib);

};

/**********************************************************************/
/** FileDownloader kind of factory constructor
 *
 * @return FileDownloader shared pointer
 */
std::shared_ptr<FileDownloader> createFileDownloader();

}
}

#endif /* End of FILEDOWNLOADER_H */
