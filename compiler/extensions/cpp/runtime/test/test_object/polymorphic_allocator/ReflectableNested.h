/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorhpicAllocator.
 */

#ifndef TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_NESTED_H
#define TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_NESTED_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/PackingContext.h>
#include <zserio/pmr/ITypeInfo.h>
#include <zserio/pmr/IReflectable.h>
#include <zserio/pmr/PolymorphicAllocator.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>
#include <zserio/pmr/ArrayTraits.h>
#include <zserio/pmr/String.h>

namespace test_object
{
namespace polymorphic_allocator
{

class ReflectableNested
{
public:
    using allocator_type = ::zserio::pmr::PropagatingPolymorphicAllocator<>;

    class ZserioPackingContext
    {
    public:
        ::zserio::DeltaContext& getValue() { return m_value_; }

    private:
        ::zserio::DeltaContext m_value_;
    };

    ReflectableNested() noexcept :
            ReflectableNested(allocator_type())
    {}

    explicit ReflectableNested(const allocator_type& allocator) noexcept;

    explicit ReflectableNested(
            uint32_t value_,
            const allocator_type& allocator = allocator_type()) :
            ReflectableNested(allocator)
    {
        m_value_ = value_;
    }

    explicit ReflectableNested(::zserio::BitStreamReader& in,
            int32_t dummyParam_,
            ::zserio::pmr::string& stringParam_, const allocator_type& allocator = allocator_type());
    explicit ReflectableNested(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in,
            int32_t dummyParam_,
            ::zserio::pmr::string& stringParam_, const allocator_type& allocator = allocator_type());

    ~ReflectableNested() = default;

    ReflectableNested(const ReflectableNested& other);
    ReflectableNested& operator=(const ReflectableNested& other);

    ReflectableNested(ReflectableNested&& other);
    ReflectableNested& operator=(ReflectableNested&& other);

    ReflectableNested(::zserio::PropagateAllocatorT,
            const ReflectableNested& other, const allocator_type& allocator);

    static const ::zserio::pmr::ITypeInfo& typeInfo();
    ::zserio::pmr::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::pmr::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initialize(
            int32_t dummyParam_,
            ::zserio::pmr::string& stringParam_);
    bool isInitialized() const;

    int32_t getDummyParam() const;

    ::zserio::pmr::string& getStringParam();
    const ::zserio::pmr::string& getStringParam() const;

    uint32_t getValue() const;
    void setValue(uint32_t value_);

    uint32_t funcGetValue() const;

    void initPackingContext(ZserioPackingContext& context) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(ZserioPackingContext& context, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(ZserioPackingContext& context, size_t bitPosition);

    bool operator==(const ReflectableNested& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const;

private:
    uint32_t readValue(::zserio::BitStreamReader& in);
    uint32_t readValue(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in);

    int32_t m_dummyParam_;
    ::zserio::pmr::string* m_stringParam_;
    bool m_isInitialized;
    uint32_t m_value_;
};

} // namespace polymorphic_allocator
} // namespace test_object

#endif // TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_NESTED_H
