/**
 * Automatically generated by Zserio C++ generator version 1.0.2 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_CREATOR_NESTED_H
#define TEST_OBJECT_STD_ALLOCATOR_CREATOR_NESTED_H

#include <zserio/Traits.h>
#include <zserio/NoInit.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <memory>
#include <zserio/ArrayTraits.h>
#include <zserio/BitBuffer.h>
#include <zserio/String.h>
#include <zserio/Types.h>
#include <zserio/Vector.h>

#include <test_object/std_allocator/CreatorBitmask.h>
#include <test_object/std_allocator/CreatorEnum.h>

namespace test_object
{
namespace std_allocator
{

class CreatorNested
{
public:
    using allocator_type = ::std::allocator<uint8_t>;

    CreatorNested() noexcept :
            CreatorNested(allocator_type())
    {}

    explicit CreatorNested(const allocator_type& allocator) noexcept;

    template <typename ZSERIO_T_text = ::zserio::string<>,
            typename ZSERIO_T_externData = ::zserio::BitBuffer,
            typename ZSERIO_T_bytesData = ::zserio::vector<uint8_t>>
    CreatorNested(
            uint32_t value_,
            ZSERIO_T_text&& text_,
            ZSERIO_T_externData&& externData_,
            ZSERIO_T_bytesData&& bytesData_,
            ::test_object::std_allocator::CreatorEnum creatorEnum_,
            ::test_object::std_allocator::CreatorBitmask creatorBitmask_,
            const allocator_type& allocator = allocator_type()) :
            CreatorNested(allocator)
    {
        m_value_ = value_;
        m_text_ = ::std::forward<ZSERIO_T_text>(text_);
        m_externData_ = ::std::forward<ZSERIO_T_externData>(externData_);
        m_bytesData_ = ::std::forward<ZSERIO_T_bytesData>(bytesData_);
        m_creatorEnum_ = creatorEnum_;
        m_creatorBitmask_ = creatorBitmask_;
    }

    explicit CreatorNested(::zserio::BitStreamReader& in,
            uint32_t param_, const allocator_type& allocator = allocator_type());

    ~CreatorNested() = default;

    CreatorNested(const CreatorNested& other);
    CreatorNested& operator=(const CreatorNested& other);

    CreatorNested(CreatorNested&& other);
    CreatorNested& operator=(CreatorNested&& other);

    CreatorNested(::zserio::NoInitT,
            const CreatorNested& other);
    CreatorNested& assign(::zserio::NoInitT, const CreatorNested& other);

    CreatorNested(::zserio::NoInitT, CreatorNested&& other);
    CreatorNested& assign(::zserio::NoInitT,
            CreatorNested&& other);

    CreatorNested(::zserio::PropagateAllocatorT,
            const CreatorNested& other, const allocator_type& allocator);
    CreatorNested(::zserio::PropagateAllocatorT, ::zserio::NoInitT,
            const CreatorNested& other, const allocator_type& allocator);

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initialize(
            uint32_t param_);
    bool isInitialized() const;

    uint32_t getParam() const;

    uint32_t getValue() const;
    void setValue(uint32_t value_);

    const ::zserio::string<>& getText() const;
    ::zserio::string<>& getText();
    void setText(const ::zserio::string<>& text_);
    void setText(::zserio::string<>&& text_);

    const ::zserio::BitBuffer& getExternData() const;
    ::zserio::BitBuffer& getExternData();
    void setExternData(const ::zserio::BitBuffer& externData_);
    void setExternData(::zserio::BitBuffer&& externData_);

    const ::zserio::vector<uint8_t>& getBytesData() const;
    ::zserio::vector<uint8_t>& getBytesData();
    void setBytesData(const ::zserio::vector<uint8_t>& bytesData_);
    void setBytesData(::zserio::vector<uint8_t>&& bytesData_);

    ::test_object::std_allocator::CreatorEnum getCreatorEnum() const;
    void setCreatorEnum(::test_object::std_allocator::CreatorEnum creatorEnum_);

    ::test_object::std_allocator::CreatorBitmask getCreatorBitmask() const;
    void setCreatorBitmask(::test_object::std_allocator::CreatorBitmask creatorBitmask_);

    size_t bitSizeOf(size_t bitPosition = 0) const;

    size_t initializeOffsets(size_t bitPosition = 0);

    bool operator==(const CreatorNested& other) const;

    bool operator<(const CreatorNested& other) const;

    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;

private:
    uint32_t readValue(::zserio::BitStreamReader& in);
    ::zserio::string<> readText(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::zserio::BitBuffer readExternData(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::zserio::vector<uint8_t> readBytesData(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::test_object::std_allocator::CreatorEnum readCreatorEnum(::zserio::BitStreamReader& in);
    ::test_object::std_allocator::CreatorBitmask readCreatorBitmask(::zserio::BitStreamReader& in);

    uint32_t m_param_;
    bool m_isInitialized;
    uint32_t m_value_;
    ::zserio::string<> m_text_;
    ::zserio::BitBuffer m_externData_;
    ::zserio::vector<uint8_t> m_bytesData_;
    ::test_object::std_allocator::CreatorEnum m_creatorEnum_;
    ::test_object::std_allocator::CreatorBitmask m_creatorBitmask_;
};

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_CREATOR_NESTED_H
