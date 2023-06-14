#include <iostream>
#include <string>
#include <sys/types.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

int main()
{
    int port = atoi("8080");
    char msg[1500];
     
    sockaddr_in servAddr;
    bzero((char*)&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(port);
 
    int serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSd < 0)
    {
        cerr << "Error in socket()" << endl;
        exit(0);
    }
    int bindStatus = bind(serverSd, (struct sockaddr*) &servAddr, sizeof(servAddr));
    if(bindStatus < 0)
    {
        cerr << "Error in binding socket." << endl;
        exit(0);
    }
    cout << "Waiting for a client to connect..." << endl;
    listen(serverSd, 5);
    sockaddr_in newSockAddr;
    socklen_t newSockAddrSize = sizeof(newSockAddr);
    int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
    if(newSd < 0)
    {
        cerr << "Error accepting request from client!" << endl;
        exit(1);
    }
    cout << "Connected with client!" << endl;
    while(1)
    {
        cout << "Awaiting client response..." << endl;
        memset(&msg, 0, sizeof(msg));
        recv(newSd, (char*)&msg, sizeof(msg), 0);
        if(!strcmp(msg, "BYE"))
        {
            cout << "Client has quit the session" << endl;
            break;
        }
        cout << "Client: " << msg << endl;
        string data;
	      cout << "Server: Enter message: ";
        getline(cin, data);
        memset(&msg, 0, sizeof(msg)); 
        strcpy(msg, data.c_str());
        if(data == "BYE")
        {
            send(newSd, (char*)&msg, strlen(msg), 0);
            break;
        }
        send(newSd, (char*)&msg, strlen(msg), 0);
    }
    close(newSd);
    close(serverSd);
    cout << "Connection closed..." << endl;
    return 0;   
}
