#include "gtest/gtest.h"

#include "zserio/Array.h"
#include "zserio/TypeInfo.h"
#include "zserio/Reflectable.h"
#include "zserio/ZserioTreeCreator.h"
#include "zserio/StringConvertUtil.h"

using namespace zserio::literals;

namespace zserio
{

namespace
{

enum class DummyEnum : uint8_t
{
    ONE = UINT8_C(0),
    TWO = UINT8_C(1)
};

} // namespace

template <>
const ITypeInfo& enumTypeInfo<DummyEnum, std::allocator<uint8_t>>()
{
    static const Span<StringView> underlyingTypeArguments;

    static const ::std::array<ItemInfo, 2> items = {
        ItemInfo{ makeStringView("ONE"), makeStringView("UINT8_C(0)") },
        ItemInfo{ makeStringView("TWO"), makeStringView("UINT8_C(1)") }
    };

    static const EnumTypeInfo<std::allocator<uint8_t>> typeInfo = {
        makeStringView("DummyEnum"),
        BuiltinTypeInfo<>::getUInt8(), underlyingTypeArguments, items
    };

    return typeInfo;
}

template <>
IReflectablePtr enumReflectable(
        DummyEnum value, const ::std::allocator<uint8_t>& allocator)
{
    class Reflectable : public ReflectableBase<::std::allocator<uint8_t>>
    {
    public:
        explicit Reflectable(DummyEnum value) :
                ReflectableBase<::std::allocator<uint8_t>>(enumTypeInfo<DummyEnum>()),
                m_value(value)
        {}

        virtual uint8_t getUInt8() const override
        {
            return static_cast<typename ::std::underlying_type<DummyEnum>::type>(m_value);
        }

        virtual void write(BitStreamWriter&) const override
        {
        }

        virtual size_t bitSizeOf(size_t) const override
        {
            return 8;
        }

    private:
        DummyEnum m_value;
    };

    return std::allocate_shared<Reflectable>(allocator, value);
}

namespace
{

class DummyBitmask
{
public:
    typedef uint8_t underlying_type;

    enum class Values : underlying_type
    {
        READ = UINT8_C(1),
        WRITE = UINT8_C(2)
    };

    constexpr DummyBitmask() noexcept :
        m_value(0)
    {}

    constexpr DummyBitmask(Values value) noexcept :
        m_value(static_cast<underlying_type>(value))
    {}

    constexpr explicit DummyBitmask(underlying_type value) noexcept :
        m_value(value)
    {}

    DummyBitmask(const DummyBitmask&) = default;
    DummyBitmask& operator=(const DummyBitmask&) = default;

    DummyBitmask(DummyBitmask&&) = default;

    constexpr underlying_type getValue() const
    {
        return m_value;
    }

    static const ITypeInfo& typeInfo();
    IReflectablePtr reflectable(const ::std::allocator<uint8_t>& allocator = ::std::allocator<uint8_t>()) const;

private:
    underlying_type m_value;
};

inline bool operator==(const DummyBitmask& lhs, const DummyBitmask& rhs)
{
    return lhs.getValue() == rhs.getValue();
}

class DummyNested
{
public:
    using allocator_type = std::allocator<uint8_t>;

    explicit DummyNested(const allocator_type& allocator = allocator_type()) noexcept;

    ~DummyNested() = default;

    static const ITypeInfo& typeInfo();
    IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initialize(
            uint32_t param_);

    uint32_t getParam() const;

    uint32_t getValue() const;
    void setValue(uint32_t value_);

    string<>& getText();
    void setText(const string<>& text_);

    BitBuffer& getData();
    void setData(const BitBuffer& data_);

    DummyEnum getDummyEnum() const;
    void setDummyEnum(DummyEnum dummyEnum_);

    DummyBitmask getDummyBitmask() const;
    void setDummyBitmask(DummyBitmask dummyBitmask_);

private:
    uint32_t m_param_;
    bool m_isInitialized;
    uint32_t m_value_;
    string<> m_text_;
    BitBuffer m_data_;
    DummyEnum m_dummyEnum_;
    DummyBitmask m_dummyBitmask_;
};

class DummyObject
{
private:
    class ZserioElementFactory_nestedArray
    {
    public:

    };

    class ZserioElementInitializer_nestedArray
    {
    public:
        explicit ZserioElementInitializer_nestedArray(DummyObject& owner) :
                m_owner(owner)
        {}

