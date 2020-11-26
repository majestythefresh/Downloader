/***********************************************************************
* FILENAME    :   ui_file_downloader.h
* AUTHOR      :   Arturo Plauchu (arturo.plauchu@gmail.com)
* DATE        :   September 2020
* DESCRIPTION :   UI Class definition
* LICENSE     :   GPL v2.0
*
***********************************************************************/

#ifndef UI_FILE_DOWNLOADER_H
#define UI_FILE_DOWNLOADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QProgressBar>
#include <QtGui/QMovie>
#include <QtGui/QShowEvent>
#include <QtCore/QSignalMapper>
#include <QtCore/QObject>
#include <QtCore/QMetaType>

/**********************************************************************/
/**********************************************************************/

#include "MainCtrl.h"
#include "DownloadThread.h"

/**********************************************************************/
/**********************************************************************/

using namespace downloader::download;
using namespace downloader::downloadfiles;

/**********************************************************************/
/**********************************************************************/

QT_BEGIN_NAMESPACE

Q_DECLARE_METATYPE(DownloadAttrib)
class Ui_Custom : public QObject
{
    Q_OBJECT
public slots:
    void setDownloadPath();
    void setDownloadData( DownloadAttrib data );
    void startDownload();
    void stopDownload();
    void getJsonList(int frameNumber);
signals:
    void downloadDatataChanged( DownloadAttrib data );
public:
    QSignalMapper *signalMapper;
    QFrame *frame_3;
    QLineEdit *path_to_download;
    QLabel *test_id_label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *tableWidget;
    QLabel *downloadLabel;
    QLabel *processLabel;
    QMovie *movie;
    QDialog *Custom;

    MainCtrl* mainCtrl;
    bool animationFlag = true;
    bool flagData = true;
    bool stopFlag = false;
    std::vector<DownloadAttrib> dataAttrib;
    std::vector<QPushButton*> pushStartButtonList;
    std::vector<QPushButton*> pushStopButtonList;
    std::vector<QProgressBar*> progressBarList;
    std::vector<QLabel*> labelList;
    std::vector<bool> completeFlag;

    void progressHandlerFunc();
    void trackDownload();

    /**********************************************************************/
    /** Passing Widget & MainCtrl
     *
     * @param Custom: QDialog widget (main Window)
     * @param mainController: MainCtrl pointer to handle data passed to UI.
     *
     */
    void setData(QDialog *Custom, MainCtrl* mainController)
    {
        mainCtrl = mainController;
        this->Custom = Custom;
    }

    /**********************************************************************/
    /** Set Data from MainCtrl to UI
     *
     */
    void setDynamicData()
    {

        dataAttrib = std::move(mainCtrl->getFilesAttrib());
        tableWidget->setRowCount(dataAttrib.size());
        tableWidget->setColumnCount(2);

        tableWidget->setColumnWidth(0,460);
        tableWidget->setColumnWidth(1,200);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setVisible(false);

        for ( uint8_t i = 0; i < dataAttrib.size(); ++i )
        {
            dataAttrib[i].status = Stopped;
            QPushButton* btn_start = new QPushButton();
            btn_start->setText("Start Download");
            btn_start->setStyleSheet("QPushButton { background-color : #4d81c9; color : white;font-weight: bold;}");
            pushStartButtonList.push_back(btn_start);
            QPushButton* btn_stop = new QPushButton();
            btn_stop->setText("Stop");
            btn_stop->hide();
            btn_stop->setStyleSheet("QPushButton { background-color : gray; color : black; font-weight: bold;}");
            pushStopButtonList.push_back(btn_stop);

            QProgressBar* progress_bar = new QProgressBar();
            progress_bar->setMinimum(0);
            progress_bar->setMaximum(100);
            progress_bar->setValue(0);
            progress_bar->hide();
            progress_bar->setStyleSheet("QProgressBar { border: 2px solid black; background-color: #adadad; \
                                         font-weight: bold; color: #000000;} \
                                         QProgressBar::chunk { background-color: #4d81c9; width: 20px;}");
            progress_bar->setAlignment(Qt::AlignCenter);
            progressBarList.push_back(progress_bar);

            QLabel* label1 = new QLabel();
            std::string fileName = dataAttrib[i].fileName+"."+dataAttrib[i].fileType;
            label1->setText(fileName.c_str());
            label1->setStyleSheet("QLabel { color : #ebebeb; font-weight: bold;}");
            labelList.push_back(label1);

            completeFlag.push_back(false);

            tableWidget->setRowHeight(i,60);

            QWidget* pWidget1 = new QWidget();
            QVBoxLayout* pLayout1 = new QVBoxLayout(pWidget1);
            pLayout1->addWidget(labelList[i]);
            pLayout1->addWidget(progressBarList[i]);
            pLayout1->setAlignment(Qt::AlignCenter);
            pWidget1->setLayout(pLayout1);
            tableWidget->setCellWidget(i, 0, pWidget1);

            QWidget* pWidget3 = new QWidget();
            connect(pushStartButtonList[i], SIGNAL(clicked()), this, SLOT (startDownload()));
            connect(pushStopButtonList[i], SIGNAL(clicked()), this, SLOT (stopDownload()));
            QHBoxLayout* pLayout3 = new QHBoxLayout(pWidget3);
            pLayout3->addWidget(pushStartButtonList[i]);
            pLayout3->addWidget(pushStopButtonList[i]);
            pLayout3->setAlignment(Qt::AlignCenter);
            pLayout3->setContentsMargins(0, 0, 0, 0);
            pWidget3->setLayout(pLayout3);
            tableWidget->setCellWidget(i, 1, pWidget3);
        }

    }

