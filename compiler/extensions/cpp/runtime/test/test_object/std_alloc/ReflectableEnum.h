/**
 * Automatically generated by Zserio C++ extension version 2.9.0-pre1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode, reflectionCode, stdAllocator.
 */

#ifndef TEST_OBJECT_STD_ALLOC_REFLECTABLE_ENUM_H
#define TEST_OBJECT_STD_ALLOC_REFLECTABLE_ENUM_H

#include <array>

#include <zserio/Enums.h>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/ITypeInfo.h>
#include <zserio/IReflectable.h>
#include <zserio/PackingContext.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

namespace test_object
{
namespace std_alloc
{

enum class ReflectableEnum : int8_t
{
    VALUE1 = INT8_C(-1),
    VALUE2 = INT8_C(0),
    VALUE3 = INT8_C(1)
};

} // namespace std_alloc
} // namespace test_object

namespace zserio
{

// This is full specialization of enumeration traits and methods for ReflectableEnum enumeration.
template <>
struct EnumTraits<::test_object::std_alloc::ReflectableEnum>
{
    static constexpr ::std::array<const char*, 3> names =
    {{
        "VALUE1",
        "VALUE2",
        "VALUE3"
    }};

    static constexpr ::std::array<::test_object::std_alloc::ReflectableEnum, 3> values =
    {{
        ::test_object::std_alloc::ReflectableEnum::VALUE1,
        ::test_object::std_alloc::ReflectableEnum::VALUE2,
        ::test_object::std_alloc::ReflectableEnum::VALUE3
    }};
};

template <>
const ::zserio::ITypeInfo& enumTypeInfo<::test_object::std_alloc::ReflectableEnum, ::std::allocator<uint8_t>>();

template <>
::zserio::IReflectablePtr enumReflectable(::test_object::std_alloc::ReflectableEnum value, const ::std::allocator<uint8_t>& allocator);

template <>
size_t enumToOrdinal<::test_object::std_alloc::ReflectableEnum>(::test_object::std_alloc::ReflectableEnum value);

template <>
::test_object::std_alloc::ReflectableEnum valueToEnum<::test_object::std_alloc::ReflectableEnum>(
        typename ::std::underlying_type<::test_object::std_alloc::ReflectableEnum>::type rawValue);

template <>
uint32_t enumHashCode<::test_object::std_alloc::ReflectableEnum>(::test_object::std_alloc::ReflectableEnum value);

template <>
void initPackingContext<::zserio::PackingContextNode, ::test_object::std_alloc::ReflectableEnum>(
        ::zserio::PackingContextNode& contextNode, ::test_object::std_alloc::ReflectableEnum value);

template <>
size_t bitSizeOf<::test_object::std_alloc::ReflectableEnum>(::test_object::std_alloc::ReflectableEnum value);

template <>
size_t bitSizeOf<::zserio::PackingContextNode, ::test_object::std_alloc::ReflectableEnum>(
        ::zserio::PackingContextNode& contextNode, ::test_object::std_alloc::ReflectableEnum value);

template <>
size_t initializeOffsets<::test_object::std_alloc::ReflectableEnum>(size_t bitPosition, ::test_object::std_alloc::ReflectableEnum value);

template <>
size_t initializeOffsets<::zserio::PackingContextNode, ::test_object::std_alloc::ReflectableEnum>(
        ::zserio::PackingContextNode& contextNode, size_t bitPosition, ::test_object::std_alloc::ReflectableEnum value);

template <>
::test_object::std_alloc::ReflectableEnum read<::test_object::std_alloc::ReflectableEnum>(::zserio::BitStreamReader& in);

template <>
::test_object::std_alloc::ReflectableEnum read<::test_object::std_alloc::ReflectableEnum, ::zserio::PackingContextNode>(
        ::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in);

template <>
void write<::test_object::std_alloc::ReflectableEnum>(::zserio::BitStreamWriter& out, ::test_object::std_alloc::ReflectableEnum value);

template <>
void write<::zserio::PackingContextNode, ::test_object::std_alloc::ReflectableEnum>(
        ::zserio::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out, ::test_object::std_alloc::ReflectableEnum value);

} // namespace zserio

#endif // TEST_OBJECT_STD_ALLOC_REFLECTABLE_ENUM_H