        void initialize(DummyNested& element, size_t index) const;

    private:
        DummyObject& m_owner;
    };

    using ZserioArrayType_nestedArray = Array<vector<DummyNested>, ObjectArrayTraits<DummyNested, ZserioElementFactory_nestedArray>, ArrayType::AUTO>;
    using ZserioArrayType_textArray = Array<vector<string<>>, StringArrayTraits, ArrayType::AUTO>;
    using ZserioArrayType_externArray = Array<vector<BitBuffer>, BitBufferArrayTraits, ArrayType::AUTO>;

public:
    using allocator_type = ::std::allocator<uint8_t>;

    explicit DummyObject(const allocator_type& allocator = allocator_type()) noexcept;
    ~DummyObject() = default;

    static const ITypeInfo& typeInfo();
    IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initializeChildren();

    uint32_t getValue() const;
    void setValue(uint32_t value_);

    DummyNested& getNested();

    string<>& getText();
    void setText(const string<>& text_);

    vector<DummyNested>& getNestedArray();

    vector<string<>>& getTextArray();

    bool isExternArraySet() const;
    vector<BitBuffer>& getExternArray();
    void setExternArray(const vector<BitBuffer>& externArray_);

    bool isOptionalBoolSet() const;
    bool getOptionalBool() const;
    void setOptionalBool(bool optionalBool_);

