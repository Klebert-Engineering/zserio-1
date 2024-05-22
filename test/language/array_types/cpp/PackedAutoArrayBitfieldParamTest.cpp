#include "array_types/packed_auto_array_bitfield_param/ParameterizedBitfieldLength.h"
#include "gtest/gtest.h"
#include "zserio/BitStreamReader.h"
#include "zserio/BitStreamWriter.h"
#include "zserio/SerializeUtil.h"

namespace array_types
{
namespace packed_auto_array_bitfield_param
{

using allocator_type = ParameterizedBitfieldLength::allocator_type;
template <typename T>
using vector_type = zserio::vector<T, allocator_type>;

class PackedAutoArrayBitfieldParamTest : public ::testing::Test
{
protected:
    void fillParameterizedBitfieldLength(ParameterizedBitfieldLength& parameterizedBitfieldLength)
    {
        // usage to none-const getter is intended to check old C++ bug
        vector_type<uint16_t>& dynamicBitfieldArray = parameterizedBitfieldLength.getDynamicBitfieldArray();
        for (uint16_t i = 0; i < DYNAMIC_BITFIELD_ARRAY_SIZE; ++i)
        {
            dynamicBitfieldArray.push_back(i);
        }
    }

    static const std::string BLOB_NAME;
    static const uint8_t NUM_BITS_PARAM;

