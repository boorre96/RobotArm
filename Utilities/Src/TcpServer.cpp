
#include "TcpServer.hpp"

#include <sys/socket.h>
#include <iostream>

namespace robotarm::utilities
{
TcpServer::TcpServer(std::string &&ip, uint16_t port) : m_ipStr(ip), m_port(port){}

TcpServer::~TcpServer() = default;

bool TcpServer::openSocket()
{
    
    // Socket created with IPv4, TCP, Default protocol
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_sockfd == -1)
    {
        std::cout << "Socket creation failed...\n" << std::endl;
        return false;
    }
    else
        std::cout << "Socket succerssfully created..\n" << std::endl;

    /*
    Socket should bind to all available network interfaces on the machine.
    Set the port number to the value provided in the constructor.
    Specify that the internet protocol should be IPv4
    */
    m_servaddr.sin_family = AF_INET;
    m_servaddr.sin_addr.s_addr = INADDR_ANY;
    m_servaddr.sin_port = htons(m_port);

    if(bind(m_sockfd, (struct sockaddr*)&m_servaddr, sizeof(m_servaddr)) == -1)
    {
        std::cout << "Socket bind failed...\n" << std::endl;
        return false;
    }
    else
        std::cout << "Socket binded! \n" << std::endl;
    return true;
}

bool TcpServer::startListen()
{
    if(listen(m_sockfd, 1) != 0)
    {
        std::cout << "Listen failed...\n" << std::endl;
        return false;
    }
    else
        std::cout << "Server listening..\n" << std::endl;

    unsigned int len = sizeof(m_cli);
    m_connfd = accept(m_sockfd, (struct sockaddr*)&m_cli, &len); 
    if(m_connfd == -1)
    {
        std::cout << "Server accept failed...\n" << std::endl;
        return false;
    }
    else
        std::cout << "Server accepted the client...\n" << std::endl;
    
    return true;
}
} // namespace robotarm::utilities