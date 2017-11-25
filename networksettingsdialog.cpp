#include "networksettingsdialog.h"
#include "networksettings.h"
#include "ui_networksettingsdialog.h"

NetworkSettings *settings;

NetworkSettingsDialog::NetworkSettingsDialog(QWidget *parent, NetworkSettings *settings_parent) :
    QDialog(parent),
    ui(new Ui::NetworkSettingsDialog)
{
    ui->setupUi(this);

    //connects close window with cancel button
    connect(ui->cancelNetworkButton, SIGNAL(clicked(bool)),
            this, SLOT(close()));
    //connects close windows with updated network settings signal
    connect(this, SIGNAL(processedAllChanges()),
            this, SLOT(close()));

    settings = settings_parent;

    ui->passWordLineEdit->setEchoMode(QLineEdit::Password); //makes sure to not show the password

    setMasksForLineEdits();
    showConfiguredSettings();
}

NetworkSettingsDialog::~NetworkSettingsDialog()
{
    delete ui;
}

void NetworkSettingsDialog::showConfiguredSettings()
{
    ui->ipaddressLineEdit->setText( settings->getIpAddress() );
    ui->submaskLineEdit->setText( settings->getSubnetMask() );
    ui->portLineEdit->setText( settings->getPortNumber() );
    ui->userNameLineEdit->setText( settings->getUsername() );
    ui->passWordLineEdit->setText( settings->getPassword() );
}

void NetworkSettingsDialog::setMasksForLineEdits()
{
    ui->ipaddressLineEdit->setInputMask("000.000.000.000");
    ui->submaskLineEdit->setInputMask("000.000.000.000");
}

void NetworkSettingsDialog::on_acceptNetworkButton_clicked()
{
    if(ui->portLineEdit->text()!="DEFAULT"){
        ui->portLineEdit->setInputMask("00000");
    }
    emit updateLog( "IP is now: " + ui->ipaddressLineEdit->text() );
    emit updateLog( "Subnetmask is now: " + ui->submaskLineEdit->text() );
    emit updateLog( "Portnumber is now: " + ui->portLineEdit->text() );
    emit updateLog( "Username is now: " + ui->userNameLineEdit->text());
    emit updateLog( "Password is now: " + ui->passWordLineEdit->text());

    if(settings->setNetworkSettings( ui->ipaddressLineEdit->text(),
                                      ui->submaskLineEdit->text(),
                                      ui->portLineEdit->text(),
                                      ui->userNameLineEdit->text(),
                                      ui->passWordLineEdit->text()) )
    {
        emit processedAllChanges();
    }

}

void NetworkSettingsDialog::on_cancelNetworkButton_clicked()
{
    //here to make sure the window is closed when the cancel button is clicked
}
