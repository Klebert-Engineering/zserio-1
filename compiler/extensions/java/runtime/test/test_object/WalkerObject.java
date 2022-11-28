/**
 * Automatically generated by Zserio Java extension version 2.9.0-pre1.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, typeInfoCode.
 */

package test_object;

@SuppressWarnings("cast")
public class WalkerObject implements zserio.runtime.io.Writer, zserio.runtime.SizeOf
{
    public WalkerObject()
    {
    }

    @Deprecated
    public WalkerObject(java.io.File file)
            throws java.io.IOException
    {
        try (final zserio.runtime.io.FileBitStreamReader in = new zserio.runtime.io.FileBitStreamReader(file))
        {
            read(in);
        }
    }

    public WalkerObject(zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        read(in);
    }

    public WalkerObject(zserio.runtime.array.PackingContextNode contextNode, zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        read(contextNode, in);
    }

    public WalkerObject(
            long identifier_,
            test_object.WalkerNested nested_,
            java.lang.String text_,
            test_object.WalkerUnion[] unionArray_,
            test_object.WalkerUnion[] optionalUnionArray_)
    {
        setIdentifier(identifier_);
        setNested(nested_);
        setText(text_);
        setUnionArray(unionArray_);
        setOptionalUnionArray(optionalUnionArray_);
    }

