#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "networksettingsdialog.h"
#include "networksettings.h"
#include <QDebug>
#include <QThread>
#include <QMessageBox>

bool protocolActivated = false;         //used to see whether a protocol is already activated
qint8 selected_protocol_index = 0;      //used to verify the selected protocol
QThread protocolThread;                 //Thread used for receiving and transmitting data
NetworkSettings settings_pointer;

//need to use QTCPServer for Timing and Scoring
//need to use QTCPSocket for Orbits protocols
//create slots for the emitted signals within on_activateProtocolButton_clicked()
//create configure dialog to configure the ip and everything else

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Protocol Analyzer 0.1 BETA");

    //Connects the update log signal with the textbrowser on the log tab
    connect( this, SIGNAL(updateLog(QString)),
             this, SLOT(on_addTextToLog(QString)));

    //Connect protocol already activated dialog with signal
    connect( this, SIGNAL(protocolAlreadyActivatedSignal()),
             this, SLOT(on_protocolAlreadyActivatedDialog()));

    //Connect no protocol selected dialog with signal
    connect( this, SIGNAL(noProtocolSelectSignal()),
             this, SLOT(on_noProtocolSelectedDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_noProtocolActivatedDialog()
{
    QMessageBox mErrorBox;

    mErrorBox.setWindowTitle("ERROR");
    mErrorBox.setText("Please activate a Protocol first!");
    mErrorBox.addButton(QMessageBox::Ok);

    mErrorBox.exec();
}

void MainWindow::on_protocolAlreadyActivatedDialog()
{
    QMessageBox mErrorBox;

    mErrorBox.setWindowTitle("ERROR");
    mErrorBox.setText("Protocol Already Activated!");
    mErrorBox.addButton(QMessageBox::Ok);

    mErrorBox.exec();
}

void MainWindow::on_noProtocolSelectedDialog()
{
    QMessageBox mErrorBox;

    mErrorBox.setWindowTitle("ERROR");
    mErrorBox.setText("No Protocol Selected!");
    mErrorBox.addButton(QMessageBox::Ok);

    mErrorBox.exec();

    //done this so the Protocol already activated signal isn't thrown
    protocolActivated = false;
}

void MainWindow::on_activateProtocolButton_clicked()
{
    //Used to verify whether a protocol is already activated
    if(protocolActivated){
        emit protocolAlreadyActivatedSignal();
        return;
    }
    protocolActivated = true;

    //Used to see what classes to make and start
    switch(selected_protocol_index){
    case NOPROTOCOLSELECTED:    emit updateLog( "Activate no selected protocol" );
                                emit noProtocolSelectSignal();
                                break;

    case TCPIP:                 emit updateLog( "Activate Timing and Scoring TCPIP Protocol" );
                                emit startTCPServer();
                                break;

    case RESULTMONITOR:         emit updateLog( "Activate Orbits RMonitor protocol" );
                                emit startTCPSocket();
                                break;

    case DAKTRONICS:            emit updateLog( "Activate Orbits Daktronics Feed" );
                                emit startTCPSocket();
                                break;
    }
}

void MainWindow::on_addTextToLog( QString log_line )
{
    ui->logTextWindow->insertPlainText( log_line + "\r\n" );
}

void MainWindow::on_protocolSelectionBox_currentIndexChanged(int index)
{
    selected_protocol_index = index;
}

void MainWindow::on_disableProtocolButton_clicked()
{
    protocolActivated = false;
    emit updateLog( "Protocol Disabled" );
    //close thread
    //delete thread
}

void MainWindow::on_configureSettingsButton_clicked()
{
    NetworkSettingsDialog settingsDialog(this, &settings_pointer);
    connect( &settingsDialog, SIGNAL(updateLog(QString)),
             this, SLOT(on_addTextToLog(QString)));
    settingsDialog.exec();
}
