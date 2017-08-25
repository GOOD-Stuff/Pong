#include "network.h"

Network::Network() {
    udp_sckt = new QUdpSocket();


}

Network::~Network(){
    delete udp_sckt;
}
