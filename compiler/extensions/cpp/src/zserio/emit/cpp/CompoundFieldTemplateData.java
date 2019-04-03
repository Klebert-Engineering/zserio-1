package zserio.emit.cpp;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

import antlr.Token;
import zserio.antlr.util.BaseTokenAST;
import zserio.ast.*;
import zserio.ast.Package;
import zserio.ast.TypeInstantiation.InstantiatedParameter;
import zserio.emit.common.ExpressionFormatter;
import zserio.emit.common.PackageMapper;
import zserio.emit.common.ZserioEmitException;
import zserio.emit.cpp.types.*;

public class CompoundFieldTemplateData
{
    public CompoundFieldTemplateData(
            PackageMapper packageMapper,
            CppNativeTypeMapper cppNativeTypeMapper,
            CompoundType parentType, Field field,
            ExpressionFormatter cppExpressionFormatter, ExpressionFormatter cppIndirectExpressionFormatter,
            IncludeCollector includeCollector, boolean withWriterCode) throws ZserioEmitException
    {
        isExternal = field.getIsExternal();
        isTemplate = field.getIsTemplateSymbol();

        final ZserioType fieldType = TypeReference.resolveType(field.getFieldType());
        final ZserioType baseFieldType = TypeReference.resolveBaseType(fieldType);
        optional = createOptional(field, cppExpressionFormatter);
        compound = createCompound(cppNativeTypeMapper, cppExpressionFormatter, cppIndirectExpressionFormatter,
                parentType, baseFieldType, withWriterCode);

        // skip type resolving for external structs/choices
        if (!isExternal || ZserioTypeUtil.isBuiltIn(baseFieldType))
        {
            final CppNativeType fieldNativeType = cppNativeTypeMapper.getCppType(fieldType);
            includeCollector.addHeaderIncludesForType(fieldNativeType);

            String templateSuffix = "";
            List<TemplateParameter> fieldTParams = field.getTemplateParameters();
            if (!fieldTParams.isEmpty())
            {
                ArrayList<String> templateIncludes = new ArrayList<String>();
                templateSuffix += "<";
                for (int i=0; i<fieldTParams.size(); i++)
                {

                    boolean isTemplateParamBound = fieldTParams.get(i).getName().contains(".");
                    String rootPackageNamPrefix = isTemplateParamBound
                            ? (packageMapper.getTopLevelPackageName().toString() + ".")
                            : "";
                    String templateTypeId = rootPackageNamPrefix + fieldTParams.get(i).getName();
                    if (!parentType.isTemplateParameterId(templateTypeId))
                        templateIncludes.add(templateTypeId.replace(".", "/") + ".h");
                    templateSuffix += templateTypeId.replace(".","::");
                    if (i<(fieldTParams.size()-1))
                        templateSuffix += ", ";
                }
                templateSuffix += ">";
                includeCollector.addHeaderUserIncludes(templateIncludes);
            }

            if (!(fieldNativeType instanceof NativeObjectArrayType)) {
                cppTypeName = fieldNativeType.getFullName() + templateSuffix;
                if (!fieldTParams.isEmpty()) {
                    String typeArgNam = fieldNativeType.getArgumentTypeName();
                    cppArgumentTypeName = typeArgNam.substring(0, typeArgNam.length() - 1) + templateSuffix + "&";
                }
                else
                    cppArgumentTypeName = fieldNativeType.getArgumentTypeName();
            }
            else
            {
                cppTypeName = fieldNativeType.getFullName();
                cppArgumentTypeName = fieldNativeType.getArgumentTypeName();
            }

            zserioTypeName = isTemplate ? fieldType.getName() : ZserioTypeUtil.getFullName(fieldType);
            isSimpleType = fieldNativeType.isSimpleType();
            isEnum = fieldNativeType instanceof NativeEnumType;
            array = createArray(fieldNativeType, baseFieldType, parentType, cppNativeTypeMapper,
                cppExpressionFormatter, cppIndirectExpressionFormatter, withWriterCode);
            final boolean isOptionalField = (optional != null);
            optionalHolder = createOptionalHolder(packageMapper, fieldType, baseFieldType, isOptionalField, cppNativeTypeMapper,
                    includeCollector, field.getTemplateParameters());
            isComplexExternal = false;
            externalParameters = null;
        }
        else
        {
            cppTypeName = "EXTERN";
            cppArgumentTypeName = "";
            zserioTypeName = "";
            isSimpleType = false;
            isEnum = false;
            array = null;
            optionalHolder = null;
            isComplexExternal = true;

            ArrayList<ParameterData> parameters = new ArrayList<ParameterData>();
            for (Parameter parameter : field.getParameters())
            {
                String cppType = cppNativeTypeMapper.getCppType(parameter.getParameterType()).getName();
                parameters.add(new ParameterData(parameter.getName(), cppType));
            }
            externalParameters = parameters;
        }

        name = field.getName();

        getterName = AccessorNameFormatter.getGetterName(field);
        setterName = AccessorNameFormatter.getSetterName(field);

        integerRange = createIntegerRange(cppNativeTypeMapper, fieldType, cppExpressionFormatter);

        alignmentValue = createAlignmentValue(field, cppExpressionFormatter);
        initializer = createInitializer(field, cppExpressionFormatter);

        usesAnyHolder = (parentType instanceof ChoiceType) || (parentType instanceof UnionType);


        constraint = createConstraint(field, cppExpressionFormatter);

        offset = createOffset(field, cppNativeTypeMapper, cppExpressionFormatter,
                cppIndirectExpressionFormatter);
        runtimeFunction = CppRuntimeFunctionDataCreator.createData(baseFieldType, cppExpressionFormatter);
        bitSizeValue = createBitSizeValue(baseFieldType, cppExpressionFormatter);
        this.withWriterCode = withWriterCode;
    }

