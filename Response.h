//
// Created by Miroslav Kudrnac on 05/03/2018.
//

#ifndef SQLITE_SERVER_RESPONSE_H
#define SQLITE_SERVER_RESPONSE_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

class Response final
{
    using HeaderSize = uint32_t;
    using ResponseData = std::vector<uint8_t>;

public:
    explicit Response(const nlohmann::json& json);

    inline const ResponseData& data() const
    {
        return m_data;
    }

private:
    ResponseData m_data;
};


#endif //SQLITE_SERVER_RESPONSE_H
