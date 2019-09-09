package zserio.runtime;

/**
 * The class provides help methods for manipulation with bit stream position.
 */
public class BitPositionUtil
{
    /**
     * Aligns the bit size to the given alignment value.
     *
     * @param alignmentValue Value to align.
     * @param bitPosition    Current bit position where to apply alignment.
     *
     * @return Aligned bit size.
     */
    public static int alignTo(int alignmentValue, long bitPosition)
    {
        return (int)((bitPosition > 0 && alignmentValue != 0) ?
                (((bitPosition - 1) / alignmentValue) + 1) * alignmentValue : bitPosition);
    }

    /**
     * Converts a given bits value into a byte value.
     *
     * If the bits value is not a multiple of 8 an exception is thrown.
     *
     * @param numBits The number of bits to convert.
     *
     * @return Number of bytes.
     *
     * @throws ZserioError Throws if given number of bits is not multiple of 8.
     */
    public static long bitsToBytes(long numBits) throws ZserioError
    {
        if (numBits % 8 != 0)
            throw new ZserioError("bitsToBytes: " + numBits + " is not a multiple of 8.");

        return numBits / 8;
    }

    /**
     * Converts a given bytes value into a bits value.
     *
     * @param numBytes The number of bytes to convert.
     *
     * @return Number of bits.
     */
    public static long bytesToBits(long numBytes)
    {
        return numBytes * 8;
    }
}
