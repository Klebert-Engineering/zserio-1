/**
 * Automatically generated by Zserio C++ extension version 2.9.0-pre1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorhpicAllocator.
 */

#ifndef TEST_OBJECT_POLYMORPHIC_ALLOCATOR_WALKER_BITMASK_H
#define TEST_OBJECT_POLYMORPHIC_ALLOCATOR_WALKER_BITMASK_H

#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/pmr/ITypeInfo.h>
#include <zserio/pmr/IReflectable.h>
#include <zserio/pmr/ArrayTraits.h>
#include <zserio/pmr/String.h>
#include <zserio/pmr/PackingContext.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

namespace test_object
{
namespace polymorphic_allocator
{

class WalkerBitmask
{
public:
    using underlying_type = uint32_t;

    enum class Values : underlying_type
    {
        ZERO = UINT32_C(1)
    };

    constexpr WalkerBitmask() noexcept :
            m_value(0)
    {}

    explicit WalkerBitmask(::zserio::BitStreamReader& in);
    WalkerBitmask(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in);
    constexpr WalkerBitmask(Values value) noexcept :
            m_value(static_cast<underlying_type>(value))
    {}

    constexpr explicit WalkerBitmask(underlying_type value) noexcept :
            m_value(value)
    {}

    ~WalkerBitmask() = default;

    WalkerBitmask(const WalkerBitmask&) = default;
    WalkerBitmask& operator=(const WalkerBitmask&) = default;

    WalkerBitmask(WalkerBitmask&&) = default;
    WalkerBitmask& operator=(WalkerBitmask&&) = default;

    static const ::zserio::pmr::ITypeInfo& typeInfo();
    ::zserio::pmr::IReflectablePtr reflectable(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator = ::zserio::pmr::PropagatingPolymorphicAllocator<>()) const;

    constexpr explicit operator underlying_type() const
    {
        return m_value;
    }

    constexpr underlying_type getValue() const
    {
        return m_value;
    }

    static void createPackingContext(::zserio::pmr::PackingContextNode& contextNode);
    void initPackingContext(::zserio::pmr::PackingContextNode& contextNode) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0) const;
    size_t initializeOffsets(::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition) const;

    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const;

    ::zserio::pmr::string toString(const ::zserio::pmr::string::allocator_type& allocator =
            ::zserio::pmr::string::allocator_type()) const;

private:
    static underlying_type readValue(::zserio::BitStreamReader& in);
    static underlying_type readValue(::zserio::pmr::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in);

    underlying_type m_value;
};

inline bool operator==(const WalkerBitmask& lhs, const WalkerBitmask& rhs)
{
    return lhs.getValue() == rhs.getValue();
}

inline bool operator!=(const WalkerBitmask& lhs, const WalkerBitmask& rhs)
{
    return lhs.getValue() != rhs.getValue();
}

inline WalkerBitmask operator|(WalkerBitmask::Values lhs, WalkerBitmask::Values rhs)
{
    return WalkerBitmask(static_cast<WalkerBitmask::underlying_type>(lhs) | static_cast<WalkerBitmask::underlying_type>(rhs));
}

inline WalkerBitmask operator|(const WalkerBitmask& lhs, const WalkerBitmask& rhs)
{
    return WalkerBitmask(lhs.getValue() | rhs.getValue());
}

inline WalkerBitmask operator&(WalkerBitmask::Values lhs, WalkerBitmask::Values rhs)
{
    return WalkerBitmask(static_cast<WalkerBitmask::underlying_type>(lhs) & static_cast<WalkerBitmask::underlying_type>(rhs));
}

inline WalkerBitmask operator&(const WalkerBitmask& lhs, const WalkerBitmask& rhs)
{
    return WalkerBitmask(lhs.getValue() & rhs.getValue());
}

inline WalkerBitmask operator^(WalkerBitmask::Values lhs, WalkerBitmask::Values rhs)
{
    return WalkerBitmask(static_cast<WalkerBitmask::underlying_type>(lhs) ^ static_cast<WalkerBitmask::underlying_type>(rhs));
}

inline WalkerBitmask operator^(const WalkerBitmask& lhs, const WalkerBitmask& rhs)
{
    return WalkerBitmask(lhs.getValue() ^ rhs.getValue());
}

inline WalkerBitmask operator~(WalkerBitmask::Values lhs)
{
    return WalkerBitmask(~static_cast<WalkerBitmask::underlying_type>(lhs));
}

inline WalkerBitmask operator~(const WalkerBitmask& lhs)
{
    return WalkerBitmask(~lhs.getValue());
}

inline WalkerBitmask operator|=(WalkerBitmask& lhs, const WalkerBitmask& rhs)
{
    lhs = WalkerBitmask(lhs.getValue() | rhs.getValue());
    return lhs;
}

inline WalkerBitmask operator&=(WalkerBitmask& lhs, const WalkerBitmask& rhs)
{
    lhs = WalkerBitmask(lhs.getValue() & rhs.getValue());
    return lhs;
}

inline WalkerBitmask operator^=(WalkerBitmask& lhs, const WalkerBitmask& rhs)
{
    lhs = WalkerBitmask(lhs.getValue() ^ rhs.getValue());
    return lhs;
}

} // namespace polymorphic_allocator
} // namespace test_object

#endif // TEST_OBJECT_POLYMORPHIC_ALLOCATOR_WALKER_BITMASK_H
