#include <cmath>

#include "gtest/gtest.h"

#include "zserio/ReflectableUtil.h"
#include "zserio/Reflectable.h"
#include "zserio/TypeInfo.h"

#include "test_object/std_allocator/CreatorBitmask.h"
#include "test_object/std_allocator/CreatorEnum.h"
#include "test_object/std_allocator/CreatorNested.h"
#include "test_object/std_allocator/CreatorObject.h"

using test_object::std_allocator::CreatorBitmask;
using test_object::std_allocator::CreatorEnum;
using test_object::std_allocator::CreatorNested;
using test_object::std_allocator::CreatorObject;

namespace zserio
{

TEST(ReflectableUtilTest, unequalTypeInfo)
{
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getBool(false),
            ReflectableFactory::getUInt8(13)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt8(0),
            ReflectableFactory::getInt16(0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt8(0),
            ReflectableFactory::getUInt8(0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getUInt64(0),
            ReflectableFactory::getVarSize(0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt8(0),
            ReflectableFactory::getFloat32(0.0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getFloat16(0.0f),
            ReflectableFactory::getFloat32(0.0f)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getString(""),
            ReflectableFactory::getInt8(0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getBitBuffer(BitBuffer()),
            ReflectableFactory::getString("")));
}

TEST(ReflectableUtilTest, equalsNullValues)
{
    ASSERT_TRUE(ReflectableUtil::equal(nullptr, nullptr));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getBool(false), nullptr));
    ASSERT_FALSE(ReflectableUtil::equal(nullptr, ReflectableFactory::getInt8(0)));
}

TEST(ReflectableUtilTest, equalBools)
{
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getBool(true), ReflectableFactory::getBool(true)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getBool(false),
            ReflectableFactory::getBool(true)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getBool(true),
            ReflectableFactory::getBool(false)));
}

TEST(ReflectableUtilTest, equalSingedIntegrals)
{
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getInt8(INT8_MIN),
            ReflectableFactory::getInt8(INT8_MIN)));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getInt8(INT8_MAX),
            ReflectableFactory::getInt8(INT8_MAX)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt8(-1),
            ReflectableFactory::getInt8(0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt8(INT8_MIN),
            ReflectableFactory::getInt8(INT8_MAX)));

    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getInt16(INT16_MIN),
            ReflectableFactory::getInt16(INT16_MIN)));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getInt16(INT16_MAX),
            ReflectableFactory::getInt16(INT16_MAX)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt16(-1),
            ReflectableFactory::getInt16(0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt16(INT16_MIN),
            ReflectableFactory::getInt16(INT16_MAX)));

    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getInt32(INT32_MIN),
            ReflectableFactory::getInt32(INT32_MIN)));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getInt32(INT32_MAX),
            ReflectableFactory::getInt32(INT32_MAX)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt32(-1),
            ReflectableFactory::getInt32(0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt32(INT32_MIN),
            ReflectableFactory::getInt32(INT32_MAX)));

    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getInt64(INT64_MIN),
            ReflectableFactory::getInt64(INT64_MIN)));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getInt64(INT64_MAX),
            ReflectableFactory::getInt64(INT64_MAX)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt64(-1),
            ReflectableFactory::getInt64(0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getInt64(INT64_MIN),
            ReflectableFactory::getInt64(INT64_MAX)));
}

TEST(ReflectableUtilTest, equalUnsignedIntegrals)
{
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getUInt8(0),
            ReflectableFactory::getUInt8(0)));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getUInt8(UINT8_MAX),
            ReflectableFactory::getUInt8(UINT8_MAX)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getUInt8(0),
            ReflectableFactory::getUInt8(1)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getUInt8(0),
            ReflectableFactory::getUInt8(UINT8_MAX)));

    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getUInt16(0),
            ReflectableFactory::getUInt16(0)));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getUInt16(UINT16_MAX),
            ReflectableFactory::getUInt16(UINT16_MAX)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getUInt16(0),
            ReflectableFactory::getUInt16(1)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getUInt16(0),
            ReflectableFactory::getUInt16(UINT16_MAX)));

    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getUInt32(0),
            ReflectableFactory::getUInt32(0)));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getUInt32(UINT32_MAX),
            ReflectableFactory::getUInt32(UINT32_MAX)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getUInt32(0),
            ReflectableFactory::getUInt32(1)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getUInt32(0),
            ReflectableFactory::getUInt32(UINT32_MAX)));

    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getUInt64(0),
            ReflectableFactory::getUInt64(0)));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getUInt64(UINT64_MAX),
            ReflectableFactory::getUInt64(UINT64_MAX)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getUInt64(0),
            ReflectableFactory::getUInt64(1)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getUInt64(0),
            ReflectableFactory::getUInt64(UINT64_MAX)));
}

