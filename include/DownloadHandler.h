/***********************************************************************
* FILENAME    :   DownloadHandler.h
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Declaration of DownloadHandler.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#ifndef DOWNLOADHANDLER_H
#define DOWNLOADHANDLER_H

#include <curl/curl.h>
#include "Downloader.h"

/**********************************************************************/
/**********************************************************************/

namespace downloader{
namespace download{

struct dataCB {
  DownloadAttrib *downAttrib;
  CURL *curl;
  NotifyDownloadCB callBack;
  uint32_t dataDownloaded;
};

class DownloadHandler
{
private:
    CURL *curl_download;
    FILE *fp;
    CURLcode res;
    std::string output_file;

    /**********************************************************************/
    /** Check if method to download the attribute is valid
     *
     * @return true success, false otherwise
     */
    bool isMethodSupported( void );

    /**********************************************************************/
    /** Get file from URL in attribute
     *
     * @return 0 success, -1 otherwise
     */
    int getWebURLFile( void );

    /**********************************************************************/
    /** method to download a Web File using CURL
     *
     * @param status: id of element/file in data list
     *
     * @return 0 success, -1 otherwise
     */
    int processDownload( void );

public:
    DownloadAttrib* downAttrib;
    NotifyDownloadCB callBack;

    /**********************************************************************/
    /** DownloadHandler Constructor
     *
     * @param attrib: pointer to attributes to get reached by control actions
     * @param handlerCB: notify callback to report status
     *
     */
    DownloadHandler( DownloadAttrib* attrib, NotifyDownloadCB& handlerCB );

    /**********************************************************************/
    /** DownloadHandler Destructor
     *
     */
    ~DownloadHandler( void );

    /**********************************************************************/
    /** start downloading the attribute
     *
     * @return true success, false otherwise
     */
    bool downloadStart( void );
};

}
}

#endif /* End of DOWNLOADHANDLER_H */
