/**
 * Automatically generated by Zserio Java generator version 1.1.1 using Zserio core 2.14.1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode.
 */

package test_object;

public class ArrayHolder implements zserio.runtime.io.Writer, zserio.runtime.SizeOf
{
    public ArrayHolder()
    {
    }

    public ArrayHolder(zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        read(in);
    }

    public ArrayHolder(
            test_object.ArrayEnum[] enumArray_,
            test_object.ArrayBitmask[] bitmaskArray_,
            test_object.ArrayObject[] packedArray_)
    {
        setEnumArray(enumArray_);
        setBitmaskArray(bitmaskArray_);
        setPackedArray(packedArray_);
    }

    public static zserio.runtime.typeinfo.TypeInfo typeInfo()
    {
        final java.lang.String templateName = "";
        final java.util.List<zserio.runtime.typeinfo.TypeInfo> templateArguments =
                new java.util.ArrayList<zserio.runtime.typeinfo.TypeInfo>();
        final java.util.List<zserio.runtime.typeinfo.FieldInfo> fieldList =
                java.util.Arrays.asList(
                        new zserio.runtime.typeinfo.FieldInfo(
                                "enumArray", // schemaName
                                "getEnumArray", // getterName
                                "setEnumArray", // setterName
                                test_object.ArrayEnum.typeInfo(), // typeInfo
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
                                true, // isArray
                                null, // arrayLength
                                true, // isPacked
                                false // isImplicit
                        ),
                        new zserio.runtime.typeinfo.FieldInfo(
                                "bitmaskArray", // schemaName
                                "getBitmaskArray", // getterName
                                "setBitmaskArray", // setterName
                                test_object.ArrayBitmask.typeInfo(), // typeInfo
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
                                true, // isArray
                                null, // arrayLength
                                true, // isPacked
                                false // isImplicit
                        ),
                        new zserio.runtime.typeinfo.FieldInfo(
                                "packedArray", // schemaName
                                "getPackedArray", // getterName
                                "setPackedArray", // setterName
                                test_object.ArrayObject.typeInfo(), // typeInfo
                                java.util.Arrays.asList(), // typeArguments
                                false, // isExtended
                                null, // alignment
                                null, // offset
                                null, // initializer
                                false, // isOptional
                                null, // optionalCondition
                                "", // isUsedIndicatorName
                                "", // isSetIndicatorName
                                null, // constraint
                                true, // isArray
                                null, // arrayLength
                                true, // isPacked
                                false // isImplicit
                        )
                );
        final java.util.List<zserio.runtime.typeinfo.ParameterInfo> parameterList =
                new java.util.ArrayList<zserio.runtime.typeinfo.ParameterInfo>();
        final java.util.List<zserio.runtime.typeinfo.FunctionInfo> functionList =
                new java.util.ArrayList<zserio.runtime.typeinfo.FunctionInfo>();

        return new zserio.runtime.typeinfo.TypeInfo.StructTypeInfo(
                "test_object.ArrayHolder", ArrayHolder.class, templateName, templateArguments,
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

        endBitPosition += enumArray_.bitSizeOfPacked(endBitPosition);
        endBitPosition += bitmaskArray_.bitSizeOfPacked(endBitPosition);
        endBitPosition += packedArray_.bitSizeOfPacked(endBitPosition);

        return (int)(endBitPosition - bitPosition);
    }

    public test_object.ArrayEnum[] getEnumArray()
    {
        return (enumArray_ == null) ? null : enumArray_.getRawArray();
    }

    public void setEnumArray(test_object.ArrayEnum[] enumArray_)
    {
        this.enumArray_ = new zserio.runtime.array.Array(
                new zserio.runtime.array.RawArray.EnumRawArray<>(test_object.ArrayEnum.class, enumArray_),
                new zserio.runtime.array.ArrayTraits.WritePackableObjectArrayTraits<test_object.ArrayEnum>(new ZserioElementFactory_enumArray()),
                zserio.runtime.array.ArrayType.AUTO);
    }

    public test_object.ArrayBitmask[] getBitmaskArray()
    {
        return (bitmaskArray_ == null) ? null : bitmaskArray_.getRawArray();
    }

    public void setBitmaskArray(test_object.ArrayBitmask[] bitmaskArray_)
    {
        this.bitmaskArray_ = new zserio.runtime.array.Array(
                new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.ArrayBitmask.class, bitmaskArray_),
                new zserio.runtime.array.ArrayTraits.WritePackableObjectArrayTraits<test_object.ArrayBitmask>(new ZserioElementFactory_bitmaskArray()),
                zserio.runtime.array.ArrayType.AUTO);
    }

    public test_object.ArrayObject[] getPackedArray()
    {
        return (packedArray_ == null) ? null : packedArray_.getRawArray();
    }

