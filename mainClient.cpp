#include <iostream>
#include "socketclient.h"


int main() {
    SocketClient* socket = new SocketClient;
    socket->create_socket();

    socket->send_Msg();
    socket->receive();
    socket->send_Msg();
    cout<<"ssss";

    socket->close_socket();

    delete socket;
    return 0;
}