TEST(ReflectableUtilTest, equalFloatingPoints)
{
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getFloat16(0.0f),
            ReflectableFactory::getFloat16(0.0f)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getFloat16(-1.0f),
            ReflectableFactory::getFloat16(1.0f)));

    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getFloat32(0.0f),
            ReflectableFactory::getFloat32(0.0f)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getFloat32(-1.0f),
            ReflectableFactory::getFloat32(1.0f)));

    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getFloat64(0.0),
            ReflectableFactory::getFloat64(0.0)));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getFloat64(-1.0),
            ReflectableFactory::getFloat64(1.0)));

    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getFloat64(static_cast<double>(NAN)),
            ReflectableFactory::getFloat64(static_cast<double>(NAN))));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getFloat64(static_cast<double>(INFINITY)),
            ReflectableFactory::getFloat64(static_cast<double>(INFINITY))));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getFloat64(-static_cast<double>(INFINITY)),
            ReflectableFactory::getFloat64(-static_cast<double>(INFINITY))));

    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getFloat64(static_cast<double>(NAN)),
            ReflectableFactory::getFloat64(static_cast<double>(INFINITY))));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getFloat64(static_cast<double>(INFINITY)),
            ReflectableFactory::getFloat64(-static_cast<double>(INFINITY))));
}

TEST(ReflectableUtilTest, equalStrings)
{
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getString(""),
            ReflectableFactory::getString("")));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getString("test"),
            ReflectableFactory::getString("test")));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getString(""),
            ReflectableFactory::getString("a")));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getString("1"),
            ReflectableFactory::getString("")));
    ASSERT_FALSE(ReflectableUtil::equal(ReflectableFactory::getString("test"),
            ReflectableFactory::getString("test2")));
}

TEST(ReflectableUtilTest, equalBitBuffers)
{
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getBitBuffer(BitBuffer()),
            ReflectableFactory::getBitBuffer(BitBuffer())));
    ASSERT_TRUE(ReflectableUtil::equal(ReflectableFactory::getBitBuffer(BitBuffer({0xAB}, 8)),
            ReflectableFactory::getBitBuffer(BitBuffer({0xAB}, 8))));
}

TEST(ReflectableUtilTest, equalEnums)
{
    const CreatorEnum one = CreatorEnum::ONE;
    const CreatorEnum two = CreatorEnum::TWO;

    ASSERT_TRUE(ReflectableUtil::equal(enumReflectable(one), enumReflectable(one)));
    ASSERT_TRUE(ReflectableUtil::equal(enumReflectable(two), enumReflectable(two)));
    ASSERT_FALSE(ReflectableUtil::equal(enumReflectable(one), enumReflectable(two)));
}

TEST(ReflectableUtilTest, equalBitmasks)
{
    const CreatorBitmask read = CreatorBitmask::Values::READ;
    const CreatorBitmask write = CreatorBitmask::Values::WRITE;

    ASSERT_TRUE(ReflectableUtil::equal(read.reflectable(), read.reflectable()));
    ASSERT_TRUE(ReflectableUtil::equal(write.reflectable(), write.reflectable()));
    ASSERT_FALSE(ReflectableUtil::equal(write.reflectable(), read.reflectable()));
}

