#ifndef ZSERIO_URLCLIENT_H_INC
#define ZSERIO_URLCLIENT_H_INC

#include <memory>
#include <string>

namespace zserio
{

class UrlClient
{
    struct Impl;

public:
    UrlClient();

    std::pair<const uint8_t*, size_t> fetchResource(const std::string& uri);

private:
    std::unique_ptr<Impl> impl_;
};

}

#endif
