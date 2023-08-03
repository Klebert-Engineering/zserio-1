/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorhpicAllocator.
 */

#ifndef TEST_OBJECT_POLYMORPHIC_ALLOCATOR_SERIALIZE_OBJECT_H
#define TEST_OBJECT_POLYMORPHIC_ALLOCATOR_SERIALIZE_OBJECT_H

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

#include <test_object/polymorphic_allocator/SerializeNested.h>

namespace test_object
{
namespace polymorphic_allocator
{

class SerializeObject
{
public:
    using allocator_type = ::zserio::pmr::PropagatingPolymorphicAllocator<>;

    class ZserioPackingContext
    {
    public:
        ::zserio::DeltaContext& getParam() { return m_param_; }
        ::test_object::polymorphic_allocator::SerializeNested::ZserioPackingContext& getNested() { return m_nested_; }

    private:
        ::zserio::DeltaContext m_param_;
        ::test_object::polymorphic_allocator::SerializeNested::ZserioPackingContext m_nested_;
    };

    SerializeObject() noexcept :
            SerializeObject(allocator_type())
    {}

    explicit SerializeObject(const allocator_type& allocator) noexcept;

    template <typename ZSERIO_T_nested = ::test_object::polymorphic_allocator::SerializeNested>
    SerializeObject(
            int8_t param_,
            ZSERIO_T_nested&& nested_,
            const allocator_type& allocator = allocator_type()) :
            SerializeObject(allocator)
    {
        m_param_ = param_;
        m_nested_ = ::std::forward<ZSERIO_T_nested>(nested_);
    }

    explicit SerializeObject(::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());
    explicit SerializeObject(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());

    ~SerializeObject() = default;

    SerializeObject(const SerializeObject& other);
    SerializeObject& operator=(const SerializeObject& other);

    SerializeObject(SerializeObject&& other);
    SerializeObject& operator=(SerializeObject&& other);

    SerializeObject(::zserio::PropagateAllocatorT,
            const SerializeObject& other, const allocator_type& allocator);

    static const ::zserio::pmr::ITypeInfo& typeInfo();
    ::zserio::pmr::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::pmr::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initializeChildren();

    int8_t getParam() const;
    void setParam(int8_t param_);

    const ::test_object::polymorphic_allocator::SerializeNested& getNested() const;
    ::test_object::polymorphic_allocator::SerializeNested& getNested();
    void setNested(const ::test_object::polymorphic_allocator::SerializeNested& nested_);
    void setNested(::test_object::polymorphic_allocator::SerializeNested&& nested_);

    void initPackingContext(ZserioPackingContext& context) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(ZserioPackingContext& context, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(ZserioPackingContext& context, size_t bitPosition);

    bool operator==(const SerializeObject& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const;

private:
    int8_t readParam(::zserio::BitStreamReader& in);
    int8_t readParam(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in);
    ::test_object::polymorphic_allocator::SerializeNested readNested(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::test_object::polymorphic_allocator::SerializeNested readNested(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in, const allocator_type& allocator);

    bool m_areChildrenInitialized;
    int8_t m_param_;
    ::test_object::polymorphic_allocator::SerializeNested m_nested_;
};

} // namespace polymorphic_allocator
} // namespace test_object

#endif // TEST_OBJECT_POLYMORPHIC_ALLOCATOR_SERIALIZE_OBJECT_H
