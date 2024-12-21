#include <sys/socket.h>
#include <netinet/in.h>
#include "Server.h"

int Server::createSocket()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == -1)
    {
        return -1; // Failed to create socket
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9339);
    serverAddress.sin_addr.s_addr = INADDR_ANY; // Any ip addr
    if(bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1)
    {
        return -2; // Failed to bind        
    }

    return serverSocket;
}