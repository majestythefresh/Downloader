/***********************************************************************
* FILENAME    :   IDownload.h
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Class Declaration for Donwload Interface.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#ifndef IDOWNLOAD_H
#define IDOWNLOAD_H

namespace downloader{
namespace download{

class IDownload
{
public:
    virtual bool startDownload(uint8_t id) = 0;
    virtual bool stopDownload(uint8_t id) = 0;
    virtual bool pauseDownload(uint8_t id) = 0;
};

}
}

#endif /* End of IDOWNLOAD_H */
