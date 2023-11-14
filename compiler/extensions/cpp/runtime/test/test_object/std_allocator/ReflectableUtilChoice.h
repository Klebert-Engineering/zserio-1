/**
 * Automatically generated by Zserio C++ extension version 2.12.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_REFLECTABLE_UTIL_CHOICE_H
#define TEST_OBJECT_STD_ALLOCATOR_REFLECTABLE_UTIL_CHOICE_H

#include <zserio/Traits.h>
#include <zserio/NoInit.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/DeltaContext.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <zserio/AnyHolder.h>
#include <memory>
#include <zserio/Array.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>
#include <zserio/Vector.h>

namespace test_object
{
namespace std_allocator
{

class ReflectableUtilChoice
{
public:
    using allocator_type = ::std::allocator<uint8_t>;

    enum ChoiceTag : int32_t
    {
        CHOICE_array = 0,
        UNDEFINED_CHOICE = -1
    };

    class ZserioPackingContext
    {
    };

    ReflectableUtilChoice() noexcept :
            ReflectableUtilChoice(allocator_type())
    {}

    explicit ReflectableUtilChoice(const allocator_type& allocator) noexcept;

    explicit ReflectableUtilChoice(::zserio::BitStreamReader& in,
            uint8_t param_, const allocator_type& allocator = allocator_type());
    explicit ReflectableUtilChoice(ZserioPackingContext& context,
            ::zserio::BitStreamReader& in,
            uint8_t param_, const allocator_type& allocator = allocator_type());

    ~ReflectableUtilChoice() = default;

    ReflectableUtilChoice(const ReflectableUtilChoice& other);
    ReflectableUtilChoice& operator=(const ReflectableUtilChoice& other);

    ReflectableUtilChoice(ReflectableUtilChoice&& other);
    ReflectableUtilChoice& operator=(ReflectableUtilChoice&& other);

    ReflectableUtilChoice(::zserio::NoInitT,
            const ReflectableUtilChoice& other);
    ReflectableUtilChoice& assign(::zserio::NoInitT, const ReflectableUtilChoice& other);

    ReflectableUtilChoice(::zserio::NoInitT, ReflectableUtilChoice&& other);
    ReflectableUtilChoice& assign(::zserio::NoInitT,
            ReflectableUtilChoice&& other);

    ReflectableUtilChoice(::zserio::PropagateAllocatorT,
            const ReflectableUtilChoice& other, const allocator_type& allocator);
    ReflectableUtilChoice(::zserio::PropagateAllocatorT, ::zserio::NoInitT,
            const ReflectableUtilChoice& other, const allocator_type& allocator);

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initialize(
            uint8_t param_);
    bool isInitialized() const;

    ChoiceTag choiceTag() const;

    uint8_t getParam() const;

    const ::zserio::vector<uint32_t>& getArray() const;
    ::zserio::vector<uint32_t>& getArray();
    void setArray(const ::zserio::vector<uint32_t>& array_);
    void setArray(::zserio::vector<uint32_t>&& array_);
    void initPackingContext(ZserioPackingContext& context) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(ZserioPackingContext& context, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(ZserioPackingContext& context, size_t bitPosition);

    bool operator==(const ReflectableUtilChoice& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(ZserioPackingContext& context, ::zserio::BitStreamWriter& out) const;

private:
    using ZserioArrayType_array = ::zserio::Array<::zserio::vector<uint32_t>, ::zserio::StdIntArrayTraits<uint32_t>, ::zserio::ArrayType::AUTO>;

    ::zserio::AnyHolder<> readObject(::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::AnyHolder<> readObject(ZserioPackingContext& context, ::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::zserio::AnyHolder<> copyObject(const allocator_type& allocator) const;

    uint8_t m_param_;
    bool m_isInitialized;
    ::zserio::AnyHolder<> m_objectChoice;
};

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_REFLECTABLE_UTIL_CHOICE_H
