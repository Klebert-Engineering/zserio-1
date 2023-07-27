/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>
#include <zserio/TypeInfo.h>
#include <zserio/AnyHolder.h>
#include <zserio/Reflectable.h>

#include <test_object/std_allocator/ArrayObject.h>

namespace test_object
{
namespace std_allocator
{

ArrayObject::ArrayObject(const allocator_type&) noexcept :
        m_value_(uint32_t())
{
}

ArrayObject::ArrayObject(::zserio::BitStreamReader& in, const allocator_type&) :
        m_value_(readValue(in))
{
}

ArrayObject::ArrayObject(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in, const allocator_type&) :
        m_value_(readValue(contextNode, in))
{
}

ArrayObject::ArrayObject(::zserio::PropagateAllocatorT,
        const ArrayObject& other, const allocator_type& allocator) :
        m_value_(::zserio::allocatorPropagatingCopy(other.m_value_, allocator))
{
}

const ::zserio::ITypeInfo& ArrayObject::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 1> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("value"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getFixedUnsignedBitField(UINT8_C(31)), // typeInfo
            {}, // typeArguments
            false, // isExtended
            {}, // alignment
            {}, // offset
            {}, // initializer
            false, // isOptional
            {}, // optionalClause
            {}, // constraint
            false, // isArray
            {}, // arrayLength
            false, // isPacked
            false // isImplicit
        }
    };

    static const ::zserio::Span<::zserio::BasicParameterInfo<allocator_type>> parameters;

    static const ::zserio::Span<::zserio::BasicFunctionInfo<allocator_type>> functions;

    static const ::zserio::StructTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.std_allocator.ArrayObject"),
        [](const allocator_type& allocator) -> ::zserio::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<ArrayObject>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::IReflectableConstPtr ArrayObject::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::std_allocator::ArrayObject& object, const allocator_type& allocator) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::std_allocator::ArrayObject::typeInfo(), allocator),
                m_object(object)
        {}

        size_t bitSizeOf(size_t bitPosition) const override
        {
            return m_object.bitSizeOf(bitPosition);
        }

        void write(::zserio::BitStreamWriter& writer) const override
        {
            m_object.write(writer);
        }

        ::zserio::IReflectableConstPtr getField(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                return ::zserio::ReflectableFactory::getFixedUnsignedBitField(m_object.getValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ArrayObject'!";
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::AnyHolder<>(::std::cref(m_object), allocator);
        }

    private:
        const ::test_object::std_allocator::ArrayObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::IReflectablePtr ArrayObject::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::std_allocator::ArrayObject& object, const allocator_type& allocator) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::std_allocator::ArrayObject::typeInfo(), allocator),
                m_object(object)
        {}

        void initializeChildren() override
        {
        }

        size_t initializeOffsets(size_t bitPosition) override
        {
            return m_object.initializeOffsets(bitPosition);
        }

        size_t bitSizeOf(size_t bitPosition) const override
        {
            return m_object.bitSizeOf(bitPosition);
        }

        void write(::zserio::BitStreamWriter& writer) const override
        {
            m_object.write(writer);
        }

        ::zserio::IReflectableConstPtr getField(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                return ::zserio::ReflectableFactory::getFixedUnsignedBitField(m_object.getValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ArrayObject'!";
        }

        ::zserio::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                return ::zserio::ReflectableFactory::getFixedUnsignedBitField(m_object.getValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ArrayObject'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                m_object.setValue(value.get<uint32_t>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ArrayObject'!";
        }

        ::zserio::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                m_object.setValue(uint32_t());
                return ::zserio::ReflectableFactory::getFixedUnsignedBitField(m_object.getValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ArrayObject'!";
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::AnyHolder<>(::std::cref(m_object), allocator);
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& allocator) override
        {
            return ::zserio::AnyHolder<>(::std::ref(m_object), allocator);
        }

    private:
        ::test_object::std_allocator::ArrayObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

uint32_t ArrayObject::getValue() const
{
    return m_value_;
}

void ArrayObject::setValue(uint32_t value_)
{
    m_value_ = value_;
}

void ArrayObject::createPackingContext(::zserio::PackingContextNode& contextNode)
{
    contextNode.reserveChildren(1);

    contextNode.createChild().createContext();
}

void ArrayObject::initPackingContext(::zserio::PackingContextNode& contextNode) const
{
    contextNode.getChildren()[0].getContext().init<::zserio::BitFieldArrayTraits<uint32_t, UINT8_C(31)>>(m_value_);
}

size_t ArrayObject::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(31);

    return endBitPosition - bitPosition;
}

size_t ArrayObject::bitSizeOf(::zserio::PackingContextNode& contextNode, size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += contextNode.getChildren()[0].getContext().bitSizeOf<::zserio::BitFieldArrayTraits<uint32_t, UINT8_C(31)>>(m_value_);

    return endBitPosition - bitPosition;
}

size_t ArrayObject::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(31);

    return endBitPosition;
}

size_t ArrayObject::initializeOffsets(::zserio::PackingContextNode& contextNode, size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += contextNode.getChildren()[0].getContext().bitSizeOf<::zserio::BitFieldArrayTraits<uint32_t, UINT8_C(31)>>(m_value_);

    return endBitPosition;
}

bool ArrayObject::operator==(const ArrayObject& other) const
{
    if (this != &other)
    {
        return
                (m_value_ == other.m_value_);
    }

    return true;
}

uint32_t ArrayObject::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, m_value_);

    return result;
}

void ArrayObject::write(::zserio::BitStreamWriter& out) const
{
    out.writeBits(m_value_, UINT8_C(31));
}

void ArrayObject::write(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const
{
    contextNode.getChildren()[0].getContext().write<::zserio::BitFieldArrayTraits<uint32_t, UINT8_C(31)>>(out, m_value_);
}

uint32_t ArrayObject::readValue(::zserio::BitStreamReader& in)
{
    return static_cast<uint32_t>(in.readBits(UINT8_C(31)));
}

uint32_t ArrayObject::readValue(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in)
{
    return contextNode.getChildren()[0].getContext().read<::zserio::BitFieldArrayTraits<uint32_t, UINT8_C(31)>>(in);
}

} // namespace std_allocator
} // namespace test_object
