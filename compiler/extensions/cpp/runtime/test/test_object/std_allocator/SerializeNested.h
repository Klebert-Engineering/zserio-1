/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_SERIALIZE_NESTED_H
#define TEST_OBJECT_STD_ALLOCATOR_SERIALIZE_NESTED_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/DeltaContext.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <memory>
#include <zserio/OptionalHolder.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

namespace test_object
{
namespace std_allocator
{

class SerializeNested
{
public:
    class ZserioPackingContext
    {
    public:
        ::zserio::DeltaContext& getOptionalValue()
        {
            return m_optionalValue_;
        }

    private:
        ::zserio::DeltaContext m_optionalValue_;
    };

    using allocator_type = ::std::allocator<uint8_t>;

    SerializeNested() noexcept :
            SerializeNested(allocator_type())
    {}

    explicit SerializeNested(const allocator_type& allocator) noexcept;

    template <typename ZSERIO_T_optionalValue = uint32_t>
    SerializeNested(
            uint8_t offset_,
            ZSERIO_T_optionalValue&& optionalValue_,
            const allocator_type& allocator = allocator_type()) :
            SerializeNested(allocator)
    {
        m_offset_ = offset_;
        m_optionalValue_ = ::std::forward<ZSERIO_T_optionalValue>(optionalValue_);
    }

    explicit SerializeNested(::zserio::BitStreamReader& in,
            int8_t param_, const allocator_type& allocator = allocator_type());
    explicit SerializeNested(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in,
            int8_t param_, const allocator_type& allocator = allocator_type());

    ~SerializeNested() = default;

    SerializeNested(const SerializeNested& other);
    SerializeNested& operator=(const SerializeNested& other);

    SerializeNested(SerializeNested&& other);
    SerializeNested& operator=(SerializeNested&& other);

    SerializeNested(::zserio::PropagateAllocatorT,
            const SerializeNested& other, const allocator_type& allocator);

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initialize(
            int8_t param_);
    bool isInitialized() const;

    int8_t getParam() const;

    uint8_t getOffset() const;
    void setOffset(uint8_t offset_);

    uint32_t getOptionalValue() const;
    void setOptionalValue(uint32_t optionalValue_);
    bool isOptionalValueUsed() const;
    bool isOptionalValueSet() const;
    void resetOptionalValue();

    void initPackingContext(ZserioPackingContext& context) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(ZserioPackingContext& context, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(ZserioPackingContext& context, size_t bitPosition);

    bool operator==(const SerializeNested& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const;

private:
    uint8_t readOffset(::zserio::BitStreamReader& in);
    ::zserio::InplaceOptionalHolder<uint32_t> readOptionalValue(::zserio::BitStreamReader& in);
    ::zserio::InplaceOptionalHolder<uint32_t> readOptionalValue(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in);

    int8_t m_param_;
    bool m_isInitialized;
    uint8_t m_offset_;
    ::zserio::InplaceOptionalHolder<uint32_t> m_optionalValue_;
};

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_SERIALIZE_NESTED_H
