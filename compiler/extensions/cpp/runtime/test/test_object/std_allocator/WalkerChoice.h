/**
 * Automatically generated by Zserio C++ extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_WALKER_CHOICE_H
#define TEST_OBJECT_STD_ALLOCATOR_WALKER_CHOICE_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <zserio/AnyHolder.h>
#include <memory>
#include <zserio/PackingContext.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

namespace test_object
{
namespace std_allocator
{

class WalkerChoice
{
public:
    using allocator_type = ::std::allocator<uint8_t>;

    enum ChoiceTag : int32_t
    {
        CHOICE_value8 = 0,
        CHOICE_value16 = 1,
        CHOICE_value32 = 2,
        CHOICE_value64 = 3,
        UNDEFINED_CHOICE = -1
    };

    WalkerChoice() noexcept :
            WalkerChoice(allocator_type())
    {}

    explicit WalkerChoice(const allocator_type& allocator) noexcept;

    explicit WalkerChoice(::zserio::BitStreamReader& in,
            uint8_t selector_, const allocator_type& allocator = allocator_type());
    explicit WalkerChoice(::zserio::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in,
            uint8_t selector_, const allocator_type& allocator = allocator_type());

    ~WalkerChoice() = default;

    WalkerChoice(const WalkerChoice& other);
    WalkerChoice& operator=(const WalkerChoice& other);

    WalkerChoice(WalkerChoice&& other);
    WalkerChoice& operator=(WalkerChoice&& other);

    WalkerChoice(::zserio::PropagateAllocatorT,
            const WalkerChoice& other, const allocator_type& allocator);

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    void initialize(
            uint8_t selector_);
    bool isInitialized() const;

    ChoiceTag choiceTag() const;

    uint8_t getSelector() const;

    uint8_t getValue8() const;
    void setValue8(uint8_t value8_);

    uint16_t getValue16() const;
    void setValue16(uint16_t value16_);

    uint32_t getValue32() const;
    void setValue32(uint32_t value32_);

    uint64_t getValue64() const;
    void setValue64(uint64_t value64_);

    static void createPackingContext(::zserio::PackingContextNode& contextNode);
    void initPackingContext(::zserio::PackingContextNode& contextNode) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(::zserio::PackingContextNode& contextNode, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(::zserio::PackingContextNode& contextNode, size_t bitPosition);

    bool operator==(const WalkerChoice& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const;

private:
    ::zserio::AnyHolder<> readObject(::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::AnyHolder<> readObject(::zserio::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::AnyHolder<> copyObject(const allocator_type& allocator) const;

    uint8_t m_selector_;
    bool m_isInitialized;
    ::zserio::AnyHolder<> m_objectChoice;
};

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_WALKER_CHOICE_H