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
#include <zserio/pmr/AnyHolder.h>
#include <zserio/pmr/Reflectable.h>

#include <test_object/polymorphic_allocator/CreatorNested.h>

namespace test_object
{
namespace polymorphic_allocator
{

CreatorNested::CreatorNested(const allocator_type& allocator) noexcept :
        m_isInitialized(false),
        m_value_(uint32_t()),
        m_text_(allocator),
        m_externData_(allocator),
        m_bytesData_(allocator),
        m_creatorEnum_(::test_object::polymorphic_allocator::CreatorEnum()),
        m_creatorBitmask_(::test_object::polymorphic_allocator::CreatorBitmask())
{
}

CreatorNested::CreatorNested(::zserio::BitStreamReader& in,
        uint32_t param_, const allocator_type& allocator) :
        m_param_(param_),
        m_isInitialized(true),
        m_value_(readValue(in)),
        m_text_(readText(in, allocator)),
        m_externData_(readExternData(in, allocator)),
        m_bytesData_(readBytesData(in, allocator)),
        m_creatorEnum_(readCreatorEnum(in)),
        m_creatorBitmask_(readCreatorBitmask(in))
{
}

CreatorNested::CreatorNested(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in,
        uint32_t param_, const allocator_type& allocator) :
        m_param_(param_),
        m_isInitialized(true),
        m_value_(readValue(contextNode, in)),
        m_text_(readText(in, allocator)),
        m_externData_(readExternData(in, allocator)),
        m_bytesData_(readBytesData(in, allocator)),
        m_creatorEnum_(readCreatorEnum(contextNode, in)),
        m_creatorBitmask_(readCreatorBitmask(contextNode, in))
{
}

CreatorNested::CreatorNested(const CreatorNested& other) :
        m_value_(other.m_value_),
        m_text_(other.m_text_),
        m_externData_(other.m_externData_),
        m_bytesData_(other.m_bytesData_),
        m_creatorEnum_(other.m_creatorEnum_),
        m_creatorBitmask_(other.m_creatorBitmask_)
{
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;
}

CreatorNested& CreatorNested::operator=(const CreatorNested& other)
{
    m_value_ = other.m_value_;
    m_text_ = other.m_text_;
    m_externData_ = other.m_externData_;
    m_bytesData_ = other.m_bytesData_;
    m_creatorEnum_ = other.m_creatorEnum_;
    m_creatorBitmask_ = other.m_creatorBitmask_;
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;

    return *this;
}

CreatorNested::CreatorNested(CreatorNested&& other) :
        m_value_(::std::move(other.m_value_)),
        m_text_(::std::move(other.m_text_)),
        m_externData_(::std::move(other.m_externData_)),
        m_bytesData_(::std::move(other.m_bytesData_)),
        m_creatorEnum_(::std::move(other.m_creatorEnum_)),
        m_creatorBitmask_(::std::move(other.m_creatorBitmask_))
{
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;
}

CreatorNested& CreatorNested::operator=(CreatorNested&& other)
{
    m_value_ = ::std::move(other.m_value_);
    m_text_ = ::std::move(other.m_text_);
    m_externData_ = ::std::move(other.m_externData_);
    m_bytesData_ = ::std::move(other.m_bytesData_);
    m_creatorEnum_ = ::std::move(other.m_creatorEnum_);
    m_creatorBitmask_ = ::std::move(other.m_creatorBitmask_);
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;

    return *this;
}

CreatorNested::CreatorNested(::zserio::PropagateAllocatorT,
        const CreatorNested& other, const allocator_type& allocator) :
        m_value_(::zserio::allocatorPropagatingCopy(other.m_value_, allocator)),
        m_text_(::zserio::allocatorPropagatingCopy(other.m_text_, allocator)),
        m_externData_(::zserio::allocatorPropagatingCopy(other.m_externData_, allocator)),
        m_bytesData_(::zserio::allocatorPropagatingCopy(other.m_bytesData_, allocator)),
        m_creatorEnum_(::zserio::allocatorPropagatingCopy(other.m_creatorEnum_, allocator)),
        m_creatorBitmask_(::zserio::allocatorPropagatingCopy(other.m_creatorBitmask_, allocator))
{
    if (other.m_isInitialized)
        initialize(other.m_param_);
    else
        m_isInitialized = false;
}

const ::zserio::pmr::ITypeInfo& CreatorNested::typeInfo()
{
    static const ::zserio::StringView templateName;
    static const ::zserio::Span<::zserio::BasicTemplateArgumentInfo<allocator_type>> templateArguments;

    static const ::std::array<::zserio::BasicFieldInfo<allocator_type>, 6> fields = {
        ::zserio::BasicFieldInfo<allocator_type>{
            ::zserio::makeStringView("value"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getUInt32(), // typeInfo
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
            ::zserio::makeStringView("text"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getString(), // typeInfo
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
            ::zserio::makeStringView("externData"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getBitBuffer(), // typeInfo
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
            ::zserio::makeStringView("bytesData"), // schemaName
            ::zserio::BuiltinTypeInfo<allocator_type>::getBytes(), // typeInfo
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
            ::zserio::makeStringView("creatorEnum"), // schemaName
            ::zserio::enumTypeInfo<::test_object::polymorphic_allocator::CreatorEnum, allocator_type>(), // typeInfo
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
            ::zserio::makeStringView("creatorBitmask"), // schemaName
            ::test_object::polymorphic_allocator::CreatorBitmask::typeInfo(), // typeInfo
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
        }
    };

    static const ::std::array<::zserio::BasicParameterInfo<allocator_type>, 1> parameters = {
        ::zserio::BasicParameterInfo<allocator_type>{
            ::zserio::makeStringView("param"),
            ::zserio::BuiltinTypeInfo<allocator_type>::getUInt32()
        }
    };

    static const ::zserio::Span<::zserio::BasicFunctionInfo<allocator_type>> functions;

    static const ::zserio::StructTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("test_object.polymorphic_allocator.CreatorNested"),
        [](const allocator_type& allocator) -> ::zserio::pmr::IReflectablePtr
        {
            return std::allocate_shared<::zserio::ReflectableOwner<CreatorNested>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

::zserio::pmr::IReflectableConstPtr CreatorNested::reflectable(const allocator_type& allocator) const
{
    class Reflectable : public ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>
    {
    public:
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getField;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getParameter;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::callFunction;
        using ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>::getAnyValue;

        explicit Reflectable(const ::test_object::polymorphic_allocator::CreatorNested& object, const allocator_type& allocator) :
                ::zserio::ReflectableConstAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::CreatorNested::typeInfo(), allocator),
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
            if (name == ::zserio::makeStringView("externData"))
            {
                return ::zserio::pmr::ReflectableFactory::getBitBuffer(m_object.getExternData(), get_allocator());
            }
            if (name == ::zserio::makeStringView("bytesData"))
            {
                return ::zserio::pmr::ReflectableFactory::getBytes(m_object.getBytesData(), get_allocator());
            }
            if (name == ::zserio::makeStringView("creatorEnum"))
            {
                return ::zserio::enumReflectable(m_object.getCreatorEnum(), get_allocator());
            }
            if (name == ::zserio::makeStringView("creatorBitmask"))
            {
                return m_object.getCreatorBitmask().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'CreatorNested'!";
        }

        ::zserio::pmr::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'CreatorNested'!";
        }

        ::zserio::pmr::AnyHolder getAnyValue(const allocator_type& allocator) const override
        {
            return ::zserio::pmr::AnyHolder(::std::cref(m_object), allocator);
        }

    private:
        const ::test_object::polymorphic_allocator::CreatorNested& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

::zserio::pmr::IReflectablePtr CreatorNested::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ::zserio::ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(::test_object::polymorphic_allocator::CreatorNested& object, const allocator_type& allocator) :
                ::zserio::ReflectableAllocatorHolderBase<allocator_type>(::test_object::polymorphic_allocator::CreatorNested::typeInfo(), allocator),
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
                throw ::zserio::CppRuntimeException("Not enough arguments to CreatorNested::initialize, ") <<
                        "expecting 1, got " << typeArguments.size();
            }

            m_object.initialize(
                typeArguments[0].get<uint32_t>()
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
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getValue(), get_allocator());
            }
            if (name == ::zserio::makeStringView("text"))
            {
                return ::zserio::pmr::ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            if (name == ::zserio::makeStringView("externData"))
            {
                return ::zserio::pmr::ReflectableFactory::getBitBuffer(m_object.getExternData(), get_allocator());
            }
            if (name == ::zserio::makeStringView("bytesData"))
            {
                return ::zserio::pmr::ReflectableFactory::getBytes(m_object.getBytesData(), get_allocator());
            }
            if (name == ::zserio::makeStringView("creatorEnum"))
            {
                return ::zserio::enumReflectable(m_object.getCreatorEnum(), get_allocator());
            }
            if (name == ::zserio::makeStringView("creatorBitmask"))
            {
                return m_object.getCreatorBitmask().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'CreatorNested'!";
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
            if (name == ::zserio::makeStringView("externData"))
            {
                return ::zserio::pmr::ReflectableFactory::getBitBuffer(m_object.getExternData(), get_allocator());
            }
            if (name == ::zserio::makeStringView("bytesData"))
            {
                return ::zserio::pmr::ReflectableFactory::getBytes(m_object.getBytesData(), get_allocator());
            }
            if (name == ::zserio::makeStringView("creatorEnum"))
            {
                return ::zserio::enumReflectable(m_object.getCreatorEnum(), get_allocator());
            }
            if (name == ::zserio::makeStringView("creatorBitmask"))
            {
                return m_object.getCreatorBitmask().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'CreatorNested'!";
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
            if (name == ::zserio::makeStringView("externData"))
            {
                m_object.setExternData(value.get<::zserio::pmr::BitBuffer>());
                return;
            }
            if (name == ::zserio::makeStringView("bytesData"))
            {
                m_object.setBytesData(value.get<::zserio::pmr::vector<uint8_t>>());
                return;
            }
            if (name == ::zserio::makeStringView("creatorEnum"))
            {
                if (value.isType<::test_object::polymorphic_allocator::CreatorEnum>())
                {
                    m_object.setCreatorEnum(value.get<::test_object::polymorphic_allocator::CreatorEnum>());
                }
                else
                {
                    m_object.setCreatorEnum(::zserio::valueToEnum<::test_object::polymorphic_allocator::CreatorEnum>(
                            value.get<typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorEnum>::type>()));
                }
                return;
            }
            if (name == ::zserio::makeStringView("creatorBitmask"))
            {
                if (value.isType<::test_object::polymorphic_allocator::CreatorBitmask>())
                {
                    m_object.setCreatorBitmask(value.get<::test_object::polymorphic_allocator::CreatorBitmask>());
                }
                else
                {
                    m_object.setCreatorBitmask(::test_object::polymorphic_allocator::CreatorBitmask(
                            value.get<::test_object::polymorphic_allocator::CreatorBitmask::underlying_type>()));
                }
                return;
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'CreatorNested'!";
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
            if (name == ::zserio::makeStringView("externData"))
            {
                m_object.setExternData(::zserio::pmr::BitBuffer(get_allocator()));
                return ::zserio::pmr::ReflectableFactory::getBitBuffer(m_object.getExternData(), get_allocator());
            }
            if (name == ::zserio::makeStringView("bytesData"))
            {
                m_object.setBytesData(::zserio::pmr::vector<uint8_t>(get_allocator()));
                return ::zserio::pmr::ReflectableFactory::getBytes(m_object.getBytesData(), get_allocator());
            }
            if (name == ::zserio::makeStringView("creatorEnum"))
            {
                m_object.setCreatorEnum(::test_object::polymorphic_allocator::CreatorEnum());
                return ::zserio::enumReflectable(m_object.getCreatorEnum(), get_allocator());
            }
            if (name == ::zserio::makeStringView("creatorBitmask"))
            {
                m_object.setCreatorBitmask(::test_object::polymorphic_allocator::CreatorBitmask());
                return m_object.getCreatorBitmask().reflectable(get_allocator());
            }
            throw ::zserio::CppRuntimeException("Field '") << name << "' doesn't exist in 'CreatorNested'!";
        }

        ::zserio::pmr::IReflectableConstPtr getParameter(::zserio::StringView name) const override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'CreatorNested'!";
        }

        ::zserio::pmr::IReflectablePtr getParameter(::zserio::StringView name) override
        {
            if (name == ::zserio::makeStringView("param"))
            {
                return ::zserio::pmr::ReflectableFactory::getUInt32(m_object.getParam(), get_allocator());
            }
            throw ::zserio::CppRuntimeException("Parameter '") << name << "' doesn't exist in 'CreatorNested'!";
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
        ::test_object::polymorphic_allocator::CreatorNested& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void CreatorNested::initialize(
        uint32_t param_)
{
    m_param_ = param_;
    m_isInitialized = true;
}

bool CreatorNested::isInitialized() const
{
    return m_isInitialized;
}

uint32_t CreatorNested::getParam() const
{
    if (!m_isInitialized)
        throw ::zserio::CppRuntimeException("Parameter 'param' of compound 'CreatorNested' is not initialized!");

    return m_param_;
}

uint32_t CreatorNested::getValue() const
{
    return m_value_;
}

void CreatorNested::setValue(uint32_t value_)
{
    m_value_ = value_;
}

::zserio::pmr::string& CreatorNested::getText()
{
    return m_text_;
}

const ::zserio::pmr::string& CreatorNested::getText() const
{
    return m_text_;
}

void CreatorNested::setText(const ::zserio::pmr::string& text_)
{
    m_text_ = text_;
}

void CreatorNested::setText(::zserio::pmr::string&& text_)
{
    m_text_ = ::std::move(text_);
}

::zserio::pmr::BitBuffer& CreatorNested::getExternData()
{
    return m_externData_;
}

const ::zserio::pmr::BitBuffer& CreatorNested::getExternData() const
{
    return m_externData_;
}

void CreatorNested::setExternData(const ::zserio::pmr::BitBuffer& externData_)
{
    m_externData_ = externData_;
}

void CreatorNested::setExternData(::zserio::pmr::BitBuffer&& externData_)
{
    m_externData_ = ::std::move(externData_);
}

::zserio::pmr::vector<uint8_t>& CreatorNested::getBytesData()
{
    return m_bytesData_;
}

const ::zserio::pmr::vector<uint8_t>& CreatorNested::getBytesData() const
{
    return m_bytesData_;
}

void CreatorNested::setBytesData(const ::zserio::pmr::vector<uint8_t>& bytesData_)
{
    m_bytesData_ = bytesData_;
}

void CreatorNested::setBytesData(::zserio::pmr::vector<uint8_t>&& bytesData_)
{
    m_bytesData_ = ::std::move(bytesData_);
}

::test_object::polymorphic_allocator::CreatorEnum CreatorNested::getCreatorEnum() const
{
    return m_creatorEnum_;
}

void CreatorNested::setCreatorEnum(::test_object::polymorphic_allocator::CreatorEnum creatorEnum_)
{
    m_creatorEnum_ = creatorEnum_;
}

::test_object::polymorphic_allocator::CreatorBitmask CreatorNested::getCreatorBitmask() const
{
    return m_creatorBitmask_;
}

void CreatorNested::setCreatorBitmask(::test_object::polymorphic_allocator::CreatorBitmask creatorBitmask_)
{
    m_creatorBitmask_ = creatorBitmask_;
}

void CreatorNested::createPackingContext(::zserio::pmr::PackingContextNode& contextNode)
{
    contextNode.reserveChildren(6);

    contextNode.createChild().createContext();
    contextNode.createChild();
    contextNode.createChild();
    contextNode.createChild();
    contextNode.createChild().createContext();
    ::test_object::polymorphic_allocator::CreatorBitmask::createPackingContext(contextNode.createChild());
}

void CreatorNested::initPackingContext(::zserio::pmr::PackingContextNode& contextNode) const
{
    contextNode.getChildren()[0].getContext().init<::zserio::StdIntArrayTraits<uint32_t>>(m_value_);
    ::zserio::initPackingContext(contextNode.getChildren()[4],
            m_creatorEnum_);
    m_creatorBitmask_.initPackingContext(contextNode.getChildren()[5]);
}

size_t CreatorNested::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(32);
    endBitPosition += ::zserio::bitSizeOfString(m_text_);
    endBitPosition += ::zserio::bitSizeOfBitBuffer(m_externData_);
    endBitPosition += ::zserio::bitSizeOfBytes(m_bytesData_);
    endBitPosition += ::zserio::bitSizeOf(m_creatorEnum_);
    endBitPosition += m_creatorBitmask_.bitSizeOf(endBitPosition);

    return endBitPosition - bitPosition;
}

size_t CreatorNested::bitSizeOf(::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += contextNode.getChildren()[0].getContext().bitSizeOf<::zserio::StdIntArrayTraits<uint32_t>>(m_value_);
    endBitPosition += ::zserio::bitSizeOfString(m_text_);
    endBitPosition += ::zserio::bitSizeOfBitBuffer(m_externData_);
    endBitPosition += ::zserio::bitSizeOfBytes(m_bytesData_);
    endBitPosition += ::zserio::bitSizeOf(
            contextNode.getChildren()[4], m_creatorEnum_);
    endBitPosition += m_creatorBitmask_.bitSizeOf(
            contextNode.getChildren()[5], endBitPosition);

    return endBitPosition - bitPosition;
}

size_t CreatorNested::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(32);
    endBitPosition += ::zserio::bitSizeOfString(m_text_);
    endBitPosition += ::zserio::bitSizeOfBitBuffer(m_externData_);
    endBitPosition += ::zserio::bitSizeOfBytes(m_bytesData_);
    endBitPosition = ::zserio::initializeOffsets(endBitPosition, m_creatorEnum_);
    endBitPosition = m_creatorBitmask_.initializeOffsets(endBitPosition);

    return endBitPosition;
}

size_t CreatorNested::initializeOffsets(::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += contextNode.getChildren()[0].getContext().bitSizeOf<::zserio::StdIntArrayTraits<uint32_t>>(m_value_);
    endBitPosition += ::zserio::bitSizeOfString(m_text_);
    endBitPosition += ::zserio::bitSizeOfBitBuffer(m_externData_);
    endBitPosition += ::zserio::bitSizeOfBytes(m_bytesData_);
    endBitPosition = ::zserio::initializeOffsets(
            contextNode.getChildren()[4], endBitPosition, m_creatorEnum_);
    endBitPosition = m_creatorBitmask_.initializeOffsets(
            contextNode.getChildren()[5], endBitPosition);

    return endBitPosition;
}

bool CreatorNested::operator==(const CreatorNested& other) const
{
    if (this != &other)
    {
        return
                (getParam() == other.getParam()) &&
                (m_value_ == other.m_value_) &&
                (m_text_ == other.m_text_) &&
                (m_externData_ == other.m_externData_) &&
                (m_bytesData_ == other.m_bytesData_) &&
                (m_creatorEnum_ == other.m_creatorEnum_) &&
                (m_creatorBitmask_ == other.m_creatorBitmask_);
    }

    return true;
}

uint32_t CreatorNested::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, getParam());
    result = ::zserio::calcHashCode(result, m_value_);
    result = ::zserio::calcHashCode(result, m_text_);
    result = ::zserio::calcHashCode(result, m_externData_);
    result = ::zserio::calcHashCode(result, m_bytesData_);
    result = ::zserio::calcHashCode(result, m_creatorEnum_);
    result = ::zserio::calcHashCode(result, m_creatorBitmask_);

    return result;
}

void CreatorNested::write(::zserio::BitStreamWriter& out) const
{
    out.writeBits(m_value_, UINT8_C(32));
    out.writeString(m_text_);
    out.writeBitBuffer(m_externData_);
    out.writeBytes(m_bytesData_);
    ::zserio::write(out, m_creatorEnum_);
    m_creatorBitmask_.write(out);
}

void CreatorNested::write(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const
{
    contextNode.getChildren()[0].getContext().write<::zserio::StdIntArrayTraits<uint32_t>>(out, m_value_);
    out.writeString(m_text_);
    out.writeBitBuffer(m_externData_);
    out.writeBytes(m_bytesData_);
    ::zserio::write(contextNode.getChildren()[4], out, m_creatorEnum_);
    m_creatorBitmask_.write(contextNode.getChildren()[5], out);
}

uint32_t CreatorNested::readValue(::zserio::BitStreamReader& in)
{
    return static_cast<uint32_t>(in.readBits(UINT8_C(32)));
}

uint32_t CreatorNested::readValue(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in)
{
    return contextNode.getChildren()[0].getContext().read<::zserio::StdIntArrayTraits<uint32_t>>(in);
}

::zserio::pmr::string CreatorNested::readText(::zserio::BitStreamReader& in,
        const allocator_type& allocator)
{
    return static_cast<::zserio::pmr::string>(in.readString(allocator));
}

::zserio::pmr::BitBuffer CreatorNested::readExternData(::zserio::BitStreamReader& in,
        const allocator_type& allocator)
{
    return static_cast<::zserio::pmr::BitBuffer>(in.readBitBuffer(allocator));
}

::zserio::pmr::vector<uint8_t> CreatorNested::readBytesData(::zserio::BitStreamReader& in,
        const allocator_type& allocator)
{
    return static_cast<::zserio::pmr::vector<uint8_t>>(in.readBytes(allocator));
}

::test_object::polymorphic_allocator::CreatorEnum CreatorNested::readCreatorEnum(::zserio::BitStreamReader& in)
{
    return ::zserio::read<::test_object::polymorphic_allocator::CreatorEnum>(in);
}

::test_object::polymorphic_allocator::CreatorEnum CreatorNested::readCreatorEnum(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in)
{
    return ::zserio::read<::test_object::polymorphic_allocator::CreatorEnum>(contextNode.getChildren()[4], in);
}

::test_object::polymorphic_allocator::CreatorBitmask CreatorNested::readCreatorBitmask(::zserio::BitStreamReader& in)
{
    return ::test_object::polymorphic_allocator::CreatorBitmask(in);
}

::test_object::polymorphic_allocator::CreatorBitmask CreatorNested::readCreatorBitmask(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in)
{
    return ::test_object::polymorphic_allocator::CreatorBitmask(contextNode.getChildren()[5], in);
}

} // namespace polymorphic_allocator
} // namespace test_object
