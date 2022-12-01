/**
 * Automatically generated by Zserio C++ extension version 2.9.0-pre1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_WALKER_OBJECT_H
#define TEST_OBJECT_STD_ALLOCATOR_WALKER_OBJECT_H

#include <zserio/Traits.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AllocatorPropagatingCopy.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <memory>
#include <zserio/PackingContext.h>
#include <zserio/OptionalHolder.h>
#include <zserio/Array.h>
#include <zserio/ArrayTraits.h>
#include <zserio/String.h>
#include <zserio/Types.h>
#include <zserio/Vector.h>

#include <test_object/std_allocator/WalkerNested.h>
#include <test_object/std_allocator/WalkerUnion.h>

namespace test_object
{
namespace std_allocator
{

class WalkerObject
{
private:
    class ZserioElementFactory_unionArray
    {
    public:
        explicit ZserioElementFactory_unionArray(WalkerObject& owner);

        void create(::zserio::vector<::test_object::std_allocator::WalkerUnion>& array,
                ::zserio::BitStreamReader& in, size_t index) const;

        void create(::zserio::PackingContextNode& contextNode,
                ::zserio::vector<::test_object::std_allocator::WalkerUnion>& array,
                ::zserio::BitStreamReader& in, size_t index) const;

    private:
        std::reference_wrapper<WalkerObject> m_ownerRef;
    };

    class ZserioElementFactory_optionalUnionArray
    {
    public:
        explicit ZserioElementFactory_optionalUnionArray(WalkerObject& owner);

        void create(::zserio::vector<::test_object::std_allocator::WalkerUnion>& array,
                ::zserio::BitStreamReader& in, size_t index) const;

        void create(::zserio::PackingContextNode& contextNode,
                ::zserio::vector<::test_object::std_allocator::WalkerUnion>& array,
                ::zserio::BitStreamReader& in, size_t index) const;

    private:
        std::reference_wrapper<WalkerObject> m_ownerRef;
    };

    using ZserioArrayType_unionArray = ::zserio::Array<::zserio::vector<::test_object::std_allocator::WalkerUnion>, ::zserio::ObjectArrayTraits<::test_object::std_allocator::WalkerUnion, ZserioElementFactory_unionArray>, ::zserio::ArrayType::AUTO>;
    using ZserioArrayType_optionalUnionArray = ::zserio::Array<::zserio::vector<::test_object::std_allocator::WalkerUnion>, ::zserio::ObjectArrayTraits<::test_object::std_allocator::WalkerUnion, ZserioElementFactory_optionalUnionArray>, ::zserio::ArrayType::AUTO>;

public:
    using allocator_type = ::std::allocator<uint8_t>;

    explicit WalkerObject(const allocator_type& allocator = allocator_type()) noexcept;

    template <typename ZSERIO_T_nested,
            typename ZSERIO_T_text,
            typename ZSERIO_T_unionArray,
            typename ZSERIO_T_optionalUnionArray>
    WalkerObject(
            uint32_t identifier_,
            ZSERIO_T_nested&& nested_,
            ZSERIO_T_text&& text_,
            ZSERIO_T_unionArray&& unionArray_,
            ZSERIO_T_optionalUnionArray&& optionalUnionArray_,
            const allocator_type& allocator = allocator_type()) :
            WalkerObject(allocator)
    {
        m_identifier_ = identifier_;
        m_nested_ = ::std::forward<ZSERIO_T_nested>(nested_);
        m_text_ = ::std::forward<ZSERIO_T_text>(text_);
        m_unionArray_ = ZserioArrayType_unionArray(::std::forward<ZSERIO_T_unionArray>(unionArray_), ::zserio::ObjectArrayTraits<::test_object::std_allocator::WalkerUnion, ZserioElementFactory_unionArray>());
        m_optionalUnionArray_ = ::zserio::createOptionalArray<ZserioArrayType_optionalUnionArray>(::std::forward<ZSERIO_T_optionalUnionArray>(optionalUnionArray_), ::zserio::ObjectArrayTraits<::test_object::std_allocator::WalkerUnion, ZserioElementFactory_optionalUnionArray>());
    }

    explicit WalkerObject(::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());
    explicit WalkerObject(::zserio::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator = allocator_type());

    ~WalkerObject() = default;

    WalkerObject(const WalkerObject&) = default;
    WalkerObject& operator=(const WalkerObject&) = default;

    WalkerObject(WalkerObject&&) = default;
    WalkerObject& operator=(WalkerObject&&) = default;

    WalkerObject(::zserio::PropagateAllocatorT,
            const WalkerObject& other, const allocator_type& allocator);

    static const ::zserio::ITypeInfo& typeInfo();
    ::zserio::IReflectableConstPtr reflectable(const allocator_type& allocator = allocator_type()) const;
    ::zserio::IReflectablePtr reflectable(const allocator_type& allocator = allocator_type());

    uint32_t getIdentifier() const;
    void setIdentifier(uint32_t identifier_);

    const ::test_object::std_allocator::WalkerNested& getNested() const;
    ::test_object::std_allocator::WalkerNested& getNested();
    void setNested(const ::test_object::std_allocator::WalkerNested& nested_);
    void setNested(::test_object::std_allocator::WalkerNested&& nested_);
    bool isNestedUsed() const;
    bool isNestedSet() const;
    void resetNested();

    const ::zserio::string<>& getText() const;
    ::zserio::string<>& getText();
    void setText(const ::zserio::string<>& text_);
    void setText(::zserio::string<>&& text_);

    const ::zserio::vector<::test_object::std_allocator::WalkerUnion>& getUnionArray() const;
    ::zserio::vector<::test_object::std_allocator::WalkerUnion>& getUnionArray();
    void setUnionArray(const ::zserio::vector<::test_object::std_allocator::WalkerUnion>& unionArray_);
    void setUnionArray(::zserio::vector<::test_object::std_allocator::WalkerUnion>&& unionArray_);

    const ::zserio::vector<::test_object::std_allocator::WalkerUnion>& getOptionalUnionArray() const;
    ::zserio::vector<::test_object::std_allocator::WalkerUnion>& getOptionalUnionArray();
    void setOptionalUnionArray(const ::zserio::vector<::test_object::std_allocator::WalkerUnion>& optionalUnionArray_);
    void setOptionalUnionArray(::zserio::vector<::test_object::std_allocator::WalkerUnion>&& optionalUnionArray_);
    bool isOptionalUnionArrayUsed() const;
    bool isOptionalUnionArraySet() const;
    void resetOptionalUnionArray();

    static void createPackingContext(::zserio::PackingContextNode& contextNode);
    void initPackingContext(::zserio::PackingContextNode& contextNode) const;

    size_t bitSizeOf(size_t bitPosition = 0) const;
    size_t bitSizeOf(::zserio::PackingContextNode& contextNode, size_t bitPosition) const;

    size_t initializeOffsets(size_t bitPosition = 0);
    size_t initializeOffsets(::zserio::PackingContextNode& contextNode, size_t bitPosition);

    bool operator==(const WalkerObject& other) const;
    uint32_t hashCode() const;

    void write(::zserio::BitStreamWriter& out) const;
    void write(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const;

private:
    uint32_t readIdentifier(::zserio::BitStreamReader& in);
    uint32_t readIdentifier(::zserio::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in);
    ::zserio::InplaceOptionalHolder<::test_object::std_allocator::WalkerNested> readNested(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::zserio::InplaceOptionalHolder<::test_object::std_allocator::WalkerNested> readNested(::zserio::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::string<> readText(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ZserioArrayType_unionArray readUnionArray(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ZserioArrayType_unionArray readUnionArray(::zserio::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator);
    ::zserio::InplaceOptionalHolder<ZserioArrayType_optionalUnionArray> readOptionalUnionArray(::zserio::BitStreamReader& in,
            const allocator_type& allocator);
    ::zserio::InplaceOptionalHolder<ZserioArrayType_optionalUnionArray> readOptionalUnionArray(::zserio::PackingContextNode& contextNode,
            ::zserio::BitStreamReader& in, const allocator_type& allocator);

    uint32_t m_identifier_;
    ::zserio::InplaceOptionalHolder<::test_object::std_allocator::WalkerNested> m_nested_;
    ::zserio::string<> m_text_;
    ZserioArrayType_unionArray m_unionArray_;
    ::zserio::InplaceOptionalHolder<ZserioArrayType_optionalUnionArray> m_optionalUnionArray_;
};

} // namespace std_allocator
} // namespace test_object

#endif // TEST_OBJECT_STD_ALLOCATOR_WALKER_OBJECT_H
