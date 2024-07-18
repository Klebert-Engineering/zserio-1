/**
 * Automatically generated by Zserio C++ generator version 1.0.2 using Zserio core 2.14.1.
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

#include <test_object/std_allocator/ReflectableUtilObject.h>

namespace test_object
{
namespace std_allocator
{

ReflectableUtilObject::ReflectableUtilObject(const allocator_type& allocator) noexcept :
        m_areChildrenInitialized(false),
        m_choiceParam_(uint8_t()),
        m_reflectableUtilChoice_(allocator)
{
}

ReflectableUtilObject::ReflectableUtilObject(::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_areChildrenInitialized(true),
        m_choiceParam_(readChoiceParam(in)),
        m_reflectableUtilChoice_(readReflectableUtilChoice(in, allocator))
{
}

ReflectableUtilObject::ReflectableUtilObject(const ReflectableUtilObject& other) :
        m_choiceParam_(other.m_choiceParam_),
        m_reflectableUtilChoice_(::zserio::NoInit, other.m_reflectableUtilChoice_)
{
    if (other.m_areChildrenInitialized)
    {
        initializeChildren();
    }
    else
    {
        m_areChildrenInitialized = false;
    }
}

ReflectableUtilObject& ReflectableUtilObject::operator=(const ReflectableUtilObject& other)
{
    m_choiceParam_ = other.m_choiceParam_;
    (void)m_reflectableUtilChoice_.assign(::zserio::NoInit, other.m_reflectableUtilChoice_);
    if (other.m_areChildrenInitialized)
    {
        initializeChildren();
    }
    else
    {
        m_areChildrenInitialized = false;
    }

    return *this;
}

ReflectableUtilObject::ReflectableUtilObject(ReflectableUtilObject&& other) :
        m_choiceParam_(::std::move(other.m_choiceParam_)),
        m_reflectableUtilChoice_(::zserio::NoInit, ::std::move(other.m_reflectableUtilChoice_))
{
    if (other.m_areChildrenInitialized)
    {
        initializeChildren();
    }
    else
    {
        m_areChildrenInitialized = false;
    }
}

ReflectableUtilObject& ReflectableUtilObject::operator=(ReflectableUtilObject&& other)
{
    m_choiceParam_ = ::std::move(other.m_choiceParam_);
    (void)m_reflectableUtilChoice_.assign(::zserio::NoInit, ::std::move(other.m_reflectableUtilChoice_));
    if (other.m_areChildrenInitialized)
    {
        initializeChildren();
    }
    else
    {
        m_areChildrenInitialized = false;
    }

    return *this;
}

ReflectableUtilObject::ReflectableUtilObject(::zserio::PropagateAllocatorT,
        const ReflectableUtilObject& other, const allocator_type& allocator) :
        m_choiceParam_(::zserio::allocatorPropagatingCopy(other.m_choiceParam_, allocator)),
        m_reflectableUtilChoice_(::zserio::NoInit, ::zserio::allocatorPropagatingCopy(::zserio::NoInit, other.m_reflectableUtilChoice_, allocator))
{
    if (other.m_areChildrenInitialized)
    {
        initializeChildren();
    }
    else
    {
        m_areChildrenInitialized = false;
    }
}

const ::zserio::ITypeInfo& ReflectableUtilObject::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::StringView, 1> reflectableUtilChoiceTypeArguments = {
        ::zserio::makeStringView("getChoiceParam()")
    };
    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 2> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("choiceParam"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getUInt8(), // typeInfo
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
            ::zserio::makeStringView("reflectableUtilChoice"), // schemaName
            ::test_object::std_allocator::ReflectableUtilChoice::typeInfo(), // typeInfo
            reflectableUtilChoiceTypeArguments, // typeArguments
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
        ::zserio::makeStringView("test_object.std_allocator.ReflectableUtilObject"),
        [](const allocator_type& allocator) -> ::zserio::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<ReflectableUtilObject>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::IReflectableConstPtr ReflectableUtilObject::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::std_allocator::ReflectableUtilObject& object, const allocator_type& alloc) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::std_allocator::ReflectableUtilObject::typeInfo(), alloc),
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
            if (name == ::zserio::makeStringView("choiceParam"))
            {
                return ::zserio::ReflectableFactory::getUInt8(m_object.getChoiceParam(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilChoice"))
            {
                return m_object.getReflectableUtilChoice().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilObject'!";
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& alloc) const override
        {
            return ::zserio::AnyHolder<>(::std::cref(m_object), alloc);
        }

    private:
        const ::test_object::std_allocator::ReflectableUtilObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::IReflectablePtr ReflectableUtilObject::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::std_allocator::ReflectableUtilObject& object, const allocator_type& alloc) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::std_allocator::ReflectableUtilObject::typeInfo(), alloc),
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
            if (name == ::zserio::makeStringView("choiceParam"))
            {
                return ::zserio::ReflectableFactory::getUInt8(m_object.getChoiceParam(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilChoice"))
            {
                return m_object.getReflectableUtilChoice().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilObject'!";
        }

        ::zserio::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("choiceParam"))
            {
                return ::zserio::ReflectableFactory::getUInt8(m_object.getChoiceParam(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilChoice"))
            {
                return m_object.getReflectableUtilChoice().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilObject'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("choiceParam"))
            {
                m_object.setChoiceParam(value.get<uint8_t>());
                return;
            }
            if (name == ::zserio::makeStringView("reflectableUtilChoice"))
            {
                m_object.setReflectableUtilChoice(value.get<::test_object::std_allocator::ReflectableUtilChoice>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilObject'!";
        }

        ::zserio::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("choiceParam"))
            {
                m_object.setChoiceParam(uint8_t());
                return ::zserio::ReflectableFactory::getUInt8(m_object.getChoiceParam(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilChoice"))
            {
                m_object.setReflectableUtilChoice(::test_object::std_allocator::ReflectableUtilChoice(get_allocator()));
                return m_object.getReflectableUtilChoice().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilObject'!";
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& alloc) const override
        {
            return ::zserio::AnyHolder<>(::std::cref(m_object), alloc);
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& alloc) override
        {
            return ::zserio::AnyHolder<>(::std::ref(m_object), alloc);
        }

    private:
        ::test_object::std_allocator::ReflectableUtilObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void ReflectableUtilObject::initializeChildren()
{
    m_reflectableUtilChoice_.initialize(static_cast<uint8_t>(getChoiceParam()));

    m_areChildrenInitialized = true;
}

uint8_t ReflectableUtilObject::getChoiceParam() const
{
    return m_choiceParam_;
}

void ReflectableUtilObject::setChoiceParam(uint8_t choiceParam_)
{
    m_choiceParam_ = choiceParam_;
}

::test_object::std_allocator::ReflectableUtilChoice& ReflectableUtilObject::getReflectableUtilChoice()
{
    return m_reflectableUtilChoice_;
}

const ::test_object::std_allocator::ReflectableUtilChoice& ReflectableUtilObject::getReflectableUtilChoice() const
{
    return m_reflectableUtilChoice_;
}

void ReflectableUtilObject::setReflectableUtilChoice(const ::test_object::std_allocator::ReflectableUtilChoice& reflectableUtilChoice_)
{
    m_reflectableUtilChoice_ = reflectableUtilChoice_;
}

void ReflectableUtilObject::setReflectableUtilChoice(::test_object::std_allocator::ReflectableUtilChoice&& reflectableUtilChoice_)
{
    m_reflectableUtilChoice_ = ::std::move(reflectableUtilChoice_);
}

size_t ReflectableUtilObject::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(8);
    endBitPosition += m_reflectableUtilChoice_.bitSizeOf(endBitPosition);

    return endBitPosition - bitPosition;
}

size_t ReflectableUtilObject::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(8);
    endBitPosition = m_reflectableUtilChoice_.initializeOffsets(endBitPosition);

    return endBitPosition;
}

bool ReflectableUtilObject::operator==(const ReflectableUtilObject& other) const
{
    if (this != &other)
    {
        return
                (m_choiceParam_ == other.m_choiceParam_) &&
                (m_reflectableUtilChoice_ == other.m_reflectableUtilChoice_);
    }

    return true;
}

bool ReflectableUtilObject::operator<(const ReflectableUtilObject& other) const
{
    if (m_choiceParam_ < other.m_choiceParam_)
    {
        return true;
    }
    if (other.m_choiceParam_ < m_choiceParam_)
    {
        return false;
    }

    if (m_reflectableUtilChoice_ < other.m_reflectableUtilChoice_)
    {
        return true;
    }
    if (other.m_reflectableUtilChoice_ < m_reflectableUtilChoice_)
    {
        return false;
    }

    return false;
}

uint32_t ReflectableUtilObject::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, m_choiceParam_);
    result = ::zserio::calcHashCode(result, m_reflectableUtilChoice_);

    return result;
}

void ReflectableUtilObject::write(::zserio::BitStreamWriter& out) const
{
    out.writeBits(m_choiceParam_, UINT8_C(8));

    // check parameters
    if (m_reflectableUtilChoice_.getParam() != static_cast<uint8_t>(getChoiceParam()))
    {
        throw ::zserio::CppRuntimeException("Write: Wrong parameter param for field ReflectableUtilObject.reflectableUtilChoice: ") <<
                m_reflectableUtilChoice_.getParam() << " != " << static_cast<uint8_t>(getChoiceParam()) << "!";
    }
    m_reflectableUtilChoice_.write(out);
}

uint8_t ReflectableUtilObject::readChoiceParam(::zserio::BitStreamReader& in)
{
    return static_cast<uint8_t>(in.readBits(UINT8_C(8)));
}

::test_object::std_allocator::ReflectableUtilChoice ReflectableUtilObject::readReflectableUtilChoice(::zserio::BitStreamReader& in,
        const allocator_type& allocator)
{
    return ::test_object::std_allocator::ReflectableUtilChoice(in, static_cast<uint8_t>(getChoiceParam()), allocator);
}


} // namespace std_allocator
} // namespace test_object