    /**********************************************************************/
    /** Setup UI
     *
     */
    void setupUi()
    {
        if (Custom->objectName().isEmpty())
            Custom->setObjectName(QStringLiteral("Custom"));
        Custom->resize(720, 522);
        QSize size(720, 522);
        Custom->setFixedSize(size);
        movie = new QMovie("./img/waitCats.gif");
        movie->setScaledSize(size);
        processLabel = new QLabel(Custom);
        processLabel->setMovie(movie);
        movie->start();
        connect(movie, SIGNAL(frameChanged(int)), this, SLOT (getJsonList(int)));
        downloadLabel = new QLabel(Custom);
        downloadLabel->setText("Download list of files...");
        downloadLabel->setStyleSheet(
            "QLabel { font-weight: bold; font-size:14pt; color : #ededed; padding: 10px 5px 10px 60px;}");

        frame_3 = new QFrame(Custom);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(20, 10, 681, 61));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        path_to_download = new QLineEdit(frame_3);
        path_to_download->setObjectName(QStringLiteral("path_to_download"));
        path_to_download->setGeometry(QRect(180, 20, 471, 23));
        test_id_label = new QLabel(frame_3);
        test_id_label->setObjectName(QStringLiteral("test_id_label"));
        test_id_label->setGeometry(QRect(30, 20, 141, 21));
        QFont font;
        font.setPointSize(11);
        test_id_label->setFont(font);
        scrollArea = new QScrollArea(Custom);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 80, 681, 421));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 673, 413));
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 671, 411));

        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Custom);

        QMetaObject::connectSlotsByName(Custom);
    } // setupUi

    /**********************************************************************/
    /** Helper to Set UI
     *
     */
    void retranslateUi(QDialog *Custom)
    {
        Custom->setWindowTitle(QApplication::translate("Custom", "File Downloader", Q_NULLPTR));
        Custom->setStyleSheet("QDialog { background-color : #242323; color : black; border: 1px solid white;}");
        path_to_download->setText(QApplication::translate("Custom","", Q_NULLPTR));
        path_to_download->setStyleSheet(" QLineEdit { background-color: #c3fac9; width: 20px; font-weight: bold;}");
        test_id_label->setText(QApplication::translate("Custom", "Local Path:", Q_NULLPTR));
        test_id_label->setStyleSheet("QLabel { color : #ebebeb; font-weight: bold;}");
        tableWidget->setStyleSheet("QTableWidget { background-color : #242323; border: 0px;} QTableWidget::item {border-bottom: 1px solid white;}");
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setShowGrid(false);
        scrollArea->setStyleSheet("QScrollArea {border: 0px;}");

        frame_3->hide();
        scrollArea->hide();

        connect(this, &Ui_Custom::downloadDatataChanged,
                this, &Ui_Custom::setDownloadData);

        connect(path_to_download, &QLineEdit::textChanged, this, &Ui_Custom::setDownloadPath);


    } // retranslateUi

};

namespace Ui {
    class Custom: public Ui_Custom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_DOWNLOADER_H
