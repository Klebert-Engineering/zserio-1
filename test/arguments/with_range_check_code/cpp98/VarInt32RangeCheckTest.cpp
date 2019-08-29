#include "gtest/gtest.h"

#include "zserio/CppRuntimeException.h"

#include "with_range_check_code/varint32_range_check/VarInt32RangeCheckCompound.h"

namespace with_range_check_code
{
namespace varint32_range_check
{

class VarInt32RangeCheckTest : public ::testing::Test
{
protected:
    void checkVarInt32Value(int32_t value)
    {
        VarInt32RangeCheckCompound varInt32RangeCheckCompound;
        varInt32RangeCheckCompound.setValue(value);
        zserio::BitStreamWriter writer;
        varInt32RangeCheckCompound.write(writer);
        size_t writeBufferByteSize;
        const uint8_t* writeBuffer = writer.getWriteBuffer(writeBufferByteSize);
        zserio::BitStreamReader reader(writeBuffer, writeBufferByteSize);
        const VarInt32RangeCheckCompound readVarInt32RangeCheckCompound(reader);
        ASSERT_EQ(varInt32RangeCheckCompound, readVarInt32RangeCheckCompound);
    }

    static const int32_t    VARINT32_LOWER_BOUND = -((INT32_C(1) << 28) - 1);
    static const int32_t    VARINT32_UPPER_BOUND = (INT32_C(1) << 28) - 1;
};

TEST_F(VarInt32RangeCheckTest, varInt32LowerBound)
{
    checkVarInt32Value(VARINT32_LOWER_BOUND);
}

TEST_F(VarInt32RangeCheckTest, varInt32UpperBound)
{
    checkVarInt32Value(VARINT32_UPPER_BOUND);
}

TEST_F(VarInt32RangeCheckTest, varInt32BelowLowerBound)
{
    try
    {
        checkVarInt32Value(VARINT32_LOWER_BOUND - 1);
        FAIL() << "Actual: no exception, Expected: zserio::CppRuntimeException";
    }
    catch (const zserio::CppRuntimeException& excpt)
    {
        ASSERT_STREQ("Value -268435456 of VarInt32RangeCheckCompound.value exceeds the range of "
                "<-268435455..268435455>!", excpt.what());
    }
}

TEST_F(VarInt32RangeCheckTest, varInt32AboveUpperBound)
{
    try
    {
        checkVarInt32Value(VARINT32_UPPER_BOUND + 1);
        FAIL() << "Actual: no exception, Expected: zserio::CppRuntimeException";
    }
    catch (const zserio::CppRuntimeException& excpt)
    {
        ASSERT_STREQ("Value 268435456 of VarInt32RangeCheckCompound.value exceeds the range of "
                "<-268435455..268435455>!", excpt.what());
    }
}

} // namespace varint32_range_check
} // namespace with_range_check_code