    public boolean getIsExternal()
    {
        return isExternal;
    }

    public Iterable<ParameterData> getExternalParameters()
    {
        return externalParameters;
    }

    public boolean getIsComplexExternal()
    {
        return isComplexExternal;
    }

    public Optional getOptional()
    {
        return optional;
    }

    public Compound getCompound()
    {
        return compound;
    }

    public String getName()
    {
        return name;
    }

    public String getCppTypeName()
    {
        return cppTypeName;
    }

    public String getCppArgumentTypeName()
    {
        return cppArgumentTypeName;
    }

    public String getZserioTypeName()
    {
        return zserioTypeName;
    }

    public String getGetterName()
    {
        return getterName;
    }

    public String getSetterName()
    {
        return setterName;
    }

    public IntegerRange getIntegerRange()
    {
        return integerRange;
    }

    public String getAlignmentValue()
    {
        return alignmentValue;
    }

    public String getInitializer()
    {
        return initializer;
    }

    public boolean getUsesAnyHolder()
    {
        return usesAnyHolder;
    }

    public boolean getIsSimpleType()
    {
        return isSimpleType;
    }

    public boolean getIsEnum()
    {
        return isEnum;
    }

    public String getConstraint()
    {
        return constraint;
    }

    public Offset getOffset()
    {
        return offset;
    }

    public Array getArray()
    {
        return array;
    }

    public RuntimeFunctionTemplateData getRuntimeFunction()
    {
        return runtimeFunction;
    }

    public String getBitSizeValue()
    {
        return bitSizeValue;
    }

    public OptionalHolder getOptionalHolder()
    {
        return optionalHolder;
    }

    public boolean getWithWriterCode()
    {
        return withWriterCode;
    }

    public class ParameterData
    {
        public ParameterData(String n, String t)
        {
            name = n;
            cppType = t;
        }

        public String getName()
        {
            return name;
        }

        public String getCppType()
        {
            return cppType;
        }

        private String name;
        private String cppType;
    }

    public static class Optional
    {
        public Optional(Expression optionalClauseExpression, String indicatorName,
                ExpressionFormatter cppExpressionFormatter) throws ZserioEmitException
        {
            clause = (optionalClauseExpression == null) ? null :
                cppExpressionFormatter.formatGetter(optionalClauseExpression);
            this.indicatorName = indicatorName;
        }

        public String getClause()
        {
            return clause;
        }

        public String getIndicatorName()
        {
            return indicatorName;
        }

        private final String  clause;
        private final String  indicatorName;
    }