TEST(ReflectableUtilTest, equalCompounds)
{
    CreatorObject creator1 = CreatorObject();
    creator1.setTextArray({{{"one"}, {"two"}}});
    creator1.initializeChildren();

    CreatorObject creator2 = CreatorObject(); // larger array
    creator2.setTextArray({{{"one"}, {"two"}, {"three"}}});
    creator2.initializeChildren();

    CreatorObject creator3 = CreatorObject();
    creator3.setTextArray({{{"one"}, {"something else"}}}); // difference in array element
    creator3.initializeChildren();

    CreatorObject creator4 = CreatorObject(); // extern array set
    creator4.setTextArray({{{"one"}, {"two"}}});
    creator4.setExternArray({{}});
    creator4.initializeChildren();

    CreatorObject creator5 = CreatorObject(); // optional bool set
    creator5.setTextArray({{{"one"}, {"two"}}});
    creator5.setOptionalBool(true);
    creator5.initializeChildren();

    CreatorObject creator6 = CreatorObject(); // optional nested set
    creator6.setTextArray({{{"one"}, {"two"}}});
    creator6.setOptionalNested(CreatorNested());
    creator6.initializeChildren();

    ASSERT_TRUE(ReflectableUtil::equal(creator1.reflectable(), creator1.reflectable()));
    ASSERT_TRUE(ReflectableUtil::equal(creator2.reflectable(), creator2.reflectable()));
    ASSERT_TRUE(ReflectableUtil::equal(creator3.reflectable(), creator3.reflectable()));
    ASSERT_TRUE(ReflectableUtil::equal(creator4.reflectable(), creator4.reflectable()));
    ASSERT_TRUE(ReflectableUtil::equal(creator5.reflectable(), creator5.reflectable()));
    ASSERT_TRUE(ReflectableUtil::equal(creator6.reflectable(), creator6.reflectable()));

    ASSERT_FALSE(ReflectableUtil::equal(creator1.reflectable(), creator2.reflectable()));
    ASSERT_FALSE(ReflectableUtil::equal(creator1.reflectable(), creator3.reflectable()));
    ASSERT_FALSE(ReflectableUtil::equal(creator1.reflectable(), creator4.reflectable()));
    ASSERT_FALSE(ReflectableUtil::equal(creator1.reflectable(), creator5.reflectable()));
    ASSERT_FALSE(ReflectableUtil::equal(creator1.reflectable(), creator6.reflectable()));

    CreatorNested nested1 = CreatorNested();
    nested1.initialize(0);

    CreatorNested nested2 = CreatorNested();
    nested2.initialize(1);

    ASSERT_FALSE(ReflectableUtil::equal(nested1.reflectable(), nested2.reflectable()));

    // array and non array
    ASSERT_FALSE(ReflectableUtil::equal(creator1.reflectable()->getField("textArray"),
            creator1.reflectable()->getField("textArray")->at(0)));
}

TEST(ReflectableUtilTest, getValueArithmeticType)
{
    ASSERT_FALSE(ReflectableUtil::getValue<bool>(ReflectableFactory::getBool(false)));

    ASSERT_EQ(1, ReflectableUtil::getValue<uint8_t>(ReflectableFactory::getUInt8(1)));
    ASSERT_EQ(12, ReflectableUtil::getValue<uint16_t>(ReflectableFactory::getUInt16(12)));
    ASSERT_EQ(123, ReflectableUtil::getValue<uint32_t>(ReflectableFactory::getUInt32(123)));
    ASSERT_EQ(1234, ReflectableUtil::getValue<uint64_t>(ReflectableFactory::getUInt64(1234)));

    ASSERT_EQ(-1, ReflectableUtil::getValue<int8_t>(ReflectableFactory::getInt8(-1)));
    ASSERT_EQ(-12, ReflectableUtil::getValue<int16_t>(ReflectableFactory::getInt16(-12)));
    ASSERT_EQ(-123, ReflectableUtil::getValue<int32_t>(ReflectableFactory::getInt32(-123)));
    ASSERT_EQ(-1234, ReflectableUtil::getValue<int64_t>(ReflectableFactory::getInt64(-1234)));

    ASSERT_EQ(12, ReflectableUtil::getValue<uint16_t>(ReflectableFactory::getVarUInt16(12)));
    ASSERT_EQ(123, ReflectableUtil::getValue<uint32_t>(ReflectableFactory::getVarUInt32(123)));
    ASSERT_EQ(1234, ReflectableUtil::getValue<uint64_t>(ReflectableFactory::getVarUInt64(1234)));
    ASSERT_EQ(UINT64_MAX, ReflectableUtil::getValue<uint64_t>(ReflectableFactory::getVarUInt(UINT64_MAX)));

    ASSERT_EQ(-12, ReflectableUtil::getValue<int16_t>(ReflectableFactory::getVarInt16(-12)));
    ASSERT_EQ(-123, ReflectableUtil::getValue<int32_t>(ReflectableFactory::getVarInt32(-123)));
    ASSERT_EQ(-1234, ReflectableUtil::getValue<int64_t>(ReflectableFactory::getVarInt64(-1234)));
    ASSERT_EQ(INT64_MIN, ReflectableUtil::getValue<int64_t>(ReflectableFactory::getVarInt(INT64_MIN)));
    ASSERT_EQ(INT64_MAX, ReflectableUtil::getValue<int64_t>(ReflectableFactory::getVarInt(INT64_MAX)));

    ASSERT_EQ(0, ReflectableUtil::getValue<uint32_t>(ReflectableFactory::getVarSize(0)));

    ASSERT_EQ(1.0f, ReflectableUtil::getValue<float>(ReflectableFactory::getFloat16(1.0f)));
    ASSERT_EQ(3.5f, ReflectableUtil::getValue<float>(ReflectableFactory::getFloat32(3.5f)));
    ASSERT_EQ(9.875, ReflectableUtil::getValue<double>(ReflectableFactory::getFloat64(9.875)));
}

