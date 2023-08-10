/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_REFLECTABLE_OBJECT_H
#define TEST_OBJECT_STD_ALLOCATOR_REFLECTABLE_OBJECT_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/DeltaContext.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <memory>
#include <zserio/ArrayTraits.h>
#include <zserio/String.h>
#include <zserio/Types.h>

#include <test_object/std_allocator/ReflectableNested.h>

namespace test_object
{
namespace std_allocator
{

class ReflectableObject
{
public:

    class ZserioPackingContext
    {
    public:
        ::test_object::std_allocator::ReflectableNested::ZserioPackingContext& getReflectableNested()
        {
                return m_reflectableNested_;
        }

    private:
        ::test_object::std_allocator::ReflectableNested::ZserioPackingContext m_reflectableNested_;
    };

public:
    using allocator_type = ::std::allocator<uint8_t>;

    ReflectableObject() noexcept :
            ReflectableObject(allocator_type())
    {}

    explicit ReflectableObject(const allocator_type& allocator) noexcept;

    template <typename ZSERIO_T_stringField = ::zserio::string<>,
            typename ZSERIO_T_reflectableNested = ::test_object::std_allocator::ReflectableNested,
            ::zserio::is_field_constructor_enabled_t<ZSERIO_T_stringField, ReflectableObject, allocator_type> = 0>
    ReflectableObject(
            ZSERIO_T_stringField&& stringField_,
            ZSERIO_T_reflectableNested&& reflectableNested_,
            const allocator_type& allocator = allocator_type()) :
            ReflectableObject(allocator)
    {
        m_stringField_ = ::std::forward<ZSERIO_T_stringField>(stringField_);
        m_reflectableNested_ = ::std::forward<ZSERIO_T_reflectableNested>(reflectableNested_);
    }

    explicit ReflectableObject(::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());
    explicit ReflectableObject(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());

    ~ReflectableObject() = default;

    ReflectableObject(const ReflectableObject& other);
    ReflectableObject& operator=(const ReflectableObject& other);

    ReflectableObject(ReflectableObject&& other);
    ReflectableObject& operator=(ReflectableObject&& other);

    ReflectableObject(::zserio::PropagateAllocatorT,
            const ReflectableObject& other, const allocator_type& allocator);

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initializeChildren();

    const ::zserio::string<>& getStringField() const;
    ::zserio::string<>& getStringField();
    void setStringField(const ::zserio::string<>& stringField_);
    void setStringField(::zserio::string<>&& stringField_);

    const ::test_object::std_allocator::ReflectableNested& getReflectableNested() const;
    ::test_object::std_allocator::ReflectableNested& getReflectableNested();
    void setReflectableNested(const ::test_object::std_allocator::ReflectableNested& reflectableNested_);
    void setReflectableNested(::test_object::std_allocator::ReflectableNested&& reflectableNested_);

    void initPackingContext(ZserioPackingContext& context) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(ZserioPackingContext& context, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(ZserioPackingContext& context, size_t bitPosition);

    bool operator==(const ReflectableObject& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const;

private:
    ::zserio::string<> readStringField(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::test_object::std_allocator::ReflectableNested readReflectableNested(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::test_object::std_allocator::ReflectableNested readReflectableNested(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in, const allocator_type& allocator);

    bool m_areChildrenInitialized;
    ::zserio::string<> m_stringField_;
    ::test_object::std_allocator::ReflectableNested m_reflectableNested_;
};

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_REFLECTABLE_OBJECT_H
