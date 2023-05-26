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

#include <test_object/std_allocator/SerializeObject.h>

namespace test_object
{
namespace std_allocator
{

SerializeObject::SerializeObject(const allocator_type& allocator) noexcept :
        m_areChildrenInitialized(false),
        m_param_(int8_t()),
        m_nested_(allocator)
{
}

SerializeObject::SerializeObject(::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_areChildrenInitialized(true),
        m_param_(readParam(in)),
        m_nested_(readNested(in, allocator))
{
}

SerializeObject::SerializeObject(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_areChildrenInitialized(true),
        m_param_(readParam(contextNode, in)),
        m_nested_(readNested(contextNode, in, allocator))
{
}

SerializeObject::SerializeObject(const SerializeObject& other) :
        m_param_(other.m_param_),
        m_nested_(other.m_nested_)
{
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;
}

SerializeObject& SerializeObject::operator=(const SerializeObject& other)
{
    m_param_ = other.m_param_;
    m_nested_ = other.m_nested_;
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;

    return *this;
}

SerializeObject::SerializeObject(SerializeObject&& other) :
        m_param_(::std::move(other.m_param_)),
        m_nested_(::std::move(other.m_nested_))
{
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;
}

SerializeObject& SerializeObject::operator=(SerializeObject&& other)
{
    m_param_ = ::std::move(other.m_param_);
    m_nested_ = ::std::move(other.m_nested_);
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;

    return *this;
}

SerializeObject::SerializeObject(::zserio::PropagateAllocatorT,
        const SerializeObject& other, const allocator_type& allocator) :
        m_param_(::zserio::allocatorPropagatingCopy(other.m_param_, allocator)),
        m_nested_(::zserio::allocatorPropagatingCopy(other.m_nested_, allocator))
{
    if (other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;
}

const ::zserio::ITypeInfo& SerializeObject::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::StringView, 1> nestedTypeArguments = {
        ::zserio::makeStringView("getParam()")
    };
    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 2> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("param"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getInt8(), // typeInfo
            {}, // typeArguments
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
            ::zserio::makeStringView("nested"), // schemaName
            ::test_object::std_allocator::SerializeNested::typeInfo(), // typeInfo
            nestedTypeArguments, // typeArguments
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
        ::zserio::makeStringView("test_object.std_allocator.SerializeObject"),
        [](const allocator_type& allocator) -> ::zserio::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<SerializeObject>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::IReflectableConstPtr SerializeObject::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::std_allocator::SerializeObject& object, const allocator_type& allocator) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::std_allocator::SerializeObject::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::ReflectableFactory::getInt8(m_object.getParam(), get_allocator());
            }
            if (name == ::zserio::makeStringView("nested"))
            {
                return m_object.getNested().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'SerializeObject'!";
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::AnyHolder<>(::std::cref(m_object), allocator);
        }

    private:
        const ::test_object::std_allocator::SerializeObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::IReflectablePtr SerializeObject::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::std_allocator::SerializeObject& object, const allocator_type& allocator) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::std_allocator::SerializeObject::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::ReflectableFactory::getInt8(m_object.getParam(), get_allocator());
            }
            if (name == ::zserio::makeStringView("nested"))
            {
                return m_object.getNested().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'SerializeObject'!";
        }

