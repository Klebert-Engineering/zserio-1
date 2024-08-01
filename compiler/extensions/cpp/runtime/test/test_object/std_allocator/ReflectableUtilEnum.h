/**
 * Automatically generated by Zserio C++ generator version 1.0.2 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, bitPosition, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOCATOR_REFLECTABLE_UTIL_ENUM_H
#define TEST_OBJECT_STD_ALLOCATOR_REFLECTABLE_UTIL_ENUM_H

#include <array>

#include <zserio/Enums.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

namespace test_object
{
namespace std_allocator
{

enum class ReflectableUtilEnum : int8_t
{
    ONE = INT8_C(0),
    TWO = INT8_C(1)
};

} // namespace std_allocator
} // namespace test_object

namespace zserio
{

// This is full specialization of enumeration traits and methods for ReflectableUtilEnum enumeration.
template <>
struct EnumTraits<::test_object::std_allocator::ReflectableUtilEnum>
{
    static constexpr ::std::array<const char*, 2> names =
    {{
        "ONE",
        "TWO"
    }};

    static constexpr ::std::array<::test_object::std_allocator::ReflectableUtilEnum, 2> values =
    {{
        ::test_object::std_allocator::ReflectableUtilEnum::ONE,
        ::test_object::std_allocator::ReflectableUtilEnum::TWO
    }};

    static constexpr const char* enumName = "ReflectableUtilEnum";
};

template <>
const ::zserio::ITypeInfo& enumTypeInfo<::test_object::std_allocator::ReflectableUtilEnum, ::std::allocator<uint8_t>>();

template <>
::zserio::IReflectablePtr enumReflectable(::test_object::std_allocator::ReflectableUtilEnum value, const ::std::allocator<uint8_t>& allocator);

template <>
size_t enumToOrdinal<::test_object::std_allocator::ReflectableUtilEnum>(::test_object::std_allocator::ReflectableUtilEnum value);

template <>
::test_object::std_allocator::ReflectableUtilEnum valueToEnum<::test_object::std_allocator::ReflectableUtilEnum>(
        typename ::std::underlying_type<::test_object::std_allocator::ReflectableUtilEnum>::type rawValue);

template <>
uint32_t enumHashCode<::test_object::std_allocator::ReflectableUtilEnum>(::test_object::std_allocator::ReflectableUtilEnum value);

template <>
size_t bitSizeOf<::test_object::std_allocator::ReflectableUtilEnum>(::test_object::std_allocator::ReflectableUtilEnum value);

template <>
size_t initializeOffsets<::test_object::std_allocator::ReflectableUtilEnum>(size_t bitPosition, ::test_object::std_allocator::ReflectableUtilEnum value);

template <>
::test_object::std_allocator::ReflectableUtilEnum read<::test_object::std_allocator::ReflectableUtilEnum>(::zserio::BitStreamReader& in);

template <>
void write<::test_object::std_allocator::ReflectableUtilEnum>(::zserio::BitStreamWriter& out, ::test_object::std_allocator::ReflectableUtilEnum value);

} // namespace zserio

#endif // TEST_OBJECT_STD_ALLOCATOR_REFLECTABLE_UTIL_ENUM_H
