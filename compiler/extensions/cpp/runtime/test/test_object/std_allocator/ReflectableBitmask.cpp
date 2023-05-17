/**
 * Automatically generated by Zserio C++ extension version 2.9.0-pre1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#include <zserio/HashCodeUtil.h>
#include <zserio/StringConvertUtil.h>
#include <zserio/TypeInfo.h>
#include <zserio/AnyHolder.h>
#include <zserio/Reflectable.h>

#include <test_object/std_allocator/ReflectableBitmask.h>

namespace test_object
{
namespace std_allocator
{

ReflectableBitmask::ReflectableBitmask(::zserio::BitStreamReader& in) :
        m_value(readValue(in))
{}

ReflectableBitmask::ReflectableBitmask(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in) :
        m_value(readValue(contextNode, in))
{}

const ::zserio::ITypeInfo& ReflectableBitmask::typeInfo()
{
    using allocator_type = ::std::allocator<uint8_t>;

    static const ::zserio::Span<::zserio::StringView> underlyingTypeArguments;

    static const ::std::array<::zserio::ItemInfo, 3> values = {
        ::zserio::ItemInfo{ ::zserio::makeStringView("CREATE"), static_cast<uint64_t>(UINT8_C(1)) },
        ::zserio::ItemInfo{ ::zserio::makeStringView("READ"), static_cast<uint64_t>(UINT8_C(2)) },
        ::zserio::ItemInfo{ ::zserio::makeStringView("WRITE"), static_cast<uint64_t>(UINT8_C(4)) }
    };

    static const ::zserio::BitmaskTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.std_allocator.ReflectableBitmask"),
        ::zserio::BuiltinTypeInfo<allocator_type>::getUInt8(), underlyingTypeArguments, values
    };

    return typeInfo;
}

::zserio::IReflectablePtr ReflectableBitmask::reflectable(const ::std::allocator<uint8_t>& allocator) const
{
    class Reflectable : public ::zserio::ReflectableBase<::std::allocator<uint8_t>>
    {
    public:
        explicit Reflectable(::test_object::std_allocator::ReflectableBitmask bitmask) :
                ::zserio::ReflectableBase<::std::allocator<uint8_t>>(::test_object::std_allocator::ReflectableBitmask::typeInfo()),
                m_bitmask(bitmask)
        {}

        size_t bitSizeOf(size_t bitPosition) const override
        {
            return m_bitmask.bitSizeOf(bitPosition);
        }

        void write(::zserio::BitStreamWriter& writer) const override
        {
            m_bitmask.write(writer);
        }

        ::zserio::AnyHolder<> getAnyValue(const ::std::allocator<uint8_t>& allocator) const override
        {
            return ::zserio::AnyHolder<>(m_bitmask, allocator);
        }

        ::zserio::AnyHolder<> getAnyValue(const ::std::allocator<uint8_t>& allocator) override
        {
            return ::zserio::AnyHolder<>(m_bitmask, allocator);
        }

        uint8_t getUInt8() const override
        {
            return m_bitmask.getValue();
        }

        uint64_t toUInt() const override
        {
            return m_bitmask.getValue();
        }

        double toDouble() const override
        {
            return static_cast<double>(toUInt());
        }

        ::zserio::string<> toString(
                const ::std::allocator<uint8_t>& allocator = ::std::allocator<uint8_t>()) const override
        {
            return m_bitmask.toString(allocator);
        }

    private:
        ::test_object::std_allocator::ReflectableBitmask m_bitmask;
    };

    return ::std::allocate_shared<Reflectable>(allocator, *this);
}

void ReflectableBitmask::createPackingContext(::zserio::PackingContextNode& contextNode)
{
    contextNode.createContext();
}

void ReflectableBitmask::initPackingContext(::zserio::PackingContextNode& contextNode) const
{
    contextNode.getContext().init<::zserio::StdIntArrayTraits<::test_object::std_allocator::ReflectableBitmask::underlying_type>>(
            m_value);
}

size_t ReflectableBitmask::bitSizeOf(size_t) const
{
    return UINT8_C(8);
}

size_t ReflectableBitmask::bitSizeOf(::zserio::PackingContextNode& contextNode, size_t) const
{
    return contextNode.getContext().bitSizeOf<::zserio::StdIntArrayTraits<::test_object::std_allocator::ReflectableBitmask::underlying_type>>(
            m_value);
}

size_t ReflectableBitmask::initializeOffsets(size_t bitPosition) const
{
    return bitPosition + bitSizeOf(bitPosition);
}

size_t ReflectableBitmask::initializeOffsets(::zserio::PackingContextNode& contextNode, size_t bitPosition) const
{
    return bitPosition + bitSizeOf(contextNode, bitPosition);
}

uint32_t ReflectableBitmask::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;
    result = ::zserio::calcHashCode(result, m_value);
    return result;
}

void ReflectableBitmask::write(::zserio::BitStreamWriter& out) const
{
    out.writeBits(m_value, UINT8_C(8));
}

void ReflectableBitmask::write(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const
{
    contextNode.getContext().write<::zserio::StdIntArrayTraits<::test_object::std_allocator::ReflectableBitmask::underlying_type>>(
            out, m_value);
}

::zserio::string<> ReflectableBitmask::toString(const ::zserio::string<>::allocator_type& allocator) const
{
    ::zserio::string<> result(allocator);
    if ((*this & ReflectableBitmask::Values::CREATE) == ReflectableBitmask::Values::CREATE)
        result += result.empty() ? "CREATE" : " | CREATE";
    if ((*this & ReflectableBitmask::Values::READ) == ReflectableBitmask::Values::READ)
        result += result.empty() ? "READ" : " | READ";
    if ((*this & ReflectableBitmask::Values::WRITE) == ReflectableBitmask::Values::WRITE)
        result += result.empty() ? "WRITE" : " | WRITE";

    return ::zserio::toString<::zserio::string<>::allocator_type>(m_value, allocator) + "[" + result + "]";
}

ReflectableBitmask::underlying_type ReflectableBitmask::readValue(::zserio::BitStreamReader& in)
{
    return static_cast<underlying_type>(in.readBits(UINT8_C(8)));
}

ReflectableBitmask::underlying_type ReflectableBitmask::readValue(::zserio::PackingContextNode& contextNode,
        ::zserio::BitStreamReader& in)
{
    return contextNode.getContext().read<::zserio::StdIntArrayTraits<::test_object::std_allocator::ReflectableBitmask::underlying_type>>(
            in);
}

} // namespace std_allocator
} // namespace test_object
