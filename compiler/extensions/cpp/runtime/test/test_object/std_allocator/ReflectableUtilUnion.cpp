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
#include <zserio/Reflectable.h>

#include <test_object/std_allocator/ReflectableUtilUnion.h>

namespace test_object
{
namespace std_allocator
{

ReflectableUtilUnion::ReflectableUtilUnion(const allocator_type& allocator) noexcept :
        m_choiceTag(UNDEFINED_CHOICE),
        m_objectChoice(allocator)
{
}

ReflectableUtilUnion::ReflectableUtilUnion(::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_choiceTag(readChoiceTag(in)),
        m_objectChoice(readObject(in, allocator))
{
}

ReflectableUtilUnion::ReflectableUtilUnion(ReflectableUtilUnion::ZserioPackingContext& context, ::zserio::BitStreamReader& in, const allocator_type& allocator) :
        m_choiceTag(readChoiceTag(context, in)),
        m_objectChoice(readObject(context, in, allocator))
{
}

ReflectableUtilUnion::ReflectableUtilUnion(::zserio::PropagateAllocatorT,
        const ReflectableUtilUnion& other, const allocator_type& allocator) :
        m_choiceTag(other.m_choiceTag),
        m_objectChoice(other.copyObject(allocator))
{
}

const ::zserio::ITypeInfo& ReflectableUtilUnion::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 3> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("reflectableUtilEnum"), // schemaName
            ::zserio::enumTypeInfo<::test_object::std_allocator::ReflectableUtilEnum, allocator_type>(), // typeInfo
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
            ::zserio::makeStringView("reflectableUtilBitmask"), // schemaName
            ::test_object::std_allocator::ReflectableUtilBitmask::typeInfo(), // typeInfo
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
            ::zserio::makeStringView("reflectableUtilObject"), // schemaName
            ::test_object::std_allocator::ReflectableUtilObject::typeInfo(), // typeInfo
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

    static const ::zserio::UnionTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.std_allocator.ReflectableUtilUnion"),
        [](const allocator_type& allocator) -> ::zserio::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<ReflectableUtilUnion>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::IReflectableConstPtr ReflectableUtilUnion::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::std_allocator::ReflectableUtilUnion& object, const allocator_type& allocator) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::std_allocator::ReflectableUtilUnion::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("reflectableUtilEnum"))
            {
                return ::zserio::enumReflectable(m_object.getReflectableUtilEnum(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilBitmask"))
            {
                return m_object.getReflectableUtilBitmask().reflectable(get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilObject"))
            {
                return m_object.getReflectableUtilObject().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilUnion'!";
        }

        ::zserio::StringView getChoice() const override
        {
            switch (m_object.choiceTag())
            {
            case CHOICE_reflectableUtilEnum:
                return ::zserio::makeStringView("reflectableUtilEnum");
            case CHOICE_reflectableUtilBitmask:
                return ::zserio::makeStringView("reflectableUtilBitmask");
            case CHOICE_reflectableUtilObject:
                return ::zserio::makeStringView("reflectableUtilObject");
            default:
                return {};
            }
        }

        ::zserio::AnyHolder<> getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::AnyHolder<>(::std::cref(m_object), allocator);
        }

    private:
        const ::test_object::std_allocator::ReflectableUtilUnion& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::IReflectablePtr ReflectableUtilUnion::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::std_allocator::ReflectableUtilUnion& object, const allocator_type& allocator) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::std_allocator::ReflectableUtilUnion::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("reflectableUtilEnum"))
            {
                return ::zserio::enumReflectable(m_object.getReflectableUtilEnum(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilBitmask"))
            {
                return m_object.getReflectableUtilBitmask().reflectable(get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilObject"))
            {
                return m_object.getReflectableUtilObject().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilUnion'!";
        }

        ::zserio::IReflectablePtr getField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("reflectableUtilEnum"))
            {
                return ::zserio::enumReflectable(m_object.getReflectableUtilEnum(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilBitmask"))
            {
                return m_object.getReflectableUtilBitmask().reflectable(get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilObject"))
            {
                return m_object.getReflectableUtilObject().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilUnion'!";
        }

        void setField(::zserio::StringView name,
                const ::zserio::AnyHolder<allocator_type>& value) override
        {
            if (name == ::zserio::makeStringView("reflectableUtilEnum"))
            {
                if (value.isType<::test_object::std_allocator::ReflectableUtilEnum>())
                {
                    m_object.setReflectableUtilEnum(value.get<::test_object::std_allocator::ReflectableUtilEnum>());
                }
                else
                {
                    m_object.setReflectableUtilEnum(::zserio::valueToEnum<::test_object::std_allocator::ReflectableUtilEnum>(
                            value.get<typename ::std::underlying_type<::test_object::std_allocator::ReflectableUtilEnum>::type>()));
                }
                return;
            }
            if (name == ::zserio::makeStringView("reflectableUtilBitmask"))
            {
                if (value.isType<::test_object::std_allocator::ReflectableUtilBitmask>())
                {
                    m_object.setReflectableUtilBitmask(value.get<::test_object::std_allocator::ReflectableUtilBitmask>());
                }
                else
                {
                    m_object.setReflectableUtilBitmask(::test_object::std_allocator::ReflectableUtilBitmask(
                            value.get<::test_object::std_allocator::ReflectableUtilBitmask::underlying_type>()));
                }
                return;
            }
            if (name == ::zserio::makeStringView("reflectableUtilObject"))
            {
                m_object.setReflectableUtilObject(value.get<::test_object::std_allocator::ReflectableUtilObject>());
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilUnion'!";
        }

        ::zserio::IReflectablePtr createField(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("reflectableUtilEnum"))
            {
                m_object.setReflectableUtilEnum(::test_object::std_allocator::ReflectableUtilEnum());
                return ::zserio::enumReflectable(m_object.getReflectableUtilEnum(), get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilBitmask"))
            {
                m_object.setReflectableUtilBitmask(::test_object::std_allocator::ReflectableUtilBitmask());
                return m_object.getReflectableUtilBitmask().reflectable(get_allocator());
            }
            if (name == ::zserio::makeStringView("reflectableUtilObject"))
            {
                m_object.setReflectableUtilObject(::test_object::std_allocator::ReflectableUtilObject(get_allocator()));
                return m_object.getReflectableUtilObject().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'ReflectableUtilUnion'!";
        }

        ::zserio::StringView getChoice() const override
        {
            switch (m_object.choiceTag())
            {
            case CHOICE_reflectableUtilEnum:
                return ::zserio::makeStringView("reflectableUtilEnum");
            case CHOICE_reflectableUtilBitmask:
                return ::zserio::makeStringView("reflectableUtilBitmask");
            case CHOICE_reflectableUtilObject:
                return ::zserio::makeStringView("reflectableUtilObject");
            default:
                return {};
            }
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
        ::test_object::std_allocator::ReflectableUtilUnion& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void ReflectableUtilUnion::initializeChildren()
{
    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        ;
        break;
    case CHOICE_reflectableUtilBitmask:
        ;
        break;
    case CHOICE_reflectableUtilObject:
        m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>().initializeChildren();
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }
}

::test_object::std_allocator::ReflectableUtilEnum ReflectableUtilUnion::getReflectableUtilEnum() const
{
    return m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>();
}

void ReflectableUtilUnion::setReflectableUtilEnum(::test_object::std_allocator::ReflectableUtilEnum reflectableUtilEnum_)
{
    m_choiceTag = CHOICE_reflectableUtilEnum;
    m_objectChoice = reflectableUtilEnum_;
}

::test_object::std_allocator::ReflectableUtilBitmask ReflectableUtilUnion::getReflectableUtilBitmask() const
{
    return m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>();
}

void ReflectableUtilUnion::setReflectableUtilBitmask(::test_object::std_allocator::ReflectableUtilBitmask reflectableUtilBitmask_)
{
    m_choiceTag = CHOICE_reflectableUtilBitmask;
    m_objectChoice = reflectableUtilBitmask_;
}

::test_object::std_allocator::ReflectableUtilObject& ReflectableUtilUnion::getReflectableUtilObject()
{
    return m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>();
}

const ::test_object::std_allocator::ReflectableUtilObject& ReflectableUtilUnion::getReflectableUtilObject() const
{
    return m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>();
}

void ReflectableUtilUnion::setReflectableUtilObject(const ::test_object::std_allocator::ReflectableUtilObject& reflectableUtilObject_)
{
    m_choiceTag = CHOICE_reflectableUtilObject;
    m_objectChoice = reflectableUtilObject_;
}

void ReflectableUtilUnion::setReflectableUtilObject(::test_object::std_allocator::ReflectableUtilObject&& reflectableUtilObject_)
{
    m_choiceTag = CHOICE_reflectableUtilObject;
    m_objectChoice = ::std::move(reflectableUtilObject_);
}

ReflectableUtilUnion::ChoiceTag ReflectableUtilUnion::choiceTag() const
{
    return m_choiceTag;
}

void ReflectableUtilUnion::initPackingContext(ReflectableUtilUnion::ZserioPackingContext& context) const
{
    context.getChoiceTag().init<::zserio::VarSizeArrayTraits>(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        ::zserio::initPackingContext(context.getReflectableUtilEnum(), m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>());
        break;
    case CHOICE_reflectableUtilBitmask:
        m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>().initPackingContext(context.getReflectableUtilBitmask());
        break;
    case CHOICE_reflectableUtilObject:
        m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>().initPackingContext(context.getReflectableUtilObject());
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }
}

size_t ReflectableUtilUnion::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfVarSize(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        endBitPosition += ::zserio::bitSizeOf(m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>());
        break;
    case CHOICE_reflectableUtilBitmask:
        endBitPosition += m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>().bitSizeOf(endBitPosition);
        break;
    case CHOICE_reflectableUtilObject:
        endBitPosition += m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>().bitSizeOf(endBitPosition);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }

    return endBitPosition - bitPosition;
}

size_t ReflectableUtilUnion::bitSizeOf(ReflectableUtilUnion::ZserioPackingContext& context, size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += context.getChoiceTag().bitSizeOf<::zserio::VarSizeArrayTraits>(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        endBitPosition += ::zserio::bitSizeOf(context.getReflectableUtilEnum(), m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>());
        break;
    case CHOICE_reflectableUtilBitmask:
        endBitPosition += m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>().bitSizeOf(context.getReflectableUtilBitmask(), endBitPosition);
        break;
    case CHOICE_reflectableUtilObject:
        endBitPosition += m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>().bitSizeOf(context.getReflectableUtilObject(), endBitPosition);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }

    return endBitPosition - bitPosition;
}

size_t ReflectableUtilUnion::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += ::zserio::bitSizeOfVarSize(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        endBitPosition = ::zserio::initializeOffsets(endBitPosition, m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>());
        break;
    case CHOICE_reflectableUtilBitmask:
        endBitPosition = m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>().initializeOffsets(endBitPosition);
        break;
    case CHOICE_reflectableUtilObject:
        endBitPosition = m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>().initializeOffsets(endBitPosition);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }

    return endBitPosition;
}

size_t ReflectableUtilUnion::initializeOffsets(ReflectableUtilUnion::ZserioPackingContext& context, size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += context.getChoiceTag().bitSizeOf<::zserio::VarSizeArrayTraits>(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        endBitPosition = ::zserio::initializeOffsets(context.getReflectableUtilEnum(), endBitPosition,
        m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>());
        break;
    case CHOICE_reflectableUtilBitmask:
        endBitPosition = m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>().initializeOffsets(context.getReflectableUtilBitmask(), endBitPosition);
        break;
    case CHOICE_reflectableUtilObject:
        endBitPosition = m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>().initializeOffsets(context.getReflectableUtilObject(), endBitPosition);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }

    return endBitPosition;
}

bool ReflectableUtilUnion::operator==(const ReflectableUtilUnion& other) const
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
    case CHOICE_reflectableUtilEnum:
        return m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>() == other.m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>();
    case CHOICE_reflectableUtilBitmask:
        return m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>() == other.m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>();
    case CHOICE_reflectableUtilObject:
        return m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>() == other.m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>();
    default:
        return true; // UNDEFINED_CHOICE
    }
}

uint32_t ReflectableUtilUnion::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, static_cast<int32_t>(m_choiceTag));
    if (m_objectChoice.hasValue())
    {
        switch (m_choiceTag)
        {
        case CHOICE_reflectableUtilEnum:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>());
            break;
        case CHOICE_reflectableUtilBitmask:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>());
            break;
        case CHOICE_reflectableUtilObject:
            result = ::zserio::calcHashCode(result, m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>());
            break;
        default:
            // UNDEFINED_CHOICE
            break;
        }
    }

    return result;
}

void ReflectableUtilUnion::write(::zserio::BitStreamWriter& out) const
{
    out.writeVarSize(static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        ::zserio::write(out, m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>());
        break;
    case CHOICE_reflectableUtilBitmask:
        m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>().write(out);
        break;
    case CHOICE_reflectableUtilObject:
        m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>().write(out);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }
}

void ReflectableUtilUnion::write(ReflectableUtilUnion::ZserioPackingContext}& context, ::zserio::BitStreamWriter& out) const
{
    context.getChoiceTag().write<::zserio::VarSizeArrayTraits>(out, static_cast<uint32_t>(m_choiceTag));

    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        ::zserio::write(context.getReflectableUtilEnum(), out, m_objectChoice.get<::test_object::std_allocator::ReflectableUtilEnum>());
        break;
    case CHOICE_reflectableUtilBitmask:
        m_objectChoice.get<::test_object::std_allocator::ReflectableUtilBitmask>().write(context.getReflectableUtilBitmask(), out);
        break;
    case CHOICE_reflectableUtilObject:
        m_objectChoice.get<::test_object::std_allocator::ReflectableUtilObject>().write(context.getReflectableUtilObject(), out);
        break;
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }
}

ReflectableUtilUnion::ChoiceTag ReflectableUtilUnion::readChoiceTag(::zserio::BitStreamReader& in)
{
    return static_cast<ReflectableUtilUnion::ChoiceTag>(static_cast<int32_t>(in.readVarSize()));
}

ReflectableUtilUnion::ChoiceTag ReflectableUtilUnion::readChoiceTag(ReflectableUtilUnion::ZserioPackingContext& context, ::zserio::BitStreamReader& in)
{
    return static_cast<ReflectableUtilUnion::ChoiceTag>(static_cast<int32_t>(context.getChoiceTag().read<::zserio::VarSizeArrayTraits>(in)));
}

::zserio::AnyHolder<> ReflectableUtilUnion::readObject(::zserio::BitStreamReader& in, const allocator_type& allocator)
{
    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        return ::zserio::AnyHolder<>(::zserio::read<::test_object::std_allocator::ReflectableUtilEnum>(in), allocator);
    case CHOICE_reflectableUtilBitmask:
        return ::zserio::AnyHolder<>(::test_object::std_allocator::ReflectableUtilBitmask(in), allocator);
    case CHOICE_reflectableUtilObject:
        return ::zserio::AnyHolder<>(::test_object::std_allocator::ReflectableUtilObject(in, allocator), allocator);
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }
}

::zserio::AnyHolder<> ReflectableUtilUnion::readObject(ReflectableUtilUnion::ZserioPackingContext& context,
        ::zserio::BitStreamReader& in, const allocator_type& allocator)
{
    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        return ::zserio::AnyHolder<>(::zserio::read<::test_object::std_allocator::ReflectableUtilEnum>(context.getReflectableUtilEnum(), in), allocator);
    case CHOICE_reflectableUtilBitmask:
        return ::zserio::AnyHolder<>(::test_object::std_allocator::ReflectableUtilBitmask(context.getReflectableUtilBitmask(), in), allocator);
    case CHOICE_reflectableUtilObject:
        return ::zserio::AnyHolder<>(::test_object::std_allocator::ReflectableUtilObject(context.getReflectableUtilObject(), in, allocator), allocator);
    default:
        throw ::zserio::CppRuntimeException("No match in union ReflectableUtilUnion!");
    }
}

::zserio::AnyHolder<> ReflectableUtilUnion::copyObject(const allocator_type& allocator) const
{
    switch (m_choiceTag)
    {
    case CHOICE_reflectableUtilEnum:
        return ::zserio::allocatorPropagatingCopy<::test_object::std_allocator::ReflectableUtilEnum>(m_objectChoice, allocator);
    case CHOICE_reflectableUtilBitmask:
        return ::zserio::allocatorPropagatingCopy<::test_object::std_allocator::ReflectableUtilBitmask>(m_objectChoice, allocator);
    case CHOICE_reflectableUtilObject:
        return ::zserio::allocatorPropagatingCopy<::test_object::std_allocator::ReflectableUtilObject>(m_objectChoice, allocator);
    default:
        return ::zserio::AnyHolder<>(allocator);
    }
}

} // namespace std_allocator
} // namespace test_object
