/**
 * Automatically generated by Zserio C++ generator version 1.0.2 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, bitPosition, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_CREATOR_BITMASK_H
#define TEST_OBJECT_STD_ALLOCATOR_CREATOR_BITMASK_H

#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <zserio/ArrayTraits.h>
#include <zserio/String.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

namespace test_object
{
namespace std_allocator
{

class CreatorBitmask
{
public:
    using underlying_type = uint8_t;

    enum class Values : underlying_type
    {
        READ = UINT8_C(1),
        WRITE = UINT8_C(2)
    };

    constexpr CreatorBitmask() noexcept :
            m_value(0)
    {}

    explicit CreatorBitmask(::zserio::BitStreamReader& in);
    constexpr CreatorBitmask(Values value) noexcept :
            m_value(static_cast<underlying_type>(value))
    {}

    constexpr explicit CreatorBitmask(underlying_type value) noexcept :
            m_value(value)
    {}

    ~CreatorBitmask() = default;

    CreatorBitmask(const CreatorBitmask&) = default;
    CreatorBitmask& operator=(const CreatorBitmask&) = default;

    CreatorBitmask(CreatorBitmask&&) = default;
    CreatorBitmask& operator=(CreatorBitmask&&) = default;

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectablePtr reflectable(const ::std::allocator<uint8_t>& allocator = ::std::allocator<uint8_t>()) const;

    constexpr explicit operator underlying_type() const
    {
        return m_value;
    }

    constexpr underlying_type getValue() const
    {
        return m_value;
    }

    size_t bitSizeOf(size_t bitPosition = 0) const;

    size_t initializeOffsets(size_t bitPosition = 0) const;

    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;

    ::zserio::string<> toString(const ::zserio::string<>::allocator_type& allocator =
            ::zserio::string<>::allocator_type()) const;

private:
    static underlying_type readValue(::zserio::BitStreamReader& in);

    underlying_type m_value;
};

inline bool operator==(const CreatorBitmask& lhs, const CreatorBitmask& rhs)
{
    return lhs.getValue() == rhs.getValue();
}

inline bool operator!=(const CreatorBitmask& lhs, const CreatorBitmask& rhs)
{
    return lhs.getValue() != rhs.getValue();
}

inline bool operator<(const CreatorBitmask& lhs, const CreatorBitmask& rhs)
{
    return lhs.getValue() < rhs.getValue();
}

inline CreatorBitmask operator|(CreatorBitmask::Values lhs, CreatorBitmask::Values rhs)
{
    return CreatorBitmask(static_cast<CreatorBitmask::underlying_type>(lhs) | static_cast<CreatorBitmask::underlying_type>(rhs));
}

inline CreatorBitmask operator|(const CreatorBitmask& lhs, const CreatorBitmask& rhs)
{
    return CreatorBitmask(lhs.getValue() | rhs.getValue());
}

inline CreatorBitmask operator&(CreatorBitmask::Values lhs, CreatorBitmask::Values rhs)
{
    return CreatorBitmask(static_cast<CreatorBitmask::underlying_type>(lhs) & static_cast<CreatorBitmask::underlying_type>(rhs));
}

inline CreatorBitmask operator&(const CreatorBitmask& lhs, const CreatorBitmask& rhs)
{
    return CreatorBitmask(lhs.getValue() & rhs.getValue());
}

inline CreatorBitmask operator^(CreatorBitmask::Values lhs, CreatorBitmask::Values rhs)
{
    return CreatorBitmask(static_cast<CreatorBitmask::underlying_type>(lhs) ^ static_cast<CreatorBitmask::underlying_type>(rhs));
}

inline CreatorBitmask operator^(const CreatorBitmask& lhs, const CreatorBitmask& rhs)
{
    return CreatorBitmask(lhs.getValue() ^ rhs.getValue());
}

inline CreatorBitmask operator~(CreatorBitmask::Values lhs)
{
    return CreatorBitmask(static_cast<CreatorBitmask::underlying_type>(static_cast<CreatorBitmask::underlying_type>(~static_cast<CreatorBitmask::underlying_type>(lhs))));
}

inline CreatorBitmask operator~(const CreatorBitmask& lhs)
{
    return CreatorBitmask(static_cast<CreatorBitmask::underlying_type>(static_cast<CreatorBitmask::underlying_type>(~lhs.getValue())));
}

inline CreatorBitmask operator|=(CreatorBitmask& lhs, const CreatorBitmask& rhs)
{
    lhs = CreatorBitmask(lhs.getValue() | rhs.getValue());
    return lhs;
}

inline CreatorBitmask operator&=(CreatorBitmask& lhs, const CreatorBitmask& rhs)
{
    lhs = CreatorBitmask(lhs.getValue() & rhs.getValue());
    return lhs;
}

inline CreatorBitmask operator^=(CreatorBitmask& lhs, const CreatorBitmask& rhs)
{
    lhs = CreatorBitmask(lhs.getValue() ^ rhs.getValue());
    return lhs;
}

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_CREATOR_BITMASK_H
