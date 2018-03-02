//
// Created by Miroslav Kudrnac on 02/03/2018.
//

#include "SQLiteSocket.h"

SQLiteSocket::SQLiteSocket(boost::asio::io_service& service,
                           boost::asio::ip::tcp::socket socket) :
        Socket(service, std::move(socket))
{

}

void SQLiteSocket::OnRead()
{

}
