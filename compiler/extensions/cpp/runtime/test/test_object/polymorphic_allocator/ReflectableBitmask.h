/**
 * Automatically generated by Zserio C++ generator version 1.0.2 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorphicAllocator.
 */

#ifndef TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_BITMASK_H
#define TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_BITMASK_H

#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/pmr/ITypeInfo.h>
#include <zserio/pmr/IReflectable.h>
#include <zserio/pmr/ArrayTraits.h>
#include <zserio/pmr/String.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

namespace test_object
{
namespace polymorphic_allocator
{

class ReflectableBitmask
{
public:
    using underlying_type = uint8_t;

    enum class Values : underlying_type
    {
        CREATE = UINT8_C(1),
        READ = UINT8_C(2),
        WRITE = UINT8_C(4)
    };

    constexpr ReflectableBitmask() noexcept :
            m_value(0)
    {}

    explicit ReflectableBitmask(::zserio::BitStreamReader& in);
    constexpr ReflectableBitmask(Values value) noexcept :
            m_value(static_cast<underlying_type>(value))
    {}

    constexpr explicit ReflectableBitmask(underlying_type value) noexcept :
            m_value(value)
    {}

    ~ReflectableBitmask() = default;

    ReflectableBitmask(const ReflectableBitmask&) = default;
    ReflectableBitmask& operator=(const ReflectableBitmask&) = default;

    ReflectableBitmask(ReflectableBitmask&&) = default;
    ReflectableBitmask& operator=(ReflectableBitmask&&) = default;

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

    size_t bitSizeOf(size_t bitPosition = 0) const;

    size_t initializeOffsets(size_t bitPosition = 0) const;

    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;

    ::zserio::pmr::string toString(const ::zserio::pmr::string::allocator_type& allocator =
            ::zserio::pmr::string::allocator_type()) const;

private:
    static underlying_type readValue(::zserio::BitStreamReader& in);

    underlying_type m_value;
};

inline bool operator==(const ReflectableBitmask& lhs, const ReflectableBitmask& rhs)
{
    return lhs.getValue() == rhs.getValue();
}

inline bool operator!=(const ReflectableBitmask& lhs, const ReflectableBitmask& rhs)
{
    return lhs.getValue() != rhs.getValue();
}

inline bool operator<(const ReflectableBitmask& lhs, const ReflectableBitmask& rhs)
{
    return lhs.getValue() < rhs.getValue();
}

inline ReflectableBitmask operator|(ReflectableBitmask::Values lhs, ReflectableBitmask::Values rhs)
{
    return ReflectableBitmask(static_cast<ReflectableBitmask::underlying_type>(lhs) | static_cast<ReflectableBitmask::underlying_type>(rhs));
}

inline ReflectableBitmask operator|(const ReflectableBitmask& lhs, const ReflectableBitmask& rhs)
{
    return ReflectableBitmask(lhs.getValue() | rhs.getValue());
}

inline ReflectableBitmask operator&(ReflectableBitmask::Values lhs, ReflectableBitmask::Values rhs)
{
    return ReflectableBitmask(static_cast<ReflectableBitmask::underlying_type>(lhs) & static_cast<ReflectableBitmask::underlying_type>(rhs));
}

inline ReflectableBitmask operator&(const ReflectableBitmask& lhs, const ReflectableBitmask& rhs)
{
    return ReflectableBitmask(lhs.getValue() & rhs.getValue());
}

inline ReflectableBitmask operator^(ReflectableBitmask::Values lhs, ReflectableBitmask::Values rhs)
{
    return ReflectableBitmask(static_cast<ReflectableBitmask::underlying_type>(lhs) ^ static_cast<ReflectableBitmask::underlying_type>(rhs));
}

inline ReflectableBitmask operator^(const ReflectableBitmask& lhs, const ReflectableBitmask& rhs)
{
    return ReflectableBitmask(lhs.getValue() ^ rhs.getValue());
}

inline ReflectableBitmask operator~(ReflectableBitmask::Values lhs)
{
    return ReflectableBitmask(static_cast<ReflectableBitmask::underlying_type>(static_cast<ReflectableBitmask::underlying_type>(~static_cast<ReflectableBitmask::underlying_type>(lhs))));
}

inline ReflectableBitmask operator~(const ReflectableBitmask& lhs)
{
    return ReflectableBitmask(static_cast<ReflectableBitmask::underlying_type>(static_cast<ReflectableBitmask::underlying_type>(~lhs.getValue())));
}

inline ReflectableBitmask operator|=(ReflectableBitmask& lhs, const ReflectableBitmask& rhs)
{
    lhs = ReflectableBitmask(lhs.getValue() | rhs.getValue());
    return lhs;
}

inline ReflectableBitmask operator&=(ReflectableBitmask& lhs, const ReflectableBitmask& rhs)
{
    lhs = ReflectableBitmask(lhs.getValue() & rhs.getValue());
    return lhs;
}

inline ReflectableBitmask operator^=(ReflectableBitmask& lhs, const ReflectableBitmask& rhs)
{
    lhs = ReflectableBitmask(lhs.getValue() ^ rhs.getValue());
    return lhs;
}

} // namespace polymorphic_allocator
} // namespace test_object

#endif // TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_BITMASK_H
