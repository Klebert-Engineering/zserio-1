/**
 * Automatically generated by Zserio Java extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode.
 */

package test_object;

public enum CreatorEnum implements zserio.runtime.io.PackableWriter, zserio.runtime.PackableSizeOf,
        zserio.runtime.ZserioEnum
{
    ONE((byte)0),
    TWO((byte)1),
    MinusOne((byte)-1);

    private CreatorEnum(byte value)
    {
        this.value = value;
    }

    public byte getValue()
    {
        return value;
    }

    @Override
    public java.lang.Number getGenericValue()
    {
        return value;
    }

    public static zserio.runtime.typeinfo.TypeInfo typeInfo()
    {
        return new zserio.runtime.typeinfo.TypeInfo.EnumTypeInfo(
                "test_object.CreatorEnum",
                CreatorEnum.class,
                zserio.runtime.typeinfo.TypeInfo.BuiltinTypeInfo.getInt8(),
                new java.util.ArrayList<java.util.function.Supplier<java.lang.Object>>(),
                java.util.Arrays.asList(
                            new zserio.runtime.typeinfo.ItemInfo("ONE", java.math.BigInteger.valueOf((byte)0)),
                            new zserio.runtime.typeinfo.ItemInfo("TWO", java.math.BigInteger.valueOf((byte)1)),
                            new zserio.runtime.typeinfo.ItemInfo("MinusOne", java.math.BigInteger.valueOf((byte)-1))
                )
            );
    }

    @Override
    public void initPackingContext(zserio.runtime.array.PackingContext context)
    {
        final zserio.runtime.array.DeltaContext deltaContext = context.cast();
        deltaContext.init(
                new zserio.runtime.array.ArrayTraits.SignedBitFieldByteArrayTraits(8),
                new zserio.runtime.array.ArrayElement.ByteArrayElement(value));
    }

    @Override
    public int bitSizeOf()
    {
        return bitSizeOf(0);
    }

    @Override
    public int bitSizeOf(long bitPosition)
    {
        return 8;
    }

    @Override
    public int bitSizeOf(zserio.runtime.array.PackingContext context, long bitPosition)
    {
        final zserio.runtime.array.DeltaContext deltaContext = context.cast();
        return deltaContext.bitSizeOf(
                new zserio.runtime.array.ArrayTraits.SignedBitFieldByteArrayTraits(8),
                new zserio.runtime.array.ArrayElement.ByteArrayElement(value));
    }

    @Override
    public long initializeOffsets()
    {
        return initializeOffsets(0);
    }

    @Override
    public long initializeOffsets(long bitPosition) throws zserio.runtime.ZserioError
    {
        return bitPosition + bitSizeOf(bitPosition);
    }

    @Override
    public long initializeOffsets(zserio.runtime.array.PackingContext context, long bitPosition)
    {
        return bitPosition + bitSizeOf(context, bitPosition);
    }

    @Override
    public void write(zserio.runtime.io.BitStreamWriter out) throws java.io.IOException
    {
        out.writeByte(getValue());
    }

    @Override
    public void write(zserio.runtime.array.PackingContext context, zserio.runtime.io.BitStreamWriter out)
            throws java.io.IOException
    {
        final zserio.runtime.array.DeltaContext deltaContext = context.cast();
        deltaContext.write(
                new zserio.runtime.array.ArrayTraits.SignedBitFieldByteArrayTraits(8), out,
                new zserio.runtime.array.ArrayElement.ByteArrayElement(value));
    }

    public static CreatorEnum readEnum(zserio.runtime.io.BitStreamReader in) throws java.io.IOException
    {
        return toEnum(in.readByte());
    }

    public static CreatorEnum readEnum(zserio.runtime.array.PackingContext context,
            zserio.runtime.io.BitStreamReader in) throws java.io.IOException
    {
        final zserio.runtime.array.DeltaContext deltaContext = context.cast();
        return toEnum(((zserio.runtime.array.ArrayElement.ByteArrayElement)
                deltaContext.read(
                        new zserio.runtime.array.ArrayTraits.SignedBitFieldByteArrayTraits(8), in)).get());
    }

    public static CreatorEnum toEnum(byte value)
    {
        switch (value)
        {
            case (byte)0:
                return ONE;
            case (byte)1:
                return TWO;
            case (byte)-1:
                return MinusOne;
            default:
                throw new java.lang.IllegalArgumentException(
                        "Unknown value for enumeration CreatorEnum: " + value + "!");
        }
    }

    public static CreatorEnum toEnum(java.lang.String itemName)
    {
        if (itemName.equals("ONE"))
            return ONE;
        if (itemName.equals("TWO"))
            return TWO;
        if (itemName.equals("MinusOne"))
            return MinusOne;
        throw new java.lang.IllegalArgumentException(
                "Enum item '" + itemName + "' doesn't exist in enumeration CreatorEnum!");
    }

    private byte value;
}
