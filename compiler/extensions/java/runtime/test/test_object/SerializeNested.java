/**
 * Automatically generated by Zserio Java generator version 1.1.1 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode.
 */

package test_object;

public class SerializeNested implements zserio.runtime.io.Writer, zserio.runtime.SizeOf
{
    public SerializeNested(
            byte param_)
    {
        this.param_ = param_;
    }

    public SerializeNested(zserio.runtime.io.BitStreamReader in,
            byte param_)
            throws java.io.IOException
    {
        this.param_ = param_;

        read(in);
    }

    public SerializeNested(
            byte param_,
            short offset_,
            java.lang.Long optionalValue_)
    {
        this(param_);

        setOffset(offset_);
        setOptionalValue(optionalValue_);
    }

    public static zserio.runtime.typeinfo.TypeInfo typeInfo()
    {
        final java.lang.String templateName = "";
        final java.util.List<zserio.runtime.typeinfo.TypeInfo> templateArguments =
                new java.util.ArrayList<zserio.runtime.typeinfo.TypeInfo>();
        final java.util.List<zserio.runtime.typeinfo.FieldInfo> fieldList =
                java.util.Arrays.asList(
                        new zserio.runtime.typeinfo.FieldInfo(
                                "offset", // schemaName
                                "getOffset", // getterName
                                "setOffset", // setterName
                                zserio.runtime.typeinfo.TypeInfo.BuiltinTypeInfo.getUInt8(), // typeInfo
                                new java.util.ArrayList<java.util.function.BiFunction<java.lang.Object, java.lang.Integer, java.lang.Object>>(), // typeArguments
                                false, // isExtended
                                null, // alignment
                                null, // offset
                                null, // initializer
                                false, // isOptional
                                null, // optionalCondition
                                "", // isUsedIndicatorName
                                "", // isSetIndicatorName
                                null, // constraint
                                false, // isArray
                                null, // arrayLength
                                false, // isPacked
                                false // isImplicit
                        ),
                        new zserio.runtime.typeinfo.FieldInfo(
                                "optionalValue", // schemaName
                                "getOptionalValue", // getterName
                                "setOptionalValue", // setterName
                                zserio.runtime.typeinfo.TypeInfo.BuiltinTypeInfo.getUInt32(), // typeInfo
                                new java.util.ArrayList<java.util.function.BiFunction<java.lang.Object, java.lang.Integer, java.lang.Object>>(), // typeArguments
                                false, // isExtended
                                null, // alignment
                                (obj, index) -> ((SerializeNested)obj).getOffset(), // offset
                                null, // initializer
                                true, // isOptional
                                (obj) -> ((SerializeNested)obj).getParam() >= 0, // optionalCondition
                                "isOptionalValueUsed", // isUsedIndicatorName
                                "isOptionalValueSet", // isSetIndicatorName
                                null, // constraint
                                false, // isArray
                                null, // arrayLength
                                false, // isPacked
                                false // isImplicit
                        )
                );
        final java.util.List<zserio.runtime.typeinfo.ParameterInfo> parameterList =
                java.util.Arrays.asList(
                        new zserio.runtime.typeinfo.ParameterInfo(
                                "param", // schemaName
                                zserio.runtime.typeinfo.TypeInfo.BuiltinTypeInfo.getInt8() // typeInfo
                        )
                );
        final java.util.List<zserio.runtime.typeinfo.FunctionInfo> functionList =
                new java.util.ArrayList<zserio.runtime.typeinfo.FunctionInfo>();

        return new zserio.runtime.typeinfo.TypeInfo.StructTypeInfo(
                "test_object.SerializeNested", SerializeNested.class, templateName, templateArguments,
                fieldList, parameterList, functionList
        );
    }

    @Override
    public int bitSizeOf()
    {
        return bitSizeOf(0);
    }

    @Override
    public int bitSizeOf(long bitPosition)
    {
        long endBitPosition = bitPosition;

        endBitPosition += 8;
        if (isOptionalValueUsed())
        {
            endBitPosition = zserio.runtime.BitPositionUtil.alignTo(java.lang.Byte.SIZE, endBitPosition);
            endBitPosition += 32;
        }

        return (int)(endBitPosition - bitPosition);
    }

    public byte getParam()
    {
        return this.param_;
    }

    public short getOffset()
    {
        return offset_;
    }

    public void setOffset(short offset_)
    {
        this.offset_ = offset_;
    }

    public java.lang.Long getOptionalValue()
    {
        return optionalValue_;
    }

    public void setOptionalValue(java.lang.Long optionalValue_)
    {
        this.optionalValue_ = optionalValue_;
    }

    public boolean isOptionalValueUsed()
    {
        return (getParam() >= 0);
    }

    public boolean isOptionalValueSet()
    {
        return (optionalValue_ != null);
    }

    public void resetOptionalValue()
    {
        this.optionalValue_ = null;
    }

    @Override
    public boolean equals(java.lang.Object obj)
    {
        if (obj instanceof SerializeNested)
        {
            final SerializeNested that = (SerializeNested)obj;

            return
                    this.param_ == that.param_ &&
                    offset_ == that.offset_ &&
                    ((!isOptionalValueUsed()) ? !that.isOptionalValueUsed() :
                        ((optionalValue_ == null) ? that.optionalValue_ == null : optionalValue_.equals(that.optionalValue_)));
        }

        return false;
    }

    @Override
    public int hashCode()
    {
        int result = zserio.runtime.HashCodeUtil.HASH_SEED;

        result = zserio.runtime.HashCodeUtil.calcHashCode(result, getParam());
        result = zserio.runtime.HashCodeUtil.calcHashCode(result, offset_);
        if (isOptionalValueUsed())
            result = zserio.runtime.HashCodeUtil.calcHashCode(result, optionalValue_);

        return result;
    }

    public void read(zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        offset_ = in.readUnsignedByte();

        if (getParam() >= 0)
        {
            in.alignTo(java.lang.Byte.SIZE);
            if (in.getBytePosition() != (getOffset()))
            {
                throw new zserio.runtime.ZserioError("Read: Wrong offset for field SerializeNested.optionalValue: " +
                        in.getBytePosition() + " != " + (getOffset()) + "!");
            }
            optionalValue_ = in.readUnsignedInt();
        }
    }

    @Override
    public long initializeOffsets()
    {
        return initializeOffsets(0);
    }

    @Override
    public long initializeOffsets(long bitPosition)
    {
        long endBitPosition = bitPosition;

        endBitPosition += 8;
        if (isOptionalValueUsed())
        {
            endBitPosition = zserio.runtime.BitPositionUtil.alignTo(java.lang.Byte.SIZE, endBitPosition);
            {
                final short value = (short)zserio.runtime.BitPositionUtil.bitsToBytes(endBitPosition);
                setOffset(value);
            }
            endBitPosition += 32;
        }

        return endBitPosition;
    }

    @Override
    public void write(zserio.runtime.io.BitStreamWriter out) throws java.io.IOException
    {
        out.writeUnsignedByte(offset_);

        if (isOptionalValueUsed())
        {
            out.alignTo(java.lang.Byte.SIZE);
            if (out.getBytePosition() != (getOffset()))
            {
                throw new zserio.runtime.ZserioError("Write: Wrong offset for field SerializeNested.optionalValue: " +
                        out.getBytePosition() + " != " + (getOffset()) + "!");
            }
            out.writeUnsignedInt(optionalValue_);
        }
    }

    private final byte param_;
    private short offset_;
    private java.lang.Long optionalValue_;
}