    public static class Compound
    {
        public Compound(CppNativeTypeMapper cppNativeTypeMapper, CompoundType owner,
                CompoundType compoundFieldType, boolean withWriterCode,ExpressionFormatter cppExpressionFormatter,
                ExpressionFormatter cppIndirectExpressionFormatter) throws ZserioEmitException {
            if (compoundFieldType instanceof TemplateSymbol) {
               TemplateSymbol s = (TemplateSymbol)  compoundFieldType;
               List<String> args = s.getTypeArguments();
               instantiatedParameters = new ArrayList<InstantiatedParameterData>(args.size());
               for (String paramNam : args)
               {
                   // TODO Fix this quick hack that fakes presence of specific tokens to support argumentlist

                   instantiatedParameters.add(new InstantiatedParameterData("get" + paramNam.substring(0,1).toUpperCase() +
                                                                                     paramNam.substring(1) + "()"));
               }
            }
            else
                instantiatedParameters = new ArrayList<InstantiatedParameterData>(0);

            needsChildrenInitialization = compoundFieldType.needsChildrenInitialization();
        }

        public Compound(CppNativeTypeMapper cppNativeTypeMapper, ExpressionFormatter cppExpressionFormatter,
                ExpressionFormatter cppIndirectExpressionFormatter, CompoundType owner,
                TypeInstantiation compoundFieldType, boolean withWriterCode) throws ZserioEmitException
        {
            final CompoundType baseType = compoundFieldType.getBaseType();
            final List<InstantiatedParameter> parameters = compoundFieldType.getInstantiatedParameters();
            instantiatedParameters = new ArrayList<InstantiatedParameterData>(parameters.size());
            for (InstantiatedParameter parameter : parameters)
            {
                instantiatedParameters.add(new InstantiatedParameterData(cppExpressionFormatter,
                        cppIndirectExpressionFormatter, parameter));
            }

            needsChildrenInitialization = baseType.needsChildrenInitialization();
        }

        public Iterable<InstantiatedParameterData> getInstantiatedParameters()
        {
            return instantiatedParameters;
        }

        public boolean getNeedsChildrenInitialization()
        {
            return needsChildrenInitialization;
        }

        public static class InstantiatedParameterData
        {
            public InstantiatedParameterData(ExpressionFormatter cppExpressionFormatter,
                    ExpressionFormatter cppIndirectExpressionFormatter,
                    InstantiatedParameter instantiatedParameter) throws ZserioEmitException
            {
                final Expression argumentExpression = instantiatedParameter.getArgumentExpression();
                expression = cppExpressionFormatter.formatGetter(argumentExpression);
                indirectExpression = cppIndirectExpressionFormatter.formatGetter(argumentExpression);
            }

            public InstantiatedParameterData(String expr)
            {
                expression = expr;
                indirectExpression = expr;
            }

            public String getExpression()
            {
                return expression;
            }

            public String getIndirectExpression()
            {
                return indirectExpression;
            }

            private final String expression;
            private final String indirectExpression;
        }

        private final ArrayList<InstantiatedParameterData>  instantiatedParameters;
        private final boolean                               needsChildrenInitialization;
    }

    public static class Offset
    {
        public Offset(Expression offsetExpression, CppNativeTypeMapper cppNativeTypeMapper,
                ExpressionFormatter cppExpressionFormatter, ExpressionFormatter cppIndirectExpressionFormatter)
                        throws ZserioEmitException
        {
            getter = cppExpressionFormatter.formatGetter(offsetExpression);
            indirectGetter = cppIndirectExpressionFormatter.formatGetter(offsetExpression);
            setter = cppExpressionFormatter.formatSetter(offsetExpression);
            indirectSetter = cppIndirectExpressionFormatter.formatSetter(offsetExpression);
            typeName = cppNativeTypeMapper.getCppType(offsetExpression.getExprZserioType()).getFullName();
            containsIndex = offsetExpression.containsIndex();
        }

        public boolean getContainsIndex()
        {
            return containsIndex;
        }

        public String getGetter()
        {
            return getter;
        }

        public String getIndirectGetter()
        {
            return indirectGetter;
        }

        public String getSetter()
        {
            return setter;
        }

        public String getIndirectSetter()
        {
            return indirectSetter;
        }

        public String getTypeName()
        {
            return typeName;
        }

        private final String    getter;
        private final String    indirectGetter;
        private final String    setter;
        private final String    indirectSetter;
        private final String    typeName;
        private final boolean   containsIndex;
    }

