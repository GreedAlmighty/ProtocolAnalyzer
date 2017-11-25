#ifndef NETWORKSETTINGS_H
#define NETWORKSETTINGS_H

#include <QString>

class NetworkSettings
{

public:
    NetworkSettings();
    ~NetworkSettings();

    bool setNetworkSettings(QString ip, QString sub, QString port, QString user, QString pass);

    QString getIpAddress();
    QString getSubnetMask();
    QString getPortNumber();
    QString getUsername();
    QString getPassword();

private:
    bool checkAddress( QString address );
};

#endif // NETWORKSETTINGS_H
