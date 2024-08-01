/**
 * Automatically generated by Zserio C++ generator version 1.0.2 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, bitPosition, polymorphicAllocator.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>
#include <zserio/TypeInfo.h>
#include <zserio/pmr/AnyHolder.h>
#include <zserio/pmr/Reflectable.h>

#include <test_object/polymorphic_allocator/WalkerNested.h>

namespace test_object
{
namespace polymorphic_allocator
{

WalkerNested::WalkerNested(const allocator_type& allocator) noexcept :
        m_bitPosition(0),
        m_text_(allocator)
{
}

WalkerNested::WalkerNested(::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_bitPosition(in.getBitPosition()),
        m_text_(readText(in, allocator))
{
}

WalkerNested::WalkerNested(::zserio::PropagateAllocatorT,
        const WalkerNested& other, const allocator_type& allocator) :
        m_bitPosition(other.m_bitPosition),
        m_text_(::zserio::allocatorPropagatingCopy(other.m_text_, allocator))
{
}

const ::zserio::pmr::ITypeInfo& WalkerNested::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 1> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("text"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getString(), // typeInfo
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
        ::zserio::makeStringView("test_object.polymorphic_allocator.WalkerNested"),
        [](const allocator_type& allocator) -> ::zserio::pmr::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<WalkerNested>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::pmr::IReflectableConstPtr WalkerNested::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::polymorphic_allocator::WalkerNested& object, const allocator_type& alloc) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::WalkerNested::typeInfo(), alloc),
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

        ::zserio::pmr::IReflectableConstPtr getField(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerNested'!";
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& alloc) const override
        {
            return ::zserio::pmr::AnyHolder(::std::cref(m_object), alloc);
        }

        size_t bitPosition() const override
        {
            return m_object.bitPosition();
        }

    private:
        const ::test_object::polymorphic_allocator::WalkerNested& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::pmr::IReflectablePtr WalkerNested::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::polymorphic_allocator::WalkerNested& object, const allocator_type& alloc) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::WalkerNested::typeInfo(), alloc),
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

        ::zserio::pmr::IReflectableConstPtr getField(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerNested'!";
        }

        ::zserio::pmr::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerNested'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("text"))
            {
                m_object.setText(value.get<::zserio::pmr::string>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerNested'!";
        }

        ::zserio::pmr::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("text"))
            {
                m_object.setText(::zserio::pmr::string(get_allocator()));
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerNested'!";
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& alloc) const override
        {
            return ::zserio::pmr::AnyHolder(::std::cref(m_object), alloc);
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& alloc) override
        {
            return ::zserio::pmr::AnyHolder(::std::ref(m_object), alloc);
        }

        size_t bitPosition() const override
        {
            return m_object.bitPosition();
        }

    private:
        ::test_object::polymorphic_allocator::WalkerNested& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::pmr::string& WalkerNested::getText()
{
    return m_text_;
}

const ::zserio::pmr::string& WalkerNested::getText() const
{
    return m_text_;
}

void WalkerNested::setText(const ::zserio::pmr::string& text_)
{
    m_text_ = text_;
}

void WalkerNested::setText(::zserio::pmr::string&& text_)
{
    m_text_ = ::std::move(text_);
}

size_t WalkerNested::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_text_);

    return endBitPosition - bitPosition;
}

size_t WalkerNested::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_text_);

    return endBitPosition;
}

bool WalkerNested::operator==(const WalkerNested& other) const
{
    if (this != &other)
    {
        return
                (m_text_ == other.m_text_);
    }

    return true;
}

bool WalkerNested::operator<(const WalkerNested& other) const
{
    if (m_text_ < other.m_text_)
    {
        return true;
    }
    if (other.m_text_ < m_text_)
    {
        return false;
    }

    return false;
}

uint32_t WalkerNested::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, m_text_);

    return result;
}

void WalkerNested::write(::zserio::BitStreamWriter& out) const
{
    out.writeString(m_text_);
}

size_t WalkerNested::bitPosition() const
{
    return m_bitPosition;
}

::zserio::pmr::string WalkerNested::readText(::zserio::BitStreamReader& in,
        const allocator_type& allocator)
{
    return static_cast<::zserio::pmr::string>(in.readString(allocator));
}


} // namespace polymorphic_allocator
} // namespace test_object
