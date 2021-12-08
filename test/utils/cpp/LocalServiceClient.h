#ifndef UTILS_LOCAL_SERVICE_CLIENT_H_INC
#define UTILS_LOCAL_SERVICE_CLIENT_H_INC

#include "zserio/IService.h"
#include "zserio/AllocatorHolder.h"

namespace utils
{

template <typename ALLOC>
class LocalServiceClient : public zserio::IBasicServiceClient<ALLOC>, public zserio::AllocatorHolder<ALLOC>
{
protected:
    using zserio::AllocatorHolder<ALLOC>::get_allocator_ref;

public:
    explicit LocalServiceClient(zserio::IBasicService<ALLOC>& service, const ALLOC& allocator = ALLOC()) :
            zserio::AllocatorHolder<ALLOC>(allocator), m_service(service)
    {}

    virtual std::vector<uint8_t, ALLOC> callMethod(zserio::StringView methodName,
            const zserio::BasicRequestData<ALLOC>& requestData,
            void* context = nullptr) override
    {
        const auto& reflectable = requestData.getReflectable();
        if (reflectable)
        {
            ::zserio::BasicBitBuffer<ALLOC> bitBuffer(reflectable->bitSizeOf(), get_allocator_ref());
            zserio::BitStreamWriter writer(bitBuffer);
            reflectable->write(writer);
            auto requestBytes = zserio::Span<const uint8_t>{bitBuffer.getBuffer(), bitBuffer.getByteSize()};
            return callMethodOnService(methodName, requestBytes, context);
        }
        else
        {
            return callMethodOnService(methodName, requestData.getData(), context);
        }
    }

private:
    virtual std::vector<uint8_t, ALLOC> callMethodOnService(zserio::StringView methodName,
            zserio::Span<const uint8_t> requestBytes, void* context)
    {
        auto responseData = m_service.callMethod(methodName, requestBytes, context);
        const auto& reflectable = responseData->getReflectable();
        if (reflectable)
        {
            std::vector<uint8_t, ALLOC> responseBytes(
                    (reflectable->bitSizeOf() + 7) / 8, 0, get_allocator_ref());
            zserio::BitStreamWriter writer(responseBytes);
            reflectable->write(writer);
            return responseBytes;
        }
        else
        {
            zserio::Span<const uint8_t> responseBytes = responseData->getData();
            return std::vector<uint8_t, ALLOC>{responseBytes.begin(), responseBytes.end(), get_allocator_ref()};
        }
    }

    zserio::IBasicService<ALLOC>& m_service;
};

} // namespace utils

#endif // UTILS_LOCAL_SERVICE_CLIENT_H_INC
