#ifndef SERVER_H
#define SERVER_H

#include <asio.hpp>
#include <iostream>
#include <string>


using asio::ip::tcp;


class Server{
    public:
    Server(int port_, std::string host_) : port(port_), host(host_){};

private:
    std::string host;
    int port;
    void createServer();

};



#endif