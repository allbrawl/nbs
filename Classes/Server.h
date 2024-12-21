#ifndef NBS_SERVER_H
#define NBS_SERVER_H
class Server
{
public:
    // Change to your desired port
    const int port = 9339;
    int serverSocket;
    int createSocket();
    void listenForConnections();
};
#endif