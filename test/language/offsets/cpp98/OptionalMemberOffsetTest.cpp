#include "gtest/gtest.h"

#include "zserio/BitStreamWriter.h"
#include "zserio/BitStreamReader.h"

#include "offsets/optional_member_offset/OptionalMemberOffset.h"

namespace offsets
{
namespace optional_member_offset
{

class OptionalMemberOffsetTest : public ::testing::Test
{
protected:
    void writeOptionalMemberOffsetToByteArray(zserio::BitStreamWriter& writer, bool hasOptional,
            uint32_t optionalFieldOffset, int32_t optionalField, int32_t field)
    {
        writer.writeBool(hasOptional);
        writer.writeBits(optionalFieldOffset, 32);

        if (hasOptional)
        {
            writer.writeBits(0, 7);
            writer.writeSignedBits(optionalField, 32);
        }

        writer.writeSignedBits(field, 32);
    }

    void checkOptionalMemberOffset(const OptionalMemberOffset& optionalMemberOffset, bool hasOptional,
            uint32_t optionalFieldOffset, int32_t optionalField, int32_t field)
    {
        ASSERT_EQ(hasOptional, optionalMemberOffset.getHasOptional());
        ASSERT_EQ(optionalFieldOffset, optionalMemberOffset.getOptionalFieldOffset());

        if (hasOptional)
        {
            ASSERT_EQ(optionalField, optionalMemberOffset.getOptionalField());
            ASSERT_TRUE(optionalMemberOffset.hasOptionalField());
        }
        else
        {
            ASSERT_FALSE(optionalMemberOffset.hasOptionalField());
        }

        ASSERT_EQ(field, (int)optionalMemberOffset.getField());
    }

    void fillOptionalMemberOffset(OptionalMemberOffset& optionalMemberOffset, bool hasOptional,
            uint32_t optionalFieldOffset, int32_t optionalField, int32_t field)
    {
        optionalMemberOffset.setHasOptional(hasOptional);
        optionalMemberOffset.setOptionalFieldOffset(optionalFieldOffset);
        if (hasOptional)
            optionalMemberOffset.setOptionalField(optionalField);
        optionalMemberOffset.setField(field);
    }

    static const size_t WITH_OPTIONAL_MEMBER_OFFSET_BIT_SIZE = 104;
    static const size_t WITHOUT_OPTIONAL_MEMBER_OFFSET_BIT_SIZE = 65;

