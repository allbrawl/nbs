#include <sys/socket.h>
#include <netinet/in.h>
#include "Server.h"
#include <unistd.h>
#include <iostream>

int Server::createSocket()
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

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

void Server::listenForConnections()
{
    if (listen(serverSocket, 10) == -1)
    {
        std::cerr << "\033[91m[ERROR]\033[0m Failed to listen on socket\n";
        close(serverSocket);
        return;
    }

    std::cout << "\033[94m[INFO]\033[0m Listening for connections...\n";

    while (true)
    {
        sockaddr_in clientAddress;
        socklen_t clientLen = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientLen);

        if (clientSocket >= 0)
        {
            std::cout << "\033[92m[NEW CONNECTION]\033[0m Client connected\n";
            close(clientSocket);
        }
    }
}