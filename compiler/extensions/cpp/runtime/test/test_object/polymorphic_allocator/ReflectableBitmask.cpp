/**
 * Automatically generated by Zserio C++ extension version 2.9.0-pre1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorhpicAllocator.
 */

#include <zserio/HashCodeUtil.h>
#include <zserio/StringConvertUtil.h>
#include <zserio/TypeInfo.h>
#include <zserio/pmr/AnyHolder.h>
#include <zserio/pmr/Reflectable.h>

#include <test_object/polymorphic_allocator/ReflectableBitmask.h>

namespace test_object
{
namespace polymorphic_allocator
{

ReflectableBitmask::ReflectableBitmask(::zserio::BitStreamReader& in) :
        m_value(readValue(in))
{}

ReflectableBitmask::ReflectableBitmask(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in) :
        m_value(readValue(contextNode, in))
{}

const ::zserio::pmr::ITypeInfo& ReflectableBitmask::typeInfo()
{
    using allocator_type = ::zserio::pmr::PropagatingPolymorphicAllocator<>;

    static const ::zserio::Span<::zserio::StringView> underlyingTypeArguments;

    static const ::std::array<::zserio::ItemInfo, 3> values = {
        ::zserio::ItemInfo{ ::zserio::makeStringView("CREATE"), static_cast<uint64_t>(UINT8_C(1)) },
        ::zserio::ItemInfo{ ::zserio::makeStringView("READ"), static_cast<uint64_t>(UINT8_C(2)) },
        ::zserio::ItemInfo{ ::zserio::makeStringView("WRITE"), static_cast<uint64_t>(UINT8_C(4)) }
    };

    static const ::zserio::BitmaskTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.polymorphic_allocator.ReflectableBitmask"),
        ::zserio::BuiltinTypeInfo<allocator_type>::getUInt8(), underlyingTypeArguments, values
    };

    return typeInfo;
}

::zserio::pmr::IReflectablePtr ReflectableBitmask::reflectable(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator) const
{
    class Reflectable : public ::zserio::ReflectableBase<::zserio::pmr::PropagatingPolymorphicAllocator<>>
    {
    public:
        explicit Reflectable(::test_object::polymorphic_allocator::ReflectableBitmask bitmask) :
                ::zserio::ReflectableBase<::zserio::pmr::PropagatingPolymorphicAllocator<>>(::test_object::polymorphic_allocator::ReflectableBitmask::typeInfo()),
                m_bitmask(bitmask)
        {}

        virtual size_t bitSizeOf(size_t bitPosition) const override
        {
            return m_bitmask.bitSizeOf(bitPosition);
        }

        virtual void write(::zserio::BitStreamWriter& writer) const override
        {
            m_bitmask.write(writer);
        }

        virtual ::zserio::pmr::AnyHolder getAnyValue(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator) const override
        {
            return ::zserio::pmr::AnyHolder(m_bitmask, allocator);
        }

        virtual ::zserio::pmr::AnyHolder getAnyValue(const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator) override
        {
            return ::zserio::pmr::AnyHolder(m_bitmask, allocator);
        }

        virtual uint8_t getUInt8() const override
        {
            return m_bitmask.getValue();
        }

        virtual uint64_t toUInt() const override
        {
            return m_bitmask.getValue();
        }

        virtual double toDouble() const override
        {
            return static_cast<double>(toUInt());
        }

        virtual ::zserio::pmr::string toString(
                const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator = ::zserio::pmr::PropagatingPolymorphicAllocator<>()) const override
        {
            return m_bitmask.toString(allocator);
        }

    private:
        ::test_object::polymorphic_allocator::ReflectableBitmask m_bitmask;
    };

    return ::std::allocate_shared<Reflectable>(allocator, *this);
}

void ReflectableBitmask::createPackingContext(::zserio::pmr::PackingContextNode& contextNode)
{
    contextNode.createContext();
}

void ReflectableBitmask::initPackingContext(::zserio::pmr::PackingContextNode& contextNode) const
{
    contextNode.getContext().init(::zserio::StdIntArrayTraits<::test_object::polymorphic_allocator::ReflectableBitmask::underlying_type>(),
            m_value);
}

size_t ReflectableBitmask::bitSizeOf(size_t) const
{
    return UINT8_C(8);
}

size_t ReflectableBitmask::bitSizeOf(::zserio::pmr::PackingContextNode& contextNode, size_t) const
{
    return contextNode.getContext().bitSizeOf(
            ::zserio::StdIntArrayTraits<::test_object::polymorphic_allocator::ReflectableBitmask::underlying_type>(),
            m_value);
}

size_t ReflectableBitmask::initializeOffsets(size_t bitPosition) const
{
    return bitPosition + bitSizeOf(bitPosition);
}

size_t ReflectableBitmask::initializeOffsets(::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition) const
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

void ReflectableBitmask::write(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const
{
    contextNode.getContext().write(
            ::zserio::StdIntArrayTraits<::test_object::polymorphic_allocator::ReflectableBitmask::underlying_type>(),
            out, m_value);
}

::zserio::pmr::string ReflectableBitmask::toString(const ::zserio::pmr::string::allocator_type& allocator) const
{
    ::zserio::pmr::string result(allocator);
    if ((*this & ReflectableBitmask::Values::CREATE) == ReflectableBitmask::Values::CREATE)
        result += result.empty() ? "CREATE" : " | CREATE";
    if ((*this & ReflectableBitmask::Values::READ) == ReflectableBitmask::Values::READ)
        result += result.empty() ? "READ" : " | READ";
    if ((*this & ReflectableBitmask::Values::WRITE) == ReflectableBitmask::Values::WRITE)
        result += result.empty() ? "WRITE" : " | WRITE";

    return ::zserio::toString<::zserio::pmr::string::allocator_type>(m_value, allocator) + "[" + result + "]";
}

ReflectableBitmask::underlying_type ReflectableBitmask::readValue(::zserio::BitStreamReader& in)
{
    return static_cast<underlying_type>(in.readBits(UINT8_C(8)));
}

ReflectableBitmask::underlying_type ReflectableBitmask::readValue(::zserio::pmr::PackingContextNode& contextNode,
        ::zserio::BitStreamReader& in)
{
    return contextNode.getContext().read(
            ::zserio::StdIntArrayTraits<::test_object::polymorphic_allocator::ReflectableBitmask::underlying_type>(), in);
}

} // namespace polymorphic_allocator
} // namespace test_object
