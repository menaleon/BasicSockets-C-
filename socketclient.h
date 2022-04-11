
#ifndef RAMELQUICLIENT_SOCKETCLIENT_H
#define RAMELQUICLIENT_SOCKETCLIENT_H
#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
//#include <thread>
//#include <pthread.h>
#include <unistd.h>
//#include <QObject>
#include <arpa/inet.h>

using namespace std;

class SocketClient

{
public:
    SocketClient();
    int socket_;
    sockaddr_in client_addr;
    char buffer[1024];
    bool create_socket();
    bool send_Msg();
    bool receive();
    void close_socket();

private:

};

#endif // SOCKETCLIENT_H



#endif //RAMELQUICLIENT_SOCKETCLIENT_H
