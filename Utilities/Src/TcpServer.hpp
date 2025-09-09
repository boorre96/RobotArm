#pragma once
#include <string>
#include <netinet/in.h>
namespace robotarm::utilities
{

class TcpServer 
{
    public:
    TcpServer(std::string &&ip, uint16_t port);
    ~TcpServer();
    TcpServer(TcpServer&) = delete;
    TcpServer& operator=(const TcpServer&) = delete;
    TcpServer(TcpServer&&) = delete;
    TcpServer& operator=(TcpServer&&) = delete;
    bool openSocket();
    bool startListen();

    private:
    std::string m_ipStr{};
    uint16_t m_port{};
    // m_sockfd = socket file descriptor which is a unique id for the socket.
    int m_sockfd{};
    int m_connfd{};
    struct sockaddr_in m_servaddr{};
    struct sockaddr_in m_cli{};
};
} // namespace robotarm::utilities