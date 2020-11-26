/***********************************************************************
* FILENAME    :   MainCtrl.cpp
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   Meta object code from reading C++ file 'ui_file_downloader.h'
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#include <chrono>
#include <sys/types.h>
#include <sys/stat.h>

#include "ui_file_downloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ui_file_downloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ui_Custom_t {
    QByteArrayData data[11];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ui_Custom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ui_Custom_t qt_meta_stringdata_Ui_Custom = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Ui_Custom"
QT_MOC_LITERAL(1, 10, 21), // "downloadDatataChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "DownloadAttrib"
QT_MOC_LITERAL(4, 48, 4), // "data"
QT_MOC_LITERAL(5, 53, 15), // "setDownloadPath"
QT_MOC_LITERAL(6, 69, 15), // "setDownloadData"
QT_MOC_LITERAL(7, 85, 13), // "startDownload"
QT_MOC_LITERAL(8, 99, 12), // "stopDownload"
QT_MOC_LITERAL(9, 112, 11), // "getJsonList"
QT_MOC_LITERAL(10, 124, 11) // "frameNumber"

    },
    "Ui_Custom\0downloadDatataChanged\0\0"
    "DownloadAttrib\0data\0setDownloadPath\0"
    "setDownloadData\0startDownload\0"
    "stopDownload\0getJsonList\0frameNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ui_Custom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x0a /* Public */,
       9,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void Ui_Custom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ui_Custom *_t = static_cast<Ui_Custom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadDatataChanged((*reinterpret_cast< DownloadAttrib(*)>(_a[1]))); break;
        case 1: _t->setDownloadPath(); break;
        case 2: _t->setDownloadData((*reinterpret_cast< DownloadAttrib(*)>(_a[1]))); break;
        case 3: _t->startDownload(); break;
        case 4: _t->stopDownload(); break;
        case 5: _t->getJsonList((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DownloadAttrib >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DownloadAttrib >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Ui_Custom::*_t)(DownloadAttrib );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ui_Custom::downloadDatataChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Ui_Custom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ui_Custom.data,
      qt_meta_data_Ui_Custom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ui_Custom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ui_Custom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ui_Custom.stringdata0))
        return static_cast<void*>(const_cast< Ui_Custom*>(this));
    return QObject::qt_metacast(_clname);
}

int Ui_Custom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

/******************************************************************************
// SIGNALS
******************************************************************************/

void Ui_Custom::downloadDatataChanged(DownloadAttrib _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}


/******************************************************************************
// SLOTS to change UI
******************************************************************************/

/******************************************************************************
 Slot to get Json list from end point at init
******************************************************************************/
void Ui_Custom::getJsonList(int frameNumber)
{
    static int loopCount = 0;
    if (animationFlag)
    {
        animationFlag = false;
        /*Getting main configuration from config Json*/
        if ( mainCtrl->getConfig() )
        {
            /*Getting JSON file list from End Point*/
            flagData = mainCtrl->getEndPointFiles();
            if ( flagData )
            {
                /*Generating UI according with data fetched*/
                setDynamicData();
                /*Passing file list to Control*/
                mainCtrl->setList();
                /*Start thread to listening data processed/downloaded */
                trackDownload();
                /*Runing slot for first path check*/
                path_to_download->setText(dataAttrib[0].localPath.c_str());
                setDownloadPath();
            }
        }
    }
    if (loopCount > 30 && flagData)
    {
        /*data fetch completed*/
        movie->stop();
        disconnect(movie, SIGNAL(frameChanged(int)), 0, 0);
        frame_3->show();
        scrollArea->show();
        downloadLabel->hide();
        processLabel->hide();
    }
    else if (loopCount > 100 && !flagData)
    {
        /*no data fetch available*/
        movie->stop();
        disconnect(movie, SIGNAL(frameChanged(int)), 0, 0);
        downloadLabel->setText("Error getting End Point files!");
        downloadLabel->setStyleSheet(
            "QLabel { font-weight: bold; font-size:14pt; color : #f0b1b1; padding: 10px 5px 10px 15px;}");
    }
    loopCount++;
}

