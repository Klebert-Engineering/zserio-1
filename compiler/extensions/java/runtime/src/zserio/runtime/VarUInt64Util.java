package zserio.runtime;

/**
 * Provide converting functions from varuint64 values which check range correctness.
 */
public final class VarUInt64Util
{
    /**
     * Converts long value read from varuint64 to signed integer value.
     *
     * Used e.g. for conversion to union choice tag values.
     *
     * @param value Value read from varuint64.
     *
     * @return Checked singed integer value.
     *
     * @throws ZserioError Throws if long value cannot be convert to signed integer value.
     */
    public static int convertVarUInt64ToInt(long value) throws ZserioError
    {
        if (value > Integer.MAX_VALUE)
            throw new ZserioError("convertVarUInt64ToInt: Value is out of bounds for conversion!");

        return (int) value;
    }
}