        ::zserio::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::ReflectableFactory::getInt8(m_object.getParam(), get_allocator());
            }
            if (name == ::zserio::makeStringView("nested"))
            {
                return m_object.getNested().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'SerializeObject'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                m_object.setParam(value.get<int8_t>());
                return;
            }
            if (name == ::zserio::makeStringView("nested"))
            {
                m_object.setNested(value.get<::test_object::std_allocator::SerializeNested>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'SerializeObject'!";
        }

        ::zserio::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                m_object.setParam(int8_t());
                return ::zserio::ReflectableFactory::getInt8(m_object.getParam(), get_allocator());
            }
            if (name == ::zserio::makeStringView("nested"))
            {
                m_object.setNested(::test_object::std_allocator::SerializeNested(get_allocator()));
                return m_object.getNested().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'SerializeObject'!";
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
        ::test_object::std_allocator::SerializeObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void SerializeObject::initializeChildren()
{
    m_nested_.initialize(static_cast<int8_t>(getParam()));

    m_areChildrenInitialized = true;
}

int8_t SerializeObject::getParam() const
{
    return m_param_;
}

void SerializeObject::setParam(int8_t param_)
{
    m_param_ = param_;
}

::test_object::std_allocator::SerializeNested& SerializeObject::getNested()
{
    return m_nested_;
}

const ::test_object::std_allocator::SerializeNested& SerializeObject::getNested() const
{
    return m_nested_;
}

void SerializeObject::setNested(const ::test_object::std_allocator::SerializeNested& nested_)
{
    m_nested_ = nested_;
}

void SerializeObject::setNested(::test_object::std_allocator::SerializeNested&& nested_)
{
    m_nested_ = ::std::move(nested_);
}

void SerializeObject::createPackingContext(::zserio::PackingContextNode& contextNode)
{
    contextNode.reserveChildren(2);

    contextNode.createChild().createContext();
    ::test_object::std_allocator::SerializeNested::createPackingContext(contextNode.createChild());
}

void SerializeObject::initPackingContext(::zserio::PackingContextNode& contextNode) const
{
    contextNode.getChildren()[0].getContext().init<::zserio::StdIntArrayTraits<int8_t>>(m_param_);
    m_nested_.initPackingContext(contextNode.getChildren()[1]);
}

size_t SerializeObject::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(8);
    endBitPosition += m_nested_.bitSizeOf(endBitPosition);

    return endBitPosition - bitPosition;
}

size_t SerializeObject::bitSizeOf(::zserio::PackingContextNode& contextNode, size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += contextNode.getChildren()[0].getContext().bitSizeOf<::zserio::StdIntArrayTraits<int8_t>>(m_param_);
    endBitPosition += m_nested_.bitSizeOf(
            contextNode.getChildren()[1], endBitPosition);

    return endBitPosition - bitPosition;
}

size_t SerializeObject::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(8);
    endBitPosition = m_nested_.initializeOffsets(endBitPosition);

    return endBitPosition;
}

size_t SerializeObject::initializeOffsets(::zserio::PackingContextNode& contextNode, size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += contextNode.getChildren()[0].getContext().bitSizeOf<::zserio::StdIntArrayTraits<int8_t>>(m_param_);
    endBitPosition = m_nested_.initializeOffsets(
            contextNode.getChildren()[1], endBitPosition);

    return endBitPosition;
}

bool SerializeObject::operator==(const SerializeObject& other) const
{
    if (this != &other)
    {
        return
                (m_param_ == other.m_param_) &&
                (m_nested_ == other.m_nested_);
    }

    return true;
}

uint32_t SerializeObject::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, m_param_);
    result = ::zserio::calcHashCode(result, m_nested_);

    return result;
}

void SerializeObject::write(::zserio::BitStreamWriter& out) const
{
    out.writeSignedBits(m_param_, UINT8_C(8));

    // check parameters
    if (m_nested_.getParam() != static_cast<int8_t>(getParam()))
    {
        throw ::zserio::CppRuntimeException("Write: Wrong parameter param for field SerializeObject.nested: ") <<
                m_nested_.getParam() << " != " << static_cast<int8_t>(getParam()) << "!";
    }
    m_nested_.write(out);
}

void SerializeObject::write(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const
{
    contextNode.getChildren()[0].getContext().write<::zserio::StdIntArrayTraits<int8_t>>(out, m_param_);

    // check parameters
    if (m_nested_.getParam() != static_cast<int8_t>(getParam()))
    {
        throw ::zserio::CppRuntimeException("Write: Wrong parameter param for field SerializeObject.nested: ") <<
                m_nested_.getParam() << " != " << static_cast<int8_t>(getParam()) << "!";
    }
    m_nested_.write(contextNode.getChildren()[1], out);
}

int8_t SerializeObject::readParam(::zserio::BitStreamReader& in)
{
    return static_cast<int8_t>(in.readSignedBits(UINT8_C(8)));
}

int8_t SerializeObject::readParam(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in)
{
    return contextNode.getChildren()[0].getContext().read<::zserio::StdIntArrayTraits<int8_t>>(in);
}

::test_object::std_allocator::SerializeNested SerializeObject::readNested(::zserio::BitStreamReader& in,
        const allocator_type& allocator)
{
    return ::test_object::std_allocator::SerializeNested(in, static_cast<int8_t>(getParam()), allocator);
}

::test_object::std_allocator::SerializeNested SerializeObject::readNested(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in, const allocator_type& allocator)
{
    return ::test_object::std_allocator::SerializeNested(contextNode.getChildren()[1], in, static_cast<int8_t>(getParam()), allocator);
}

} // namespace std_allocator
} // namespace test_object
