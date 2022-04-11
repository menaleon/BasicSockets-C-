#include "socketclient.h"

SocketClient::SocketClient()
{

}

bool SocketClient::create_socket(){

    socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(socket_ < 0){
        cout<<"Failed to CREATE client socket :("<<endl;
        return false;
    }

    client_addr.sin_addr.s_addr = inet_addr("192.168.0.2"); //192.168.0.2 // 127.0.0.1 // 192.168.0.255
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(4050);
    memset(&client_addr.sin_zero, 0 , sizeof(client_addr.sin_zero));

    int connected = connect(socket_, (sockaddr*) &client_addr, (socklen_t) sizeof(client_addr));

    if(connected < 0){
        cout<<"Failed to CONNECT socket :("<<endl;
        return false;
    }

    cout<<"Client socket connected!!!"<<endl;

    return true;
}

bool SocketClient::send_Msg(){

    cout<<"Write your message for server: ";
    cin>>this->buffer;
    int num = send(socket_, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    if(num == -1){
        cout<<"Failed to send msg because function send is equal to -1"<<endl;
        return false;
    }
    return true;
}

bool SocketClient::receive(){
    int num = recv(socket_, buffer, sizeof (buffer), 0);

    if(num == -1){
        cout<<"Failed to receive msg because function recv is equal to -1"<<endl;
        return false;
    }

    cout<<"Client says: "<<buffer<<endl;
    memset(buffer, 0, sizeof(buffer));
}

void SocketClient::close_socket(){
    close(socket_);
    cout<<"Socket closed"<<endl;
}
