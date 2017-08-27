#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    //defines for the protocol in the combobox
    #define NOPROTOCOLSELECTED 0
    #define TCPIP 1
    #define RESULTMONITOR 2
    #define DAKTRONICS 3

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void protocolAlreadyActivatedSignal();
    void noProtocolSelectSignal();
    void startTCPServer();
    void startTCPSocket();
    void updateLog( QString );

private:
    void show_noProtocolActivatedDialog();

public slots:
    void on_addTextToLog( QString log_line );

private slots:
    void on_activateProtocolButton_clicked();
    void on_protocolSelectionBox_currentIndexChanged(int index);
    void on_disableProtocolButton_clicked();
    void on_protocolAlreadyActivatedDialog();
    void on_noProtocolSelectedDialog();
    void on_configureSettingsButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
