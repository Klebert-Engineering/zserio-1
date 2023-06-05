/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorhpicAllocator.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/TypeInfo.h>
#include <zserio/pmr/AnyHolder.h>
#include <zserio/pmr/Reflectable.h>

#include <test_object/polymorphic_allocator/CreatorUnsignedEnum.h>

namespace zserio
{

// This is full specialization of enumeration traits and methods for CreatorUnsignedEnum enumeration.
constexpr ::std::array<const char*, 2> EnumTraits<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::names;
constexpr ::std::array<::test_object::polymorphic_allocator::CreatorUnsignedEnum, 2> EnumTraits<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::values;
constexpr const char* EnumTraits<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::enumName;

template <>
const ::zserio::pmr::ITypeInfo& enumTypeInfo<::test_object::polymorphic_allocator::CreatorUnsignedEnum, ::zserio::pmr::PropagatingPolymorphicAllocator<>>()
{
    using allocator_type = ::zserio::pmr::PropagatingPolymorphicAllocator<>;

    static const ::zserio::Span<::zserio::StringView> underlyingTypeArguments;

    static const ::std::array<::zserio::ItemInfo, 2> items = {
        ::zserio::ItemInfo{ ::zserio::makeStringView("ONE"), static_cast<uint64_t>(UINT8_C(0)) },
        ::zserio::ItemInfo{ ::zserio::makeStringView("TWO"), static_cast<uint64_t>(UINT8_C(1)) }
    };

    static const ::zserio::EnumTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.polymorphic_allocator.CreatorUnsignedEnum"),
        ::zserio::BuiltinTypeInfo<allocator_type>::getUInt8(), underlyingTypeArguments, items
    };

    return typeInfo;
}

template <>
::zserio::pmr::IReflectablePtr enumReflectable(::test_object::polymorphic_allocator::CreatorUnsignedEnum value, const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator)
{
    class Reflectable : public ::zserio::ReflectableBase<::zserio::pmr::PropagatingPolymorphicAllocator<>>
    {
    public:
        explicit Reflectable(::test_object::polymorphic_allocator::CreatorUnsignedEnum value) :
                ::zserio::ReflectableBase<::zserio::pmr::PropagatingPolymorphicAllocator<>>(
                        ::zserio::enumTypeInfo<::test_object::polymorphic_allocator::CreatorUnsignedEnum, ::zserio::pmr::PropagatingPolymorphicAllocator<>>()),
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

        ::zserio::pmr::AnyHolder getAnyValue(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator) const override
        {
            return ::zserio::pmr::AnyHolder(m_value, allocator);
        }

        ::zserio::pmr::AnyHolder getAnyValue(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator) override
        {
            return ::zserio::pmr::AnyHolder(m_value, allocator);
        }

        uint8_t getUInt8() const override
        {
            return static_cast<typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::type>(m_value);
        }

        uint64_t toUInt() const override
        {
            return static_cast<typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::type>(m_value);
        }

        double toDouble() const override
        {
            return static_cast<double>(toUInt());
        }

        ::zserio::pmr::string toString(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator) const override
        {
            return ::zserio::pmr::string(::zserio::enumToString(m_value), allocator);
        }

    private:
        ::test_object::polymorphic_allocator::CreatorUnsignedEnum m_value;
    };

    return std::allocate_shared<Reflectable>(allocator, value);
}

template <>
size_t enumToOrdinal(::test_object::polymorphic_allocator::CreatorUnsignedEnum value)
{
    switch (value)
    {
    case ::test_object::polymorphic_allocator::CreatorUnsignedEnum::ONE:
        return 0;
    case ::test_object::polymorphic_allocator::CreatorUnsignedEnum::TWO:
        return 1;
    default:
        throw ::zserio::CppRuntimeException("Unknown value for enumeration CreatorUnsignedEnum: ") <<
                static_cast<typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::type>(value) << "!";
    }
}

template <>
::test_object::polymorphic_allocator::CreatorUnsignedEnum valueToEnum(
        typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::type rawValue)
{
    switch (rawValue)
    {
    case UINT8_C(0):
    case UINT8_C(1):
        return static_cast<::test_object::polymorphic_allocator::CreatorUnsignedEnum>(rawValue);
    default:
        throw ::zserio::CppRuntimeException("Unknown value for enumeration CreatorUnsignedEnum: ") << rawValue << "!";
    }
}

template <>
uint32_t enumHashCode<::test_object::polymorphic_allocator::CreatorUnsignedEnum>(::test_object::polymorphic_allocator::CreatorUnsignedEnum value)
{
    uint32_t result = ::zserio::HASH_SEED;
    result = ::zserio::calcHashCode(result, enumToValue(value));
    return result;
}

template <>
void initPackingContext(::zserio::pmr::PackingContextNode& contextNode, ::test_object::polymorphic_allocator::CreatorUnsignedEnum value)
{
    contextNode.getContext().init<::zserio::StdIntArrayTraits<typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::type>>(
            ::zserio::enumToValue(value));
}

template <>
size_t bitSizeOf(::test_object::polymorphic_allocator::CreatorUnsignedEnum)
{
    return UINT8_C(8);
}

template <>
size_t bitSizeOf(::zserio::pmr::PackingContextNode& contextNode, ::test_object::polymorphic_allocator::CreatorUnsignedEnum value)
{
    return contextNode.getContext().bitSizeOf<::zserio::StdIntArrayTraits<typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::type>>(
            ::zserio::enumToValue(value));
}

template <>
size_t initializeOffsets(size_t bitPosition, ::test_object::polymorphic_allocator::CreatorUnsignedEnum value)
{
    return bitPosition + bitSizeOf(value);
}

template <>
size_t initializeOffsets(::zserio::pmr::PackingContextNode& contextNode,
        size_t bitPosition, ::test_object::polymorphic_allocator::CreatorUnsignedEnum value)
{
    return bitPosition + bitSizeOf(contextNode, value);
}

template <>
::test_object::polymorphic_allocator::CreatorUnsignedEnum read(::zserio::BitStreamReader& in)
{
    return valueToEnum<::test_object::polymorphic_allocator::CreatorUnsignedEnum>(
            static_cast<typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::type>(
                    in.readBits(UINT8_C(8))));
}

template <>
::test_object::polymorphic_allocator::CreatorUnsignedEnum read(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in)
{
    return valueToEnum<::test_object::polymorphic_allocator::CreatorUnsignedEnum>(contextNode.getContext().read<::zserio::StdIntArrayTraits<typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::type>>(
            in));
}

template <>
void write(::zserio::BitStreamWriter& out, ::test_object::polymorphic_allocator::CreatorUnsignedEnum value)
{
    out.writeBits(::zserio::enumToValue(value), UINT8_C(8));
}

template <>
void write(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out, ::test_object::polymorphic_allocator::CreatorUnsignedEnum value)
{
    contextNode.getContext().write<::zserio::StdIntArrayTraits<typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorUnsignedEnum>::type>>(
            out, ::zserio::enumToValue(value));
}

} // namespace zserio
