#include "gtest/gtest.h"

#include "zserio/CppRuntimeException.h"

#include "with_range_check_code/varuint64_range_check/VarUInt64RangeCheckCompound.h"

namespace with_range_check_code
{
namespace varuint64_range_check
{

class VarUInt64RangeCheckTest : public ::testing::Test
{
protected:
    void checkVarUInt64Value(uint64_t value)
    {
        VarUInt64RangeCheckCompound varUInt64RangeCheckCompound;
        varUInt64RangeCheckCompound.setValue(value);
        zserio::BitStreamWriter writer;
        varUInt64RangeCheckCompound.write(writer);
        size_t writeBufferByteSize;
        const uint8_t* writeBuffer = writer.getWriteBuffer(writeBufferByteSize);
        zserio::BitStreamReader reader(writeBuffer, writeBufferByteSize);
        const VarUInt64RangeCheckCompound readVarUInt64RangeCheckCompound(reader);
        ASSERT_EQ(varUInt64RangeCheckCompound, readVarUInt64RangeCheckCompound);
    }

    static const uint64_t   VARUINT64_LOWER_BOUND = UINT64_C(0);
    static const uint64_t   VARUINT64_UPPER_BOUND = (UINT64_C(1) << 57) - 1;
};

TEST_F(VarUInt64RangeCheckTest, varUInt64LowerBound)
{
    checkVarUInt64Value(VARUINT64_LOWER_BOUND);
}

TEST_F(VarUInt64RangeCheckTest, varUInt64UpperBound)
{
    checkVarUInt64Value(VARUINT64_UPPER_BOUND);
}

TEST_F(VarUInt64RangeCheckTest, varUInt64AboveUpperBound)
{
    try
    {
        checkVarUInt64Value(VARUINT64_UPPER_BOUND + 1);
        FAIL() << "Actual: no exception, Expected: zserio::CppRuntimeException";
    }
    catch (const zserio::CppRuntimeException& excpt)
    {
        ASSERT_STREQ("Value 144115188075855872 of VarUInt64RangeCheckCompound.value exceeds the range of "
                "<0..144115188075855871>!", excpt.what());
    }
}

} // namespace varuint64_range_check
} // namespace with_range_check_code