/******************************************************************************
 Slot to change Path from Edit field
******************************************************************************/
void Ui_Custom::setDownloadPath()
{
    /*Changing state of widgets according to valid or not valid Path set*/
    std::string path = path_to_download->text().toStdString();
    if ( mainCtrl->setDownloadPath( path ) )
    {
        for ( uint8_t i = 0; i < dataAttrib.size(); ++i)
        {
            dataAttrib[i].localPath = path;
            std::string filePath = dataAttrib[i].localPath+"/"+dataAttrib[i].fileName+"."+dataAttrib[i].fileType;
            double percentDownloaded = ((double)mainCtrl->getPathSize( filePath )/(double)dataAttrib[i].fileLen*100);
            if ( mainCtrl->getPathSize( filePath ) == dataAttrib[i].fileLen )
            {
                /*Download Complete widgets behaviour*/
                pushStartButtonList[i]->setText("Download Completed");
                pushStartButtonList[i]->setStyleSheet("QPushButton { background-color : #376e35; color : black; font-weight: bold;}");
                pushStartButtonList[i]->setEnabled(false);
                pushStartButtonList[i]->setFocusPolicy(Qt::NoFocus);
                pushStopButtonList[i]->hide();
                progressBarList[i]->hide();
                progressBarList[i]->setValue(0);
                labelList[i]->setStyleSheet("QLabel { color : #b1f0c5; font-weight: bold;}");
                path_to_download->setEnabled( true );
            }
            else if ( mainCtrl->getPathSize( filePath ) <= 10240 ) //size minor than a Kilobyte
            {
              /*Start Download widgets behaviour*/
              dataAttrib[i].status = Stopped;
              pushStartButtonList[i]->setText("Start Download");
              pushStartButtonList[i]->setStyleSheet("QPushButton { background-color : #4d81c9; color : white;font-weight: bold;}");
              pushStartButtonList[i]->setFocusPolicy(Qt::NoFocus);
              labelList[i]->setStyleSheet("QLabel { color : #ebebeb; font-weight: bold;}");
              pushStartButtonList[i]->setEnabled(true);
              labelList[i]->setStyleSheet("QLabel { color : #ebebeb; font-weight: bold;}");
              progressBarList[i]->setValue( 0 );
            }
            else
            {
                /*Resume Download widgets behaviour*/
                dataAttrib[i].status = Stopped;
                pushStartButtonList[i]->setText("Resume Download");
                pushStartButtonList[i]->setStyleSheet("QPushButton { background-color : #4d81c9; color : white;font-weight: bold;}");
                pushStartButtonList[i]->setFocusPolicy(Qt::NoFocus);
                labelList[i]->setStyleSheet("QLabel { color : #ebebeb; font-weight: bold;}");
                pushStartButtonList[i]->setEnabled(true);
                labelList[i]->setStyleSheet("QLabel { color : #ebebeb; font-weight: bold;}");
                progressBarList[i]->setValue( (uint32_t) percentDownloaded );
                progressBarList[i]->show();
            }
        }
        path_to_download->setStyleSheet(" QLineEdit { background-color: #c3fac9; width: 20px; font-weight: bold;}");
    }
    else
    {
        for ( uint8_t i = 0; i < dataAttrib.size(); ++i)
        {
            pushStartButtonList[i]->setText("Local Path Error");
            pushStartButtonList[i]->setStyleSheet("QPushButton { background-color : #822e28; color : black; font-weight: bold;}");
            pushStartButtonList[i]->setEnabled(false);
            pushStartButtonList[i]->setFocusPolicy(Qt::NoFocus);
            pushStopButtonList[i]->hide();
            progressBarList[i]->hide();
            labelList[i]->setStyleSheet("QLabel { color : #f0b1b1; font-weight: bold;}");
            path_to_download->setEnabled( true );
        }
        path_to_download->setStyleSheet(" QLineEdit { background-color: #fac3c3; width: 20px; font-weight: bold;}");
    }
}

/******************************************************************************
 Slot to set download progress to ProgressBar
******************************************************************************/
void Ui_Custom::setDownloadData( DownloadAttrib data )
{
    if( ! completeFlag[data.id] )
    {
        progressBarList[data.id]->setValue( (uint32_t) data.percentDownloaded);
        path_to_download->setEnabled( false );
    }
    else
    {
        if ( completeFlag[data.id] )
        {
            if ( data.status == Error && completeFlag[data.id] == true){
                pushStartButtonList[data.id]->setText("Download Error");
                pushStartButtonList[data.id]->setStyleSheet("QPushButton { background-color : #822e28; color : black; font-weight: bold;}");
                pushStartButtonList[data.id]->setEnabled(false);
                pushStartButtonList[data.id]->setFocusPolicy(Qt::NoFocus);
                pushStopButtonList[data.id]->hide();
                progressBarList[data.id]->hide();
                labelList[data.id]->setStyleSheet("QLabel { color : #f0b1b1; font-weight: bold;}");
                dataAttrib[data.id].status = Stopped;
                progressBarList[data.id]->setValue( 0 );
            }
            else {
                pushStartButtonList[data.id]->setText("Download Completed");
                pushStartButtonList[data.id]->setStyleSheet("QPushButton { background-color : #376e35; color : black; font-weight: bold;}");
                pushStartButtonList[data.id]->setEnabled(false);
                pushStartButtonList[data.id]->setFocusPolicy(Qt::NoFocus);
                pushStopButtonList[data.id]->hide();
                progressBarList[data.id]->hide();
                progressBarList[data.id]->setValue(100);
                labelList[data.id]->setStyleSheet("QLabel { color : #b1f0c5; font-weight: bold;}");
                path_to_download->setEnabled( true );
                dataAttrib[data.id].status = Completed;
            }
        }
    }
}

