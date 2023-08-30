/**
 * Automatically generated by Zserio Java extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode.
 */

package test_object;

public class CreatorBitmask implements zserio.runtime.io.PackableWriter, zserio.runtime.PackableSizeOf,
        zserio.runtime.ZserioBitmask
{
    public CreatorBitmask()
    {
        this((short)0);
    }

    public CreatorBitmask(short value)
    {
        if (value < (short)0 || value > (short)255)
        {
            throw new java.lang.IllegalArgumentException(
                    "Value for bitmask 'CreatorBitmask' out of bounds: " + value + "!");
        }
        this.value = value;
    }

    public CreatorBitmask(zserio.runtime.io.BitStreamReader in) throws java.io.IOException
    {
        value = in.readUnsignedByte();
    }

    public CreatorBitmask(zserio.runtime.array.PackingContext context, zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        final zserio.runtime.array.DeltaContext deltaContext = context.cast();
        value = ((zserio.runtime.array.ArrayElement.ShortArrayElement)
                deltaContext.read(
                        new zserio.runtime.array.ArrayTraits.BitFieldShortArrayTraits(8), in)).get();
    }

    public static zserio.runtime.typeinfo.TypeInfo typeInfo()
    {
        return new zserio.runtime.typeinfo.TypeInfo.BitmaskTypeInfo(
                "test_object.CreatorBitmask",
                CreatorBitmask.class,
                zserio.runtime.typeinfo.TypeInfo.BuiltinTypeInfo.getUInt8(),
                new java.util.ArrayList<java.util.function.Supplier<java.lang.Object>>(),
                java.util.Arrays.asList(
                            new zserio.runtime.typeinfo.ItemInfo("READ", java.math.BigInteger.valueOf((short)1)),
                            new zserio.runtime.typeinfo.ItemInfo("WRITE", java.math.BigInteger.valueOf((short)2))
                )
        );
    }

    @Override
    public void initPackingContext(zserio.runtime.array.PackingContext context)
    {
        final zserio.runtime.array.DeltaContext deltaContext = context.cast();
        deltaContext.init(
                new zserio.runtime.array.ArrayTraits.BitFieldShortArrayTraits(8),
                new zserio.runtime.array.ArrayElement.ShortArrayElement(value));
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
                new zserio.runtime.array.ArrayTraits.BitFieldShortArrayTraits(8),
                new zserio.runtime.array.ArrayElement.ShortArrayElement(value));
    }

    @Override
    public long initializeOffsets()
    {
        return initializeOffsets(0);
    }

    @Override
    public long initializeOffsets(long bitPosition)
    {
        return bitPosition + bitSizeOf(bitPosition);
    }

    @Override
    public long initializeOffsets(zserio.runtime.array.PackingContext context, long bitPosition)
    {
        return bitPosition + bitSizeOf(context, bitPosition);
    }

    @Override
    public boolean equals(java.lang.Object other)
    {
        if (!(other instanceof CreatorBitmask))
            return false;

        final CreatorBitmask otherCreatorBitmask = (CreatorBitmask)other;
        return value == otherCreatorBitmask.value;
    }

    @Override
    public int hashCode()
    {
        int result = zserio.runtime.HashCodeUtil.HASH_SEED;
        result = zserio.runtime.HashCodeUtil.calcHashCode(result, value);
        return result;
    }

    @Override
    public java.lang.String toString()
    {
        final java.lang.StringBuilder builder = new java.lang.StringBuilder();

        if (this.and(CreatorBitmask.Values.READ).equals(CreatorBitmask.Values.READ))
            builder.append(builder.length() == 0 ? "READ" : " | READ");
        if (this.and(CreatorBitmask.Values.WRITE).equals(CreatorBitmask.Values.WRITE))
            builder.append(builder.length() == 0 ? "WRITE" : " | WRITE");

        return java.lang.String.valueOf(value) + "[" + builder.toString() + "]";
    }

    @Override
    public void write(zserio.runtime.io.BitStreamWriter out) throws java.io.IOException
    {
        out.writeUnsignedByte(value);
    }

    @Override
    public void write(zserio.runtime.array.PackingContext context, zserio.runtime.io.BitStreamWriter out)
            throws java.io.IOException
    {
        final zserio.runtime.array.DeltaContext deltaContext = context.cast();
        deltaContext.write(
                new zserio.runtime.array.ArrayTraits.BitFieldShortArrayTraits(8), out,
                new zserio.runtime.array.ArrayElement.ShortArrayElement(value));
    }

    public short getValue()
    {
        return value;
    }

    @Override
    public java.lang.Number getGenericValue()
    {
        return value;
    }

    public CreatorBitmask or(CreatorBitmask other)
    {
        return new CreatorBitmask((short)(value | other.value));
    }

    public CreatorBitmask and(CreatorBitmask other)
    {
        return new CreatorBitmask((short)(value & other.value));
    }

    public CreatorBitmask xor(CreatorBitmask other)
    {
        return new CreatorBitmask((short)(value ^ other.value));
    }

    public CreatorBitmask not()
    {
        return new CreatorBitmask((short)(~value & (short)255));
    }

    public static final class Values
    {
        public static final CreatorBitmask READ = new CreatorBitmask((short)1);
        public static final CreatorBitmask WRITE = new CreatorBitmask((short)2);
    }

    private short value;
}
