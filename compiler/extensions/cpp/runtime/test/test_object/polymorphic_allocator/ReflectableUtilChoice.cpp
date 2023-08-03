/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorhpicAllocator.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>
#include <zserio/TypeInfo.h>
#include <zserio/pmr/Reflectable.h>

#include <test_object/polymorphic_allocator/ReflectableUtilChoice.h>

namespace test_object
{
namespace polymorphic_allocator
{

ReflectableUtilChoice::ReflectableUtilChoice(const allocator_type& allocator) noexcept :
        m_isInitialized(false),
        m_objectChoice(allocator)
{
}

ReflectableUtilChoice::ReflectableUtilChoice(::zserio::BitStreamReader& in,
        uint8_t param_, const allocator_type& allocator) :
        m_param_(param_),
        m_isInitialized(true),
        m_objectChoice(readObject(in, allocator), allocator)
{
}

ReflectableUtilChoice::ReflectableUtilChoice(ReflectableUtilChoice::ZserioPackingContext& context, ::zserio::BitStreamReader& in,
        uint8_t param_, const allocator_type& allocator) :
        m_param_(param_),
        m_isInitialized(true),
        m_objectChoice(readObject(context, in, allocator), allocator)
{
}

ReflectableUtilChoice::ReflectableUtilChoice(const ReflectableUtilChoice& other) :
        m_objectChoice(other.m_objectChoice)
{
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;
}

ReflectableUtilChoice& ReflectableUtilChoice::operator=(const ReflectableUtilChoice& other)
{
    m_objectChoice = other.m_objectChoice;
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;

    return *this;
}

ReflectableUtilChoice::ReflectableUtilChoice(ReflectableUtilChoice&& other) :
        m_objectChoice(::std::move(other.m_objectChoice))
{
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;
}

ReflectableUtilChoice& ReflectableUtilChoice::operator=(ReflectableUtilChoice&& other)
{
    m_objectChoice = ::std::move(other.m_objectChoice);
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;

    return *this;
}

ReflectableUtilChoice::ReflectableUtilChoice(::zserio::PropagateAllocatorT,
        const ReflectableUtilChoice& other, const allocator_type& allocator) :
        m_objectChoice(other.copyObject(allocator))
{
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;
}

const ::zserio::pmr::ITypeInfo& ReflectableUtilChoice::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 1> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("array"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getUInt32(), // typeInfo
            {}, // typeArguments
            false, // isExtended
            {}, // alignment
            {}, // offset
            {}, // initializer
            false, // isOptional
            {}, // optionalClause
            {}, // constraint
            true, // isArray
            {}, // arrayLength
            false, // isPacked
            false // isImplicit
        }
    };

    static const ::std::array<::zserio::BasicParameterInfo<allocator_type>, 1> parameters = {
        ::zserio::BasicParameterInfo<allocator_type>{
            ::zserio::makeStringView("param"),
            ::zserio::BuiltinTypeInfo<allocator_type>::getUInt8()
        }
    };

    static const ::zserio::Span<::zserio::BasicFunctionInfo<allocator_type>> functions;

    static const std::array<::zserio::StringView, 2> case0Expressions = {
        ::zserio::makeStringView("1"),
        ::zserio::makeStringView("2")
    };
    static const ::std::array<::zserio::BasicCaseInfo<allocator_type>, 2> cases = {
        ::zserio::BasicCaseInfo<allocator_type>{
            case0Expressions,
            &fields[0]
        },
        ::zserio::BasicCaseInfo<allocator_type>{
            {}, nullptr
        }
    };

    static const ::zserio::ChoiceTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.polymorphic_allocator.ReflectableUtilChoice"),
        [](const allocator_type& allocator) -> ::zserio::pmr::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<ReflectableUtilChoice>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions, ::zserio::makeStringView("getParam()"), cases
    };

    return typeInfo;
}

