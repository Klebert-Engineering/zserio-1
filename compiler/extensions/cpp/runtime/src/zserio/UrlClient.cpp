#include "UrlClient.h"

#include <curl/curl.h>
#include <iostream>

namespace zserio
{

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

    curl_easy_setopt(impl_->curl, CURLOPT_URL, uri.c_str());
    curl_easy_setopt(impl_->curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(impl_->curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(impl_->curl, CURLOPT_WRITEFUNCTION, &Impl::curlRecvFn);
    curl_easy_setopt(impl_->curl, CURLOPT_WRITEDATA, impl_.get());

    impl_->status = curl_easy_perform(impl_->curl);
    if (impl_->status != CURLE_OK) {
        impl_->statusText = std::string(curl_easy_strerror(impl_->status));
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