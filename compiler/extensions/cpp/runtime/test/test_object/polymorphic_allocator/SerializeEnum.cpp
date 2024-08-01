/**
 * Automatically generated by Zserio C++ generator version 1.0.2 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, bitPosition, polymorphicAllocator.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/TypeInfo.h>
#include <zserio/pmr/AnyHolder.h>
#include <zserio/pmr/Reflectable.h>

#include <test_object/polymorphic_allocator/SerializeEnum.h>

namespace zserio
{

// This is full specialization of enumeration traits and methods for SerializeEnum enumeration.
constexpr ::std::array<const char*, 3> EnumTraits<::test_object::polymorphic_allocator::SerializeEnum>::names;
constexpr ::std::array<::test_object::polymorphic_allocator::SerializeEnum, 3> EnumTraits<::test_object::polymorphic_allocator::SerializeEnum>::values;
constexpr const char* EnumTraits<::test_object::polymorphic_allocator::SerializeEnum>::enumName;

template <>
const ::zserio::pmr::ITypeInfo& enumTypeInfo<::test_object::polymorphic_allocator::SerializeEnum, ::zserio::pmr::PropagatingPolymorphicAllocator<>>()
{
    using allocator_type = ::zserio::pmr::PropagatingPolymorphicAllocator<>;

    static const ::zserio::Span<::zserio::StringView> underlyingTypeArguments;

    static const ::std::array<::zserio::ItemInfo, 3> items = {
        ::zserio::ItemInfo{ ::zserio::makeStringView("VALUE1"), static_cast<uint64_t>(UINT8_C(0)), false, false},
        ::zserio::ItemInfo{ ::zserio::makeStringView("VALUE2"), static_cast<uint64_t>(UINT8_C(1)), false, false},
        ::zserio::ItemInfo{ ::zserio::makeStringView("VALUE3"), static_cast<uint64_t>(UINT8_C(2)), false, false}
    };

    static const ::zserio::EnumTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.polymorphic_allocator.SerializeEnum"),
        ::zserio::BuiltinTypeInfo<allocator_type>::getUInt8(), underlyingTypeArguments, items
    };

    return typeInfo;
}

template <>
::zserio::pmr::IReflectablePtr enumReflectable(::test_object::polymorphic_allocator::SerializeEnum value, const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator)
{
    class Reflectable : public ::zserio::ReflectableBase<::zserio::pmr::PropagatingPolymorphicAllocator<>>
    {
    public:
        explicit Reflectable(::test_object::polymorphic_allocator::SerializeEnum value) :
                ::zserio::ReflectableBase<::zserio::pmr::PropagatingPolymorphicAllocator<>>(
                        ::zserio::enumTypeInfo<::test_object::polymorphic_allocator::SerializeEnum, ::zserio::pmr::PropagatingPolymorphicAllocator<>>()),
                m_value(value)
        {}

        size_t bitSizeOf(size_t) const override
        {
            return ::zserio::bitSizeOf(m_value);
        }

        void write(::zserio::BitStreamWriter& writer) const override
        {
            ::zserio::write(writer, m_value);
        }

        ::zserio::pmr::AnyHolder getAnyValue(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& alloc) const override
        {
            return ::zserio::pmr::AnyHolder(m_value, alloc);
        }

        ::zserio::pmr::AnyHolder getAnyValue(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& alloc) override
        {
            return ::zserio::pmr::AnyHolder(m_value, alloc);
        }

        uint8_t getUInt8() const override
        {
            return static_cast<typename ::std::underlying_type<::test_object::polymorphic_allocator::SerializeEnum>::type>(m_value);
        }

        uint64_t toUInt() const override
        {
            return static_cast<typename ::std::underlying_type<::test_object::polymorphic_allocator::SerializeEnum>::type>(m_value);
        }

        double toDouble() const override
        {
            return static_cast<double>(toUInt());
        }

        ::zserio::pmr::string toString(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& alloc) const override
        {
            return ::zserio::pmr::string(::zserio::enumToString(m_value), alloc);
        }

    private:
        ::test_object::polymorphic_allocator::SerializeEnum m_value;
    };

    return std::allocate_shared<Reflectable>(allocator, value);
}

template <>
size_t enumToOrdinal(::test_object::polymorphic_allocator::SerializeEnum value)
{
    switch (value)
    {
    case ::test_object::polymorphic_allocator::SerializeEnum::VALUE1:
        return 0;
    case ::test_object::polymorphic_allocator::SerializeEnum::VALUE2:
        return 1;
    case ::test_object::polymorphic_allocator::SerializeEnum::VALUE3:
        return 2;
    default:
        throw ::zserio::CppRuntimeException("Unknown value for enumeration SerializeEnum: ") <<
                static_cast<typename ::std::underlying_type<::test_object::polymorphic_allocator::SerializeEnum>::type>(value) << "!";
    }
}

template <>
::test_object::polymorphic_allocator::SerializeEnum valueToEnum(
        typename ::std::underlying_type<::test_object::polymorphic_allocator::SerializeEnum>::type rawValue)
{
    switch (rawValue)
    {
    case UINT8_C(0):
    case UINT8_C(1):
    case UINT8_C(2):
        return static_cast<::test_object::polymorphic_allocator::SerializeEnum>(rawValue);
    default:
        throw ::zserio::CppRuntimeException("Unknown value for enumeration SerializeEnum: ") << rawValue << "!";
    }
}

template <>
uint32_t enumHashCode<::test_object::polymorphic_allocator::SerializeEnum>(::test_object::polymorphic_allocator::SerializeEnum value)
{
    uint32_t result = ::zserio::HASH_SEED;
    result = ::zserio::calcHashCode(result, enumToValue(value));
    return result;
}

template <>
size_t bitSizeOf(::test_object::polymorphic_allocator::SerializeEnum)
{
    return UINT8_C(8);
}

template <>
size_t initializeOffsets(size_t bitPosition, ::test_object::polymorphic_allocator::SerializeEnum value)
{
    return bitPosition + bitSizeOf(value);
}

template <>
::test_object::polymorphic_allocator::SerializeEnum read(::zserio::BitStreamReader& in)
{
    return valueToEnum<::test_object::polymorphic_allocator::SerializeEnum>(
            static_cast<typename ::std::underlying_type<::test_object::polymorphic_allocator::SerializeEnum>::type>(
                    in.readBits(UINT8_C(8))));
}

template <>
void write(::zserio::BitStreamWriter& out, ::test_object::polymorphic_allocator::SerializeEnum value)
{
    out.writeBits(::zserio::enumToValue(value), UINT8_C(8));
}

} // namespace zserio