    public static class IntegerRange
    {
        public IntegerRange(CppNativeTypeMapper cppNativeTypeMapper, IntegerType typeToCheck,
                ExpressionFormatter cppExpressionFormatter) throws ZserioEmitException
        {
            bitFieldLength = !(typeToCheck instanceof BitFieldType) ? null :
                    cppExpressionFormatter.formatGetter(((BitFieldType)typeToCheck).getLengthExpression());

            final NativeIntegralType nativeType = cppNativeTypeMapper.getCppIntegralType(typeToCheck);
            final BigInteger zserioLowerBound = typeToCheck.getLowerBound();
            final BigInteger nativeLowerBound = nativeType.getLowerBound();
            checkLowerBound = zserioLowerBound == null || nativeLowerBound.compareTo(zserioLowerBound) < 0;

            final BigInteger zserioUpperBound = typeToCheck.getUpperBound();
            final BigInteger nativeUpperBound = nativeType.getUpperBound();
            final boolean checkUpperBound = zserioUpperBound == null ||
                    nativeUpperBound.compareTo(zserioUpperBound) > 0;

            // Zserio types that have the same bounds as their native type are not checked
            hasFullRange = !checkLowerBound && !checkUpperBound;

            lowerBound = zserioLowerBound != null ? nativeType.formatLiteral(zserioLowerBound) : null;
            upperBound = zserioUpperBound != null ? nativeType.formatLiteral(zserioUpperBound) : null;
        }

        public String getBitFieldLength()
        {
            return bitFieldLength;
        }

        public boolean getHasFullRange()
        {
            return hasFullRange;
        }

        public boolean getCheckLowerBound()
        {
            return checkLowerBound;
        }

        public String getLowerBound()
        {
            return lowerBound;
        }

        public String getUpperBound()
        {
            return upperBound;
        }

        private final String    bitFieldLength;
        private final boolean   hasFullRange;
        private final boolean   checkLowerBound;
        private final String    lowerBound;
        private final String    upperBound;
    }

    public static class Array
    {
        public Array(NativeArrayType nativeType, ArrayType baseType, CompoundType parentType,
                CppNativeTypeMapper cppNativeTypeMapper, ExpressionFormatter cppExpressionFormatter,
                ExpressionFormatter cppIndirectExpressionFormatter, boolean withWriterCode)
                        throws ZserioEmitException
        {
            final ZserioType elementType = TypeReference.resolveBaseType(baseType.getElementType());

            isImplicit = baseType.isImplicit();
            length = createLength(baseType, cppExpressionFormatter);
            indirectLength = createLength(baseType, cppIndirectExpressionFormatter);
            elementZserioTypeName = ZserioTypeUtil.getFullName(elementType);

            String suffix = "";
            if (nativeType.getElementType() instanceof NativeCompoundType)
                suffix = ((NativeCompoundType) nativeType.getElementType()).getTypeSuffix();

            elementCppTypeName = nativeType.getElementType().getFullName() + suffix;
            requiresElementBitSize = nativeType.requiresElementBitSize();
            requiresElementFactory = nativeType.requiresElementFactory();
            elementBitSizeValue = createBitSizeValue(elementType, cppExpressionFormatter);
            elementCompound = createCompound(cppNativeTypeMapper, cppExpressionFormatter,
                    cppIndirectExpressionFormatter, parentType, elementType, withWriterCode);
            elementIntegerRange = createIntegerRange(cppNativeTypeMapper, elementType, cppExpressionFormatter);
        }

        public boolean getIsImplicit()
        {
            return isImplicit;
        }

        public String getLength()
        {
            return length;
        }

        public String getIndirectLength()
        {
            return indirectLength;
        }

        public String getElementZserioTypeName()
        {
            return elementZserioTypeName;
        }

        public String getElementCppTypeName()
        {
            return elementCppTypeName;
        }

        public boolean getRequiresElementBitSize()
        {
            return requiresElementBitSize;
        }

        public boolean getRequiresElementFactory()
        {
            return requiresElementFactory;
        }

        public String getElementBitSizeValue()
        {
            return elementBitSizeValue;
        }

        public Compound getElementCompound()
        {
            return elementCompound;
        }

        public IntegerRange getElementIntegerRange()
        {
            return elementIntegerRange;
        }

        private static String createLength(ArrayType arrayType, ExpressionFormatter cppExpressionFormatter)
                throws ZserioEmitException
        {
            final Expression lengthExpression = arrayType.getLengthExpression();
            if (lengthExpression == null)
                return null;

            return cppExpressionFormatter.formatGetter(lengthExpression);
        }

        private final boolean       isImplicit;
        private final String        length;
        private final String        indirectLength;
        private final String        elementZserioTypeName;
        private final String        elementCppTypeName;
        private final boolean       requiresElementBitSize;
        private final boolean       requiresElementFactory;
        private final String        elementBitSizeValue;
        private final Compound      elementCompound;
        private final IntegerRange  elementIntegerRange;
    }

