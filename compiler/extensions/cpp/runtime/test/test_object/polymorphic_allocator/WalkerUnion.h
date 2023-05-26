/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorhpicAllocator.
 */

#ifndef TEST_OBJECT_POLYMORPHIC_ALLOCATOR_WALKER_UNION_H
#define TEST_OBJECT_POLYMORPHIC_ALLOCATOR_WALKER_UNION_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/pmr/ITypeInfo.h>
#include <zserio/pmr/IReflectable.h>
#include <zserio/pmr/AnyHolder.h>
#include <zserio/pmr/PolymorphicAllocator.h>
#include <zserio/pmr/PackingContext.h>
#include <zserio/Array.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>
#include <zserio/pmr/ArrayTraits.h>
#include <zserio/pmr/String.h>
#include <zserio/pmr/Vector.h>

#include <test_object/polymorphic_allocator/WalkerNested.h>

namespace test_object
{
namespace polymorphic_allocator
{

class WalkerUnion
{
private:
    class ZserioElementFactory_nestedArray
    {
    public:
        using OwnerType = WalkerUnion;

        static ::test_object::polymorphic_allocator::WalkerNested create(WalkerUnion& owner,
                ::zserio::BitStreamReader& in, const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator, size_t index);

        static ::test_object::polymorphic_allocator::WalkerNested create(WalkerUnion& owner,
                ::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in,
                const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator, size_t index);
    };

    using ZserioArrayType_nestedArray = ::zserio::Array<::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>, ::zserio::ObjectArrayTraits<::test_object::polymorphic_allocator::WalkerNested, ZserioElementFactory_nestedArray>, ::zserio::ArrayType::AUTO>;

public:
    using allocator_type = ::zserio::pmr::PropagatingPolymorphicAllocator<>;

    enum ChoiceTag : int32_t
    {
        CHOICE_value = 0,
        CHOICE_text = 1,
        CHOICE_nestedArray = 2,
        UNDEFINED_CHOICE = -1
    };

    WalkerUnion() noexcept :
            WalkerUnion(allocator_type())
    {}

    explicit WalkerUnion(const allocator_type& allocator) noexcept;

    explicit WalkerUnion(::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());
    explicit WalkerUnion(::zserio::pmr::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());

    ~WalkerUnion() = default;

    WalkerUnion(const WalkerUnion&) = default;
    WalkerUnion& operator=(const WalkerUnion&) = default;

    WalkerUnion(WalkerUnion&&) = default;
    WalkerUnion& operator=(WalkerUnion&&) = default;

    WalkerUnion(::zserio::PropagateAllocatorT,
            const WalkerUnion& other, const allocator_type& allocator);

    static const ::zserio::pmr::ITypeInfo& typeInfo();
    ::zserio::pmr::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::pmr::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    ChoiceTag choiceTag() const;

    uint32_t getValue() const;
    void setValue(uint32_t value_);

    const ::zserio::pmr::string& getText() const;
    ::zserio::pmr::string& getText();
    void setText(const ::zserio::pmr::string& text_);
    void setText(::zserio::pmr::string&& text_);

    const ::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>& getNestedArray() const;
    ::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>& getNestedArray();
    void setNestedArray(const ::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>& nestedArray_);
    void setNestedArray(::zserio::pmr::vector<::test_object::polymorphic_allocator::WalkerNested>&& nestedArray_);

    static void createPackingContext(::zserio::pmr::PackingContextNode& contextNode);
    void initPackingContext(::zserio::pmr::PackingContextNode& contextNode) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition);

    bool operator==(const WalkerUnion& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const;

private:
    ChoiceTag readChoiceTag(::zserio::BitStreamReader& in);
    ChoiceTag readChoiceTag(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in);
    ::zserio::pmr::AnyHolder readObject(::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::pmr::AnyHolder readObject(::zserio::pmr::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::pmr::AnyHolder copyObject(const allocator_type& allocator) const;

    ChoiceTag m_choiceTag;
    ::zserio::pmr::AnyHolder m_objectChoice;
};

} // namespace polymorphic_allocator
} // namespace test_object

#endif // TEST_OBJECT_POLYMORPHIC_ALLOCATOR_WALKER_UNION_H
