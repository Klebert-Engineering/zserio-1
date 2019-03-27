#ifndef ZSERIO_URLCLIENT_H_INC
#define ZSERIO_URLCLIENT_H_INC

#include "CppRuntimeException.h"
#include <memory>
#include <string>
#include <vector>


namespace zserio
{
// to_string functions for all types fields could have
template <class T>
std::string to_string(const T& /*o*/)
{
    throw CppRuntimeException("to_string is not supported for compound types.");
}
// Set of datatypes that are actually supported at the moment
template<> std::string to_string<std::string>(const std::string& s);
template<> std::string to_string<int>(const int& val);
template<> std::string to_string<long>(const long& val);
template<> std::string to_string<long long>(const long long& val);
template<> std::string to_string<unsigned>(const unsigned& val);
template<> std::string to_string<unsigned long>(const unsigned long& val);
template<> std::string to_string<unsigned long long>(const unsigned long long& val);
template<> std::string to_string<float>(const float& val);
template<> std::string to_string<double>(const double& val);
template<> std::string to_string<long double>(const long double& val);

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