    public static class OptionalHolder
    {
        public OptionalHolder(PackageMapper packageMapper, NativeOptionalHolderType nativeOptionalHolderType, List<TemplateParameter> fieldTParams)
        {
            String templateSuffix = "";
            if (!fieldTParams.isEmpty())
            {
                templateSuffix += "<";
                for (int i=0; i<fieldTParams.size(); i++)
                {
                    boolean isTemplateParamBound = fieldTParams.get(i).getName().contains(".");
                    String rootPackageNamPrefix = isTemplateParamBound
                            ? (packageMapper.getTopLevelPackageName().toString() + ".")
                            : "";
                    String templateTypeId = rootPackageNamPrefix + fieldTParams.get(i).getName();
                    templateSuffix += templateTypeId.replace(".", "::");
                    if (i<(fieldTParams.size()-1))
                        templateSuffix += ", ";
                }
                templateSuffix += ">";
            }

            // TODO Error-prone quick hack! Intro proper TemplatedNativeType or some similar concept
            String typNam = nativeOptionalHolderType.getFullName();
            cppTypeName = typNam.substring(0, typNam.length()-1) + templateSuffix + ">";
            String typArgNam = nativeOptionalHolderType.getArgumentTypeName();
            cppArgumentTypeName = typArgNam.substring(0, typArgNam.length()-2) + templateSuffix + ">&";
        }

        public String getCppTypeName()
        {
            return cppTypeName;
        }

        public String getCppArgumentTypeName()
        {
            return cppArgumentTypeName;
        }

        private final String cppTypeName;
        private final String cppArgumentTypeName;
    }

    private static Optional createOptional(Field field, ExpressionFormatter cppExpressionFormatter)
            throws ZserioEmitException
    {
        if (!field.getIsOptional())
            return null;

        final Expression optionalClauseExpression = field.getOptionalClauseExpr();
        final String indicatorName = AccessorNameFormatter.getIndicatorName(field);

        return new Optional(optionalClauseExpression, indicatorName, cppExpressionFormatter);
    }

    private static IntegerRange createIntegerRange(CppNativeTypeMapper cppNativeTypeMapper,
            ZserioType typeToCheck, ExpressionFormatter cppExpressionFormatter) throws ZserioEmitException
    {
        if (!(typeToCheck instanceof IntegerType))
            return null;

        return new IntegerRange(cppNativeTypeMapper, (IntegerType)typeToCheck, cppExpressionFormatter);
    }

    private static String createAlignmentValue(Field field, ExpressionFormatter cppExpressionFormatter)
            throws ZserioEmitException
    {
        final Expression alignmentExpression = field.getAlignmentExpr();
        if (alignmentExpression == null)
            return null;

        return cppExpressionFormatter.formatGetter(alignmentExpression);
    }

    private static String createInitializer(Field field, ExpressionFormatter cppExpressionFormatter)
            throws ZserioEmitException
    {
        final Expression initializerExpression = field.getInitializerExpr();
        if (initializerExpression == null)
            return null;

        return cppExpressionFormatter.formatGetter(initializerExpression);
    }

    private static String createConstraint(Field field, ExpressionFormatter cppExpressionFormatter)
            throws ZserioEmitException
    {
        final Expression constraintExpression = field.getConstraintExpr();
        if (constraintExpression == null)
            return null;

        return cppExpressionFormatter.formatGetter(constraintExpression);
    }

    private static Offset createOffset(Field field, CppNativeTypeMapper cppNativeTypeMapper,
            ExpressionFormatter cppExpressionFormatter, ExpressionFormatter cppIndirectExpressionFormatter)
                    throws ZserioEmitException
    {
        final Expression offsetExpression = field.getOffsetExpr();
        if (offsetExpression == null)
            return null;

        return new Offset(offsetExpression, cppNativeTypeMapper, cppExpressionFormatter,
                cppIndirectExpressionFormatter);
    }

