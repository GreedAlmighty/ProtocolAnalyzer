#include "networksettings.h"
#include <QStringList>

static QString ip_address;
static QString subnet_mask;
static QString port_number;
static QString username;
static QString password;

NetworkSettings::NetworkSettings()
{
    ip_address = "127.0.0.1";
    subnet_mask = "255.255.255.0";
    port_number = "DEFAULT";
    username = "user";
    password = "pass";
}

NetworkSettings::~NetworkSettings()
{

}

QString NetworkSettings::getIpAddress()
{
    return ip_address;
}

QString NetworkSettings::getSubnetMask()
{
    return subnet_mask;
}

QString NetworkSettings::getPortNumber()
{
    return port_number;
}

QString NetworkSettings::getUsername()
{
    return username;
}

QString NetworkSettings::getPassword()
{
    return password;
}

bool NetworkSettings::setNetworkSettings(QString ip, QString sub, QString port, QString user, QString pass)
{
    if( checkAddress(ip) && checkAddress(sub) && port!=""){
        ip_address = ip;
        subnet_mask = sub;
        port_number = port;
        username = user;
        password = pass;
        return true;
    }
    return false;
}

bool NetworkSettings::checkAddress( QString address )
{
    QStringList list;
    list = address.split(".");

    QString str;
    int value;

    foreach (str, list) {
        value = str.toInt();
        if(value>255 || value < 0){
            return false;
        }
    }
    return true;
}