    zserio::BitBuffer bitBuffer = zserio::BitBuffer(1024 * 8);

private:
    static const size_t DYNAMIC_BITFIELD_ARRAY_SIZE;
};

const std::string PackedAutoArrayBitfieldParamTest::BLOB_NAME =
        "language/array_types/packed_auto_array_bitfield_param.blob";
const uint8_t PackedAutoArrayBitfieldParamTest::NUM_BITS_PARAM = 9;

const size_t PackedAutoArrayBitfieldParamTest::DYNAMIC_BITFIELD_ARRAY_SIZE = (1U << 9U) - 1;

TEST_F(PackedAutoArrayBitfieldParamTest, copyConstructor)
{
    ParameterizedBitfieldLength parameterizedBitfieldLengthOrig;
    fillParameterizedBitfieldLength(parameterizedBitfieldLengthOrig);
    parameterizedBitfieldLengthOrig.initialize(NUM_BITS_PARAM);
    const size_t origBitSize = parameterizedBitfieldLengthOrig.bitSizeOf();

    zserio::BitBuffer bitBufferOrig(origBitSize);
    zserio::BitStreamWriter writerOrig(bitBufferOrig);
    parameterizedBitfieldLengthOrig.write(writerOrig);

    ParameterizedBitfieldLength parameterizedBitfieldLengthCopied(parameterizedBitfieldLengthOrig);
    ASSERT_EQ(origBitSize, parameterizedBitfieldLengthCopied.bitSizeOf());

    // check that PackedArrayTraits in the copied array was properly reinitialized:
    // - change parameter in the parameterizedBitfieldLengthOrig to ensure that it's not
    //   used in the parameterizedBitfieldLengthCopied
    parameterizedBitfieldLengthOrig.initialize(0);
    ASSERT_EQ(origBitSize, parameterizedBitfieldLengthCopied.bitSizeOf());
}

TEST_F(PackedAutoArrayBitfieldParamTest, moveConstructor)
{
    ParameterizedBitfieldLength parameterizedBitfieldLengthOrig;
    fillParameterizedBitfieldLength(parameterizedBitfieldLengthOrig);
    parameterizedBitfieldLengthOrig.initialize(NUM_BITS_PARAM);
    const size_t origBitSize = parameterizedBitfieldLengthOrig.bitSizeOf();

    zserio::BitBuffer bitBufferOrig(origBitSize);
    zserio::BitStreamWriter writerOrig(bitBufferOrig);
    parameterizedBitfieldLengthOrig.write(writerOrig);

    ParameterizedBitfieldLength parameterizedBitfieldLengthMoved(std::move(parameterizedBitfieldLengthOrig));
    ASSERT_EQ(origBitSize, parameterizedBitfieldLengthMoved.bitSizeOf());

    // check that PackedArrayTraits in the moved array was properly reinitialized:
    // - change parameter in the parameterizedBitfieldLengthOrig to ensure that it's not
    //   used in the parameterizedBitfieldLengthMoved
    parameterizedBitfieldLengthOrig.initialize(0);
    ASSERT_EQ(origBitSize, parameterizedBitfieldLengthMoved.bitSizeOf());
}

TEST_F(PackedAutoArrayBitfieldParamTest, copyAssignmentOperator)
{
    ParameterizedBitfieldLength parameterizedBitfieldLengthCopied;
    size_t origBitSize = 0;
    {
        ParameterizedBitfieldLength parameterizedBitfieldLengthOrig;
        fillParameterizedBitfieldLength(parameterizedBitfieldLengthOrig);
        parameterizedBitfieldLengthOrig.initialize(NUM_BITS_PARAM);
        origBitSize = parameterizedBitfieldLengthOrig.bitSizeOf();

        parameterizedBitfieldLengthCopied = parameterizedBitfieldLengthOrig;
        ASSERT_EQ(origBitSize, parameterizedBitfieldLengthCopied.bitSizeOf());
    }

    // check that ArrayTraits in the copied array was properly reinitialized:
    // - create a replacement for the parameterizedBitfieldLengthOrig on stack which will override the old
    //   parameter to ensure that it's not used in the parameterizedBitfieldLengthCopied
    ParameterizedBitfieldLength parameterizedBitfieldLengthOther;
    parameterizedBitfieldLengthOther.initialize(0);

    ASSERT_EQ(origBitSize, parameterizedBitfieldLengthCopied.bitSizeOf());
}

TEST_F(PackedAutoArrayBitfieldParamTest, moveAssignmentOperator)
{
    ParameterizedBitfieldLength parameterizedBitfieldLengthMoved;
    size_t origBitSize = 0;
    {
        ParameterizedBitfieldLength parameterizedBitfieldLengthOrig;
        fillParameterizedBitfieldLength(parameterizedBitfieldLengthOrig);
        parameterizedBitfieldLengthOrig.initialize(NUM_BITS_PARAM);
        origBitSize = parameterizedBitfieldLengthOrig.bitSizeOf();

        parameterizedBitfieldLengthMoved = std::move(parameterizedBitfieldLengthOrig);
        ASSERT_EQ(origBitSize, parameterizedBitfieldLengthMoved.bitSizeOf());
    }

    // check that ArrayTraits in the moved array was properly reinitialized:
    // - create a replacement for the parameterizedBitfieldLengthOrig on stack which will override the old
    //   parameter to ensure that it's not used in the parameterizedBitfieldLengthMoved
    ParameterizedBitfieldLength parameterizedBitfieldLengthOther;
    parameterizedBitfieldLengthOther.initialize(0);

    ASSERT_EQ(origBitSize, parameterizedBitfieldLengthMoved.bitSizeOf());
}

TEST_F(PackedAutoArrayBitfieldParamTest, writeRead)
{
    ParameterizedBitfieldLength parameterizedBitfieldLength;
    fillParameterizedBitfieldLength(parameterizedBitfieldLength);
    parameterizedBitfieldLength.initialize(NUM_BITS_PARAM);

    zserio::BitStreamWriter writer(bitBuffer);
    parameterizedBitfieldLength.write(writer);

    zserio::BitStreamReader reader(writer.getWriteBuffer(), writer.getBitPosition(), zserio::BitsTag());
    ParameterizedBitfieldLength readParameterizedBitfieldLength(reader, NUM_BITS_PARAM);
    ASSERT_EQ(parameterizedBitfieldLength, readParameterizedBitfieldLength);
}

TEST_F(PackedAutoArrayBitfieldParamTest, writeReadFile)
{
    ParameterizedBitfieldLength parameterizedBitfieldLength;
    fillParameterizedBitfieldLength(parameterizedBitfieldLength);

    zserio::serializeToFile(parameterizedBitfieldLength, BLOB_NAME, NUM_BITS_PARAM);

    const auto readParameterizedBitfieldLength =
            zserio::deserializeFromFile<ParameterizedBitfieldLength>(BLOB_NAME, NUM_BITS_PARAM);
    ASSERT_EQ(parameterizedBitfieldLength, readParameterizedBitfieldLength);
}

} // namespace packed_auto_array_bitfield_param
} // namespace array_types
