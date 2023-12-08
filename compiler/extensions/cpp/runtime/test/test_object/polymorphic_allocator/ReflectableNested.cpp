/**
 * Automatically generated by Zserio C++ generator version 1.0.0 using Zserio core 2.12.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorphicAllocator.
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
#include <functional>

#include <test_object/polymorphic_allocator/ReflectableNested.h>

namespace test_object
{
namespace polymorphic_allocator
{

ReflectableNested::ReflectableNested(const allocator_type&) noexcept :
        m_isInitialized(false),
        m_value_(uint32_t())
{
}

ReflectableNested::ReflectableNested(::zserio::BitStreamReader& in,
        int32_t dummyParam_,
        ::zserio::pmr::string& stringParam_, const allocator_type&) :
        m_dummyParam_(dummyParam_),
        m_stringParam_(&stringParam_),
        m_isInitialized(true),
        m_value_(readValue(in))
{
}

ReflectableNested::ReflectableNested(const ReflectableNested& other) :
        m_value_(other.m_value_)
{
    if (other.m_isInitialized)
        initialize(other.m_dummyParam_, *(other.m_stringParam_));
    else
        m_isInitialized = false;
}

ReflectableNested& ReflectableNested::operator=(const ReflectableNested& other)
{
    m_value_ = other.m_value_;
    if (other.m_isInitialized)
        initialize(other.m_dummyParam_, *(other.m_stringParam_));
    else
        m_isInitialized = false;

    return *this;
}

ReflectableNested::ReflectableNested(ReflectableNested&& other) :
        m_value_(::std::move(other.m_value_))
{
    if (other.m_isInitialized)
        initialize(other.m_dummyParam_, *(other.m_stringParam_));
    else
        m_isInitialized = false;
}

ReflectableNested& ReflectableNested::operator=(ReflectableNested&& other)
{
    m_value_ = ::std::move(other.m_value_);
    if (other.m_isInitialized)
        initialize(other.m_dummyParam_, *(other.m_stringParam_));
    else
        m_isInitialized = false;

    return *this;
}

ReflectableNested::ReflectableNested(::zserio::NoInitT,
        const ReflectableNested& other) :
        m_isInitialized(false),
        m_value_(other.m_value_)
{
}

ReflectableNested& ReflectableNested::assign(::zserio::NoInitT,
        const ReflectableNested& other)
{
    m_isInitialized = false;
    m_value_ = other.m_value_;

    return *this;
}

ReflectableNested::ReflectableNested(::zserio::NoInitT,
        ReflectableNested&& other) :
        m_isInitialized(false),
        m_value_(::std::move(other.m_value_))
{
}

ReflectableNested& ReflectableNested::assign(::zserio::NoInitT,
        ReflectableNested&& other)
{
    m_isInitialized = false;
    m_value_ = ::std::move(other.m_value_);

    return *this;
}

ReflectableNested::ReflectableNested(::zserio::PropagateAllocatorT,
        const ReflectableNested& other, const allocator_type& allocator) :
        m_value_(::zserio::allocatorPropagatingCopy(other.m_value_, allocator))
{
    if (other.m_isInitialized)
        initialize(other.m_dummyParam_, *(other.m_stringParam_));
    else
        m_isInitialized = false;
}

ReflectableNested::ReflectableNested(::zserio::PropagateAllocatorT, ::zserio::NoInitT,
        const ReflectableNested& other, const allocator_type& allocator) :
        m_isInitialized(false),
        m_value_(::zserio::allocatorPropagatingCopy(other.m_value_, allocator))
{
}

const ::zserio::pmr::ITypeInfo& ReflectableNested::typeInfo()
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

    static const ::std::array<::zserio::BasicParameterInfo<allocator_type>, 2> parameters = {
        ::zserio::BasicParameterInfo<allocator_type>{
            ::zserio::makeStringView("dummyParam"),
            ::zserio::BuiltinTypeInfo<allocator_type>::getFixedSignedBitField(UINT8_C(31))
        },
        ::zserio::BasicParameterInfo<allocator_type>{
            ::zserio::makeStringView("stringParam"),
            ::zserio::BuiltinTypeInfo<allocator_type>::getString()
        }
    };

    static const ::std::array<::zserio::BasicFunctionInfo<allocator_type>, 1> functions = {
        ::zserio::BasicFunctionInfo<allocator_type>{
            ::zserio::makeStringView("getValue"),
            ::zserio::BuiltinTypeInfo<allocator_type>::getFixedUnsignedBitField(UINT8_C(31)),
            ::zserio::makeStringView("getValue()")
        }
    };

    static const ::zserio::StructTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.polymorphic_allocator.ReflectableNested"),
        [](const allocator_type& allocator) -> ::zserio::pmr::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<ReflectableNested>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::pmr::IReflectableConstPtr ReflectableNested::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::polymorphic_allocator::ReflectableNested& object, const allocator_type& allocator) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::ReflectableNested::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("value"))
            {
                return ::zserio::pmr::ReflectableFactory::getFixedUnsignedBitField(m_object.getValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("dummyParam"))
            {
                return ::zserio::pmr::ReflectableFactory::getFixedSignedBitField(m_object.getDummyParam(), UINT8_C(31), get_allocator());
            }
            if (name == ::zserio::makeStringView("stringParam"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getStringParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::IReflectableConstPtr callFunction(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("getValue"))
            {
                return ::zserio::pmr::ReflectableFactory::getFixedUnsignedBitField(m_object.funcGetValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Function '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::pmr::AnyHolder(::std::cref(m_object), allocator);
        }

    private:
        const ::test_object::polymorphic_allocator::ReflectableNested& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::pmr::IReflectablePtr ReflectableNested::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::polymorphic_allocator::ReflectableNested& object, const allocator_type& allocator) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::ReflectableNested::typeInfo(), allocator),
                m_object(object)
        {}

        void initializeChildren() override
        {
        }

        void initialize(
                const ::zserio::vector<::zserio::AnyHolder<allocator_type>, allocator_type>& typeArguments) override
        {
            if (typeArguments.size() != 2)
            {
                throw ::zserio::CppRuntimeException("Not enough arguments to ReflectableNested::initialize, ") <<
                        "expecting 2, got " << typeArguments.size();
            }

            m_object.initialize(
                typeArguments[0].get<int32_t>(),
                typeArguments[1].get<::std::reference_wrapper<::zserio::pmr::string>>().get()
            );
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
            if (name == ::zserio::makeStringView("value"))
            {
                return ::zserio::pmr::ReflectableFactory::getFixedUnsignedBitField(m_object.getValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                return ::zserio::pmr::ReflectableFactory::getFixedUnsignedBitField(m_object.getValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                m_object.setValue(value.get<uint32_t>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                m_object.setValue(uint32_t());
                return ::zserio::pmr::ReflectableFactory::getFixedUnsignedBitField(m_object.getValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("dummyParam"))
            {
                return ::zserio::pmr::ReflectableFactory::getFixedSignedBitField(m_object.getDummyParam(), UINT8_C(31), get_allocator());
            }
            if (name == ::zserio::makeStringView("stringParam"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getStringParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::IReflectablePtr getParameter(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("dummyParam"))
            {
                return ::zserio::pmr::ReflectableFactory::getFixedSignedBitField(m_object.getDummyParam(), UINT8_C(31), get_allocator());
            }
            if (name == ::zserio::makeStringView("stringParam"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getStringParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::IReflectableConstPtr callFunction(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("getValue"))
            {
                return ::zserio::pmr::ReflectableFactory::getFixedUnsignedBitField(m_object.funcGetValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Function '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::IReflectablePtr callFunction(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("getValue"))
            {
                return ::zserio::pmr::ReflectableFactory::getFixedUnsignedBitField(m_object.funcGetValue(), UINT8_C(31), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Function '") << name << "' doesn't exist in 'ReflectableNested'!";
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::pmr::AnyHolder(::std::cref(m_object), allocator);
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& allocator) override
        {
            return ::zserio::pmr::AnyHolder(::std::ref(m_object), allocator);
        }

    private:
        ::test_object::polymorphic_allocator::ReflectableNested& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void ReflectableNested::initialize(
        int32_t dummyParam_,
        ::zserio::pmr::string& stringParam_)
{
    m_dummyParam_ = dummyParam_;
    m_stringParam_ = &stringParam_;
    m_isInitialized = true;
}

bool ReflectableNested::isInitialized() const
{
    return m_isInitialized;
}

int32_t ReflectableNested::getDummyParam() const
{
    if (!m_isInitialized)
        throw ::zserio::CppRuntimeException("Parameter 'dummyParam' of compound 'ReflectableNested' is not initialized!");

    return m_dummyParam_;
}

::zserio::pmr::string& ReflectableNested::getStringParam()
{
    if (!m_isInitialized)
        throw ::zserio::CppRuntimeException("Parameter 'stringParam' of compound 'ReflectableNested' is not initialized!");

    return *m_stringParam_;
}

const ::zserio::pmr::string& ReflectableNested::getStringParam() const
{
    if (!m_isInitialized)
        throw ::zserio::CppRuntimeException("Parameter 'stringParam' of compound 'ReflectableNested' is not initialized!");

    return *m_stringParam_;
}

uint32_t ReflectableNested::getValue() const
{
    return m_value_;
}

void ReflectableNested::setValue(uint32_t value_)
{
    m_value_ = value_;
}

uint32_t ReflectableNested::funcGetValue() const
{
    return static_cast<uint32_t>(getValue());
}

size_t ReflectableNested::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(31);

    return endBitPosition - bitPosition;
}

size_t ReflectableNested::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(31);

    return endBitPosition;
}

bool ReflectableNested::operator==(const ReflectableNested& other) const
{
    if (this != &other)
    {
        return
                (getDummyParam() == other.getDummyParam()) &&
                (getStringParam() == other.getStringParam()) &&
                (m_value_ == other.m_value_);
    }

    return true;
}

bool ReflectableNested::operator<(const ReflectableNested& other) const
{
    if (getDummyParam() < other.getDummyParam())
        return true;
    if (other.getDummyParam() < getDummyParam())
        return false;

    if (getStringParam() < other.getStringParam())
        return true;
    if (other.getStringParam() < getStringParam())
        return false;

    if (m_value_ < other.m_value_)
        return true;
    if (other.m_value_ < m_value_)
        return false;

    return false;
}

uint32_t ReflectableNested::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, getDummyParam());
    result = ::zserio::calcHashCode(result, getStringParam());
    result = ::zserio::calcHashCode(result, m_value_);

    return result;
}

void ReflectableNested::write(::zserio::BitStreamWriter& out) const
{
    out.writeBits(m_value_, UINT8_C(31));
}

uint32_t ReflectableNested::readValue(::zserio::BitStreamReader& in)
{
    return static_cast<uint32_t>(in.readBits(UINT8_C(31)));
}

} // namespace polymorphic_allocator
} // namespace test_object
