/**
 * Automatically generated by Zserio C++ extension version 2.9.0-pre1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, polymorhpicAllocator.
 */

#ifndef TEST_OBJECT_POLYMORPHIC_ALLOCATOR_CREATOR_ENUM_H
#define TEST_OBJECT_POLYMORPHIC_ALLOCATOR_CREATOR_ENUM_H

#include <array>

#include <zserio/Enums.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/pmr/ITypeInfo.h>
#include <zserio/pmr/IReflectable.h>
#include <zserio/pmr/PackingContext.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

namespace test_object
{
namespace polymorphic_allocator
{

enum class CreatorEnum : int8_t
{
    ONE = INT8_C(0),
    TWO = INT8_C(1),
    MinusOne = INT8_C(-1)
};

} // namespace polymorphic_allocator
} // namespace test_object

namespace zserio
{

// This is full specialization of enumeration traits and methods for CreatorEnum enumeration.
template <>
struct EnumTraits<::test_object::polymorphic_allocator::CreatorEnum>
{
    static constexpr ::std::array<const char*, 3> names =
    {{
        "ONE",
        "TWO",
        "MinusOne"
    }};

    static constexpr ::std::array<::test_object::polymorphic_allocator::CreatorEnum, 3> values =
    {{
        ::test_object::polymorphic_allocator::CreatorEnum::ONE,
        ::test_object::polymorphic_allocator::CreatorEnum::TWO,
        ::test_object::polymorphic_allocator::CreatorEnum::MinusOne
    }};
};

template <>
const ::zserio::pmr::ITypeInfo& enumTypeInfo<::test_object::polymorphic_allocator::CreatorEnum, ::zserio::pmr::PropagatingPolymorphicAllocator<>>();

template <>
::zserio::pmr::IReflectablePtr enumReflectable(::test_object::polymorphic_allocator::CreatorEnum value, const ::zserio::pmr::PropagatingPolymorphicAllocator<>& allocator);

template <>
size_t enumToOrdinal<::test_object::polymorphic_allocator::CreatorEnum>(::test_object::polymorphic_allocator::CreatorEnum value);

template <>
::test_object::polymorphic_allocator::CreatorEnum valueToEnum<::test_object::polymorphic_allocator::CreatorEnum>(
        typename ::std::underlying_type<::test_object::polymorphic_allocator::CreatorEnum>::type rawValue);

template <>
uint32_t enumHashCode<::test_object::polymorphic_allocator::CreatorEnum>(::test_object::polymorphic_allocator::CreatorEnum value);

template <>
void initPackingContext<::zserio::pmr::PackingContextNode, ::test_object::polymorphic_allocator::CreatorEnum>(
        ::zserio::pmr::PackingContextNode& contextNode, ::test_object::polymorphic_allocator::CreatorEnum value);

template <>
size_t bitSizeOf<::test_object::polymorphic_allocator::CreatorEnum>(::test_object::polymorphic_allocator::CreatorEnum value);

template <>
size_t bitSizeOf<::zserio::pmr::PackingContextNode, ::test_object::polymorphic_allocator::CreatorEnum>(
        ::zserio::pmr::PackingContextNode& contextNode, ::test_object::polymorphic_allocator::CreatorEnum value);

template <>
size_t initializeOffsets<::test_object::polymorphic_allocator::CreatorEnum>(size_t bitPosition, ::test_object::polymorphic_allocator::CreatorEnum value);

template <>
size_t initializeOffsets<::zserio::pmr::PackingContextNode, ::test_object::polymorphic_allocator::CreatorEnum>(
        ::zserio::pmr::PackingContextNode& contextNode, size_t bitPosition, ::test_object::polymorphic_allocator::CreatorEnum value);

template <>
::test_object::polymorphic_allocator::CreatorEnum read<::test_object::polymorphic_allocator::CreatorEnum>(::zserio::BitStreamReader& in);

template <>
::test_object::polymorphic_allocator::CreatorEnum read<::test_object::polymorphic_allocator::CreatorEnum, ::zserio::pmr::PackingContextNode>(
        ::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamReader& in);

template <>
void write<::test_object::polymorphic_allocator::CreatorEnum>(::zserio::BitStreamWriter& out, ::test_object::polymorphic_allocator::CreatorEnum value);

template <>
void write<::zserio::pmr::PackingContextNode, ::test_object::polymorphic_allocator::CreatorEnum>(
        ::zserio::pmr::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out, ::test_object::polymorphic_allocator::CreatorEnum value);

} // namespace zserio

#endif // TEST_OBJECT_POLYMORPHIC_ALLOCATOR_CREATOR_ENUM_H
