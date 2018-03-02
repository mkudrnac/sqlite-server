//
// Created by Miroslav Kudrnac on 02/03/2018.
//

#ifndef SQLITE_SERVER_LISTENSOCKET_H
#define SQLITE_SERVER_LISTENSOCKET_H

#include <boost/asio.hpp>

template <class T>
class ListenSocket final
{
public:
    explicit ListenSocket(boost::asio::io_service& service, unsigned short listenPort) :
            m_service(service),
            m_acceptor(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), listenPort)),
            m_socket(service)
    {
        do_accept();
    }
    
private:
    void do_accept()
    {
        m_acceptor.async_accept(m_socket, [this](std::error_code ec)
        {
            if(!ec)
            {
                std::make_shared<T>(m_service, std::move(m_socket))->OnRead();
            }
            
            do_accept();
        });
    }
    
private:
    boost::asio::io_service&       m_service;
    boost::asio::ip::tcp::acceptor m_acceptor;
    boost::asio::ip::tcp::socket   m_socket;
};

#endif /* AsioListenSocket_h */
