/**
 * Automatically generated by Zserio C++ generator version 1.0.2 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorphicAllocator.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>
#include <zserio/TypeInfo.h>
#include <zserio/pmr/Reflectable.h>

#include <test_object/polymorphic_allocator/WalkerChoice.h>

namespace test_object
{
namespace polymorphic_allocator
{

WalkerChoice::WalkerChoice(const allocator_type& allocator) noexcept :
        m_isInitialized(false),
        m_objectChoice(allocator)
{
}

WalkerChoice::WalkerChoice(::zserio::BitStreamReader& in,
        uint8_t selector_, const allocator_type& allocator) :
        m_selector_(selector_),
        m_isInitialized(true),
        m_objectChoice(readObject(in, allocator), allocator)
{
}

WalkerChoice::WalkerChoice(const WalkerChoice& other) :
        m_objectChoice(::zserio::NoInit, other.m_objectChoice)
{
    if (other.m_isInitialized)
    {
        initialize(other.m_selector_);
    }
    else
    {
        m_isInitialized = false;
    }
}

WalkerChoice& WalkerChoice::operator=(const WalkerChoice& other)
{
    (void)m_objectChoice.assign(::zserio::NoInit, other.m_objectChoice);
    if (other.m_isInitialized)
    {
        initialize(other.m_selector_);
    }
    else
    {
        m_isInitialized = false;
    }

    return *this;
}

WalkerChoice::WalkerChoice(WalkerChoice&& other) :
        m_objectChoice(::zserio::NoInit, ::std::move(other.m_objectChoice))
{
    if (other.m_isInitialized)
    {
        initialize(other.m_selector_);
    }
    else
    {
        m_isInitialized = false;
    }
}

WalkerChoice& WalkerChoice::operator=(WalkerChoice&& other)
{
    (void)m_objectChoice.assign(::zserio::NoInit, ::std::move(other.m_objectChoice));
    if (other.m_isInitialized)
    {
        initialize(other.m_selector_);
    }
    else
    {
        m_isInitialized = false;
    }

    return *this;
}

WalkerChoice::WalkerChoice(::zserio::NoInitT,
        const WalkerChoice& other) :
        m_isInitialized(false),
        m_objectChoice(::zserio::NoInit, other.m_objectChoice)
{
}

WalkerChoice& WalkerChoice::assign(::zserio::NoInitT,
        const WalkerChoice& other)
{
    m_isInitialized = false;
    (void)m_objectChoice.assign(::zserio::NoInit, other.m_objectChoice);

    return *this;
}

WalkerChoice::WalkerChoice(::zserio::NoInitT,
        WalkerChoice&& other) :
        m_isInitialized(false),
        m_objectChoice(::zserio::NoInit, ::std::move(other.m_objectChoice))
{
}

WalkerChoice& WalkerChoice::assign(::zserio::NoInitT,
        WalkerChoice&& other)
{
    m_isInitialized = false;
    (void)m_objectChoice.assign(::zserio::NoInit, ::std::move(other.m_objectChoice));

    return *this;
}

WalkerChoice::WalkerChoice(::zserio::PropagateAllocatorT,
        const WalkerChoice& other, const allocator_type& allocator) :
        m_objectChoice(::zserio::NoInit, other.copyObject(allocator))
{
    if (other.m_isInitialized)
    {
        initialize(other.m_selector_);
    }
    else
    {
        m_isInitialized = false;
    }
}

WalkerChoice::WalkerChoice(::zserio::PropagateAllocatorT, ::zserio::NoInitT,
        const WalkerChoice& other, const allocator_type& allocator) :
        m_isInitialized(false),
        m_objectChoice(::zserio::NoInit, other.copyObject(allocator))
{
}

const ::zserio::pmr::ITypeInfo& WalkerChoice::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 4> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("value8"), // schemaName
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
            ::zserio::makeStringView("value16"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getUInt16(), // typeInfo
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
            ::zserio::makeStringView("value32"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getUInt32(), // typeInfo
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
            ::zserio::makeStringView("value64"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getUInt64(), // typeInfo
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

    static const ::std::array<::zserio::BasicParameterInfo<allocator_type>, 1> parameters = {
        ::zserio::BasicParameterInfo<allocator_type>{
            ::zserio::makeStringView("selector"),
            ::zserio::BuiltinTypeInfo<allocator_type>::getUInt8()
        }
    };

    static const ::zserio::Span<::zserio::BasicFunctionInfo<allocator_type>> functions;

    static const std::array<::zserio::StringView, 1> case0Expressions = {
        ::zserio::makeStringView("8")
    };
    static const std::array<::zserio::StringView, 1> case1Expressions = {
        ::zserio::makeStringView("16")
    };
    static const std::array<::zserio::StringView, 1> case2Expressions = {
        ::zserio::makeStringView("32")
    };
    static const std::array<::zserio::StringView, 1> case3Expressions = {
        ::zserio::makeStringView("64")
    };
    static const ::std::array<::zserio::BasicCaseInfo<allocator_type>, 5> cases = {
        ::zserio::BasicCaseInfo<allocator_type>{
            case0Expressions,
            &fields[0]
        },
        ::zserio::BasicCaseInfo<allocator_type>{
            case1Expressions,
            &fields[1]
        },
        ::zserio::BasicCaseInfo<allocator_type>{
            case2Expressions,
            &fields[2]
        },
        ::zserio::BasicCaseInfo<allocator_type>{
            case3Expressions,
            &fields[3]
        },
        ::zserio::BasicCaseInfo<allocator_type>{
            {}, nullptr
        }
    };

    static const ::zserio::ChoiceTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.polymorphic_allocator.WalkerChoice"),
        [](const allocator_type& allocator) -> ::zserio::pmr::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<WalkerChoice>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions, ::zserio::makeStringView("getSelector()"), cases
    };

    return typeInfo;
}

::zserio::pmr::IReflectableConstPtr WalkerChoice::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::polymorphic_allocator::WalkerChoice& object, const allocator_type& alloc) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::WalkerChoice::typeInfo(), alloc),
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
            if (name == ::zserio::makeStringView("value8"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getValue8(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value16"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt16(m_object.getValue16(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value32"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getValue32(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value64"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt64(m_object.getValue64(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerChoice'!";
        }

        ::zserio::pmr::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("selector"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getSelector(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'WalkerChoice'!";
        }

        ::zserio::StringView getChoice() const override
        {
            switch (m_object.getSelector())
            {
            case 8:
                return ::zserio::makeStringView("value8");
            case 16:
                return ::zserio::makeStringView("value16");
            case 32:
                return ::zserio::makeStringView("value32");
            case 64:
                return ::zserio::makeStringView("value64");
            default:
                return {};
            }
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& alloc) const override
        {
            return ::zserio::pmr::AnyHolder(::std::cref(m_object), alloc);
        }

    private:
        const ::test_object::polymorphic_allocator::WalkerChoice& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::pmr::IReflectablePtr WalkerChoice::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::polymorphic_allocator::WalkerChoice& object, const allocator_type& alloc) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::WalkerChoice::typeInfo(), alloc),
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
                throw ::zserio::CppRuntimeException("Not enough arguments to WalkerChoice::initialize, ") <<
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
            if (name == ::zserio::makeStringView("value8"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getValue8(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value16"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt16(m_object.getValue16(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value32"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getValue32(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value64"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt64(m_object.getValue64(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerChoice'!";
        }

        ::zserio::pmr::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("value8"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getValue8(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value16"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt16(m_object.getValue16(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value32"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getValue32(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value64"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt64(m_object.getValue64(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerChoice'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("value8"))
            {
                m_object.setValue8(value.get<uint8_t>());
                return;
            }
            if (name == ::zserio::makeStringView("value16"))
            {
                m_object.setValue16(value.get<uint16_t>());
                return;
            }
            if (name == ::zserio::makeStringView("value32"))
            {
                m_object.setValue32(value.get<uint32_t>());
                return;
            }
            if (name == ::zserio::makeStringView("value64"))
            {
                m_object.setValue64(value.get<uint64_t>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerChoice'!";
        }

        ::zserio::pmr::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("value8"))
            {
                m_object.setValue8(uint8_t());
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getValue8(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value16"))
            {
                m_object.setValue16(uint16_t());
                return ::zserio::pmr::ReflectableFactory::getUInt16(m_object.getValue16(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value32"))
            {
                m_object.setValue32(uint32_t());
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getValue32(), get_allocator());
            }
            if (name == ::zserio::makeStringView("value64"))
            {
                m_object.setValue64(uint64_t());
                return ::zserio::pmr::ReflectableFactory::getUInt64(m_object.getValue64(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerChoice'!";
        }

        ::zserio::pmr::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("selector"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getSelector(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'WalkerChoice'!";
        }

        ::zserio::pmr::IReflectablePtr getParameter(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("selector"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt8(m_object.getSelector(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'WalkerChoice'!";
        }

        ::zserio::StringView getChoice() const override
        {
            switch (m_object.getSelector())
            {
            case 8:
                return ::zserio::makeStringView("value8");
            case 16:
                return ::zserio::makeStringView("value16");
            case 32:
                return ::zserio::makeStringView("value32");
            case 64:
                return ::zserio::makeStringView("value64");
            default:
                return {};
            }
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& alloc) const override
        {
            return ::zserio::pmr::AnyHolder(::std::cref(m_object), alloc);
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& alloc) override
        {
            return ::zserio::pmr::AnyHolder(::std::ref(m_object), alloc);
        }

    private:
        ::test_object::polymorphic_allocator::WalkerChoice& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void WalkerChoice::initialize(
        uint8_t selector_)
{
    m_selector_ = selector_;
    m_isInitialized = true;
}

bool WalkerChoice::isInitialized() const
{
    return m_isInitialized;
}

uint8_t WalkerChoice::getSelector() const
{
    if (!m_isInitialized)
    {
        throw ::zserio::CppRuntimeException("Parameter 'selector' of compound 'WalkerChoice' is not initialized!");
    }

    return m_selector_;
}

uint8_t WalkerChoice::getValue8() const
{
    return m_objectChoice.get<uint8_t>();
}

void WalkerChoice::setValue8(uint8_t value8_)
{
    m_objectChoice = value8_;
}

uint16_t WalkerChoice::getValue16() const
{
    return m_objectChoice.get<uint16_t>();
}

void WalkerChoice::setValue16(uint16_t value16_)
{
    m_objectChoice = value16_;
}

uint32_t WalkerChoice::getValue32() const
{
    return m_objectChoice.get<uint32_t>();
}

void WalkerChoice::setValue32(uint32_t value32_)
{
    m_objectChoice = value32_;
}

uint64_t WalkerChoice::getValue64() const
{
    return m_objectChoice.get<uint64_t>();
}

void WalkerChoice::setValue64(uint64_t value64_)
{
    m_objectChoice = value64_;
}

WalkerChoice::ChoiceTag WalkerChoice::choiceTag() const
{
    switch (getSelector())
    {
    case 8:
        return CHOICE_value8;
    case 16:
        return CHOICE_value16;
    case 32:
        return CHOICE_value32;
    case 64:
        return CHOICE_value64;
    default:
        return UNDEFINED_CHOICE;
    }
}

size_t WalkerChoice::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    switch (getSelector())
    {
    case 8:
        endBitPosition += UINT8_C(8);
        break;
    case 16:
        endBitPosition += UINT8_C(16);
        break;
    case 32:
        endBitPosition += UINT8_C(32);
        break;
    case 64:
        endBitPosition += UINT8_C(64);
        break;
    default:
        // empty
        break;
    }

    return endBitPosition - bitPosition;
}

size_t WalkerChoice::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    switch (getSelector())
    {
    case 8:
        endBitPosition += UINT8_C(8);
        break;
    case 16:
        endBitPosition += UINT8_C(16);
        break;
    case 32:
        endBitPosition += UINT8_C(32);
        break;
    case 64:
        endBitPosition += UINT8_C(64);
        break;
    default:
        // empty
        break;
    }

    return endBitPosition;
}

bool WalkerChoice::operator==(const WalkerChoice& other) const
{
    if (this == &other)
    {
        return true;
    }

    if (!(getSelector() == other.getSelector()))
    {
        return false;
    }

    switch (getSelector())
    {
    case 8:
        return (!m_objectChoice.hasValue() && !other.m_objectChoice.hasValue()) ||
                (m_objectChoice.hasValue() && other.m_objectChoice.hasValue() &&
                m_objectChoice.get<uint8_t>() == other.m_objectChoice.get<uint8_t>());
    case 16:
        return (!m_objectChoice.hasValue() && !other.m_objectChoice.hasValue()) ||
                (m_objectChoice.hasValue() && other.m_objectChoice.hasValue() &&
                m_objectChoice.get<uint16_t>() == other.m_objectChoice.get<uint16_t>());
    case 32:
        return (!m_objectChoice.hasValue() && !other.m_objectChoice.hasValue()) ||
                (m_objectChoice.hasValue() && other.m_objectChoice.hasValue() &&
                m_objectChoice.get<uint32_t>() == other.m_objectChoice.get<uint32_t>());
    case 64:
        return (!m_objectChoice.hasValue() && !other.m_objectChoice.hasValue()) ||
                (m_objectChoice.hasValue() && other.m_objectChoice.hasValue() &&
                m_objectChoice.get<uint64_t>() == other.m_objectChoice.get<uint64_t>());
    default:
        return true; // empty
    }
}

bool WalkerChoice::operator<(const WalkerChoice& other) const
{
    if (getSelector() < other.getSelector())
    {
        return true;
    }
    if (other.getSelector() < getSelector())
    {
        return false;
    }

    switch (getSelector())
    {
    case 8:
        if (m_objectChoice.hasValue() && other.m_objectChoice.hasValue())
        {
            return m_objectChoice.get<uint8_t>() < other.m_objectChoice.get<uint8_t>();
        }
        else
        {
            return !m_objectChoice.hasValue() && other.m_objectChoice.hasValue();
        }
    case 16:
        if (m_objectChoice.hasValue() && other.m_objectChoice.hasValue())
        {
            return m_objectChoice.get<uint16_t>() < other.m_objectChoice.get<uint16_t>();
        }
        else
        {
            return !m_objectChoice.hasValue() && other.m_objectChoice.hasValue();
        }
    case 32:
        if (m_objectChoice.hasValue() && other.m_objectChoice.hasValue())
        {
            return m_objectChoice.get<uint32_t>() < other.m_objectChoice.get<uint32_t>();
        }
        else
        {
            return !m_objectChoice.hasValue() && other.m_objectChoice.hasValue();
        }
    case 64:
        if (m_objectChoice.hasValue() && other.m_objectChoice.hasValue())
        {
            return m_objectChoice.get<uint64_t>() < other.m_objectChoice.get<uint64_t>();
        }
        else
        {
            return !m_objectChoice.hasValue() && other.m_objectChoice.hasValue();
        }
    default:
        return false;
    }
}

uint32_t WalkerChoice::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, getSelector());
    if (m_objectChoice.hasValue())
    {
        switch (getSelector())
        {
        case 8:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<uint8_t>());
            break;
        case 16:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<uint16_t>());
            break;
        case 32:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<uint32_t>());
            break;
        case 64:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<uint64_t>());
            break;
        default:
            // empty
            break;
        }
    }

    return result;
}

void WalkerChoice::write(::zserio::BitStreamWriter& out) const
{
    switch (getSelector())
    {
    case 8:
        out.writeBits(m_objectChoice.get<uint8_t>(), UINT8_C(8));
        break;
    case 16:
        out.writeBits(m_objectChoice.get<uint16_t>(), UINT8_C(16));
        break;
    case 32:
        out.writeBits(m_objectChoice.get<uint32_t>(), UINT8_C(32));
        break;
    case 64:
        out.writeBits64(m_objectChoice.get<uint64_t>(), UINT8_C(64));
        break;
    default:
        // empty
        break;
    }
}

::zserio::pmr::AnyHolder WalkerChoice::readObject(::zserio::BitStreamReader& in, const allocator_type& allocator)
{
    switch (getSelector())
    {
    case 8:
        return ::zserio::pmr::AnyHolder(static_cast<uint8_t>(in.readBits(UINT8_C(8))), allocator);
    case 16:
        return ::zserio::pmr::AnyHolder(static_cast<uint16_t>(in.readBits(UINT8_C(16))), allocator);
    case 32:
        return ::zserio::pmr::AnyHolder(static_cast<uint32_t>(in.readBits(UINT8_C(32))), allocator);
    case 64:
        return ::zserio::pmr::AnyHolder(static_cast<uint64_t>(in.readBits64(UINT8_C(64))), allocator);
    default:
        return ::zserio::pmr::AnyHolder(allocator);
    }
}

::zserio::pmr::AnyHolder WalkerChoice::copyObject(const allocator_type& allocator) const
{
    switch (getSelector())
    {
    case 8:
        return ::zserio::allocatorPropagatingCopy<uint8_t>(m_objectChoice, allocator);
    case 16:
        return ::zserio::allocatorPropagatingCopy<uint16_t>(m_objectChoice, allocator);
    case 32:
        return ::zserio::allocatorPropagatingCopy<uint32_t>(m_objectChoice, allocator);
    case 64:
        return ::zserio::allocatorPropagatingCopy<uint64_t>(m_objectChoice, allocator);
    default:
        return ::zserio::pmr::AnyHolder(allocator);
    }
}

} // namespace polymorphic_allocator
} // namespace test_object
