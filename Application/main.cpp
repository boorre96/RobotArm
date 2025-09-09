#include <iostream>

#include "TcpServer.hpp"

int main()
{
    std::cout << "Hello World!"<< std::endl;
    robotarm::utilities::TcpServer server("127.0.0.1", 8080);
    server.openSocket();
    server.startListen();
    return 0;
}