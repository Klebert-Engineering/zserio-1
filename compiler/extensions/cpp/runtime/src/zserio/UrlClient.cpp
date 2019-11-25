#include "UrlClient.h"

#include <curl/curl.h>
#include <zserio/CppRuntimeException.h>
#include <iostream>

namespace zserio
{

template<> std::string to_string<std::string>(const std::string& s) { return s; }
template<> std::string to_string<int>(const int& val) {return std::to_string(val);}
template<> std::string to_string<long>(const long& val) {return std::to_string(val);}
template<> std::string to_string<long long>(const long long& val) {return std::to_string(val);}
template<> std::string to_string<unsigned>(const unsigned& val) {return std::to_string(val);}
template<> std::string to_string<unsigned long>(const unsigned long& val) {return std::to_string(val);}
template<> std::string to_string<unsigned long long>(const unsigned long long& val) {return std::to_string(val);}
template<> std::string to_string<float>(const float& val) {return std::to_string(val);}
template<> std::string to_string<double>(const double& val) {return std::to_string(val);}
template<> std::string to_string<long double>(const long double& val) {return std::to_string(val);}

UrlClient::~UrlClient() = default;

struct UrlClient::Impl
{
    CURL *curl = nullptr;
    CURLcode status = CURLE_OK;
    std::string statusText;
    std::vector<uint8_t> result;

    static size_t curlRecvFn (void *ptr, size_t size, size_t nmemb, void *thisPtr) {
        auto& resultVector = reinterpret_cast<Impl*>(thisPtr)->result;
        resultVector.insert(resultVector.end(), (uint8_t*)ptr, (uint8_t*)ptr + nmemb);
        return nmemb;
    };

    Impl() {
        curl = curl_easy_init();
    }

    Impl(Impl const& other) = default;

    ~Impl() {
        curl_easy_cleanup(curl);
    }
};

UrlClient::UrlClient() : impl_(new Impl) {}

std::vector<uint8_t> UrlClient::fetchResource(const std::string& uri)
{
    impl_->result.clear();

    curl_easy_setopt(impl_->curl, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(impl_->curl, CURLOPT_URL, uri.c_str());
    curl_easy_setopt(impl_->curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(impl_->curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(impl_->curl, CURLOPT_WRITEFUNCTION, &Impl::curlRecvFn);
    curl_easy_setopt(impl_->curl, CURLOPT_WRITEDATA, impl_.get());

    impl_->status = curl_easy_perform(impl_->curl);
    if (impl_->status != CURLE_OK) {
        impl_->statusText = std::string(curl_easy_strerror(impl_->status));
        throw zserio::CppRuntimeException(impl_->statusText);
    }

    return impl_->result;
}

UrlClient::Status UrlClient::status() {
    switch (impl_->status) {
    case CURLE_OK:
        return Healthy;
    default:
        return Error;
    }
}

std::string UrlClient::statusDescription() {
    return impl_->statusText;
}

}
