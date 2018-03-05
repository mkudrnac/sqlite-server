//
// Created by Miroslav Kudrnac on 05/03/2018.
//

#ifndef SQLITE_SERVER_REQUESTHANDLER_H
#define SQLITE_SERVER_REQUESTHANDLER_H

#include <string>
#include <nlohmann/json.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "Response.h"

class RequestHandler final
{
public:
    RequestHandler();

    const Response handle_request(const std::string& req);

private:
    const nlohmann::json parse_request(const std::string& req);

    //handlers
    const Response handle_query(const nlohmann::json&);
    const Response handle_list(const nlohmann::json&);
    const Response handle_delete_db(const nlohmann::json&);

private:
    std::map<std::string, boost::function<const Response(const nlohmann::json&)>> m_map;
};


#endif //SQLITE_SERVER_REQUESTHANDLER_H
