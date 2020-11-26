/***********************************************************************
* FILENAME    :   main.cpp
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   main function.
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#include "ui_file_downloader.h"

int main(int argc, char *argv[]){

    /*QT Application build*/
    QApplication app(argc, argv);
    qRegisterMetaType<DownloadAttrib>();

    /*Creating File Downloader controller*/
    std::shared_ptr<FileDownloader> ptrFileDownloader = createFileDownloader();
    MainCtrl mainCtrl( ptrFileDownloader );

    /*QT UI Main Window*/
    QDialog widget;
    Ui::Custom ui;

    /*passing control and setting up the UI*/
    ui.setData(&widget, &mainCtrl);
    ui.setupUi();

    widget.show();

    return app.exec();
}
