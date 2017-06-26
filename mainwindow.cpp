#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

/****   TODO List   ********************************************
 * TCP-IP
    * FIRST
        * Amount of passings received
        * Time of last received passing
        * Amount of markers received
        * Time of last marker received
    * SECOND
        * Race information
        * Marker information
        * Passing information
    * THIRD
        * Device Info (Name, Type, Mac)
        * Update Log so its readable

 * RMONITOR/SCOREBOARD FEED
    * FIRST
        * Time
        * Flag Status
        * Event/Race Info
    * SECOND
        * Update log so its readable
    * THIRD
        * Create additional window containing all data
        * (something like Rmonitor program?)

 * DAKTRONICS
    * All information of this protocol is shown in one go

****    END TODO LIST   *****************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Protocol Analyzer 0.1 BETA");
}

MainWindow::~MainWindow()
{
    delete ui;
}
