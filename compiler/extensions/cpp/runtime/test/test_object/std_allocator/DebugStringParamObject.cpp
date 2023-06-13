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
#include <zserio/StringView.h>

#include <test_object/std_allocator/DebugStringParamObject.h>

namespace test_object
{
namespace std_allocator
{

DebugStringParamObject::DebugStringParamObject(const allocator_type& allocator) noexcept :
        m_isInitialized(false),
        m_text_(::zserio::stringViewToString(::zserio::makeStringView("test"), allocator))
{
}

DebugStringParamObject::DebugStringParamObject(::zserio::BitStreamReader& in,
        int32_t param_, const allocator_type& allocator) :
        m_param_(param_),
        m_isInitialized(true),
        m_text_(readText(in, allocator))
{
}

DebugStringParamObject::DebugStringParamObject(::zserio::PackingContextNode&, ::zserio::BitStreamReader& in,
        int32_t param_, const allocator_type& allocator) :
        m_param_(param_),
        m_isInitialized(true),
        m_text_(readText(in, allocator))
{
}

DebugStringParamObject::DebugStringParamObject(const DebugStringParamObject& other) :
        m_text_(other.m_text_)
{
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;
}

DebugStringParamObject& DebugStringParamObject::operator=(const DebugStringParamObject& other)
{
    m_text_ = other.m_text_;
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;

    return *this;
}

DebugStringParamObject::DebugStringParamObject(DebugStringParamObject&& other) :
        m_text_(::std::move(other.m_text_))
{
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;
}

DebugStringParamObject& DebugStringParamObject::operator=(DebugStringParamObject&& other)
{
    m_text_ = ::std::move(other.m_text_);
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;

    return *this;
}

DebugStringParamObject::DebugStringParamObject(::zserio::PropagateAllocatorT,
        const DebugStringParamObject& other, const allocator_type& allocator) :
        m_text_(::zserio::allocatorPropagatingCopy(other.m_text_, allocator))
{
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;
}

const ::zserio::ITypeInfo& DebugStringParamObject::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 1> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("text"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getString(), // typeInfo
            {}, // typeArguments
            {}, // alignment
            {}, // offset
            ::zserio::makeStringView("::zserio::makeStringView(\"test\")"), // initializer
            false, // isOptional
            {}, // optionalClause
            {}, // constraint
            false, // isArray
            {}, // arrayLength
            false, // isPacked
            false // isImplicit
        }
    };

    static const ::std::array<::zserio::BasicParameterInfo<allocator_type>, 1> parameters = {
        ::zserio::BasicParameterInfo<allocator_type>{
            ::zserio::makeStringView("param"),
            ::zserio::BuiltinTypeInfo<allocator_type>::getInt32()
        }
    };

    static const ::zserio::Span<::zserio::BasicFunctionInfo<allocator_type>> functions;

    static const ::zserio::StructTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.std_allocator.DebugStringParamObject"),
        [](const allocator_type& allocator) -> ::zserio::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<DebugStringParamObject>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::IReflectableConstPtr DebugStringParamObject::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::std_allocator::DebugStringParamObject& object, const allocator_type& allocator) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::std_allocator::DebugStringParamObject::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'DebugStringParamObject'!";
        }

        ::zserio::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::ReflectableFactory::getInt32(m_object.getParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'DebugStringParamObject'!";
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::AnyHolder<>(::std::cref(m_object), allocator);
        }

    private:
        const ::test_object::std_allocator::DebugStringParamObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::IReflectablePtr DebugStringParamObject::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::std_allocator::DebugStringParamObject& object, const allocator_type& allocator) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::std_allocator::DebugStringParamObject::typeInfo(), allocator),
                m_object(object)
        {}

        void initializeChildren() override
        {
        }

        void initialize(
                const ::zserio::vector<::zserio::AnyHolder<allocator_type>, allocator_type>& typeArguments) override
        {
            if (typeArguments.size() != 1)
            {
                throw ::zserio::CppRuntimeException("Not enough arguments to DebugStringParamObject::initialize, ") <<
                        "expecting 1, got " << typeArguments.size();
            }

            m_object.initialize(
                typeArguments[0].get<int32_t>()
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

        ::zserio::IReflectableConstPtr getField(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'DebugStringParamObject'!";
        }

        ::zserio::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'DebugStringParamObject'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("text"))
            {
                m_object.setText(value.get<::zserio::string<>>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'DebugStringParamObject'!";
        }

        ::zserio::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("text"))
            {
                m_object.setText(::zserio::string<>(get_allocator()));
                return ::zserio::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'DebugStringParamObject'!";
        }

        ::zserio::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::ReflectableFactory::getInt32(m_object.getParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'DebugStringParamObject'!";
        }

        ::zserio::IReflectablePtr getParameter(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::ReflectableFactory::getInt32(m_object.getParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'DebugStringParamObject'!";
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
        ::test_object::std_allocator::DebugStringParamObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void DebugStringParamObject::initialize(
        int32_t param_)
{
    m_param_ = param_;
    m_isInitialized = true;
}

bool DebugStringParamObject::isInitialized() const
{
    return m_isInitialized;
}

int32_t DebugStringParamObject::getParam() const
{
    if (!m_isInitialized)
        throw ::zserio::CppRuntimeException("Parameter 'param' of compound 'DebugStringParamObject' is not initialized!");

    return m_param_;
}

::zserio::string<>& DebugStringParamObject::getText()
{
    return m_text_;
}

const ::zserio::string<>& DebugStringParamObject::getText() const
{
    return m_text_;
}

void DebugStringParamObject::setText(const ::zserio::string<>& text_)
{
    m_text_ = text_;
}

void DebugStringParamObject::setText(::zserio::string<>&& text_)
{
    m_text_ = ::std::move(text_);
}

void DebugStringParamObject::createPackingContext(::zserio::PackingContextNode& contextNode)
{
    contextNode.reserveChildren(1);

    contextNode.createChild();
}

void DebugStringParamObject::initPackingContext(::zserio::PackingContextNode&) const
{
}

size_t DebugStringParamObject::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_text_);

    return endBitPosition - bitPosition;
}

size_t DebugStringParamObject::bitSizeOf(::zserio::PackingContextNode&, size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_text_);

    return endBitPosition - bitPosition;
}

size_t DebugStringParamObject::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_text_);

    return endBitPosition;
}

size_t DebugStringParamObject::initializeOffsets(::zserio::PackingContextNode&, size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfString(m_text_);

    return endBitPosition;
}

bool DebugStringParamObject::operator==(const DebugStringParamObject& other) const
{
    if (this != &other)
    {
        return
                (getParam() == other.getParam()) &&
                (m_text_ == other.m_text_);
    }

    return true;
}

uint32_t DebugStringParamObject::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, getParam());
    result = ::zserio::calcHashCode(result, m_text_);

    return result;
}

void DebugStringParamObject::write(::zserio::BitStreamWriter& out) const
{
    out.writeString(m_text_);
}

void DebugStringParamObject::write(::zserio::PackingContextNode&, ::zserio::BitStreamWriter& out) const
{
    out.writeString(m_text_);
}

::zserio::string<> DebugStringParamObject::readText(::zserio::BitStreamReader& in,
        const allocator_type& allocator)
{
    return static_cast<::zserio::string<>>(in.readString(allocator));
}

} // namespace std_allocator
} // namespace test_object