    private static Array createArray(CppNativeType cppNativeType, ZserioType baseType,
            CompoundType parentType, CppNativeTypeMapper cppNativeTypeMapper,
            ExpressionFormatter cppExpressionFormatter, ExpressionFormatter cppIndirectExpressionFormatter,
            boolean withWriterCode) throws ZserioEmitException
    {
        if (!(baseType instanceof ArrayType))
            return null;

        if (cppNativeType instanceof NativeOptionalHolderType)
            cppNativeType = ((NativeOptionalHolderType)cppNativeType).getWrappedType();

        if (!(cppNativeType instanceof NativeArrayType))
            throw new ZserioEmitException("Inconsistent base type '" + baseType.getClass() +
                    "' and native type '" + cppNativeType.getClass() + "'!");

        return new Array((NativeArrayType)cppNativeType, (ArrayType)baseType, parentType, cppNativeTypeMapper,
                cppExpressionFormatter, cppIndirectExpressionFormatter, withWriterCode);
    }

    static String createBitSizeValue(ZserioType baseFieldType, ExpressionFormatter cppExpressionFormatter)
            throws ZserioEmitException
    {
        String value;
        if (baseFieldType instanceof FixedSizeType)
        {
            value = CppLiteralFormatter.formatUInt8Literal(((FixedSizeType)baseFieldType).getBitSize());
        }
        else if (baseFieldType instanceof BitFieldType)
        {
            final BitFieldType bitFieldType = (BitFieldType)baseFieldType;
            final Integer bitSize = bitFieldType.getBitSize();
            if (bitSize != null)
                value = CppLiteralFormatter.formatUInt8Literal(bitSize);
            else
                value = cppExpressionFormatter.formatGetter(bitFieldType.getLengthExpression());
        }
        else
        {
            value = null;
        }

        return value;
    }

    private static Compound createCompound(CppNativeTypeMapper cppNativeTypeMapper,
            ExpressionFormatter cppExpressionFormatter, ExpressionFormatter cppIndirectExpressionFormatter,
            CompoundType owner, ZserioType baseFieldType, boolean withWriterCode) throws ZserioEmitException
    {
        if (baseFieldType instanceof CompoundType)
            return new Compound(cppNativeTypeMapper, owner, (CompoundType)baseFieldType, withWriterCode, cppExpressionFormatter,
                    cppIndirectExpressionFormatter);
        else if (baseFieldType instanceof TypeInstantiation)
            return new Compound(cppNativeTypeMapper, cppExpressionFormatter, cppIndirectExpressionFormatter,
                    owner, (TypeInstantiation)baseFieldType, withWriterCode);
        else
            return null;
    }

    private static OptionalHolder createOptionalHolder(PackageMapper packageMapper, ZserioType fieldType, ZserioType baseFieldType,
            boolean isOptionalField, CppNativeTypeMapper cppNativeTypeMapper, IncludeCollector includeCollector,
                                                       List<TemplateParameter> tparams)
                    throws ZserioEmitException
    {
        ZserioType fieldInstantiatedType = baseFieldType;
        if (baseFieldType instanceof TypeInstantiation)
            fieldInstantiatedType = ((TypeInstantiation)baseFieldType).getBaseType();

        final boolean isCompoundField = (fieldInstantiatedType instanceof CompoundType);
        if (!isOptionalField && !isCompoundField)
            return null;

        final boolean useHeapOptionalHolder = (isCompoundField) ?
                ((CompoundType)fieldInstantiatedType).containsOptionalRecursion() : false;
        final NativeOptionalHolderType nativeOptionalHolderType =
                cppNativeTypeMapper.getCppOptionalHolderType(fieldType, isOptionalField, useHeapOptionalHolder);
        includeCollector.addHeaderIncludesForType(nativeOptionalHolderType);

        return new OptionalHolder(packageMapper, nativeOptionalHolderType, tparams);
    }

    private final Optional                      optional;
    private final Compound                      compound;
    private final ArrayList<ParameterData>      externalParameters;
    private final String                        name;
    private final String                        cppTypeName;
    private final String                        cppArgumentTypeName;
    private final String                        zserioTypeName;
    private final String                        getterName;
    private final String                        setterName;
    private final IntegerRange                  integerRange;
    private final String                        alignmentValue;
    private final String                        initializer;
    private final boolean                       usesAnyHolder;
    private final boolean                       isSimpleType;
    private final boolean                       isEnum;
    private final String                        constraint;
    private final Offset                        offset;
    private final Array                         array;
    private final RuntimeFunctionTemplateData   runtimeFunction;
    private final String                        bitSizeValue;
    private final OptionalHolder                optionalHolder;
    private final boolean                       withWriterCode;
    private final boolean                       isExternal;
    private final boolean                       isComplexExternal;
    private final boolean                       isTemplate;
}
