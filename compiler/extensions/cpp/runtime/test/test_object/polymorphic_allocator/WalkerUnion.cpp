/**
 * Automatically generated by Zserio C++ extension version 2.12.0.
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

#include <test_object/polymorphic_allocator/WalkerUnion.h>

namespace test_object
{
namespace polymorphic_allocator
{

WalkerUnion::WalkerUnion(const allocator_type& allocator) noexcept :
        m_choiceTag(UNDEFINED_CHOICE),
        m_objectChoice(allocator)
{
}

WalkerUnion::WalkerUnion(::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_choiceTag(readChoiceTag(in)),
        m_objectChoice(readObject(in, allocator))
{
}

WalkerUnion::WalkerUnion(WalkerUnion::ZserioPackingContext& context, ::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_choiceTag(readChoiceTag(context, in)),
        m_objectChoice(readObject(context, in, allocator))
{
}

WalkerUnion::WalkerUnion(::zserio::PropagateAllocatorT,
        const WalkerUnion& other, const allocator_type& allocator) :
        m_choiceTag(other.m_choiceTag),
        m_objectChoice(::zserio::NoInit, other.copyObject(allocator))
{
}

const ::zserio::pmr::ITypeInfo& WalkerUnion::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 3> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("value"), // schemaName
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
        },
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("nestedArray"), // schemaName
            ::test_object::polymorphic_allocator::WalkerNested::typeInfo(), // typeInfo
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

    static const ::zserio::Span<::zserio::BasicParameterInfo<allocator_type>> parameters;

    static const ::zserio::Span<::zserio::BasicFunctionInfo<allocator_type>> functions;

    static const ::zserio::UnionTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.polymorphic_allocator.WalkerUnion"),
        [](const allocator_type& allocator) -> ::zserio::pmr::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<WalkerUnion>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::pmr::IReflectableConstPtr WalkerUnion::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::polymorphic_allocator::WalkerUnion& object, const allocator_type& allocator) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::WalkerUnion::typeInfo(), allocator),
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
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getValue(), get_allocator());
            }
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            if (name == ::zserio::makeStringView("nestedArray"))
            {
                return ::zserio::pmr::ReflectableFactory::getCompoundArray(m_object.getNestedArray(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerUnion'!";
        }

        ::zserio::StringView getChoice() const override
        {
            switch (m_object.choiceTag())
            {
            case CHOICE_value:
                return ::zserio::makeStringView("value");
            case CHOICE_text:
                return ::zserio::makeStringView("text");
            case CHOICE_nestedArray:
                return ::zserio::makeStringView("nestedArray");
            default:
                return {};
            }
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::pmr::AnyHolder(::std::cref(m_object), allocator);
        }

    private:
        const ::test_object::polymorphic_allocator::WalkerUnion& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::pmr::IReflectablePtr WalkerUnion::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::polymorphic_allocator::WalkerUnion& object, const allocator_type& allocator) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::WalkerUnion::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("value"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getValue(), get_allocator());
            }
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            if (name == ::zserio::makeStringView("nestedArray"))
            {
                return ::zserio::pmr::ReflectableFactory::getCompoundArray(m_object.getNestedArray(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerUnion'!";
        }

        ::zserio::pmr::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getValue(), get_allocator());
            }
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            if (name == ::zserio::makeStringView("nestedArray"))
            {
                return ::zserio::pmr::ReflectableFactory::getCompoundArray(m_object.getNestedArray(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerUnion'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                m_object.setValue(value.get<uint32_t>());
                return;
            }
            if (name == ::zserio::makeStringView("text"))
            {
                m_object.setText(value.get<::zserio::pmr::string>());
                return;
            }
            if (name == ::zserio::makeStringView("nestedArray"))
            {
                m_object.setNestedArray(value.get<::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerUnion'!";
        }

        ::zserio::pmr::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("value"))
            {
                m_object.setValue(uint32_t());
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getValue(), get_allocator());
            }
            if (name == ::zserio::makeStringView("text"))
            {
                m_object.setText(::zserio::pmr::string(get_allocator()));
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            if (name == ::zserio::makeStringView("nestedArray"))
            {
                m_object.setNestedArray(::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>(get_allocator()));
                return ::zserio::pmr::ReflectableFactory::getCompoundArray(m_object.getNestedArray(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'WalkerUnion'!";
        }

        ::zserio::StringView getChoice() const override
        {
            switch (m_object.choiceTag())
            {
            case CHOICE_value:
                return ::zserio::makeStringView("value");
            case CHOICE_text:
                return ::zserio::makeStringView("text");
            case CHOICE_nestedArray:
                return ::zserio::makeStringView("nestedArray");
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
        ::test_object::polymorphic_allocator::WalkerUnion& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

uint32_t WalkerUnion::getValue() const
{
    return m_objectChoice.get<uint32_t>();
}

void WalkerUnion::setValue(uint32_t value_)
{
    m_choiceTag = CHOICE_value;
    m_objectChoice = value_;
}

::zserio::pmr::string& WalkerUnion::getText()
{
    return m_objectChoice.get<::zserio::pmr::string>();
}

const ::zserio::pmr::string& WalkerUnion::getText() const
{
    return m_objectChoice.get<::zserio::pmr::string>();
}

void WalkerUnion::setText(const ::zserio::pmr::string& text_)
{
    m_choiceTag = CHOICE_text;
    m_objectChoice = text_;
}

void WalkerUnion::setText(::zserio::pmr::string&& text_)
{
    m_choiceTag = CHOICE_text;
    m_objectChoice = ::std::move(text_);
}

::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>& WalkerUnion::getNestedArray()
{
    return m_objectChoice.get<ZserioArrayType_nestedArray>().getRawArray();
}

const ::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>& WalkerUnion::getNestedArray() const
{
    return m_objectChoice.get<ZserioArrayType_nestedArray>().getRawArray();
}

void WalkerUnion::setNestedArray(const ::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>& nestedArray_)
{
    m_choiceTag = CHOICE_nestedArray;
    m_objectChoice = ZserioArrayType_nestedArray(nestedArray_);
}

void WalkerUnion::setNestedArray(::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>&& nestedArray_)
{
    m_choiceTag = CHOICE_nestedArray;
    m_objectChoice = ZserioArrayType_nestedArray(std::move(nestedArray_));
}

WalkerUnion::ChoiceTag WalkerUnion::choiceTag() const
{
    return m_choiceTag;
}

void WalkerUnion::initPackingContext(WalkerUnion::ZserioPackingContext& context) const
{
    context.getChoiceTag().init<::zserio::VarSizeArrayTraits>(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_value:
        context.getValue().init<::zserio::StdIntArrayTraits<uint32_t>>(m_objectChoice.get<uint32_t>());
        break;
    case CHOICE_text:
        break;
    case CHOICE_nestedArray:
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union WalkerUnion!");
    }
}

size_t WalkerUnion::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfVarSize(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_value:
        endBitPosition += UINT8_C(32);
        break;
    case CHOICE_text:
        endBitPosition += ::zserio::bitSizeOfString(m_objectChoice.get<::zserio::pmr::string>());
        break;
    case CHOICE_nestedArray:
        endBitPosition += m_objectChoice.get<ZserioArrayType_nestedArray>().bitSizeOf(*this, endBitPosition);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union WalkerUnion!");
    }

    return endBitPosition - bitPosition;
}

size_t WalkerUnion::bitSizeOf(WalkerUnion::ZserioPackingContext& context, size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += context.getChoiceTag().bitSizeOf<::zserio::VarSizeArrayTraits>(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_value:
        endBitPosition += context.getValue().bitSizeOf<::zserio::StdIntArrayTraits<uint32_t>>(m_objectChoice.get<uint32_t>());
        break;
    case CHOICE_text:
        endBitPosition += ::zserio::bitSizeOfString(m_objectChoice.get<::zserio::pmr::string>());
        break;
    case CHOICE_nestedArray:
        endBitPosition += m_objectChoice.get<ZserioArrayType_nestedArray>().bitSizeOf(*this, endBitPosition);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union WalkerUnion!");
    }

    return endBitPosition - bitPosition;
}

size_t WalkerUnion::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfVarSize(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_value:
        endBitPosition += UINT8_C(32);
        break;
    case CHOICE_text:
        endBitPosition += ::zserio::bitSizeOfString(m_objectChoice.get<::zserio::pmr::string>());
        break;
    case CHOICE_nestedArray:
        endBitPosition = m_objectChoice.get<ZserioArrayType_nestedArray>().initializeOffsets(*this, endBitPosition);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union WalkerUnion!");
    }

    return endBitPosition;
}

size_t WalkerUnion::initializeOffsets(WalkerUnion::ZserioPackingContext& context, size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += context.getChoiceTag().bitSizeOf<::zserio::VarSizeArrayTraits>(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_value:
        endBitPosition += context.getValue().bitSizeOf<::zserio::StdIntArrayTraits<uint32_t>>(m_objectChoice.get<uint32_t>());
        break;
    case CHOICE_text:
        endBitPosition += ::zserio::bitSizeOfString(m_objectChoice.get<::zserio::pmr::string>());
        break;
    case CHOICE_nestedArray:
        endBitPosition = m_objectChoice.get<ZserioArrayType_nestedArray>().initializeOffsets(*this, endBitPosition);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union WalkerUnion!");
    }

    return endBitPosition;
}

bool WalkerUnion::operator==(const WalkerUnion& other) const
{
    if (this == &other)
        return true;

    if (m_choiceTag != other.m_choiceTag)
        return false;

    if (m_objectChoice.hasValue() != other.m_objectChoice.hasValue())
        return false;

    if (!m_objectChoice.hasValue())
        return true;

    switch (m_choiceTag)
    {
    case CHOICE_value:
        return m_objectChoice.get<uint32_t>() == other.m_objectChoice.get<uint32_t>();
    case CHOICE_text:
        return m_objectChoice.get<::zserio::pmr::string>() == other.m_objectChoice.get<::zserio::pmr::string>();
    case CHOICE_nestedArray:
        return m_objectChoice.get<ZserioArrayType_nestedArray>() == other.m_objectChoice.get<ZserioArrayType_nestedArray>();
    default:
        return true; // UNDEFINED_CHOICE
    }
}

uint32_t WalkerUnion::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, static_cast<int32_t>(m_choiceTag));
    if (m_objectChoice.hasValue())
    {
        switch (m_choiceTag)
        {
        case CHOICE_value:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<uint32_t>());
            break;
        case CHOICE_text:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<::zserio::pmr::string>());
            break;
        case CHOICE_nestedArray:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<ZserioArrayType_nestedArray>());
            break;
        default:
            // UNDEFINED_CHOICE
            break;
        }
    }

    return result;
}

void WalkerUnion::write(::zserio::BitStreamWriter& out) const
{
    out.writeVarSize(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_value:
        out.writeBits(m_objectChoice.get<uint32_t>(), UINT8_C(32));
        break;
    case CHOICE_text:
        out.writeString(m_objectChoice.get<::zserio::pmr::string>());
        break;
    case CHOICE_nestedArray:
        m_objectChoice.get<ZserioArrayType_nestedArray>().write(*this, out);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union WalkerUnion!");
    }
}

void WalkerUnion::write(WalkerUnion::ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const
{
    context.getChoiceTag().write<::zserio::VarSizeArrayTraits>(out, static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_value:
        context.getValue().write<::zserio::StdIntArrayTraits<uint32_t>>(out, m_objectChoice.get<uint32_t>());
        break;
    case CHOICE_text:
        out.writeString(m_objectChoice.get<::zserio::pmr::string>());
        break;
    case CHOICE_nestedArray:
        m_objectChoice.get<ZserioArrayType_nestedArray>().write(*this, out);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union WalkerUnion!");
    }
}

void WalkerUnion::ZserioElementFactory_nestedArray::create(WalkerUnion&        ,
        ::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>& array,
        ::zserio::BitStreamReader& in, size_t)
{
    array.emplace_back(in, array.get_allocator());
}

WalkerUnion::ChoiceTag WalkerUnion::readChoiceTag(::zserio::BitStreamReader& in)
{
    return static_cast<WalkerUnion::ChoiceTag>(static_cast<int32_t>(in.readVarSize()));
}

WalkerUnion::ChoiceTag WalkerUnion::readChoiceTag(WalkerUnion::ZserioPackingContext& context, ::zserio::BitStreamReader& in)
{
    return static_cast<WalkerUnion::ChoiceTag>(static_cast<int32_t>(context.getChoiceTag().read<::zserio::VarSizeArrayTraits>(in)));
}

::zserio::pmr::AnyHolder WalkerUnion::readObject(::zserio::BitStreamReader& in, const allocator_type& allocator)
{
    switch (m_choiceTag)
    {
    case CHOICE_value:
        return ::zserio::pmr::AnyHolder(static_cast<uint32_t>(in.readBits(UINT8_C(32))), allocator);
    case CHOICE_text:
        return ::zserio::pmr::AnyHolder(static_cast<::zserio::pmr::string>(in.readString(allocator)), allocator);
    case CHOICE_nestedArray:
        {
            ZserioArrayType_nestedArray readField(allocator);
            readField.read(*this, in);

            return ::zserio::pmr::AnyHolder(::std::move(readField), allocator);
        }
    default:
        throw ::zserio::CppRuntimeException("No match in union WalkerUnion!");
    }
}

::zserio::pmr::AnyHolder WalkerUnion::readObject(WalkerUnion::ZserioPackingContext& context,
        ::zserio::BitStreamReader& in, const allocator_type& allocator)
{
    switch (m_choiceTag)
    {
    case CHOICE_value:
        return ::zserio::pmr::AnyHolder(context.getValue().read<::zserio::StdIntArrayTraits<uint32_t>>(in), allocator);
    case CHOICE_text:
        return ::zserio::pmr::AnyHolder(static_cast<::zserio::pmr::string>(in.readString(allocator)), allocator);
    case CHOICE_nestedArray:
        {
            ZserioArrayType_nestedArray readField(allocator);
            readField.read(*this, in);

            return ::zserio::pmr::AnyHolder(::std::move(readField), allocator);
        }
    default:
        throw ::zserio::CppRuntimeException("No match in union WalkerUnion!");
    }
}

::zserio::pmr::AnyHolder WalkerUnion::copyObject(const allocator_type& allocator) const
{
    switch (m_choiceTag)
    {
    case CHOICE_value:
        return ::zserio::allocatorPropagatingCopy<uint32_t>(m_objectChoice, allocator);
    case CHOICE_text:
        return ::zserio::allocatorPropagatingCopy<::zserio::pmr::string>(m_objectChoice, allocator);
    case CHOICE_nestedArray:
        return ::zserio::allocatorPropagatingCopy<ZserioArrayType_nestedArray>(m_objectChoice, allocator);
    default:
        return ::zserio::pmr::AnyHolder(allocator);
    }
}

} // namespace polymorphic_allocator
} // namespace test_object
