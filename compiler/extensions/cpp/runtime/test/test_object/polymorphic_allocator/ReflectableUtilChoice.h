/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorhpicAllocator.
 */

#ifndef TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_UTIL_CHOICE_H
#define TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_UTIL_CHOICE_H

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
#include <zserio/pmr/Vector.h>

namespace test_object
{
namespace polymorphic_allocator
{

class ReflectableUtilChoice
{
private:
    using ZserioArrayType_array = ::zserio::Array<::zserio::pmr::vector<uint32_t>, ::zserio::StdIntArrayTraits<uint32_t>, ::zserio::ArrayType::AUTO>;

public:
    using allocator_type = ::zserio::pmr::PropagatingPolymorphicAllocator<>;

    enum ChoiceTag : int32_t
    {
        CHOICE_array = 0,
        UNDEFINED_CHOICE = -1
    };

    ReflectableUtilChoice() noexcept :
            ReflectableUtilChoice(allocator_type())
    {}

    explicit ReflectableUtilChoice(const allocator_type& allocator) noexcept;

    explicit ReflectableUtilChoice(::zserio::BitStreamReader& in,
            uint8_t param_, const allocator_type& allocator = allocator_type());
    explicit ReflectableUtilChoice(::zserio::pmr::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in,
            uint8_t param_, const allocator_type& allocator = allocator_type());

    ~ReflectableUtilChoice() = default;

    ReflectableUtilChoice(const ReflectableUtilChoice& other);
    ReflectableUtilChoice& operator=(const ReflectableUtilChoice& other);

    ReflectableUtilChoice(ReflectableUtilChoice&& other);
    ReflectableUtilChoice& operator=(ReflectableUtilChoice&& other);

    ReflectableUtilChoice(::zserio::PropagateAllocatorT,
            const ReflectableUtilChoice& other, const allocator_type& allocator);

    static const ::zserio::pmr::ITypeInfo& typeInfo();
    ::zserio::pmr::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::pmr::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initialize(
            uint8_t param_);
    bool isInitialized() const;

    ChoiceTag choiceTag() const;

    uint8_t getParam() const;

    const ::zserio::pmr::vector<uint32_t>& getArray() const;
    ::zserio::pmr::vector<uint32_t>& getArray();
    void setArray(const ::zserio::pmr::vector<uint32_t>& array_);
    void setArray(::zserio::pmr::vector<uint32_t>&& array_);

    static void createPackingContext(::zserio::pmr::PackingContextNode& contextNode);
    void initPackingContext(::zserio::pmr::PackingContextNode& contextNode) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition);

    bool operator==(const ReflectableUtilChoice& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const;

private:
    ::zserio::pmr::AnyHolder readObject(::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::pmr::AnyHolder readObject(::zserio::pmr::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::pmr::AnyHolder copyObject(const allocator_type& allocator) const;

    uint8_t m_param_;
    bool m_isInitialized;
    ::zserio::pmr::AnyHolder m_objectChoice;
};

} // namespace polymorphic_allocator
} // namespace test_object

#endif // TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_UTIL_CHOICE_H