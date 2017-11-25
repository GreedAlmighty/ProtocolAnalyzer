#ifndef NETWORKSETTINGSDIALOG_H
#define NETWORKSETTINGSDIALOG_H

#include <QDialog>
#include "networksettings.h"

namespace Ui {
class NetworkSettingsDialog;
}

class NetworkSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetworkSettingsDialog(QWidget *parent = 0, NetworkSettings *settings_parent = 0);
    ~NetworkSettingsDialog();
    void showConfiguredSettings();

signals:
    processedAllChanges();
    updateNetworkSettings(QString, QString, QString, QString, QString);
    updateLog(QString);

private slots:
    void on_cancelNetworkButton_clicked();
    void on_acceptNetworkButton_clicked();

private:
    Ui::NetworkSettingsDialog *ui;
    void setMasksForLineEdits();
};

#endif // NETWORKSETTINGSDIALOG_H
