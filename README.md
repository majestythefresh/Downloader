### Install dependencies:

    Fedora Linux Install:
      - sudo yum install qt5
      - sudo yum install libcurl libcurl-devel

    MacOSX Install:
      - brew install qt5
      - brew install curl



### Compile:
  Once you download QT5, locate the include and lib and set in makefile in:

	example:
     - QT_INCLUDE=/usr/include/qt5
     - QTLIB=/usr/lib/qt5

  use makefile with next targets to compile and clean:
    - $ make all
    - $ make clean

Note: MAC OSX versions have different behaviours in compilation due stat/stat.h or qt5 libraries

### Run:

a FileDownloader binary will be created in bin/ folder

    - $ bin/FileDownloader
Config: config/config.json

   - "json_file": use to set the endpoint URL (files.json) list of files to download.
   - "defaul_path": use to set the default path to download files.

         {
            "defaul_path":"/home/plauchu/Documents",
            "json_file":"https://downloader.blob.core.windows.net/api/files.json"
         }
