//
// Created by Miroslav Kudrnac on 02/03/2018.
//

#ifndef SQLITE_SERVER_SOCKET_H
#define SQLITE_SERVER_SOCKET_H

#include <memory>
#include <boost/asio.hpp>

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
    
    virtual void OnRead() = 0;
    
    void Disconnect()
    {
        auto self(shared_from_this());
        m_service.post([this, self](){
            try
            {
                if(m_socket.is_open())
                {
                    m_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
                    m_socket.close();
                }
            }
            catch(boost::system::system_error& error)
            {
                //TODO: log
            }
        });
    }
    
    const std::string GetRemoteIP() const
    {
        return m_socket.remote_endpoint().address().to_string();
    }
    
protected:
    boost::asio::io_service&       m_service;
    boost::asio::ip::tcp::socket   m_socket;
};

#endif /* SQLITE_SERVER_SOCKET_H */
