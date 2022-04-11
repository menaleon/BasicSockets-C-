#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

class SocketServer
{
public:
    SocketServer();
    bool create_socket();
    bool receive();
    bool send_Msg();
    void close_socket();

    int socket_server, socket_client;
    int binding;
    char buffer[1024];
    sockaddr_in server_addr, client_addr;
    int* client_socket_pointer = nullptr;

    void run();

private:

};

#endif // SOCKETSERVER_H
