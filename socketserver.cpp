#include "socketserver.h"

// In this approach I assume I will only have one client, so I don't use threads or
// a vector with the sockets of various clients. Only one socket client!!!

SocketServer::SocketServer()
{
}

bool SocketServer::create_socket(){

    this->socket_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(socket_server < 0){
        cout<<"Failed to CREATE server socket :("<<endl;
        return false;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port =  htons(4050);
    memset(&server_addr.sin_zero, 0, sizeof(server_addr.sin_zero));

    //_____________________________________________________________________________________________//

    int binding = bind(socket_server, (sockaddr*) &server_addr, (socklen_t) sizeof(server_addr));

    if (binding < 0){
        cout<<"Failed to BIND server socket :("<<endl;
        return false;
    }

    //_____________________________________________________________________________________________//

    listen(socket_server, 1);
    socklen_t client_addrSize = sizeof (client_addr);

    //_____________________________________________________________________________________________//

    socket_client = accept(socket_server, (sockaddr*) &client_addr, &client_addrSize);

    if(socket_client < 0){
        cout<<"Failed to ACCEPT client :("<<endl;
        return false;
    }

    this->client_socket_pointer = &socket_client;

    cout<<"Client connected :)"<<endl;
    return true;
}

bool SocketServer::receive(){

    if(socket_server < 0 || socket_client < 0){
        cout<<"Could not receive because some Socket is lower than zero"<<endl;
        return false;
    }
    int num = recv(socket_client, buffer, sizeof (buffer), 0);

    if(num == -1){
        cout<<"Failed to receive msg because function recv is equal to -1"<<endl;
        return false;
    }
    cout<<"Client says: "<<buffer<<endl;
    memset(buffer, 0, sizeof(buffer));

    return true;
}

bool SocketServer::send_Msg(){
    if(socket_server < 0 || socket_client < 0){
        return false;
    }
    cout<<"Write your message for client: ";
    cin>>this->buffer;

    int num = send(socket_client, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    if(num == -1){
        cout<<"Failed to send msg because function send is equal to -1"<<endl;
        return false;
    }

    return true;
}

void SocketServer::close_socket(){
    close(socket_client);
    cout<<"Client disconnected, socket closed"<<endl;
}