::zserio::pmr::IReflectableConstPtr ReflectableUtilChoice::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::polymorphic_allocator::ReflectableUtilChoice& object, const allocator_type& allocator) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::ReflectableUtilChoice::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("array"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32Array(m_object.getArray(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilChoice'!";
        }

        ::zserio::pmr::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'ReflectableUtilChoice'!";
        }

        ::zserio::StringView getChoice() const override
        {
            switch (m_object.getParam())
            {
            case 1:
            case 2:
                return ::zserio::makeStringView("array");
            default:
                return {};
            }
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::pmr::AnyHolder(::std::cref(m_object), allocator);
        }

    private:
        const ::test_object::polymorphic_allocator::ReflectableUtilChoice& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::pmr::IReflectablePtr ReflectableUtilChoice::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::polymorphic_allocator::ReflectableUtilChoice& object, const allocator_type& allocator) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::ReflectableUtilChoice::typeInfo(), allocator),
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
                throw ::zserio::CppRuntimeException("Not enough arguments to ReflectableUtilChoice::initialize, ") <<
                        "expecting 1, got " << typeArguments.size();
            }

            m_object.initialize(
                typeArguments[0].get<uint8_t>()
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
            if (name == ::zserio::makeStringView("array"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32Array(m_object.getArray(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilChoice'!";
        }

        ::zserio::pmr::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("array"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32Array(m_object.getArray(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilChoice'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("array"))
            {
                m_object.setArray(value.get<::zserio::pmr::vector<uint32_t>>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilChoice'!";
        }

        ::zserio::pmr::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("array"))
            {
                m_object.setArray(::zserio::pmr::vector<uint32_t>(get_allocator()));
                return ::zserio::pmr::ReflectableFactory::getUInt32Array(m_object.getArray(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilChoice'!";
        }

        ::zserio::pmr::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'ReflectableUtilChoice'!";
        }

        ::zserio::pmr::IReflectablePtr getParameter(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'ReflectableUtilChoice'!";
        }

        ::zserio::StringView getChoice() const override
        {
            switch (m_object.getParam())
            {
            case 1:
            case 2:
                return ::zserio::makeStringView("array");
            default:
                return {};
            }
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
        ::test_object::polymorphic_allocator::ReflectableUtilChoice& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void ReflectableUtilChoice::initialize(
        uint8_t param_)
{
    m_param_ = param_;
    m_isInitialized = true;
}

bool ReflectableUtilChoice::isInitialized() const
{
    return m_isInitialized;
}

uint8_t ReflectableUtilChoice::getParam() const
{
    if (!m_isInitialized)
        throw ::zserio::CppRuntimeException("Parameter 'param' of compound 'ReflectableUtilChoice' is not initialized!");

    return m_param_;
}

::zserio::pmr::vector<uint32_t>& ReflectableUtilChoice::getArray()
{
    return m_objectChoice.get<ZserioArrayType_array>().getRawArray();
}

const ::zserio::pmr::vector<uint32_t>& ReflectableUtilChoice::getArray() const
{
    return m_objectChoice.get<ZserioArrayType_array>().getRawArray();
}

void ReflectableUtilChoice::setArray(const ::zserio::pmr::vector<uint32_t>& array_)
{
    m_objectChoice = ZserioArrayType_array(array_);
}

void ReflectableUtilChoice::setArray(::zserio::pmr::vector<uint32_t>&& array_)
{
    m_objectChoice = ZserioArrayType_array(std::move(array_));
}

ReflectableUtilChoice::ChoiceTag ReflectableUtilChoice::choiceTag() const
{
    switch (getParam())
    {
    case 1:
    case 2:
        return CHOICE_array;
    default:
        return UNDEFINED_CHOICE;
    }
}

void ReflectableUtilChoice::initPackingContext(ReflectableUtilChoice::ZserioPackingContext& context) const
{
    switch (getParam())
    {
    case 1:
    case 2:
        break;
    default:
        // empty
        break;
    }
}

size_t ReflectableUtilChoice::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    switch (getParam())
    {
    case 1:
    case 2:
        endBitPosition += m_objectChoice.get<ZserioArrayType_array>().bitSizeOf(endBitPosition);
        break;
    default:
        // empty
        break;
    }

    return endBitPosition - bitPosition;
}

size_t ReflectableUtilChoice::bitSizeOf(ReflectableUtilChoice::ZserioPackingContext& context, size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    switch (getParam())
    {
    case 1:
    case 2:
        endBitPosition += m_objectChoice.get<ZserioArrayType_array>().bitSizeOfPacked(endBitPosition);
        break;
    default:
        // empty
        break;
    }

    return endBitPosition - bitPosition;
}

size_t ReflectableUtilChoice::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    switch (getParam())
    {
    case 1:
    case 2:
        endBitPosition = m_objectChoice.get<ZserioArrayType_array>().initializeOffsets(endBitPosition);
        break;
    default:
        // empty
        break;
    }

    return endBitPosition;
}

size_t ReflectableUtilChoice::initializeOffsets(ReflectableUtilChoice::ZserioPackingContext& context, size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    switch (getParam())
    {
    case 1:
    case 2:
        endBitPosition = m_objectChoice.get<ZserioArrayType_array>().initializeOffsetsPacked(endBitPosition);
        break;
    default:
        // empty
        break;
    }

    return endBitPosition;
}

bool ReflectableUtilChoice::operator==(const ReflectableUtilChoice& other) const
{
    if (this == &other)
        return true;

    if (!(getParam() == other.getParam()))
        return false;

    switch (getParam())
    {
    case 1:
    case 2:
        return (!m_objectChoice.hasValue() && !other.m_objectChoice.hasValue()) ||
                (m_objectChoice.hasValue() && other.m_objectChoice.hasValue() &&
                m_objectChoice.get<ZserioArrayType_array>() == other.m_objectChoice.get<ZserioArrayType_array>());
    default:
        return true; // empty
    }
}

uint32_t ReflectableUtilChoice::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, getParam());
    if (m_objectChoice.hasValue())
    {
        switch (getParam())
        {
        case 1:
        case 2:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<ZserioArrayType_array>());
            break;
        default:
            // empty
            break;
        }
    }

    return result;
}

void ReflectableUtilChoice::write(::zserio::BitStreamWriter& out) const
{
    switch (getParam())
    {
    case 1:
    case 2:
        m_objectChoice.get<ZserioArrayType_array>().write(out);
        break;
    default:
        // empty
        break;
    }
}

void ReflectableUtilChoice::write(ReflectableUtilChoice::ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const
{
    switch (getParam())
    {
    case 1:
    case 2:
        m_objectChoice.get<ZserioArrayType_array>().writePacked(out);
        break;
    default:
        // empty
        break;
    }
}

::zserio::pmr::AnyHolder ReflectableUtilChoice::readObject(::zserio::BitStreamReader& in, const allocator_type& allocator)
{
    switch (getParam())
    {
    case 1:
    case 2:
        {
            ZserioArrayType_array readField(allocator);
            readField.read(in);

            return ::zserio::pmr::AnyHolder(::std::move(readField), allocator);
        }
    default:
        return ::zserio::pmr::AnyHolder(allocator);
    }
}

::zserio::pmr::AnyHolder ReflectableUtilChoice::readObject(ReflectableUtilChoice::ZserioPackingContext& context,
        ::zserio::BitStreamReader& in, const allocator_type& allocator)
{
    switch (getParam())
    {
    case 1:
    case 2:
        {
            ZserioArrayType_array readField(allocator);
            readField.readPacked(in);

            return ::zserio::pmr::AnyHolder(::std::move(readField), allocator);
        }
    default:
        return ::zserio::pmr::AnyHolder(allocator);
    }
}

::zserio::pmr::AnyHolder ReflectableUtilChoice::copyObject(const allocator_type& allocator) const
{
    switch (getParam())
    {
    case 1:
    case 2:
        return ::zserio::allocatorPropagatingCopy<ZserioArrayType_array>(m_objectChoice, allocator);
    default:
        return ::zserio::pmr::AnyHolder(allocator);
    }
}

} // namespace polymorphic_allocator
} // namespace test_object
