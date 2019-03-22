#include "UrlClient.h"

#include <curl/curl.h>

namespace zserio
{

struct UrlClient::Impl
{
    CURL *curl = nullptr;

    Impl() {
        curl = curl_easy_init();
    }

    Impl(Impl const& other) = default;

    ~Impl() {
        curl_easy_cleanup(curl);
    }
};

UrlClient::UrlClient() : impl_(new Impl) {}

std::pair<const uint8_t*, size_t> UrlClient::fetchResource(const std::string& uri) {
    curl_easy_setopt(impl_->curl, CURLOPT_URL, uri.c_str());

    return {nullptr, 0};
}

}