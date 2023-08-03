/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/TypeInfo.h>
#include <zserio/AnyHolder.h>
#include <zserio/Reflectable.h>

#include <test_object/std_allocator/SerializeEnum.h>

namespace zserio
{

// This is full specialization of enumeration traits and methods for SerializeEnum enumeration.
constexpr ::std::array<const char*, 3> EnumTraits<::test_object::std_allocator::SerializeEnum>::names;
constexpr ::std::array<::test_object::std_allocator::SerializeEnum, 3> EnumTraits<::test_object::std_allocator::SerializeEnum>::values;
constexpr const char* EnumTraits<::test_object::std_allocator::SerializeEnum>::enumName;

template <>
const ::zserio::ITypeInfo& enumTypeInfo<::test_object::std_allocator::SerializeEnum, ::std::allocator<uint8_t>>()
{
    using allocator_type = ::std::allocator<uint8_t>;

    static const ::zserio::Span<::zserio::StringView> underlyingTypeArguments;

    static const ::std::array<::zserio::ItemInfo, 3> items = {
        ::zserio::ItemInfo{ ::zserio::makeStringView("VALUE1"), static_cast<uint64_t>(UINT8_C(0)) },
        ::zserio::ItemInfo{ ::zserio::makeStringView("VALUE2"), static_cast<uint64_t>(UINT8_C(1)) },
        ::zserio::ItemInfo{ ::zserio::makeStringView("VALUE3"), static_cast<uint64_t>(UINT8_C(2)) }
    };

    static const ::zserio::EnumTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.std_allocator.SerializeEnum"),
        ::zserio::BuiltinTypeInfo<allocator_type>::getUInt8(), underlyingTypeArguments, items
    };

    return typeInfo;
}

template <>
::zserio::IReflectablePtr enumReflectable(::test_object::std_allocator::SerializeEnum value, const ::std::allocator<uint8_t>& allocator)
{
    class Reflectable : public ::zserio::ReflectableBase<::std::allocator<uint8_t>>
    {
    public:
        explicit Reflectable(::test_object::std_allocator::SerializeEnum value) :
                ::zserio::ReflectableBase<::std::allocator<uint8_t>>(
                        ::zserio::enumTypeInfo<::test_object::std_allocator::SerializeEnum, ::std::allocator<uint8_t>>()),
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

        ::zserio::AnyHolder<> getAnyValue(const ::std::allocator<uint8_t>& allocator) const override
        {
            return ::zserio::AnyHolder<>(m_value, allocator);
        }

        ::zserio::AnyHolder<> getAnyValue(const ::std::allocator<uint8_t>& allocator) override
        {
            return ::zserio::AnyHolder<>(m_value, allocator);
        }

        uint8_t getUInt8() const override
        {
            return static_cast<typename ::std::underlying_type<::test_object::std_allocator::SerializeEnum>::type>(m_value);
        }

        uint64_t toUInt() const override
        {
            return static_cast<typename ::std::underlying_type<::test_object::std_allocator::SerializeEnum>::type>(m_value);
        }

        double toDouble() const override
        {
            return static_cast<double>(toUInt());
        }

        ::zserio::string<> toString(const ::std::allocator<uint8_t>& allocator) const override
        {
            return ::zserio::string<>(::zserio::enumToString(m_value), allocator);
        }

    private:
        ::test_object::std_allocator::SerializeEnum m_value;
    };

    return std::allocate_shared<Reflectable>(allocator, value);
}

template <>
size_t enumToOrdinal(::test_object::std_allocator::SerializeEnum value)
{
    switch (value)
    {
    case ::test_object::std_allocator::SerializeEnum::VALUE1:
        return 0;
    case ::test_object::std_allocator::SerializeEnum::VALUE2:
        return 1;
    case ::test_object::std_allocator::SerializeEnum::VALUE3:
        return 2;
    default:
        throw ::zserio::CppRuntimeException("Unknown value for enumeration SerializeEnum: ") <<
                static_cast<typename ::std::underlying_type<::test_object::std_allocator::SerializeEnum>::type>(value) << "!";
    }
}

template <>
::test_object::std_allocator::SerializeEnum valueToEnum(
        typename ::std::underlying_type<::test_object::std_allocator::SerializeEnum>::type rawValue)
{
    switch (rawValue)
    {
    case UINT8_C(0):
    case UINT8_C(1):
    case UINT8_C(2):
        return static_cast<::test_object::std_allocator::SerializeEnum>(rawValue);
    default:
        throw ::zserio::CppRuntimeException("Unknown value for enumeration SerializeEnum: ") << rawValue << "!";
    }
}

template <>
uint32_t enumHashCode<::test_object::std_allocator::SerializeEnum>(::test_object::std_allocator::SerializeEnum value)
{
    uint32_t result = ::zserio::HASH_SEED;
    result = ::zserio::calcHashCode(result, enumToValue(value));
    return result;
}

template <>
void initPackingContext(::zserio::DeltaContext& context, ::test_object::std_allocator::SerializeEnum value)
{
    context.init<::zserio::StdIntArrayTraits<typename ::std::underlying_type<::test_object::std_allocator::SerializeEnum>::type>>(
            ::zserio::enumToValue(value));
}

template <>
size_t bitSizeOf(::test_object::std_allocator::SerializeEnum)
{
    return UINT8_C(8);
}

template <>
size_t bitSizeOf(::zserio::DeltaContext& context, ::test_object::std_allocator::SerializeEnum value)
{
    return context.bitSizeOf<::zserio::StdIntArrayTraits<typename ::std::underlying_type<::test_object::std_allocator::SerializeEnum>::type>>(
            ::zserio::enumToValue(value));
}

template <>
size_t initializeOffsets(size_t bitPosition, ::test_object::std_allocator::SerializeEnum value)
{
    return bitPosition + bitSizeOf(value);
}

template <>
size_t initializeOffsets(::zserio::DeltaContext& context, size_t bitPosition, ::test_object::std_allocator::SerializeEnum value)
{
    return bitPosition + bitSizeOf(context, value);
}

template <>
::test_object::std_allocator::SerializeEnum read(::zserio::BitStreamReader& in)
{
    return valueToEnum<::test_object::std_allocator::SerializeEnum>(
            static_cast<typename ::std::underlying_type<::test_object::std_allocator::SerializeEnum>::type>(
                    in.readBits(UINT8_C(8))));
}

template <>
::test_object::std_allocator::SerializeEnum read(::zserio::DeltaContext& context, ::zserio::BitStreamReader& in)
{
    return valueToEnum<::test_object::std_allocator::SerializeEnum>(context.read<::zserio::StdIntArrayTraits<typename ::std::underlying_type<::test_object::std_allocator::SerializeEnum>::type>>(
            in));
}

template <>
void write(::zserio::BitStreamWriter& out, ::test_object::std_allocator::SerializeEnum value)
{
    out.writeBits(::zserio::enumToValue(value), UINT8_C(8));
}

template <>
void write(::zserio::DeltaContext& context, ::zserio::BitStreamWriter& out, ::test_object::std_allocator::SerializeEnum value)
{
    context.write<::zserio::StdIntArrayTraits<typename ::std::underlying_type<::test_object::std_allocator::SerializeEnum>::type>>(
            out, ::zserio::enumToValue(value));
}

} // namespace zserio
