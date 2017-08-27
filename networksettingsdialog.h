#ifndef NETWORKSETTINGSDIALOG_H
#define NETWORKSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class NetworkSettingsDialog;
}

class NetworkSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetworkSettingsDialog(QWidget *parent = 0);
    ~NetworkSettingsDialog();
    void setConfiguredSettings( QString ip, QString subnet, QString port);

signals:
    newIPAddress(QString);
    newSubnetMask(QString);
    newPortNumber(QString);
    processedAllChanges();
    updateLog(QString);

private slots:
    void on_cancelNetworkButton_clicked();
    void on_acceptNetworkButton_clicked();

private:
    Ui::NetworkSettingsDialog *ui;
    void setMasksForLineEdits();
};

#endif // NETWORKSETTINGSDIALOG_H
