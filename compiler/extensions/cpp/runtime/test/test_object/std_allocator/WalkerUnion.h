/**
 * Automatically generated by Zserio C++ extension version 2.9.0-pre1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_WALKER_UNION_H
#define TEST_OBJECT_STD_ALLOCATOR_WALKER_UNION_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <zserio/AnyHolder.h>
#include <memory>
#include <zserio/PackingContext.h>
#include <zserio/Array.h>
#include <zserio/ArrayTraits.h>
#include <zserio/String.h>
#include <zserio/Types.h>
#include <zserio/Vector.h>

#include <test_object/std_allocator/WalkerNested.h>

namespace test_object
{
namespace std_allocator
{

class WalkerUnion
{
private:
    class ZserioElementFactory_nestedArray
    {
    public:
        explicit ZserioElementFactory_nestedArray(WalkerUnion& owner);

        void create(::zserio::vector<::test_object::std_allocator::WalkerNested>& array,
                ::zserio::BitStreamReader& in, size_t index) const;

        void create(::zserio::PackingContextNode& contextNode,
                ::zserio::vector<::test_object::std_allocator::WalkerNested>& array,
                ::zserio::BitStreamReader& in, size_t index) const;

    private:
        std::reference_wrapper<WalkerUnion> m_ownerRef;
    };

    using ZserioArrayType_nestedArray = ::zserio::Array<::zserio::vector<::test_object::std_allocator::WalkerNested>, ::zserio::ObjectArrayTraits<::test_object::std_allocator::WalkerNested, ZserioElementFactory_nestedArray>, ::zserio::ArrayType::AUTO>;

public:
    using allocator_type = ::std::allocator<uint8_t>;

    enum ChoiceTag : int32_t
    {
        CHOICE_value = 0,
        CHOICE_text = 1,
        CHOICE_nestedArray = 2,
        UNDEFINED_CHOICE = -1
    };

    explicit WalkerUnion(const allocator_type& allocator = allocator_type()) noexcept;

    explicit WalkerUnion(::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());
    explicit WalkerUnion(::zserio::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());

    ~WalkerUnion() = default;

    WalkerUnion(const WalkerUnion&) = default;
    WalkerUnion& operator=(const WalkerUnion&) = default;

    WalkerUnion(WalkerUnion&&) = default;
    WalkerUnion& operator=(WalkerUnion&&) = default;

    WalkerUnion(::zserio::PropagateAllocatorT,
            const WalkerUnion& other, const allocator_type& allocator);

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    ChoiceTag choiceTag() const;

    uint32_t getValue() const;
    void setValue(uint32_t value_);

    const ::zserio::string<>& getText() const;
    ::zserio::string<>& getText();
    void setText(const ::zserio::string<>& text_);
    void setText(::zserio::string<>&& text_);

    const ::zserio::vector<::test_object::std_allocator::WalkerNested>& getNestedArray() const;
    ::zserio::vector<::test_object::std_allocator::WalkerNested>& getNestedArray();
    void setNestedArray(const ::zserio::vector<::test_object::std_allocator::WalkerNested>& nestedArray_);
    void setNestedArray(::zserio::vector<::test_object::std_allocator::WalkerNested>&& nestedArray_);

    static void createPackingContext(::zserio::PackingContextNode& contextNode);
    void initPackingContext(::zserio::PackingContextNode& contextNode) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(::zserio::PackingContextNode& contextNode, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(::zserio::PackingContextNode& contextNode, size_t bitPosition);

    bool operator==(const WalkerUnion& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const;

private:
    ChoiceTag readChoiceTag(::zserio::BitStreamReader& in);
    ChoiceTag readChoiceTag(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in);
    ::zserio::AnyHolder<> readObject(::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::AnyHolder<> readObject(::zserio::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::AnyHolder<> copyObject(const allocator_type& allocator) const;

    ChoiceTag m_choiceTag;
    ::zserio::AnyHolder<> m_objectChoice;
};

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_WALKER_UNION_H