/******************************************************************************
 Slot to Start Button
******************************************************************************/
void Ui_Custom::startDownload()
{

    QObject* obj = sender();
    int indexToProcess = -1;
    bool findFlag = false;

    for ( indexToProcess = 0; indexToProcess < dataAttrib.size(); ++indexToProcess)
    {
        if(pushStartButtonList[indexToProcess] == obj )
        {
            findFlag = true;
            break;
        }
    }

    if( findFlag )
    {
        if (dataAttrib[indexToProcess].status == Stopped ||
            dataAttrib[indexToProcess].status == Paused ||
            dataAttrib[indexToProcess].status == Error )
        {
            
            pushStartButtonList[indexToProcess]->setText("Pause");
            labelList[indexToProcess]->setStyleSheet("QLabel { color : #b1eef0; font-weight: bold;}");
            pushStopButtonList[indexToProcess]->show();
            progressBarList[indexToProcess]->show();
            dataAttrib[indexToProcess].status = Started;
            mainCtrl->startDownload( indexToProcess );
            completeFlag[indexToProcess] = false;
        }
        else
        {
            pushStartButtonList[indexToProcess]->setText("Start");
            labelList[indexToProcess]->setStyleSheet("QLabel { color : #ebebeb; font-weight: bold;}");
            pushStopButtonList[indexToProcess]->show();
            progressBarList[indexToProcess]->show();
            dataAttrib[indexToProcess].status = Paused;
            mainCtrl->pauseDownload( indexToProcess );
        }
    }
}

/******************************************************************************
 Slot to Stop Button
******************************************************************************/
void Ui_Custom::stopDownload(){
    QObject* obj = sender();
    int indexToProcess = -1;
    bool findFlag = false;

    for ( indexToProcess = 0; indexToProcess < dataAttrib.size(); ++indexToProcess)
    {
        if(pushStopButtonList[indexToProcess] == obj )
        {
            findFlag = true;
            break;
        }
    }

    if ( dataAttrib[indexToProcess].status != Stopped && findFlag )
    {
        pushStartButtonList[indexToProcess]->setText("Resume Download");
        pushStopButtonList[indexToProcess]->hide();
        labelList[indexToProcess]->setStyleSheet("QLabel { color : #ebebeb; font-weight: bold;}");
        dataAttrib[indexToProcess].status = Stopped;
        mainCtrl->stopDownload( indexToProcess );
        path_to_download->setEnabled( true );
    }
}

/******************************************************************************
// HANDLERS
******************************************************************************/

/******************************************************************************
 Track download progress
******************************************************************************/
void Ui_Custom::trackDownload()
{
    std::thread handlerDownload(&Ui_Custom::progressHandlerFunc, this);
    handlerDownload.detach();
}

/******************************************************************************
 Progress handler to get download data : Thread
******************************************************************************/
void Ui_Custom::progressHandlerFunc()
{
    std::vector<DownloadAttrib> downloadData;
    while ( ! stopFlag )
    {
        downloadData = mainCtrl->getDownloadStatus();
        for ( uint8_t i = 0; i < downloadData.size(); ++i)
        {
            if( downloadData[i].percentDownloaded < 100 )
            {
                if ( downloadData[i].status == Started )
                {
                    printf("[Ui_Custom::progressHandlerFunc] Progress %lf Percent in [%s] \n",
                            downloadData[i].percentDownloaded, downloadData[i].fileName.c_str());
                    emit downloadDatataChanged( downloadData[i] );
                }
                else if ( downloadData[i].status == Error && ! completeFlag[i])
                {
                    printf("[Ui_Custom::progressHandlerFunc] ERROR Progress %lf Percent in [%s] \n",
                            downloadData[i].percentDownloaded, downloadData[i].fileName.c_str());
                    completeFlag[i] = true;
                    emit downloadDatataChanged( downloadData[i] );
                }
            }
            else if ( ! completeFlag[i] && downloadData[i].percentDownloaded >= 100 )
            {
                downloadData = mainCtrl->getDownloadStatus();
                completeFlag[i] = true;
                emit downloadDatataChanged( downloadData[i] );

            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500) );
    }
}

QT_END_MOC_NAMESPACE
