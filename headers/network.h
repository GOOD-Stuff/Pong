#ifndef NETWORK_H
#define NETWORK_H

/*
    This class responsible of set connection (UDP) and send position of
        second player and ball;
*/

#include <QtNetwork/QUdpSocket>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>               // TODO: delete for release
#include <QDataStream>

class Network {
public:
    Network();
    ~Network();
private:
    QUdpSocket *udp_sckt;
};

#endif // NETWORK_H
