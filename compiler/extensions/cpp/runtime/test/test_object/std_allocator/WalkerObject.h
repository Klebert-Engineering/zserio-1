/**
 * Automatically generated by Zserio C++ generator version 1.0.2 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_WALKER_OBJECT_H
#define TEST_OBJECT_STD_ALLOCATOR_WALKER_OBJECT_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <memory>
#include <zserio/OptionalHolder.h>
#include <zserio/Array.h>
#include <zserio/ArrayTraits.h>
#include <zserio/String.h>
#include <zserio/Types.h>
#include <zserio/Vector.h>

#include <test_object/std_allocator/WalkerChoice.h>
#include <test_object/std_allocator/WalkerNested.h>
#include <test_object/std_allocator/WalkerUnion.h>

namespace test_object
{
namespace std_allocator
{

class WalkerObject
{
public:
    using allocator_type = ::std::allocator<uint8_t>;

    WalkerObject() noexcept :
            WalkerObject(allocator_type())
    {}

    explicit WalkerObject(const allocator_type& allocator) noexcept;

    template <typename ZSERIO_T_nested = ::test_object::std_allocator::WalkerNested,
            typename ZSERIO_T_text = ::zserio::string<>,
            typename ZSERIO_T_unionArray = ::zserio::vector<::test_object::std_allocator::WalkerUnion>,
            typename ZSERIO_T_optionalUnionArray = ::zserio::vector<::test_object::std_allocator::WalkerUnion>,
            typename ZSERIO_T_choiceField = ::test_object::std_allocator::WalkerChoice>
    WalkerObject(
            uint32_t identifier_,
            ZSERIO_T_nested&& nested_,
            ZSERIO_T_text&& text_,
            ZSERIO_T_unionArray&& unionArray_,
            ZSERIO_T_optionalUnionArray&& optionalUnionArray_,
            uint8_t choiceSelector_,
            ZSERIO_T_choiceField&& choiceField_,
            const allocator_type& allocator = allocator_type()) :
            WalkerObject(allocator)
    {
        m_identifier_ = identifier_;
        m_nested_ = ::std::forward<ZSERIO_T_nested>(nested_);
        m_text_ = ::std::forward<ZSERIO_T_text>(text_);
        m_unionArray_ = ZserioArrayType_unionArray(::std::forward<ZSERIO_T_unionArray>(unionArray_));
        m_optionalUnionArray_ = ::zserio::createOptionalArray<ZserioArrayType_optionalUnionArray>(::std::forward<ZSERIO_T_optionalUnionArray>(optionalUnionArray_));
        m_choiceSelector_ = choiceSelector_;
        m_choiceField_ = ::std::forward<ZSERIO_T_choiceField>(choiceField_);
    }

    explicit WalkerObject(::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());

    ~WalkerObject() = default;

    WalkerObject(const WalkerObject& other);
    WalkerObject& operator=(const WalkerObject& other);

    WalkerObject(WalkerObject&& other);
    WalkerObject& operator=(WalkerObject&& other);

    WalkerObject(::zserio::PropagateAllocatorT,
            const WalkerObject& other, const allocator_type& allocator);

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initializeChildren();

    uint32_t getIdentifier() const;
    void setIdentifier(uint32_t identifier_);

    const ::test_object::std_allocator::WalkerNested& getNested() const;
    ::test_object::std_allocator::WalkerNested& getNested();
    void setNested(const ::test_object::std_allocator::WalkerNested& nested_);
    void setNested(::test_object::std_allocator::WalkerNested&& nested_);
    bool isNestedUsed() const;
    bool isNestedSet() const;
    void resetNested();

    const ::zserio::string<>& getText() const;
    ::zserio::string<>& getText();
    void setText(const ::zserio::string<>& text_);
    void setText(::zserio::string<>&& text_);

    const ::zserio::vector<::test_object::std_allocator::WalkerUnion>& getUnionArray() const;
    ::zserio::vector<::test_object::std_allocator::WalkerUnion>& getUnionArray();
    void setUnionArray(const ::zserio::vector<::test_object::std_allocator::WalkerUnion>& unionArray_);
    void setUnionArray(::zserio::vector<::test_object::std_allocator::WalkerUnion>&& unionArray_);

    const ::zserio::vector<::test_object::std_allocator::WalkerUnion>& getOptionalUnionArray() const;
    ::zserio::vector<::test_object::std_allocator::WalkerUnion>& getOptionalUnionArray();
    void setOptionalUnionArray(const ::zserio::vector<::test_object::std_allocator::WalkerUnion>& optionalUnionArray_);
    void setOptionalUnionArray(::zserio::vector<::test_object::std_allocator::WalkerUnion>&& optionalUnionArray_);
    bool isOptionalUnionArrayUsed() const;
    bool isOptionalUnionArraySet() const;
    void resetOptionalUnionArray();

    uint8_t getChoiceSelector() const;
    void setChoiceSelector(uint8_t choiceSelector_);

    const ::test_object::std_allocator::WalkerChoice& getChoiceField() const;
    ::test_object::std_allocator::WalkerChoice& getChoiceField();
    void setChoiceField(const ::test_object::std_allocator::WalkerChoice& choiceField_);
    void setChoiceField(::test_object::std_allocator::WalkerChoice&& choiceField_);

    size_t bitSizeOf(size_t bitPosition = 0) const;

    size_t initializeOffsets(size_t bitPosition = 0);

    bool operator==(const WalkerObject& other) const;

    bool operator<(const WalkerObject& other) const;

    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;

private:
    class ZserioElementFactory_unionArray
    {
    public:
        using OwnerType = WalkerObject;

        static void create(WalkerObject& owner,
                ::zserio::vector<::test_object::std_allocator::WalkerUnion>& array,
                ::zserio::BitStreamReader& in, size_t index);
    };

    class ZserioElementFactory_optionalUnionArray
    {
    public:
        using OwnerType = WalkerObject;

        static void create(WalkerObject& owner,
                ::zserio::vector<::test_object::std_allocator::WalkerUnion>& array,
                ::zserio::BitStreamReader& in, size_t index);
    };

    using ZserioArrayType_unionArray = ::zserio::Array<::zserio::vector<::test_object::std_allocator::WalkerUnion>, ::zserio::ObjectArrayTraits<::test_object::std_allocator::WalkerUnion, ZserioElementFactory_unionArray>, ::zserio::ArrayType::AUTO>;
    using ZserioArrayType_optionalUnionArray = ::zserio::Array<::zserio::vector<::test_object::std_allocator::WalkerUnion>, ::zserio::ObjectArrayTraits<::test_object::std_allocator::WalkerUnion, ZserioElementFactory_optionalUnionArray>, ::zserio::ArrayType::AUTO>;

    uint32_t readIdentifier(::zserio::BitStreamReader& in);
    ::zserio::InplaceOptionalHolder<::test_object::std_allocator::WalkerNested> readNested(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::zserio::string<> readText(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ZserioArrayType_unionArray readUnionArray(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::zserio::InplaceOptionalHolder<ZserioArrayType_optionalUnionArray> readOptionalUnionArray(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    uint8_t readChoiceSelector(::zserio::BitStreamReader& in);
    ::test_object::std_allocator::WalkerChoice readChoiceField(::zserio::BitStreamReader& in,
            const allocator_type& allocator);

    bool m_areChildrenInitialized;
    uint32_t m_identifier_;
    ::zserio::InplaceOptionalHolder<::test_object::std_allocator::WalkerNested> m_nested_;
    ::zserio::string<> m_text_;
    ZserioArrayType_unionArray m_unionArray_;
    ::zserio::InplaceOptionalHolder<ZserioArrayType_optionalUnionArray> m_optionalUnionArray_;
    uint8_t m_choiceSelector_;
    ::test_object::std_allocator::WalkerChoice m_choiceField_;
};

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_WALKER_OBJECT_H
