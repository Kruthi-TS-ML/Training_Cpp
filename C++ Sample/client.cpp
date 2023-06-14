#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

int main()
{
    char serverIp[10] = "127.0.0.1"; 
    int port = atoi("8080"); 
    char msg[1500]; 
    struct hostent* host = gethostbyname(serverIp); 
    sockaddr_in sendSockAddr;   
    bzero((char*)&sendSockAddr, sizeof(sendSockAddr)); 
    sendSockAddr.sin_family = AF_INET; 
    sendSockAddr.sin_addr.s_addr = 
        inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    sendSockAddr.sin_port = htons(port);
    int clientSd = socket(AF_INET, SOCK_STREAM, 0);
    int status = connect(clientSd,
                         (sockaddr*) &sendSockAddr, sizeof(sendSockAddr));
    if(status < 0)
    {
        cout<<"Error connecting to socket!"<<endl;
    }
    cout << "Connected to the server!" << endl;
    while(1)
    {
        cout << ">";
        string data;
        getline(cin, data);
        memset(&msg, 0, sizeof(msg));
        strcpy(msg, data.c_str());
        if(data == "BYE")
        {
            send(clientSd, (char*)&msg, strlen(msg), 0);
            break;
        }
        send(clientSd, (char*)&msg, strlen(msg), 0);
        cout << "Awaiting server response..." << endl;
        memset(&msg, 0, sizeof(msg));
        recv(clientSd, (char*)&msg, sizeof(msg), 0);
	if(!strcmp(msg, "BYE"))
        {
            cout << "Server has quit the session" << endl;
            break;
        }
        cout << "Server: " << msg << endl;
    }
    close(clientSd);
    cout << "Connection closed" << endl;
    return 0;    
}
