/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorphicAllocator.
 */

#ifndef TEST_OBJECT_POLYMORPHIC_ALLOCATOR_ARRAY_OBJECT_H
#define TEST_OBJECT_POLYMORPHIC_ALLOCATOR_ARRAY_OBJECT_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/DeltaContext.h>
#include <zserio/pmr/ITypeInfo.h>
#include <zserio/pmr/IReflectable.h>
#include <zserio/pmr/PolymorphicAllocator.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

namespace test_object
{
namespace polymorphic_allocator
{

class ArrayObject
{
public:
    class ZserioPackingContext
    {
    public:
        ::zserio::DeltaContext& getValue()
        {
            return m_value_;
        }

    private:
        ::zserio::DeltaContext m_value_;
    };

    using allocator_type = ::zserio::pmr::PropagatingPolymorphicAllocator<>;

    ArrayObject() noexcept :
            ArrayObject(allocator_type())
    {}

    explicit ArrayObject(const allocator_type& allocator) noexcept;

    explicit ArrayObject(
            uint32_t value_,
            const allocator_type& allocator = allocator_type()) :
            ArrayObject(allocator)
    {
        m_value_ = value_;
    }

    explicit ArrayObject(::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());
    explicit ArrayObject(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());

    ~ArrayObject() = default;

    ArrayObject(const ArrayObject&) = default;
    ArrayObject& operator=(const ArrayObject&) = default;

    ArrayObject(ArrayObject&&) = default;
    ArrayObject& operator=(ArrayObject&&) = default;

    ArrayObject(::zserio::PropagateAllocatorT,
            const ArrayObject& other, const allocator_type& allocator);

    static const ::zserio::pmr::ITypeInfo& typeInfo();
    ::zserio::pmr::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::pmr::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    uint32_t getValue() const;
    void setValue(uint32_t value_);

    void initPackingContext(ZserioPackingContext& context) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(ZserioPackingContext& context, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(ZserioPackingContext& context, size_t bitPosition);

    bool operator==(const ArrayObject& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const;

private:
    uint32_t readValue(::zserio::BitStreamReader& in);
    uint32_t readValue(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in);

    uint32_t m_value_;
};

} // namespace polymorphic_allocator
} // namespace test_object

#endif // TEST_OBJECT_POLYMORPHIC_ALLOCATOR_ARRAY_OBJECT_H
