/**
 * Automatically generated by Zserio Java extension version 2.11.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode.
 */

package test_object;

public class SerializeObject implements zserio.runtime.io.PackableWriter, zserio.runtime.PackableSizeOf
{
    public static final class ZserioPackingContext extends zserio.runtime.array.PackingContext
    {
        public ZserioPackingContext()
        {
            param_ = new zserio.runtime.array.DeltaContext();
            nested_ = new test_object.SerializeNested.ZserioPackingContext();
        }

        public zserio.runtime.array.DeltaContext getParam()
        {
            return param_;
        }

        public test_object.SerializeNested.ZserioPackingContext getNested()
        {
            return nested_;
        }

        private zserio.runtime.array.DeltaContext param_;
        private test_object.SerializeNested.ZserioPackingContext nested_;
    };

    public SerializeObject()
    {
    }

    public SerializeObject(zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        read(in);
    }

    public SerializeObject(zserio.runtime.array.PackingContext context, zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        read(context, in);
    }

    public SerializeObject(
            byte param_,
            test_object.SerializeNested nested_)
    {
        setParam(param_);
        setNested(nested_);
    }

    public static zserio.runtime.typeinfo.TypeInfo typeInfo()
    {
        final java.lang.String templateName = "";
        final java.util.List<zserio.runtime.typeinfo.TypeInfo> templateArguments =
                new java.util.ArrayList<zserio.runtime.typeinfo.TypeInfo>();
        final java.util.List<zserio.runtime.typeinfo.FieldInfo> fieldList =
                java.util.Arrays.asList(
                        new zserio.runtime.typeinfo.FieldInfo(
                                "param", // schemaName
                                "getParam", // getterName
                                "setParam", // setterName
                                zserio.runtime.typeinfo.TypeInfo.BuiltinTypeInfo.getInt8(), // typeInfo
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
                                "nested", // schemaName
                                "getNested", // getterName
                                "setNested", // setterName
                                test_object.SerializeNested.typeInfo(), // typeInfo
                                java.util.Arrays.asList((obj, index) -> ((SerializeObject)obj).getParam()), // typeArguments
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
                        )
                );
        final java.util.List<zserio.runtime.typeinfo.ParameterInfo> parameterList =
                new java.util.ArrayList<zserio.runtime.typeinfo.ParameterInfo>();
        final java.util.List<zserio.runtime.typeinfo.FunctionInfo> functionList =
                new java.util.ArrayList<zserio.runtime.typeinfo.FunctionInfo>();

        return new zserio.runtime.typeinfo.TypeInfo.StructTypeInfo(
                "test_object.SerializeObject", SerializeObject.class, templateName, templateArguments,
                fieldList, parameterList, functionList
        );
    }

    @Override
    public void initPackingContext(zserio.runtime.array.PackingContext context)
    {
        final ZserioPackingContext zserioContext = context.cast();
        zserioContext.getParam().init(new zserio.runtime.array.ArrayTraits.SignedBitFieldByteArrayTraits((int)(8)),
                new zserio.runtime.array.ArrayElement.ByteArrayElement(param_));
        nested_.initPackingContext(zserioContext.getNested());
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
        endBitPosition += nested_.bitSizeOf(endBitPosition);

        return (int)(endBitPosition - bitPosition);
    }

    @Override
    public int bitSizeOf(zserio.runtime.array.PackingContext context, long bitPosition)
    {
        final ZserioPackingContext zserioContext = context.cast();
        long endBitPosition = bitPosition;

        endBitPosition += zserioContext.getParam().bitSizeOf(new zserio.runtime.array.ArrayTraits.SignedBitFieldByteArrayTraits((int)(8)),
                new zserio.runtime.array.ArrayElement.ByteArrayElement(param_));
        endBitPosition += nested_.bitSizeOf(zserioContext.getNested(), endBitPosition);

        return (int)(endBitPosition - bitPosition);
    }

    public byte getParam()
    {
        return param_;
    }

    public void setParam(byte param_)
    {
        this.param_ = param_;
    }

    public test_object.SerializeNested getNested()
    {
        return nested_;
    }

    public void setNested(test_object.SerializeNested nested_)
    {
        this.nested_ = nested_;
    }

    @Override
    public boolean equals(java.lang.Object obj)
    {
        if (obj instanceof SerializeObject)
        {
            final SerializeObject that = (SerializeObject)obj;

            return
                    param_ == that.param_ &&
                    ((nested_ == null) ? that.nested_ == null : nested_.equals(that.nested_));
        }

        return false;
    }

    @Override
    public int hashCode()
    {
        int result = zserio.runtime.HashCodeUtil.HASH_SEED;

        result = zserio.runtime.HashCodeUtil.calcHashCode(result, param_);
        result = zserio.runtime.HashCodeUtil.calcHashCode(result, nested_);

        return result;
    }

    public void read(zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        param_ = in.readByte();

        nested_ = new test_object.SerializeNested(in, (byte)(getParam()));
    }

    public void read(zserio.runtime.array.PackingContext context, zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        final ZserioPackingContext zserioContext = context.cast();
        param_ = ((zserio.runtime.array.ArrayElement.ByteArrayElement)
                zserioContext.getParam().read(new zserio.runtime.array.ArrayTraits.SignedBitFieldByteArrayTraits((int)(8)), in)).get();

        nested_ = new test_object.SerializeNested(zserioContext.getNested(), in, (byte)(getParam()));
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
        endBitPosition = nested_.initializeOffsets(endBitPosition);

        return endBitPosition;
    }

    @Override
    public long initializeOffsets(zserio.runtime.array.PackingContext context, long bitPosition)
    {
        final ZserioPackingContext zserioContext = context.cast();
        long endBitPosition = bitPosition;

        endBitPosition += zserioContext.getParam().bitSizeOf(new zserio.runtime.array.ArrayTraits.SignedBitFieldByteArrayTraits((int)(8)),
                new zserio.runtime.array.ArrayElement.ByteArrayElement(param_));
        endBitPosition = nested_.initializeOffsets(zserioContext.getNested(), endBitPosition);

        return endBitPosition;
    }

    @Override
    public void write(zserio.runtime.io.BitStreamWriter out) throws java.io.IOException
    {
        out.writeByte(param_);

        // check parameters
        if (nested_.getParam() != (byte)(getParam()))
        {
            throw new zserio.runtime.ZserioError("Write: Wrong parameter param for field SerializeObject.nested: " +
                    nested_.getParam() + " != " + (byte)(getParam()) + "!");
        }
        nested_.write(out);
    }

    @Override
    public void write(zserio.runtime.array.PackingContext context, zserio.runtime.io.BitStreamWriter out)
            throws java.io.IOException
    {
        final ZserioPackingContext zserioContext = context.cast();
        zserioContext.getParam().write(new zserio.runtime.array.ArrayTraits.SignedBitFieldByteArrayTraits((int)(8)), out,
                new zserio.runtime.array.ArrayElement.ByteArrayElement(param_));

        nested_.write(zserioContext.getNested(), out);
    }

    private byte param_;
    private test_object.SerializeNested nested_;
}