TEST(ReflectableUtilTest, getValueString)
{
    ASSERT_EQ("test"_sv, ReflectableUtil::getValue<StringView>(ReflectableFactory::getString("test")));
}

TEST(ReflectableUtilTest, getValueBitBuffer)
{
    const BitBuffer bitBuffer;
    auto reflectable = ReflectableFactory::getBitBuffer(bitBuffer);
    const BitBuffer& bitBufferRef = ReflectableUtil::getValue<BitBuffer>(reflectable);
    ASSERT_EQ(bitBuffer, bitBufferRef);
}

TEST(ReflectableUtilTest, getValueEnum)
{
    CreatorEnum creatorEnum = CreatorEnum::ONE;
    auto reflectable = enumReflectable(creatorEnum);
    ASSERT_EQ(creatorEnum, ReflectableUtil::getValue<CreatorEnum>(reflectable));
}

TEST(ReflectableUtilTest, getValueBitmask)
{
    CreatorBitmask creatorBitmask = CreatorBitmask::Values::READ;
    auto reflectable = creatorBitmask.reflectable();
    ASSERT_EQ(creatorBitmask, ReflectableUtil::getValue<CreatorBitmask>(reflectable));
}

TEST(ReflectableUtilTest, getValueCompound)
{
    CreatorObject creatorObject;
    auto reflectable = creatorObject.reflectable();
    ASSERT_EQ(&creatorObject, &ReflectableUtil::getValue<CreatorObject>(reflectable));

    CreatorObject& creatorObjectRef = ReflectableUtil::getValue<CreatorObject>(reflectable);
    creatorObjectRef.setValue(32);
    ASSERT_EQ(32, creatorObject.getValue());

    auto constReflectable = static_cast<const CreatorObject&>(creatorObject).reflectable();
    const CreatorObject& creatorObjectConstRef = ReflectableUtil::getValue<CreatorObject>(constReflectable);
    ASSERT_EQ(32, creatorObjectConstRef.getValue());
    ASSERT_EQ(&creatorObject, &creatorObjectConstRef);
}

TEST(ReflectableUtilTest, getValueBuiltinArray)
{
    std::vector<uint8_t> uint8Array{{1, 2, 3}};
    auto reflectable = ReflectableFactory::getBuiltinArray(BuiltinTypeInfo<>::getUInt8(), uint8Array);
    std::vector<uint8_t>& uint8ArrayRef = ReflectableUtil::getValue<std::vector<uint8_t>>(reflectable);
    ASSERT_EQ(&uint8Array, &uint8ArrayRef);

    auto constReflectable = ReflectableFactory::getBuiltinArray(BuiltinTypeInfo<>::getUInt8(),
            static_cast<const std::vector<uint8_t>&>(uint8Array));
    const std::vector<uint8_t>& uint8ArrayConstRef =
            ReflectableUtil::getValue<std::vector<uint8_t>>(constReflectable);
    ASSERT_EQ(&uint8Array, &uint8ArrayConstRef);
}

TEST(ReflectableUtilTest, getValueCompoundArray)
{
    CreatorObject creatorObject;
    auto reflectable = ReflectableFactory::getCompoundArray(creatorObject.getNestedArray());
    std::vector<CreatorNested>& nestedArrayRef =
            ReflectableUtil::getValue<std::vector<CreatorNested>>(reflectable);
    ASSERT_EQ(&creatorObject.getNestedArray(), &nestedArrayRef);
}

} // namespace zserio
