/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorphicAllocator.
 */

#ifndef TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_UTIL_UNION_H
#define TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_UTIL_UNION_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/DeltaContext.h>
#include <zserio/pmr/ITypeInfo.h>
#include <zserio/pmr/IReflectable.h>
#include <zserio/pmr/AnyHolder.h>
#include <zserio/pmr/PolymorphicAllocator.h>
#include <zserio/ArrayTraits.h>

#include <test_object/polymorphic_allocator/ReflectableUtilBitmask.h>
#include <test_object/polymorphic_allocator/ReflectableUtilEnum.h>
#include <test_object/polymorphic_allocator/ReflectableUtilObject.h>

namespace test_object
{
namespace polymorphic_allocator
{

class ReflectableUtilUnion
{
public:
    using allocator_type = ::zserio::pmr::PropagatingPolymorphicAllocator<>;

    enum ChoiceTag : int32_t
    {
        CHOICE_reflectableUtilEnum = 0,
        CHOICE_reflectableUtilBitmask = 1,
        CHOICE_reflectableUtilObject = 2,
        UNDEFINED_CHOICE = -1
    };

    class ZserioPackingContext
    {
    public:
        ::zserio::DeltaContext& getChoiceTag()
        {
            return m_choiceTag;
        }

        ::zserio::DeltaContext& getReflectableUtilEnum()
        {
            return m_reflectableUtilEnum_;
        }

        ::zserio::DeltaContext& getReflectableUtilBitmask()
        {
            return m_reflectableUtilBitmask_;
        }

        ::test_object::polymorphic_allocator::ReflectableUtilObject::ZserioPackingContext& getReflectableUtilObject()
        {
            return m_reflectableUtilObject_;
        }

    private:
        ::zserio::DeltaContext m_choiceTag;
        ::zserio::DeltaContext m_reflectableUtilEnum_;
        ::zserio::DeltaContext m_reflectableUtilBitmask_;
        ::test_object::polymorphic_allocator::ReflectableUtilObject::ZserioPackingContext m_reflectableUtilObject_;
    };

    ReflectableUtilUnion() noexcept :
            ReflectableUtilUnion(allocator_type())
    {}

    explicit ReflectableUtilUnion(const allocator_type& allocator) noexcept;

    explicit ReflectableUtilUnion(::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());
    explicit ReflectableUtilUnion(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());

    ~ReflectableUtilUnion() = default;

    ReflectableUtilUnion(const ReflectableUtilUnion&) = default;
    ReflectableUtilUnion& operator=(const ReflectableUtilUnion&) = default;

    ReflectableUtilUnion(ReflectableUtilUnion&&) = default;
    ReflectableUtilUnion& operator=(ReflectableUtilUnion&&) = default;

    ReflectableUtilUnion(::zserio::PropagateAllocatorT,
            const ReflectableUtilUnion& other, const allocator_type& allocator);

    static const ::zserio::pmr::ITypeInfo& typeInfo();
    ::zserio::pmr::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::pmr::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initializeChildren();

    ChoiceTag choiceTag() const;

    ::test_object::polymorphic_allocator::ReflectableUtilEnum getReflectableUtilEnum() const;
    void setReflectableUtilEnum(::test_object::polymorphic_allocator::ReflectableUtilEnum reflectableUtilEnum_);

    ::test_object::polymorphic_allocator::ReflectableUtilBitmask getReflectableUtilBitmask() const;
    void setReflectableUtilBitmask(::test_object::polymorphic_allocator::ReflectableUtilBitmask reflectableUtilBitmask_);

    const ::test_object::polymorphic_allocator::ReflectableUtilObject& getReflectableUtilObject() const;
    ::test_object::polymorphic_allocator::ReflectableUtilObject& getReflectableUtilObject();
    void setReflectableUtilObject(const ::test_object::polymorphic_allocator::ReflectableUtilObject& reflectableUtilObject_);
    void setReflectableUtilObject(::test_object::polymorphic_allocator::ReflectableUtilObject&& reflectableUtilObject_);
    void initPackingContext(ZserioPackingContext& context) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(ZserioPackingContext& context, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(ZserioPackingContext& context, size_t bitPosition);

    bool operator==(const ReflectableUtilUnion& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const;

private:
    ChoiceTag readChoiceTag(::zserio::BitStreamReader& in);
    ChoiceTag readChoiceTag(ZserioPackingContext& context, ::zserio::BitStreamReader& in);
    ::zserio::pmr::AnyHolder readObject(::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::pmr::AnyHolder readObject(ZserioPackingContext& context, ::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::zserio::pmr::AnyHolder copyObject(const allocator_type& allocator) const;

    ChoiceTag m_choiceTag;
    ::zserio::pmr::AnyHolder m_objectChoice;
};

} // namespace polymorphic_allocator
} // namespace test_object

#endif // TEST_OBJECT_POLYMORPHIC_ALLOCATOR_REFLECTABLE_UTIL_UNION_H
