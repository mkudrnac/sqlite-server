//
// Created by Miroslav Kudrnac on 05/03/2018.
//

#ifndef SQLITE_SERVER_IREQUESTHANDLER_H
#define SQLITE_SERVER_IREQUESTHANDLER_H

#include <string>
#include "IResponse.h"

class IRequestHandler {
public:
    virtual ~IRequestHandler() = default;

    virtual std::unique_ptr<IResponse> handle_request(const std::string &) = 0;
};

#endif