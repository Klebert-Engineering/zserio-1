/**
 * Automatically generated by Zserio C++ generator version 1.0.0 using Zserio core 2.12.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_DEBUG_STRING_PARAM_OBJECT_H
#define TEST_OBJECT_STD_ALLOCATOR_DEBUG_STRING_PARAM_OBJECT_H

#include <zserio/Traits.h>
#include <zserio/NoInit.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <memory>
#include <zserio/ArrayTraits.h>
#include <zserio/String.h>
#include <zserio/Types.h>

namespace test_object
{
namespace std_allocator
{

class DebugStringParamObject
{
public:
    using allocator_type = ::std::allocator<uint8_t>;

    DebugStringParamObject() noexcept :
            DebugStringParamObject(allocator_type())
    {}

    explicit DebugStringParamObject(const allocator_type& allocator) noexcept;

    template <typename ZSERIO_T_text = ::zserio::string<>,
            ::zserio::is_field_constructor_enabled_t<ZSERIO_T_text, DebugStringParamObject, allocator_type> = 0>
    explicit DebugStringParamObject(
            ZSERIO_T_text&& text_,
            const allocator_type& allocator = allocator_type()) :
            DebugStringParamObject(allocator)
    {
        m_text_ = ::std::forward<ZSERIO_T_text>(text_);
    }

    explicit DebugStringParamObject(::zserio::BitStreamReader& in,
            int32_t param_, const allocator_type& allocator = allocator_type());

    ~DebugStringParamObject() = default;

    DebugStringParamObject(const DebugStringParamObject& other);
    DebugStringParamObject& operator=(const DebugStringParamObject& other);

    DebugStringParamObject(DebugStringParamObject&& other);
    DebugStringParamObject& operator=(DebugStringParamObject&& other);

    DebugStringParamObject(::zserio::NoInitT,
            const DebugStringParamObject& other);
    DebugStringParamObject& assign(::zserio::NoInitT, const DebugStringParamObject& other);

    DebugStringParamObject(::zserio::NoInitT, DebugStringParamObject&& other);
    DebugStringParamObject& assign(::zserio::NoInitT,
            DebugStringParamObject&& other);

    DebugStringParamObject(::zserio::PropagateAllocatorT,
            const DebugStringParamObject& other, const allocator_type& allocator);
    DebugStringParamObject(::zserio::PropagateAllocatorT, ::zserio::NoInitT,
            const DebugStringParamObject& other, const allocator_type& allocator);

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initialize(
            int32_t param_);
    bool isInitialized() const;

    int32_t getParam() const;

    const ::zserio::string<>& getText() const;
    ::zserio::string<>& getText();
    void setText(const ::zserio::string<>& text_);
    void setText(::zserio::string<>&& text_);

    size_t bitSizeOf(size_t bitPosition = 0) const;

    size_t initializeOffsets(size_t bitPosition = 0);

    bool operator==(const DebugStringParamObject& other) const;

    bool operator<(const DebugStringParamObject& other) const;

    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;

private:
    ::zserio::string<> readText(::zserio::BitStreamReader& in,
            const allocator_type& allocator);

    int32_t m_param_;
    bool m_isInitialized;
    ::zserio::string<> m_text_;
};

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_DEBUG_STRING_PARAM_OBJECT_H
