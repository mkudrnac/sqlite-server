//
// Created by Miroslav Kudrnac on 02/03/2018.
//

#ifndef SQLITE_SERVER_SQLITESOCKET_H
#define SQLITE_SERVER_SQLITESOCKET_H

#include "Socket.h"

class SQLiteSocket : public Socket
{
public:
    explicit SQLiteSocket(boost::asio::io_service& service, boost::asio::ip::tcp::socket socket);

    //MARK: Socket
    void OnRead() override;

private:

};


#endif //SQLITE_SERVER_SQLITESOCKET_H