    public static zserio.runtime.typeinfo.TypeInfo typeInfo()
    {
        final java.lang.String templateName = "";
        final java.util.List<zserio.runtime.typeinfo.TypeInfo> templateArguments =
                new java.util.ArrayList<zserio.runtime.typeinfo.TypeInfo>();
        final java.util.List<zserio.runtime.typeinfo.FieldInfo> fieldList =
                java.util.Arrays.asList(
                        new zserio.runtime.typeinfo.FieldInfo(
                                "identifier", // schemaName
                                "getIdentifier", // getterName
                                "setIdentifier", // setterName
                                zserio.runtime.typeinfo.TypeInfo.BuiltinTypeInfo.getUInt32(), // typeInfo
                                new java.util.ArrayList<java.util.function.BiFunction<java.lang.Object, java.lang.Integer, java.lang.Object>>(), // typeArguments
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
                                test_object.WalkerNested.typeInfo(), // typeInfo
                                java.util.Arrays.asList(), // typeArguments
                                null, // alignment
                                null, // offset
                                null, // initializer
                                true, // isOptional
                                (obj) -> ((WalkerObject)obj).getIdentifier() != 0, // optionalCondition
                                "isNestedUsed", // isUsedIndicatorName
                                "isNestedSet", // isSetIndicatorName
                                null, // constraint
                                false, // isArray
                                null, // arrayLength
                                false, // isPacked
                                false // isImplicit
                        ),
                        new zserio.runtime.typeinfo.FieldInfo(
                                "text", // schemaName
                                "getText", // getterName
                                "setText", // setterName
                                zserio.runtime.typeinfo.TypeInfo.BuiltinTypeInfo.getString(), // typeInfo
                                new java.util.ArrayList<java.util.function.BiFunction<java.lang.Object, java.lang.Integer, java.lang.Object>>(), // typeArguments
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
                                "unionArray", // schemaName
                                "getUnionArray", // getterName
                                "setUnionArray", // setterName
                                test_object.WalkerUnion.typeInfo(), // typeInfo
                                java.util.Arrays.asList(), // typeArguments
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
                                false, // isPacked
                                false // isImplicit
                        ),
                        new zserio.runtime.typeinfo.FieldInfo(
                                "optionalUnionArray", // schemaName
                                "getOptionalUnionArray", // getterName
                                "setOptionalUnionArray", // setterName
                                test_object.WalkerUnion.typeInfo(), // typeInfo
                                java.util.Arrays.asList(), // typeArguments
                                null, // alignment
                                null, // offset
                                null, // initializer
                                true, // isOptional
                                null, // optionalCondition
                                "isOptionalUnionArrayUsed", // isUsedIndicatorName
                                "isOptionalUnionArraySet", // isSetIndicatorName
                                null, // constraint
                                true, // isArray
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
                "test_object.WalkerObject", WalkerObject.class, templateName, templateArguments,
                fieldList, parameterList, functionList
        );
    }

    public static void createPackingContext(zserio.runtime.array.PackingContextNode contextNode)
    {
        contextNode.createChild().createContext();
        test_object.WalkerNested.createPackingContext(contextNode.createChild());
        contextNode.createChild();
        contextNode.createChild();
        contextNode.createChild();
    }

    @Override
    public void initPackingContext(zserio.runtime.array.PackingContextNode contextNode)
    {
        contextNode.getChildren().get(0).getContext().init(
                new zserio.runtime.array.ArrayTraits.BitFieldLongArrayTraits((int)(32)),
                new zserio.runtime.array.ArrayElement.LongArrayElement(identifier_));
        if (isNestedUsed())
        {
            nested_.initPackingContext(contextNode.getChildren().get(1));
        }
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

        endBitPosition += 32;
        if (isNestedUsed())
        {
            endBitPosition += nested_.bitSizeOf(endBitPosition);
        }
        endBitPosition += zserio.runtime.BitSizeOfCalculator.getBitSizeOfString(text_);
        endBitPosition += unionArray_.bitSizeOf(endBitPosition);
        endBitPosition += 1;
        if (isOptionalUnionArrayUsed())
        {
            endBitPosition += optionalUnionArray_.bitSizeOf(endBitPosition);
        }

        return (int)(endBitPosition - bitPosition);
    }

    @Override
    public int bitSizeOf(zserio.runtime.array.PackingContextNode contextNode, long bitPosition)
    {
        long endBitPosition = bitPosition;

        endBitPosition += contextNode.getChildren().get(0).getContext().bitSizeOf(
                new zserio.runtime.array.ArrayTraits.BitFieldLongArrayTraits((int)(32)),
                new zserio.runtime.array.ArrayElement.LongArrayElement(identifier_));
        if (isNestedUsed())
        {
            endBitPosition += nested_.bitSizeOf(contextNode.getChildren().get(1),
                    endBitPosition);
        }
        endBitPosition += zserio.runtime.BitSizeOfCalculator.getBitSizeOfString(text_);
        endBitPosition += unionArray_.bitSizeOfPacked(endBitPosition);
        endBitPosition += 1;
        if (isOptionalUnionArrayUsed())
        {
            endBitPosition += optionalUnionArray_.bitSizeOfPacked(endBitPosition);
        }

        return (int)(endBitPosition - bitPosition);
    }

    public long getIdentifier()
    {
        return identifier_;
    }

    public void setIdentifier(long identifier_)
    {
        this.identifier_ = identifier_;
    }

    public test_object.WalkerNested getNested()
    {
        return nested_;
    }

    public void setNested(test_object.WalkerNested nested_)
    {
        this.nested_ = nested_;
    }

    public boolean isNestedUsed()
    {
        return (getIdentifier() != 0);
    }

    public boolean isNestedSet()
    {
        return (nested_ != null);
    }

    public void resetNested()
    {
        nested_ = null;
    }

    public java.lang.String getText()
    {
        return text_;
    }

    public void setText(java.lang.String text_)
    {
        this.text_ = text_;
    }

    public test_object.WalkerUnion[] getUnionArray()
    {
        return (unionArray_ == null) ? null : unionArray_.getRawArray();
    }

    public void setUnionArray(test_object.WalkerUnion[] unionArray_)
    {
        this.unionArray_ = new zserio.runtime.array.Array(
                new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.WalkerUnion.class, unionArray_),
                new zserio.runtime.array.ArrayTraits.WriteObjectArrayTraits<test_object.WalkerUnion>(new ZserioElementFactory_unionArray()),
                zserio.runtime.array.ArrayType.AUTO);
    }

    public test_object.WalkerUnion[] getOptionalUnionArray()
    {
        return (optionalUnionArray_ == null) ? null : optionalUnionArray_.getRawArray();
    }

