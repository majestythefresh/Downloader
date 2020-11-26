/***********************************************************************
* FILENAME    :   DownloadThread.h
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Declaration of DownloadThread.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#ifndef DOWNLOADTHREAD_H
#define DOWNLOADTHREAD_H

#include <thread>
#include <functional>

/**********************************************************************/
/**********************************************************************/

namespace downloader{
namespace download{

class DownloadThread
{
private:
    uint8_t id;
    std::function<void(uint8_t)> handlerCB;
public:

    /**********************************************************************/
    /** DownloadThread Constructor
     *
     */
    DownloadThread( uint8_t idThread, std::function<void(uint8_t)>& handler );

    /**********************************************************************/
    /** DownloadThread Destructor
     *
     */
    ~DownloadThread( void );

    /**********************************************************************/
    /** Start Thread to execute downloadHandler
     *
     * @return true success, false otherwise
     */
    bool start( void );

    /**********************************************************************/
    /** Handler to execute download for specific ID
     *
     * @param id: id of element/file in data list
     *
     */
    void downloadHandler( uint8_t id );
};

}
}

#endif  /* End of DOWNLOADTHREAD_H */
