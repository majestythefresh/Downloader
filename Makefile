#***********************************************************************
# FILENAME    :   Makefile
# AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
# DATE        :   September 2020
# DESCRIPTION :   Make a Build for Downloader.
# LICENSE     :   GPL v2.0
#
#***********************************************************************/

SRC=src
INC=include
BIN=bin
UI_INC=ui
EXT_INC=external

QT_INCLUDE=/usr/include/qt5
QTLIB=/usr/lib/qt5

CC=g++ -std=c++11
CCFLAGS=-I$(INC) -I$(QT_INCLUDE) -I$(UI_INC) -I$(EXT_INC) -Wpedantic -O
LDFLAGS=-L$(QTLIB) -lpthread -lcurl -lQt5Core -lQt5Widgets -lQt5Gui

FILES=$(SRC)/MainCtrl.cpp $(SRC)/FileDownloader.cpp $(SRC)/Downloader.cpp \
	  $(SRC)/DownloadThread.cpp -o $(BIN)/FileDownloader $(SRC)/DownloadHandler.cpp \
	  $(EXT_INC)/libparson.cpp $(UI_INC)/ui_file_downloader.cpp $(SRC)/main.cpp

#***********************************************************************/
#*************************** Compile targets ***************************/
#***********************************************************************/

all:
	$(CC) $(CCFLAGS) $(FILES) $(LDFLAGS) -fPIC

clean:
	rm $(BIN)/FileDownloader
