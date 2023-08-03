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

#include <test_object/std_allocator/ReflectableObject.h>

namespace test_object
{
namespace std_allocator
{

ReflectableObject::ReflectableObject(const allocator_type& allocator) noexcept :
        m_areChildrenInitialized(false),
        m_stringField_(allocator),
        m_reflectableNested_(allocator)
{
}

ReflectableObject::ReflectableObject(::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_areChildrenInitialized(true),
        m_stringField_(readStringField(in, allocator)),
        m_reflectableNested_(readReflectableNested(in, allocator))
{
}

ReflectableObject::ReflectableObject(ReflectableObject::ZserioPackingContext& context, ::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_areChildrenInitialized(true),
        m_stringField_(readStringField(in, allocator)),
        m_reflectableNested_(readReflectableNested(context, in, allocator))
{
}

ReflectableObject::ReflectableObject(const ReflectableObject& other) :
        m_stringField_(other.m_stringField_),
        m_reflectableNested_(other.m_reflectableNested_)
{
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;
}

ReflectableObject& ReflectableObject::operator=(const ReflectableObject& other)
{
    m_stringField_ = other.m_stringField_;
    m_reflectableNested_ = other.m_reflectableNested_;
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;

    return *this;
}

ReflectableObject::ReflectableObject(ReflectableObject&& other) :
        m_stringField_(::std::move(other.m_stringField_)),
        m_reflectableNested_(::std::move(other.m_reflectableNested_))
{
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;
}

ReflectableObject& ReflectableObject::operator=(ReflectableObject&& other)
{
    m_stringField_ = ::std::move(other.m_stringField_);
    m_reflectableNested_ = ::std::move(other.m_reflectableNested_);
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;

    return *this;
}

ReflectableObject::ReflectableObject(::zserio::PropagateAllocatorT,
        const ReflectableObject& other, const allocator_type& allocator) :
        m_stringField_(::zserio::allocatorPropagatingCopy(other.m_stringField_, allocator)),
        m_reflectableNested_(::zserio::allocatorPropagatingCopy(other.m_reflectableNested_, allocator))
{
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;
}

const ::zserio::ITypeInfo& ReflectableObject::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::StringView, 2> reflectableNestedTypeArguments = {
        ::zserio::makeStringView("13"), 
        ::zserio::makeStringView("getStringField()")
    };
    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 2> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("stringField"), // schemaName
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
        },
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("reflectableNested"), // schemaName
            ::test_object::std_allocator::ReflectableNested::typeInfo(), // typeInfo
            reflectableNestedTypeArguments, // typeArguments
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
        ::zserio::makeStringView("test_object.std_allocator.ReflectableObject"),
        [](const allocator_type& allocator) -> ::zserio::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<ReflectableObject>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::IReflectableConstPtr ReflectableObject::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::std_allocator::ReflectableObject& object, const allocator_type& allocator) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::std_allocator::ReflectableObject::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("stringField"))
            {
                return ::zserio::ReflectableFactory::getString(m_object.getStringField(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableNested"))
            {
                return m_object.getReflectableNested().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableObject'!";
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::AnyHolder<>(::std::cref(m_object), allocator);
        }

    private:
        const ::test_object::std_allocator::ReflectableObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::IReflectablePtr ReflectableObject::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::std_allocator::ReflectableObject& object, const allocator_type& allocator) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::std_allocator::ReflectableObject::typeInfo(), allocator),
                m_object(object)
        {}

        void initializeChildren() override
        {
            m_object.initializeChildren();
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
            if (name == ::zserio::makeStringView("stringField"))
            {
                return ::zserio::ReflectableFactory::getString(m_object.getStringField(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableNested"))
            {
                return m_object.getReflectableNested().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableObject'!";
        }

        ::zserio::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("stringField"))
            {
                return ::zserio::ReflectableFactory::getString(m_object.getStringField(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableNested"))
            {
                return m_object.getReflectableNested().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableObject'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("stringField"))
            {
                m_object.setStringField(value.get<::zserio::string<>>());
                return;
            }
            if (name == ::zserio::makeStringView("reflectableNested"))
            {
                m_object.setReflectableNested(value.get<::test_object::std_allocator::ReflectableNested>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableObject'!";
        }

        ::zserio::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("stringField"))
            {
                m_object.setStringField(::zserio::string<>(get_allocator()));
                return ::zserio::ReflectableFactory::getString(m_object.getStringField(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableNested"))
            {
                m_object.setReflectableNested(::test_object::std_allocator::ReflectableNested(get_allocator()));
                return m_object.getReflectableNested().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableObject'!";
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
        ::test_object::std_allocator::ReflectableObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void ReflectableObject::initializeChildren()
{
    m_reflectableNested_.initialize(static_cast<int32_t>(13), getStringField());

    m_areChildrenInitialized = true;
}

::zserio::string<>& ReflectableObject::getStringField()
{
    return m_stringField_;
}

const ::zserio::string<>& ReflectableObject::getStringField() const
{
    return m_stringField_;
}

void ReflectableObject::setStringField(const ::zserio::string<>& stringField_)
{
    m_stringField_ = stringField_;
}

void ReflectableObject::setStringField(::zserio::string<>&& stringField_)
{
    m_stringField_ = ::std::move(stringField_);
}

::test_object::std_allocator::ReflectableNested& ReflectableObject::getReflectableNested()
{
    return m_reflectableNested_;
}

const ::test_object::std_allocator::ReflectableNested& ReflectableObject::getReflectableNested() const
{
    return m_reflectableNested_;
}

void ReflectableObject::setReflectableNested(const ::test_object::std_allocator::ReflectableNested& reflectableNested_)
{
    m_reflectableNested_ = reflectableNested_;
}

void ReflectableObject::setReflectableNested(::test_object::std_allocator::ReflectableNested&& reflectableNested_)
{
    m_reflectableNested_ = ::std::move(reflectableNested_);
}

void ReflectableObject::initPackingContext(ReflectableObject::ZserioPackingContext& context) const
{
    m_reflectableNested_.initPackingContext(context.getReflectableNested());
}

size_t ReflectableObject::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_stringField_);
    endBitPosition += m_reflectableNested_.bitSizeOf(endBitPosition);

    return endBitPosition - bitPosition;
}

size_t ReflectableObject::bitSizeOf(ReflectableObject::ZserioPackingContext& context, size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_stringField_);
    endBitPosition += m_reflectableNested_.bitSizeOf(context.getReflectableNested(), endBitPosition);

    return endBitPosition - bitPosition;
}

size_t ReflectableObject::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_stringField_);
    endBitPosition = m_reflectableNested_.initializeOffsets(endBitPosition);

    return endBitPosition;
}

size_t ReflectableObject::initializeOffsets(ReflectableObject::ZserioPackingContext& context, size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_stringField_);
    endBitPosition = m_reflectableNested_.initializeOffsets(context.getReflectableNested(), endBitPosition);

    return endBitPosition;
}

bool ReflectableObject::operator==(const ReflectableObject& other) const
{
    if (this != &other)
    {
        return
                (m_stringField_ == other.m_stringField_) &&
                (m_reflectableNested_ == other.m_reflectableNested_);
    }

    return true;
}

uint32_t ReflectableObject::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, m_stringField_);
    result = ::zserio::calcHashCode(result, m_reflectableNested_);

    return result;
}

void ReflectableObject::write(::zserio::BitStreamWriter& out) const
{
    out.writeString(m_stringField_);

    // check parameters
    if (m_reflectableNested_.getDummyParam() != static_cast<int32_t>(13))
    {
        throw ::zserio::CppRuntimeException("Write: Wrong parameter dummyParam for field ReflectableObject.reflectableNested: ") <<
                m_reflectableNested_.getDummyParam() << " != " << static_cast<int32_t>(13) << "!";
    }
    if (&(m_reflectableNested_.getStringParam()) != &(getStringField()))
    {
        throw ::zserio::CppRuntimeException("Write: Inconsistent parameter stringParam for field ReflectableObject.reflectableNested!");
    }
    m_reflectableNested_.write(out);
}

void ReflectableObject::write(ReflectableObject::ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const
{
    out.writeString(m_stringField_);

    // check parameters
    if (m_reflectableNested_.getDummyParam() != static_cast<int32_t>(13))
    {
        throw ::zserio::CppRuntimeException("Write: Wrong parameter dummyParam for field ReflectableObject.reflectableNested: ") <<
                m_reflectableNested_.getDummyParam() << " != " << static_cast<int32_t>(13) << "!";
    }
    if (&(m_reflectableNested_.getStringParam()) != &(getStringField()))
    {
        throw ::zserio::CppRuntimeException("Write: Inconsistent parameter stringParam for field ReflectableObject.reflectableNested!");
    }
    m_reflectableNested_.write(context.getReflectableNested(), out);
}

::zserio::string<> ReflectableObject::readStringField(::zserio::BitStreamReader& in,
        const allocator_type& allocator)
{
    return static_cast<::zserio::string<>>(in.readString(allocator));
}

::test_object::std_allocator::ReflectableNested ReflectableObject::readReflectableNested(::zserio::BitStreamReader& in,
        const allocator_type& allocator)
{
    return ::test_object::std_allocator::ReflectableNested(in, static_cast<int32_t>(13), getStringField(), allocator);
}

::test_object::std_allocator::ReflectableNested ReflectableObject::readReflectableNested(ReflectableObject::ZserioPackingContext& context, ::zserio::BitStreamReader& in, const allocator_type& allocator)
{
    return ::test_object::std_allocator::ReflectableNested(context.getReflectableNested(), in, static_cast<int32_t>(13), getStringField(), allocator);
}

} // namespace std_allocator
} // namespace test_object
