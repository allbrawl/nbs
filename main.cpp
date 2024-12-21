#include <iostream>
#include <unistd.h>
#include "Classes/Server.h"
#include <thread>

int main()
{
    Server server;
    int socket = server.createSocket();
    if (socket == -1)
    {
        std::cerr << "\033[91m[ERROR]\033[0m Failed to create socket\n";
    }
    else if (socket == -2)
    {
        std::cerr << "\033[91m[ERROR]\033[0m Failed to bind to " << server.port << "\n";
    }
    else
    {
        std::cout << "\033[94m[INFO]\033[0m Socket created and bound to port " << server.port << "\n";
    }

    std::thread listenerThread(&Server::listenForConnections, &server);
    listenerThread.detach();
    std::this_thread::sleep_for(std::chrono::seconds(60));

    return 0;
}