    public void setOptionalUnionArray(test_object.WalkerUnion[] optionalUnionArray_)
    {
        if (optionalUnionArray_ == null)
        {
            this.optionalUnionArray_ = null;
        }
        else
        {
            this.optionalUnionArray_ = new zserio.runtime.array.Array(
                    new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.WalkerUnion.class, optionalUnionArray_),
                    new zserio.runtime.array.ArrayTraits.WriteObjectArrayTraits<test_object.WalkerUnion>(new ZserioElementFactory_optionalUnionArray()),
                    zserio.runtime.array.ArrayType.AUTO);
        }
    }

    public boolean isOptionalUnionArrayUsed()
    {
        return isOptionalUnionArraySet();
    }

    public boolean isOptionalUnionArraySet()
    {
        return (optionalUnionArray_ != null);
    }

    public void resetOptionalUnionArray()
    {
        optionalUnionArray_ = null;
    }

    @Override
    public boolean equals(java.lang.Object obj)
    {
        if (obj instanceof WalkerObject)
        {
            final WalkerObject that = (WalkerObject)obj;

            return
                    identifier_ == that.identifier_ &&
                    ((!isNestedUsed()) ? !that.isNestedUsed() :
                        ((nested_ == null) ? that.nested_ == null : nested_.equals(that.nested_))) &&
                    ((text_ == null) ? that.text_ == null : text_.equals(that.text_)) &&
                    ((unionArray_ == null) ? that.unionArray_ == null : unionArray_.equals(that.unionArray_)) &&
                    ((!isOptionalUnionArrayUsed()) ? !that.isOptionalUnionArrayUsed() :
                        ((optionalUnionArray_ == null) ? that.optionalUnionArray_ == null : optionalUnionArray_.equals(that.optionalUnionArray_)));
        }

        return false;
    }

    @Override
    public int hashCode()
    {
        int result = zserio.runtime.HashCodeUtil.HASH_SEED;

        result = zserio.runtime.HashCodeUtil.calcHashCode(result, identifier_);
        if (isNestedUsed())
            result = zserio.runtime.HashCodeUtil.calcHashCode(result, nested_);
        result = zserio.runtime.HashCodeUtil.calcHashCode(result, text_);
        result = zserio.runtime.HashCodeUtil.calcHashCode(result, unionArray_);
        if (isOptionalUnionArrayUsed())
            result = zserio.runtime.HashCodeUtil.calcHashCode(result, optionalUnionArray_);

        return result;
    }

    public void read(zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        identifier_ = in.readUnsignedInt();

        if (getIdentifier() != 0)
        {
            nested_ = new test_object.WalkerNested(in);
        }

        text_ = in.readString();

        unionArray_ = new zserio.runtime.array.Array(
                new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.WalkerUnion.class),
                new zserio.runtime.array.ArrayTraits.WriteObjectArrayTraits<test_object.WalkerUnion>(new ZserioElementFactory_unionArray()),
                zserio.runtime.array.ArrayType.AUTO);
        unionArray_.read(in);

        if (in.readBool())
        {
            optionalUnionArray_ = new zserio.runtime.array.Array(
                    new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.WalkerUnion.class),
                    new zserio.runtime.array.ArrayTraits.WriteObjectArrayTraits<test_object.WalkerUnion>(new ZserioElementFactory_optionalUnionArray()),
                    zserio.runtime.array.ArrayType.AUTO);
            optionalUnionArray_.read(in);
        }
    }

    public void read(zserio.runtime.array.PackingContextNode contextNode, zserio.runtime.io.BitStreamReader in)
            throws java.io.IOException
    {
        identifier_ = ((zserio.runtime.array.ArrayElement.LongArrayElement)
                contextNode.getChildren().get(0).getContext().read(
                        new zserio.runtime.array.ArrayTraits.BitFieldLongArrayTraits((int)(32)), in)).get();

        if (getIdentifier() != 0)
        {
            nested_ = new test_object.WalkerNested(contextNode.getChildren().get(1), in);
        }

        text_ = in.readString();

        unionArray_ = new zserio.runtime.array.Array(
                new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.WalkerUnion.class),
                new zserio.runtime.array.ArrayTraits.WriteObjectArrayTraits<test_object.WalkerUnion>(new ZserioElementFactory_unionArray()),
                zserio.runtime.array.ArrayType.AUTO);
        unionArray_.readPacked(in);

        if (in.readBool())
        {
            optionalUnionArray_ = new zserio.runtime.array.Array(
                    new zserio.runtime.array.RawArray.ObjectRawArray<>(test_object.WalkerUnion.class),
                    new zserio.runtime.array.ArrayTraits.WriteObjectArrayTraits<test_object.WalkerUnion>(new ZserioElementFactory_optionalUnionArray()),
                    zserio.runtime.array.ArrayType.AUTO);
            optionalUnionArray_.readPacked(in);
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

        endBitPosition += 32;
        if (isNestedUsed())
        {
            endBitPosition = nested_.initializeOffsets(endBitPosition);
        }
        endBitPosition += zserio.runtime.BitSizeOfCalculator.getBitSizeOfString(text_);
        endBitPosition = unionArray_.initializeOffsets(endBitPosition);
        endBitPosition += 1;
        if (isOptionalUnionArrayUsed())
        {
            endBitPosition = optionalUnionArray_.initializeOffsets(endBitPosition);
        }

        return endBitPosition;
    }

    @Override
    public long initializeOffsets(zserio.runtime.array.PackingContextNode contextNode, long bitPosition)
    {
        long endBitPosition = bitPosition;

        endBitPosition += contextNode.getChildren().get(0).getContext().bitSizeOf(
                new zserio.runtime.array.ArrayTraits.BitFieldLongArrayTraits((int)(32)),
                new zserio.runtime.array.ArrayElement.LongArrayElement(identifier_));
        if (isNestedUsed())
        {
            endBitPosition = nested_.initializeOffsets(contextNode.getChildren().get(1),
                    endBitPosition);
        }
        endBitPosition += zserio.runtime.BitSizeOfCalculator.getBitSizeOfString(text_);
        endBitPosition = unionArray_.initializeOffsetsPacked(endBitPosition);
        endBitPosition += 1;
        if (isOptionalUnionArrayUsed())
        {
            endBitPosition = optionalUnionArray_.initializeOffsetsPacked(endBitPosition);
        }

        return endBitPosition;
    }

    @Deprecated
    public void write(java.io.File file) throws java.io.IOException
    {
        try (final zserio.runtime.io.FileBitStreamWriter out = new zserio.runtime.io.FileBitStreamWriter(file))
        {
            write(out);
        }
    }

    @Override
    public void write(zserio.runtime.io.BitStreamWriter out) throws java.io.IOException
    {
        out.writeUnsignedInt(identifier_);

        if (isNestedUsed())
        {
            nested_.write(out);
        }

        out.writeString(text_);

        unionArray_.write(out);

        if (isOptionalUnionArrayUsed())
        {
            out.writeBool(true);
            optionalUnionArray_.write(out);
        }
        else
        {
            out.writeBool(false);
        }
    }

    @Override
    public void write(zserio.runtime.array.PackingContextNode contextNode,
            zserio.runtime.io.BitStreamWriter out) throws java.io.IOException
    {
        contextNode.getChildren().get(0).getContext().write(
                new zserio.runtime.array.ArrayTraits.BitFieldLongArrayTraits((int)(32)), out,
                new zserio.runtime.array.ArrayElement.LongArrayElement(identifier_));

        if (isNestedUsed())
        {
            nested_.write(contextNode.getChildren().get(1), out);
        }

        out.writeString(text_);

        unionArray_.writePacked(out);

        if (isOptionalUnionArrayUsed())
        {
            out.writeBool(true);
            optionalUnionArray_.writePacked(out);
        }
        else
        {
            out.writeBool(false);
        }
    }

    private static final class ZserioElementFactory_unionArray implements zserio.runtime.array.ElementFactory<test_object.WalkerUnion>
    {
        @Override
        public test_object.WalkerUnion create(zserio.runtime.io.BitStreamReader in, int index)
                throws java.io.IOException
        {
            return new test_object.WalkerUnion(in);
        }

        @Override
        public void createPackingContext(zserio.runtime.array.PackingContextNode contextNode)
        {
            test_object.WalkerUnion.createPackingContext(contextNode);
        }

        @Override
        public test_object.WalkerUnion create(zserio.runtime.array.PackingContextNode contextNode,
                zserio.runtime.io.BitStreamReader in, int index) throws java.io.IOException
        {
            return new test_object.WalkerUnion(contextNode, in);
        }
    }

    private static final class ZserioElementFactory_optionalUnionArray implements zserio.runtime.array.ElementFactory<test_object.WalkerUnion>
    {
        @Override
        public test_object.WalkerUnion create(zserio.runtime.io.BitStreamReader in, int index)
                throws java.io.IOException
        {
            return new test_object.WalkerUnion(in);
        }

        @Override
        public void createPackingContext(zserio.runtime.array.PackingContextNode contextNode)
        {
            test_object.WalkerUnion.createPackingContext(contextNode);
        }

        @Override
        public test_object.WalkerUnion create(zserio.runtime.array.PackingContextNode contextNode,
                zserio.runtime.io.BitStreamReader in, int index) throws java.io.IOException
        {
            return new test_object.WalkerUnion(contextNode, in);
        }
    }

    private long identifier_;
    private test_object.WalkerNested nested_;
    private java.lang.String text_;
    private zserio.runtime.array.Array unionArray_;
    private zserio.runtime.array.Array optionalUnionArray_;
}
