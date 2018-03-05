//
// Created by Miroslav Kudrnac on 02/03/2018.
//

#ifndef SQLITE_SERVER_SOCKET_H
#define SQLITE_SERVER_SOCKET_H

#include <memory>
#include <boost/asio.hpp>
#include <fmt/printf.h>

class Socket : public std::enable_shared_from_this<Socket>
{
public:
    explicit Socket(boost::asio::io_service& service, boost::asio::ip::tcp::socket socket) :
            m_service(service),
            m_socket(std::move(socket))
    {
        //disable Nagle by default
        m_socket.set_option(boost::asio::ip::tcp::no_delay(true));
    }
    
    virtual void do_read() = 0;
    
protected:
    boost::asio::io_service&       m_service;
    boost::asio::ip::tcp::socket   m_socket;
};

#endif /* SQLITE_SERVER_SOCKET_H */