    static const size_t OPTIONAL_FIELD_OFFSET = 5;
    static const size_t WRONG_OPTIONAL_FIELD_OFFSET = 0;
};

TEST_F(OptionalMemberOffsetTest, readWithOptional)
{
    const bool hasOptional = true;
    const int32_t optionalField = 0x1212;
    const int32_t field = 0x2121;
    zserio::BitStreamWriter writer;
    writeOptionalMemberOffsetToByteArray(writer, hasOptional, OPTIONAL_FIELD_OFFSET, optionalField, field);
    size_t writeBufferByteSize;
    const uint8_t* writeBuffer = writer.getWriteBuffer(writeBufferByteSize);
    zserio::BitStreamReader reader(writeBuffer, writeBufferByteSize);

    OptionalMemberOffset optionalMemberOffset(reader);
    checkOptionalMemberOffset(optionalMemberOffset, hasOptional, OPTIONAL_FIELD_OFFSET, optionalField, field);
}

TEST_F(OptionalMemberOffsetTest, readWithoutOptional)
{
    const bool hasOptional = false;
    const uint32_t optionalFieldOffset = 0xABCD;
    const int32_t optionalField = 0;
    const int32_t field = 0x2121;
    zserio::BitStreamWriter writer;
    writeOptionalMemberOffsetToByteArray(writer, hasOptional, optionalFieldOffset, optionalField, field);
    size_t writeBufferByteSize;
    const uint8_t* writeBuffer = writer.getWriteBuffer(writeBufferByteSize);
    zserio::BitStreamReader reader(writeBuffer, writeBufferByteSize);

    OptionalMemberOffset optionalMemberOffset(reader);
    checkOptionalMemberOffset(optionalMemberOffset, hasOptional, optionalFieldOffset, optionalField, field);
}

TEST_F(OptionalMemberOffsetTest, bitSizeOfWithOptional)
{
    OptionalMemberOffset optionalMemberOffset;
    fillOptionalMemberOffset(optionalMemberOffset, true, OPTIONAL_FIELD_OFFSET, 0x1010, 0x2020);

    const size_t expectedBitSize = WITH_OPTIONAL_MEMBER_OFFSET_BIT_SIZE;
    ASSERT_EQ(expectedBitSize, optionalMemberOffset.bitSizeOf());
}

TEST_F(OptionalMemberOffsetTest, bitSizeOfWithoutOptional)
{
    OptionalMemberOffset optionalMemberOffset;
    fillOptionalMemberOffset(optionalMemberOffset, false, 0xDEAD, 0, 0xBEEF);

    const size_t expectedBitSize = WITHOUT_OPTIONAL_MEMBER_OFFSET_BIT_SIZE;
    ASSERT_EQ(expectedBitSize, optionalMemberOffset.bitSizeOf());
}

TEST_F(OptionalMemberOffsetTest, initializeOffsetsWithOptional)
{
    const bool hasOptional = true;
    const uint32_t optionalField = 0x1010;
    const int32_t field = 0x2020;
    OptionalMemberOffset optionalMemberOffset;
    fillOptionalMemberOffset(optionalMemberOffset, hasOptional, WRONG_OPTIONAL_FIELD_OFFSET, optionalField,
            field);

    const size_t bitPosition = 2;
    const size_t expectedBitSize = WITH_OPTIONAL_MEMBER_OFFSET_BIT_SIZE;
    ASSERT_EQ(expectedBitSize, optionalMemberOffset.initializeOffsets(bitPosition));
    checkOptionalMemberOffset(optionalMemberOffset, hasOptional, OPTIONAL_FIELD_OFFSET, optionalField, field);
}

TEST_F(OptionalMemberOffsetTest, initializeOffsetsWithoutOptional)
{
    const bool hasOptional = false;
    const uint32_t optionalFieldOffset = 0xABCD;
    const int32_t optionalField = 0;
    const int32_t field = 0x2020;
    OptionalMemberOffset optionalMemberOffset;
    fillOptionalMemberOffset(optionalMemberOffset, hasOptional, optionalFieldOffset, optionalField, field);

    const size_t bitPosition = 2;
    const size_t expectedBitSize = WITHOUT_OPTIONAL_MEMBER_OFFSET_BIT_SIZE;
    ASSERT_EQ(expectedBitSize + bitPosition, optionalMemberOffset.initializeOffsets(bitPosition));
    checkOptionalMemberOffset(optionalMemberOffset, hasOptional, optionalFieldOffset, optionalField, field);
}

TEST_F(OptionalMemberOffsetTest, writeWithOptional)
{
    const bool hasOptional = true;
    const int32_t optionalField = 0x1A1A;
    const int32_t field = 0xA1A1;
    OptionalMemberOffset optionalMemberOffset;
    fillOptionalMemberOffset(optionalMemberOffset, hasOptional, WRONG_OPTIONAL_FIELD_OFFSET, optionalField,
            field);

    zserio::BitStreamWriter writer;
    optionalMemberOffset.write(writer);
    checkOptionalMemberOffset(optionalMemberOffset, hasOptional, OPTIONAL_FIELD_OFFSET, optionalField, field);

    size_t writeBufferByteSize;
    const uint8_t* writeBuffer = writer.getWriteBuffer(writeBufferByteSize);
    zserio::BitStreamReader reader(writeBuffer, writeBufferByteSize);
    OptionalMemberOffset readOptionalMemberOffset(reader);
    checkOptionalMemberOffset(readOptionalMemberOffset, hasOptional, OPTIONAL_FIELD_OFFSET, optionalField,
            field);
    ASSERT_TRUE(optionalMemberOffset == readOptionalMemberOffset);
}

TEST_F(OptionalMemberOffsetTest, writeWithoutOptional)
{
    const bool hasOptional = false;
    const uint32_t optionalFieldOffset = 0xABCE;
    const int32_t optionalField = 0;
    const int32_t field = 0x7ACF;
    OptionalMemberOffset optionalMemberOffset;
    fillOptionalMemberOffset(optionalMemberOffset, hasOptional, optionalFieldOffset, optionalField, field);

    zserio::BitStreamWriter writer;
    optionalMemberOffset.write(writer);

    size_t writeBufferByteSize;
    const uint8_t* writeBuffer = writer.getWriteBuffer(writeBufferByteSize);
    zserio::BitStreamReader reader(writeBuffer, writeBufferByteSize);
    OptionalMemberOffset readOptionalMemberOffset(reader);
    checkOptionalMemberOffset(readOptionalMemberOffset, hasOptional, optionalFieldOffset, optionalField, field);
    ASSERT_TRUE(optionalMemberOffset == readOptionalMemberOffset);
}

} // namespace optional_member_offset
} // namespace offsets
