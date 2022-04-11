#include <iostream>
#include "socketserver.h"
int main() {

    SocketServer* server_socket = new SocketServer;
    int num = server_socket->create_socket();

    if (num < 1){
        cout<<"Socket is lower than 1"<<endl;
        return 0;
    }

    server_socket->receive();
    server_socket->close_socket();

    delete server_socket;

    return 0;
}
