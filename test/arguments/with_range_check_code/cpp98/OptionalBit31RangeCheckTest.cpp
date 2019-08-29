#include "gtest/gtest.h"

#include "zserio/CppRuntimeException.h"

#include "with_range_check_code/optional_bit31_range_check/OptionalBit31RangeCheckCompound.h"

namespace with_range_check_code
{
namespace optional_bit31_range_check
{

class OptionalBit31RangeCheckTest : public ::testing::Test
{
protected:
    void checkOptionalBit31Value(uint32_t value)
    {
        OptionalBit31RangeCheckCompound optionalBit31RangeCheckCompound;
        optionalBit31RangeCheckCompound.setHasOptional(true);
        optionalBit31RangeCheckCompound.setValue(value);
        zserio::BitStreamWriter writer;
        optionalBit31RangeCheckCompound.write(writer);
        size_t writeBufferByteSize;
        const uint8_t* writeBuffer = writer.getWriteBuffer(writeBufferByteSize);
        zserio::BitStreamReader reader(writeBuffer, writeBufferByteSize);
        const OptionalBit31RangeCheckCompound readOptionalBit31RangeCheckCompound(reader);
        ASSERT_EQ(optionalBit31RangeCheckCompound, readOptionalBit31RangeCheckCompound);
    }

    static const uint32_t   OPTIONAL_BIT31_LOWER_BOUND = UINT32_C(0);
    static const uint32_t   OPTIONAL_BIT31_UPPER_BOUND = UINT32_C(2147483647);
};

TEST_F(OptionalBit31RangeCheckTest, optionalBit31LowerBound)
{
    checkOptionalBit31Value(OPTIONAL_BIT31_LOWER_BOUND);
}

TEST_F(OptionalBit31RangeCheckTest, optionalBit31UpperBound)
{
    checkOptionalBit31Value(OPTIONAL_BIT31_UPPER_BOUND);
}

TEST_F(OptionalBit31RangeCheckTest, optionalBit31AboveUpperBound)
{
    try
    {
        checkOptionalBit31Value(OPTIONAL_BIT31_UPPER_BOUND + 1);
        FAIL() << "Actual: no exception, Expected: zserio::CppRuntimeException";
    }
    catch (const zserio::CppRuntimeException& excpt)
    {
        ASSERT_STREQ("Value 2147483648 of OptionalBit31RangeCheckCompound.value exceeds the range of "
                "<0..2147483647>!", excpt.what());
    }
}

} // namespace optional_bit31_range_check
} // namespace with_range_check_code
