#ifndef ZSERIO_URLCLIENT_H_INC
#define ZSERIO_URLCLIENT_H_INC

#include <memory>
#include <string>
#include <vector>

namespace zserio
{

class UrlClient
{
    struct Impl;

public:
    UrlClient();
    ~UrlClient();

    std::vector<uint8_t> fetchResource(const std::string& uri);

    enum Status {
        Healthy,
        Error
    };

    Status status();
    std::string statusDescription();

private:
    std::unique_ptr<Impl> impl_;
};

}

#endif
