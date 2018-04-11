//
// Created by Miroslav Kudrnac on 11/04/2018.
//

#import "Socket.h"
#include "Logger.h"

Socket::Socket(boost::asio::io_service& service, boost::asio::ip::tcp::socket socket) :
        m_service(service),
        m_socket(std::move(socket))
{
    Log.debug("Socket create\n");
}

Socket::~Socket()
{
    Log.debug("Socket destroy\n");
}