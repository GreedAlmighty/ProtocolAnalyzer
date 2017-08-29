#include "networksettingsdialog.h"
#include "ui_networksettingsdialog.h"

NetworkSettingsDialog::NetworkSettingsDialog(QWidget *parent) :
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

    setMasksForLineEdits();
}

NetworkSettingsDialog::~NetworkSettingsDialog()
{
    delete ui;
}

void NetworkSettingsDialog::setConfiguredSettings( QString ip, QString subnet, QString port)
{
    ui->ipaddressLineEdit->setText(ip);
    ui->submaskLineEdit->setText(subnet);
    ui->portLineEdit->setText(port);
}

void NetworkSettingsDialog::setMasksForLineEdits()
{
    ui->ipaddressLineEdit->setInputMask("000.000.000.000");
    ui->submaskLineEdit->setInputMask("000.000.000.000");
    ui->portLineEdit->setInputMask("00000");
}

void NetworkSettingsDialog::on_acceptNetworkButton_clicked()
{
    emit newIPAddress( ui->ipaddressLineEdit->text() );
    emit updateLog( "IP is now: " + ui->ipaddressLineEdit->text() );
    emit newSubnetMask( ui->submaskLineEdit->text() );
    emit updateLog( "Subnetmask is now: " + ui->submaskLineEdit->text() );
    emit newPortNumber( ui->portLineEdit->text() );
    emit updateLog( "Portnumber is now: " + ui->portLineEdit->text() );
    emit processedAllChanges();
}

void NetworkSettingsDialog::on_cancelNetworkButton_clicked()
{
    //here to make sure the window is closed when the cancel button is clicked
}