    bool isOptionalNestedSet() const;
    DummyNested& getOptionalNested();
    void setOptionalNested(const DummyNested& optionalNested_);

private:
    bool m_areChildrenInitialized;
    uint32_t m_value_;
    DummyNested m_nested_;
    string<> m_text_;
    ZserioArrayType_nestedArray m_nestedArray_;
    ZserioArrayType_textArray m_textArray_;
    InplaceOptionalHolder<ZserioArrayType_externArray> m_externArray_;
    InplaceOptionalHolder<bool> m_optionalBool_;
    InplaceOptionalHolder<DummyNested> m_optionalNested_;
};

const ITypeInfo& DummyBitmask::typeInfo()
{
    static const Span<StringView> underlyingTypeArguments;

    static const ::std::array<ItemInfo, 2> values = {
        ItemInfo{ makeStringView("READ"), makeStringView("UINT8_C(1)") },
        ItemInfo{ makeStringView("WRITE"), makeStringView("UINT8_C(2)") }
    };

    static const BitmaskTypeInfo<std::allocator<uint8_t>> typeInfo = {
        makeStringView("DummyBitmask"),
        BuiltinTypeInfo<>::getUInt8(), underlyingTypeArguments, values
    };

    return typeInfo;
}

IReflectablePtr DummyBitmask::reflectable(const ::std::allocator<uint8_t>& allocator) const
{
    class Reflectable : public ReflectableBase<::std::allocator<uint8_t>>
    {
    public:
        explicit Reflectable(DummyBitmask bitmask) :
                ReflectableBase<::std::allocator<uint8_t>>(DummyBitmask::typeInfo()),
                m_bitmask(bitmask)
        {}

        virtual uint8_t getUInt8() const override
        {
            return m_bitmask.getValue();
        }

        virtual void write(BitStreamWriter&) const override
        {
        }

        virtual size_t bitSizeOf(size_t) const override
        {
            return 8;
        }

    private:
        DummyBitmask m_bitmask;
    };

    return ::std::allocate_shared<Reflectable>(allocator, *this);
}

DummyNested::DummyNested(const allocator_type& allocator) noexcept :
        m_isInitialized(false),
        m_value_(uint32_t()),
        m_text_(allocator),
        m_dummyEnum_(DummyEnum()),
        m_dummyBitmask_(DummyBitmask())
{
}

const ITypeInfo& DummyNested::typeInfo()
{
    static const StringView templateName;
    static const Span<TemplateArgumentInfo> templateArguments;

    static const ::std::array<FieldInfo, 5> fields = {
        FieldInfo{
            makeStringView("value"), // schemaName
            BuiltinTypeInfo<>::getUInt32(), // typeInfo
            {}, // typeArguments
            {}, // alignment
            {}, // offset
            {}, // initializer
            false, // isOptional
            {}, // optionalClause
            makeStringView("getValue() < getParam()"), // constraint
            false, // isArray
            {}, // arrayLength
            false, // isPacked
            false // isImplicit
        },
        FieldInfo{
            makeStringView("text"), // schemaName
            BuiltinTypeInfo<>::getString(), // typeInfo
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
        FieldInfo{
            makeStringView("data"), // schemaName
            BuiltinTypeInfo<>::getBitBuffer(), // typeInfo
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
        FieldInfo{
            makeStringView("dummyEnum"), // schemaName
            enumTypeInfo<DummyEnum>(), // typeInfo
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
        FieldInfo{
            makeStringView("dummyBitmask"), // schemaName
            DummyBitmask::typeInfo(), // typeInfo
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

    static const ::std::array<ParameterInfo, 1> parameters = {
        ParameterInfo{
            makeStringView("param"),
            BuiltinTypeInfo<>::getUInt32()
        }
    };

    static const Span<FunctionInfo> functions;

    static const StructTypeInfo<std::allocator<uint8_t>> typeInfo = {
        makeStringView("DummyNested"), nullptr,
        templateName, templateArguments, fields, parameters, functions
    };

    return typeInfo;
}

IReflectablePtr DummyNested::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(DummyNested& object, const allocator_type& allocator) :
                ReflectableAllocatorHolderBase<allocator_type>(DummyNested::typeInfo(), allocator),
                m_object(object)
        {}

        virtual IReflectablePtr getField(StringView name) override
        {
            if (name == makeStringView("value"))
            {
                return ReflectableFactory::getUInt32(m_object.getValue(), get_allocator());
            }
            if (name == makeStringView("text"))
            {
                return ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            if (name == makeStringView("data"))
            {
                return ReflectableFactory::getBitBuffer(m_object.getData(), get_allocator());
            }
            if (name == makeStringView("dummyEnum"))
            {
                return enumReflectable(m_object.getDummyEnum(), get_allocator());
            }
            if (name == makeStringView("dummyBitmask"))
            {
                return m_object.getDummyBitmask().reflectable(get_allocator());
            }

            throw CppRuntimeException("Field '") + name + "' doesn't exist in 'DummyNested'!";
        }

        virtual void setField(StringView name,
                const AnyHolder<allocator_type>& value) override
        {
            if (name == makeStringView("value"))
            {
                m_object.setValue(value.get<uint32_t>());
                return;
            }
            if (name == makeStringView("text"))
            {
                m_object.setText(value.get<string<>>());
                return;
            }
            if (name == makeStringView("data"))
            {
                m_object.setData(value.get<BitBuffer>());
                return;
            }
            if (name == makeStringView("dummyEnum"))
            {
                m_object.setDummyEnum(value.get<DummyEnum>());
                return;
            }
            if (name == makeStringView("dummyBitmask"))
            {
                m_object.setDummyBitmask(value.get<DummyBitmask>());
                return;
            }

            throw CppRuntimeException("Field '") + name + "' doesn't exist in 'DummyNested'!";
        }

        virtual IReflectablePtr getParameter(StringView name) override
        {
            if (name == makeStringView("param"))
            {
                return ReflectableFactory::getUInt32(m_object.getParam(), get_allocator());
            }

            throw CppRuntimeException("Parameter '") + name + "' doesn't exist in 'DummyNested'!";
        }

        virtual void write(BitStreamWriter&) const override
        {}

        virtual size_t bitSizeOf(size_t) const override
        {
            return 0;
        }

    private:
        DummyNested& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void DummyNested::initialize(
        uint32_t param_)
{
    m_param_ = param_;
    m_isInitialized = true;
}

uint32_t DummyNested::getParam() const
{
    if (!m_isInitialized)
        throw CppRuntimeException("Parameter 'param' of compound 'DummyNested' is not initialized!");

    return m_param_;
}

uint32_t DummyNested::getValue() const
{
    return m_value_;
}

void DummyNested::setValue(uint32_t value_)
{
    m_value_ = value_;
}

string<>& DummyNested::getText()
{
    return m_text_;
}

void DummyNested::setText(const string<>& text_)
{
    m_text_ = text_;
}

BitBuffer& DummyNested::getData()
{
    return m_data_;
}

void DummyNested::setData(const BitBuffer& data_)
{
    m_data_ = data_;
}

DummyEnum DummyNested::getDummyEnum() const
{
    return m_dummyEnum_;
}

void DummyNested::setDummyEnum(DummyEnum dummyEnum_)
{
    m_dummyEnum_ = dummyEnum_;
}

DummyBitmask DummyNested::getDummyBitmask() const
{
    return m_dummyBitmask_;
}

void DummyNested::setDummyBitmask(DummyBitmask dummyBitmask_)
{
    m_dummyBitmask_ = dummyBitmask_;
}

void DummyObject::ZserioElementInitializer_nestedArray::initialize(DummyNested& element, size_t index) const
{
    (void)index;
    element.initialize(static_cast<uint32_t>(m_owner.getValue()));
}

DummyObject::DummyObject(const allocator_type& allocator) noexcept :
        m_areChildrenInitialized(false),
        m_value_(uint32_t()),
        m_nested_(allocator),
        m_text_(allocator),
        m_nestedArray_(ObjectArrayTraits<DummyNested, ZserioElementFactory_nestedArray>(), allocator),
        m_textArray_(StringArrayTraits(), allocator)
{
}

const ITypeInfo& DummyObject::typeInfo()
{
    static const StringView templateName;
    static const Span<TemplateArgumentInfo> templateArguments;

    static const std::array<StringView, 1> nestedTypeArguments = { "getValue"_sv };

    static const std::array<StringView, 1> nestedArrayTypeArguments = { "getValue"_sv };
    static const ::std::array<FieldInfo, 8> fields = {
        FieldInfo{
            makeStringView("value"), // schemaName
            BuiltinTypeInfo<>::getUInt32(), // typeInfo
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
        FieldInfo{
            makeStringView("nested"), // schemaName
            DummyNested::typeInfo(), // typeInfo
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
        },
        FieldInfo{
            makeStringView("text"), // schemaName
            BuiltinTypeInfo<>::getString(), // typeInfo
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
        FieldInfo{
            makeStringView("nestedArray"), // schemaName
            DummyNested::typeInfo(), // typeInfo
            nestedArrayTypeArguments, // typeArguments
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
        },
        FieldInfo{
            makeStringView("textArray"), // schemaName
            BuiltinTypeInfo<>::getString(), // typeInfo
            {}, // typeArguments
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
        },
        FieldInfo{
            makeStringView("externArray"), // schemaName
            BuiltinTypeInfo<>::getBitBuffer(), // typeInfo
            {}, // typeArguments
            {}, // alignment
            {}, // offset
            {}, // initializer
            true, // isOptional
            {}, // optionalClause
            {}, // constraint
            true, // isArray
            {}, // arrayLength
            false, // isPacked
            false // isImplicit
        },
        FieldInfo{
            makeStringView("optionalBool"), // schemaName
            BuiltinTypeInfo<>::getBool(), // typeInfo
            {}, // typeArguments
            {}, // alignment
            {}, // offset
            {}, // initializer
            true, // isOptional
            {}, // optionalClause
            {}, // constraint
            false, // isArray
            {}, // arrayLength
            false, // isPacked
            false // isImplicit
        },
        FieldInfo{
            makeStringView("optionalNested"), // schemaName
            DummyNested::typeInfo(), // typeInfo
            {}, // typeArguments
            {}, // alignment
            {}, // offset
            {}, // initializer
            true, // isOptional
            {}, // optionalClause
            {}, // constraint
            false, // isArray
            {}, // arrayLength
            false, // isPacked
            false // isImplicit
        },
    };

    static const Span<ParameterInfo> parameters;

    static const Span<FunctionInfo> functions;

    static const StructTypeInfo<std::allocator<uint8_t>> typeInfo = {
        makeStringView("DummyObject"),
        [](const std::allocator<uint8_t>& allocator) -> IReflectablePtr {
            return std::allocate_shared<ReflectableOwner<DummyObject>>(allocator, allocator);
        },
        templateName, templateArguments,
        fields, parameters, functions
    };

    return typeInfo;
}

IReflectablePtr DummyObject::reflectable(const allocator_type& allocator)
{
    class Reflectable : public ReflectableAllocatorHolderBase<allocator_type>
    {
    public:
        explicit Reflectable(DummyObject& object, const allocator_type& allocator) :
                ReflectableAllocatorHolderBase<allocator_type>(DummyObject::typeInfo(), allocator),
                m_object(object)
        {}

        virtual IReflectablePtr getField(StringView name) override
        {
            if (name == makeStringView("value"))
            {
                return ReflectableFactory::getUInt32(m_object.getValue(), get_allocator());
            }
            if (name == makeStringView("nested"))
            {
                return m_object.getNested().reflectable(get_allocator());
            }
            if (name == makeStringView("text"))
            {
                return ReflectableFactory::getString(m_object.getText(), get_allocator());
            }
            if (name == makeStringView("nestedArray"))
            {
                return ReflectableFactory::getCompoundArray(m_object.getNestedArray(), get_allocator());
            }
            if (name == makeStringView("textArray"))
            {
                return ReflectableFactory::getBuiltinArray(BuiltinTypeInfo<>::getString(),
                        m_object.getTextArray(), get_allocator());
            }
            if (name == makeStringView("externArray"))
            {
                if (!m_object.isExternArraySet())
                    return nullptr;

                return ReflectableFactory::getBuiltinArray(BuiltinTypeInfo<>::getBitBuffer(),
                        m_object.getExternArray(), get_allocator());
            }
            if (name == makeStringView("optionalBool"))
            {
                if (!m_object.isOptionalBoolSet())
                    return nullptr;

                return ReflectableFactory::getBool(m_object.getOptionalBool(), get_allocator());
            }
            if (name == makeStringView("optionalNested"))
            {
                if (!m_object.isOptionalNestedSet())
                    return nullptr;

                return m_object.getOptionalNested().reflectable(get_allocator());
            }

            throw CppRuntimeException("Field '") + name + "' doesn't exist in 'DummyObject'!";
        }

        virtual void setField(StringView name,
                const AnyHolder<allocator_type>& value) override
        {
            if (name == makeStringView("value"))
            {
                m_object.setValue(value.get<uint32_t>());
                return;
            }
            if (name == makeStringView("text"))
            {
                m_object.setText(value.get<string<>>());
                return;
            }
            if (name == makeStringView("optionalBool"))
            {
                m_object.setOptionalBool(value.get<bool>());
                return;
            }

            // note that unused setters are omitted!

            throw CppRuntimeException("Field '") + name + "' doesn't exist in 'DummyObject'!";
        }

        virtual IReflectablePtr createField(StringView name) override
        {
            if (name == makeStringView("externArray"))
            {
                if (m_object.isExternArraySet())
                    throw CppRuntimeException("Field '") + name + "' is already created!";

                m_object.setExternArray(std::vector<BitBuffer>(get_allocator()));
                return ReflectableFactory::getBuiltinArray(BuiltinTypeInfo<>::getBitBuffer(),
                        m_object.getExternArray(), get_allocator());
            }

            if (name == makeStringView("optionalNested"))
            {
                if (m_object.isOptionalNestedSet())
                    throw CppRuntimeException("Field '") + name + "' is already created!";

                m_object.setOptionalNested(DummyNested(get_allocator()));
                return m_object.getOptionalNested().reflectable(get_allocator());
            }

            throw CppRuntimeException("Field '") + name + "' is not an optional field in 'DummyObject'!";
        }

        virtual void initializeChildren() override
        {
            m_object.initializeChildren();
        }

        virtual void write(BitStreamWriter&) const override
        {}

        virtual size_t bitSizeOf(size_t) const override
        {
            return 0;
        }

    private:
        DummyObject& m_object;
    };

    return std::allocate_shared<Reflectable>(allocator, *this, allocator);
}

void DummyObject::initializeChildren()
{
    m_nested_.initialize(static_cast<uint32_t>(getValue()));
    m_nestedArray_.initializeElements(ZserioElementInitializer_nestedArray(*this));

    m_areChildrenInitialized = true;
}

uint32_t DummyObject::getValue() const
{
    return m_value_;
}

void DummyObject::setValue(uint32_t value_)
{
    m_value_ = value_;
}

DummyNested& DummyObject::getNested()
{
    return m_nested_;
}

string<>& DummyObject::getText()
{
    return m_text_;
}

void DummyObject::setText(const string<>& text_)
{
    m_text_ = text_;
}

vector<DummyNested>& DummyObject::getNestedArray()
{
    return m_nestedArray_.getRawArray();
}

vector<string<>>& DummyObject::getTextArray()
{
    return m_textArray_.getRawArray();
}

bool DummyObject::isExternArraySet() const
{
    return m_externArray_.hasValue();
}

vector<BitBuffer>& DummyObject::getExternArray()
{
    return m_externArray_.value().getRawArray();
}

void DummyObject::setExternArray(const vector<BitBuffer>& externArray_)
{
    m_externArray_ = ZserioArrayType_externArray(externArray_, BitBufferArrayTraits());
}

bool DummyObject::isOptionalBoolSet() const
{
    return m_optionalBool_.hasValue();
}

bool DummyObject::getOptionalBool() const
{
    return m_optionalBool_.value();
}

void DummyObject::setOptionalBool(bool optionalBool_)
{
    m_optionalBool_ = optionalBool_;
}

bool DummyObject::isOptionalNestedSet() const
{
    return m_optionalNested_.hasValue();
}

DummyNested& DummyObject::getOptionalNested()
{
    return m_optionalNested_.value();
}

void DummyObject::setOptionalNested(const DummyNested& optionalNested_)
{
    m_optionalNested_ = optionalNested_;
}

} // namespace

TEST(ZserioTreeCreator, makeAnyValue)
{
    const std::allocator<uint8_t> allocator;

    auto any = detail::makeAnyValue(BuiltinTypeInfo<>::getUInt8(), 8, allocator);
    ASSERT_EQ(8, any.get<uint8_t>());

    any = detail::makeAnyValue(BuiltinTypeInfo<>::getUInt16(), 16, allocator);
    ASSERT_EQ(16, any.get<uint16_t>());

    any = detail::makeAnyValue(BuiltinTypeInfo<>::getUInt32(), 32, allocator);
    ASSERT_EQ(32, any.get<uint32_t>());

    any = detail::makeAnyValue(BuiltinTypeInfo<>::getUInt64(), 64, allocator);
    ASSERT_EQ(64, any.get<uint64_t>());

    any = detail::makeAnyValue(BuiltinTypeInfo<>::getInt8(), 8, allocator);
    ASSERT_EQ(8, any.get<int8_t>());

    any = detail::makeAnyValue(BuiltinTypeInfo<>::getInt16(), 16, allocator);
    ASSERT_EQ(16, any.get<int16_t>());

    any = detail::makeAnyValue(BuiltinTypeInfo<>::getInt32(), 32, allocator);
    ASSERT_EQ(32, any.get<int32_t>());

    any = detail::makeAnyValue(BuiltinTypeInfo<>::getInt64(), 64, allocator);
    ASSERT_EQ(64, any.get<int64_t>());

    any = detail::makeAnyValue(BuiltinTypeInfo<>::getFloat32(), 3.5f, allocator);
    ASSERT_EQ(3.5f, any.get<float>());

    any = detail::makeAnyValue(BuiltinTypeInfo<>::getFloat64(), 3.14, allocator);
    ASSERT_EQ(3.14, any.get<double>());
}

TEST(ZserioTreeCreatorTest, createObject)
{
    ZserioTreeCreator creator(DummyObject::typeInfo());
    creator.beginRoot();
    IReflectablePtr reflectable = creator.endRoot();
    ASSERT_TRUE(reflectable);
    ASSERT_EQ(CppType::STRUCT, reflectable->getTypeInfo().getCppType());
}

TEST(ZserioTreeCreatorTest, createObjectSetFields)
{
    ZserioTreeCreator creator(DummyObject::typeInfo());
    creator.beginRoot();
    creator.setValue("value", 13);
    creator.setValue("text", "test");
    IReflectablePtr reflectable = creator.endRoot();
    ASSERT_TRUE(reflectable);

    ASSERT_EQ(13, reflectable->getField("value")->getUInt32());
    ASSERT_EQ("test"_sv, reflectable->getField("text")->getString());
}

TEST(ZserioTreeCreatorTest, createObjectFull)
{
    ZserioTreeCreator creator(DummyObject::typeInfo());
    creator.beginRoot();
    creator.setValue("value", 13);
    creator.setValue("text", string<>("test"));
    creator.beginCompound("nested");
    creator.setValue("value", 10);
    creator.setValue("text", "nested"_sv);
    creator.setValue("data", BitBuffer({0x3c}, 6));
    creator.setValue("dummyEnum", DummyEnum::ONE);
    creator.setValue("dummyBitmask", DummyBitmask(DummyBitmask::Values::WRITE));
    creator.endCompound();
    creator.beginArray("nestedArray");
    creator.beginCompoundElement();
    creator.setValue("value", 5);
    const std::string nestedArrayText = "nestedArray";
    creator.setValue("text", nestedArrayText);
    creator.setValue("dummyEnum", DummyEnum::TWO);
    creator.setValue("dummyBitmask", DummyBitmask(DummyBitmask::Values::READ));
    creator.endCompoundElement();
    creator.endArray();
    creator.beginArray("textArray");
    creator.addValueElement("this");
    creator.addValueElement("is");
    creator.addValueElement("text"_sv);
    creator.addValueElement("array");
    creator.endArray();
    creator.beginArray("externArray");
    creator.addValueElement(BitBuffer({0x0F}, 4));
    creator.endArray();
    creator.setValue("optionalBool", false);
    creator.beginCompound("optionalNested");
    creator.setValue("text", "optionalNested");
    creator.endCompound();
    IReflectablePtr reflectable = creator.endRoot();
    ASSERT_TRUE(reflectable);

    reflectable->initializeChildren();

    ASSERT_EQ(13, reflectable->getField("value")->getUInt32());
    ASSERT_EQ("test"_sv, reflectable->getField("text")->getString());
    ASSERT_EQ(13, reflectable->find("nested.param")->getUInt32());
    ASSERT_EQ(10, reflectable->find("nested.value")->getUInt32());
    ASSERT_EQ("nested"_sv, reflectable->find("nested.text")->getString());
    ASSERT_EQ(0x3c, reflectable->find("nested.data")->getBitBuffer().getBuffer()[0]);
    ASSERT_EQ(6, reflectable->find("nested.data")->getBitBuffer().getBitSize());
    ASSERT_EQ(enumToValue(DummyEnum::ONE), reflectable->find("nested.dummyEnum")->getUInt8());
    ASSERT_EQ(DummyBitmask::Values::WRITE, DummyBitmask(reflectable->find("nested.dummyBitmask")->getUInt8()));
    ASSERT_EQ(1, reflectable->getField("nestedArray")->size());
    ASSERT_EQ(5, reflectable->getField("nestedArray")->at(0)->getField("value")->getUInt32());
    ASSERT_EQ("nestedArray"_sv, reflectable->getField("nestedArray")->at(0)->getField("text")->getString());
    ASSERT_EQ(enumToValue(DummyEnum::TWO),
            reflectable->getField("nestedArray")->at(0)->getField("dummyEnum")->getUInt8());
    ASSERT_EQ(DummyBitmask::Values::READ,
            DummyBitmask(reflectable->getField("nestedArray")->at(0)->getField("dummyBitmask")->getUInt8()));
    ASSERT_EQ(4, reflectable->getField("textArray")->size());
    ASSERT_EQ("this"_sv, reflectable->getField("textArray")->at(0)->getString());
    ASSERT_EQ("is"_sv, reflectable->getField("textArray")->at(1)->getString());
    ASSERT_EQ("text"_sv, reflectable->getField("textArray")->at(2)->getString());
    ASSERT_EQ("array"_sv, reflectable->getField("textArray")->at(3)->getString());
    ASSERT_EQ(1, reflectable->getField("externArray")->size());
    ASSERT_EQ(0x0f, reflectable->getField("externArray")->at(0)->getBitBuffer().getBuffer()[0]);
    ASSERT_EQ(4, reflectable->getField("externArray")->at(0)->getBitBuffer().getBitSize());
    ASSERT_EQ(false, reflectable->getField("optionalBool")->getBool());
    ASSERT_TRUE(reflectable->getField("optionalNested"));
    ASSERT_EQ("optionalNested"_sv, reflectable->find("optionalNested.text")->getString());
}

TEST(ZserioTreeCreator, exceptionsBeforeRoot)
{
    ZserioTreeCreator creator(DummyObject::typeInfo());

    ASSERT_THROW(creator.endRoot(), CppRuntimeException);
    ASSERT_THROW(creator.beginArray("nestedArray"), CppRuntimeException);
    ASSERT_THROW(creator.endArray(), CppRuntimeException);
    ASSERT_THROW(creator.beginCompound("nested"), CppRuntimeException);
    ASSERT_THROW(creator.endCompound(), CppRuntimeException);
    ASSERT_THROW(creator.setValue("value", 13), CppRuntimeException);
    ASSERT_THROW(creator.beginCompoundElement(), CppRuntimeException);
    ASSERT_THROW(creator.endCompoundElement(), CppRuntimeException);
    ASSERT_THROW(creator.addValueElement(13), CppRuntimeException);
}

TEST(ZserioTreeCreator, exceptionsInRoot)
{
    ZserioTreeCreator creator(DummyObject::typeInfo());
    creator.beginRoot();

    ASSERT_THROW(creator.beginRoot(), CppRuntimeException);
    ASSERT_THROW(creator.beginArray("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.beginArray("nested"), CppRuntimeException); // not an array
    ASSERT_THROW(creator.endArray(), CppRuntimeException);
    ASSERT_THROW(creator.beginCompound("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.beginCompound("nestedArray"), CppRuntimeException); // is array
    ASSERT_THROW(creator.endCompound(), CppRuntimeException);
    ASSERT_THROW(creator.setValue("nonexistent", 13), CppRuntimeException);
    ASSERT_THROW(creator.setValue("nestedArray", 13), CppRuntimeException); // is array
    ASSERT_THROW(creator.beginCompoundElement(), CppRuntimeException);
    ASSERT_THROW(creator.endCompoundElement(), CppRuntimeException);
    ASSERT_THROW(creator.addValueElement(13), CppRuntimeException);
}

TEST(ZserioTreeCreator, exceptionsInCompound)
{
    ZserioTreeCreator creator(DummyObject::typeInfo());
    creator.beginRoot();
    creator.beginCompound("nested");

    ASSERT_THROW(creator.beginRoot(), CppRuntimeException);
    ASSERT_THROW(creator.endRoot(), CppRuntimeException);
    ASSERT_THROW(creator.beginArray("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.beginArray("value"), CppRuntimeException); // not an array
    ASSERT_THROW(creator.endArray(), CppRuntimeException);
    ASSERT_THROW(creator.beginCompound("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.beginCompound("text"), CppRuntimeException); // not a compound
    ASSERT_THROW(creator.setValue("nonexistent", "test"), CppRuntimeException);
    ASSERT_THROW(creator.setValue("value", "test"), CppRuntimeException); // wrong type
    ASSERT_THROW(creator.beginCompoundElement(), CppRuntimeException);
    ASSERT_THROW(creator.endCompoundElement(), CppRuntimeException);
    ASSERT_THROW(creator.addValueElement(13), CppRuntimeException);
}

TEST(ZserioTreeCreator, exceptionsInCompoundArray)
{
    ZserioTreeCreator creator(DummyObject::typeInfo());
    creator.beginRoot();
    creator.beginArray("nestedArray");

    ASSERT_THROW(creator.beginRoot(), CppRuntimeException);
    ASSERT_THROW(creator.endRoot(), CppRuntimeException);
    ASSERT_THROW(creator.beginArray("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.beginCompound("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.endCompound(), CppRuntimeException);
    ASSERT_THROW(creator.setValue("nonexistent", 13), CppRuntimeException);
    ASSERT_THROW(creator.endCompoundElement(), CppRuntimeException);
    ASSERT_THROW(creator.addValueElement(13), CppRuntimeException);
}

TEST(ZserioTreeCreator, exceptionsInSimpleArray)
{
    ZserioTreeCreator creator(DummyObject::typeInfo());
    creator.beginRoot();
    creator.beginArray("textArray");

    ASSERT_THROW(creator.beginRoot(), CppRuntimeException);
    ASSERT_THROW(creator.endRoot(), CppRuntimeException);
    ASSERT_THROW(creator.beginArray("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.beginCompound("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.endCompound(), CppRuntimeException);
    ASSERT_THROW(creator.setValue("nonexistent", 13), CppRuntimeException);
    ASSERT_THROW(creator.beginCompoundElement(), CppRuntimeException); // not a compound array
    ASSERT_THROW(creator.endCompoundElement(), CppRuntimeException);
    ASSERT_THROW(creator.addValueElement(13), CppRuntimeException); // wrong type
}

TEST(ZserioTreeCreator, exceptionsInCompoundElement)
{
    ZserioTreeCreator creator(DummyObject::typeInfo());
    creator.beginRoot();
    creator.beginArray("nestedArray");
    creator.beginCompoundElement();

    ASSERT_THROW(creator.beginRoot(), CppRuntimeException);
    ASSERT_THROW(creator.endRoot(), CppRuntimeException);
    ASSERT_THROW(creator.beginArray("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.endArray(), CppRuntimeException);
    ASSERT_THROW(creator.beginCompound("nonexistent"), CppRuntimeException);
    ASSERT_THROW(creator.endCompound(), CppRuntimeException);
    ASSERT_THROW(creator.setValue("nonexistent", 13), CppRuntimeException);
    ASSERT_THROW(creator.beginCompoundElement(), CppRuntimeException);
    ASSERT_THROW(creator.addValueElement(13), CppRuntimeException);
}

} // namespace zserio