    public void setPackedArray(test_object.ArrayObject[] packedArray_)
    {
        this.packedArray_ = new zserio.runtime.array.Array(
                new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.ArrayObject.class, packedArray_),
                new zserio.runtime.array.ArrayTraits.WritePackableObjectArrayTraits<test_object.ArrayObject>(new ZserioElementFactory_packedArray()),
                zserio.runtime.array.ArrayType.AUTO);
    }

    @Override
    public boolean equals(java.lang.Object obj)
    {
        if (obj instanceof ArrayHolder)
        {
            final ArrayHolder that = (ArrayHolder)obj;

            return
                    ((enumArray_ == null) ? that.enumArray_ == null : enumArray_.equals(that.enumArray_)) &&
                    ((bitmaskArray_ == null) ? that.bitmaskArray_ == null : bitmaskArray_.equals(that.bitmaskArray_)) &&
                    ((packedArray_ == null) ? that.packedArray_ == null : packedArray_.equals(that.packedArray_));
        }

        return false;
    }

    @Override
    public int hashCode()
    {
        int result = zserio.runtime.HashCodeUtil.HASH_SEED;

        result = zserio.runtime.HashCodeUtil.calcHashCode(result, enumArray_);
        result = zserio.runtime.HashCodeUtil.calcHashCode(result, bitmaskArray_);
        result = zserio.runtime.HashCodeUtil.calcHashCode(result, packedArray_);

        return result;
    }

    public void read(zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        enumArray_ = new zserio.runtime.array.Array(
                new zserio.runtime.array.RawArray.EnumRawArray<>(test_object.ArrayEnum.class),
                new zserio.runtime.array.ArrayTraits.WritePackableObjectArrayTraits<test_object.ArrayEnum>(new ZserioElementFactory_enumArray()),
                zserio.runtime.array.ArrayType.AUTO);
        enumArray_.readPacked(in);

        bitmaskArray_ = new zserio.runtime.array.Array(
                new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.ArrayBitmask.class),
                new zserio.runtime.array.ArrayTraits.WritePackableObjectArrayTraits<test_object.ArrayBitmask>(new ZserioElementFactory_bitmaskArray()),
                zserio.runtime.array.ArrayType.AUTO);
        bitmaskArray_.readPacked(in);

        packedArray_ = new zserio.runtime.array.Array(
                new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.ArrayObject.class),
                new zserio.runtime.array.ArrayTraits.WritePackableObjectArrayTraits<test_object.ArrayObject>(new ZserioElementFactory_packedArray()),
                zserio.runtime.array.ArrayType.AUTO);
        packedArray_.readPacked(in);
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

        endBitPosition = enumArray_.initializeOffsetsPacked(endBitPosition);
        endBitPosition = bitmaskArray_.initializeOffsetsPacked(endBitPosition);
        endBitPosition = packedArray_.initializeOffsetsPacked(endBitPosition);

        return endBitPosition;
    }

    @Override
    public void write(zserio.runtime.io.BitStreamWriter out) throws java.io.IOException
    {
        enumArray_.writePacked(out);

        bitmaskArray_.writePacked(out);

        packedArray_.writePacked(out);
    }

    private static final class ZserioElementFactory_enumArray implements zserio.runtime.array.PackableElementFactory<test_object.ArrayEnum>
    {
        @Override
        public test_object.ArrayEnum create(zserio.runtime.io.BitStreamReader in, int index)
                throws java.io.IOException
        {
            return test_object.ArrayEnum.readEnum(in);
        }

        @Override
        public zserio.runtime.array.PackingContext createPackingContext()
        {
            return new zserio.runtime.array.DeltaContext();
        }

        @Override
        public test_object.ArrayEnum create(zserio.runtime.array.PackingContext context,
                zserio.runtime.io.BitStreamReader in, int index) throws java.io.IOException
        {
            return test_object.ArrayEnum.readEnum(context, in);
        }
    }

    private static final class ZserioElementFactory_bitmaskArray implements zserio.runtime.array.PackableElementFactory<test_object.ArrayBitmask>
    {
        @Override
        public test_object.ArrayBitmask create(zserio.runtime.io.BitStreamReader in, int index)
                throws java.io.IOException
        {
            return new test_object.ArrayBitmask(in);
        }

        @Override
        public zserio.runtime.array.PackingContext createPackingContext()
        {
            return new zserio.runtime.array.DeltaContext();
        }

        @Override
        public test_object.ArrayBitmask create(zserio.runtime.array.PackingContext context,
                zserio.runtime.io.BitStreamReader in, int index) throws java.io.IOException
        {
            return new test_object.ArrayBitmask(context, in);
        }
    }

    private static final class ZserioElementFactory_packedArray implements zserio.runtime.array.PackableElementFactory<test_object.ArrayObject>
    {
        @Override
        public test_object.ArrayObject create(zserio.runtime.io.BitStreamReader in, int index)
                throws java.io.IOException
        {
            return new test_object.ArrayObject(in);
        }

        @Override
        public zserio.runtime.array.PackingContext createPackingContext()
        {
            return new test_object.ArrayObject.ZserioPackingContext();
        }

        @Override
        public test_object.ArrayObject create(zserio.runtime.array.PackingContext context,
                zserio.runtime.io.BitStreamReader in, int index) throws java.io.IOException
        {
            return new test_object.ArrayObject(context, in);
        }
    }

    private zserio.runtime.array.Array enumArray_;
    private zserio.runtime.array.Array bitmaskArray_;
    private zserio.runtime.array.Array packedArray_;
}
