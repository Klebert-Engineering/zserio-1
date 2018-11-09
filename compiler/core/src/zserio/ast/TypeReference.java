package zserio.ast;

import zserio.antlr.ZserioParserTokenTypes;
import zserio.antlr.util.BaseTokenAST;
import zserio.antlr.util.ParserException;

/**
 * AST node for type references.
 *
 * A type reference is either a simple name or a sequence of simple names separated by dots referring to
 * a nested type, e.g. {@code Outer.Inner}.
 *
 * Type references are Zserio types as well.
 */
public class TypeReference extends TokenAST implements ZserioType
{
    @Override
    public Package getPackage()
    {
        return referencedType.getPackage();
    }

    @Override
    public String getName()
    {
        return referencedTypeName;
    }

    @Override
    public Iterable<ZserioType> getUsedTypeList()
    {
        throw new InternalError("TypeReference.getUsedTypeList() is not implemented!");
    }

    /**
     * Gets referenced type.
     *
     * @return Referenced type.
     */
    public ZserioType getReferencedType()
    {
        return referencedType;
    }

    @Override
    public void callVisitor(ZserioTypeVisitor visitor)
    {
        visitor.visitTypeReference(this);
    }

    /**
     * Sets flag to signal a need of checking if referenced type is non parametrized.
     *
     * This method is called by code generated by ANTLR using ZserioParser.g.
     */
    public void setNonParametrizedTypeCheck()
    {
        checkNonParametrizedType = true;
    }

    @Override
    protected boolean evaluateChild(BaseTokenAST child) throws ParserException
    {
        switch (child.getType())
        {
        case ZserioParserTokenTypes.ID:
            if (referencedTypeName != null)
                referencedPackageName.addId(referencedTypeName);
            referencedTypeName = child.getText();
            break;

        default:
            return false;
        }

        return true;
    }

    @Override
    protected void check() throws ParserException
    {
        final ZserioType referencedBaseType = resolveBaseType(referencedType);
        if (checkNonParametrizedType && referencedBaseType instanceof CompoundType)
        {
            final CompoundType referencedCompoundType = (CompoundType)referencedBaseType;
            if (referencedCompoundType.getParameters().size() > 0)
                throw new ParserException(this, "Referenced type '" + referencedTypeName +
                        "' is defined as parameterized type!");
        }
    }

    /**
     * Resolves this reference to the corresponding referenced type.
     *
     * @param pkg Package to use for referenced type resolving.
     *
     * @throws ParserException Throws if the referenced type is unresolvable.
     */
    protected void resolve(Package pkg) throws ParserException
    {
        // resolve referenced type
        referencedType = pkg.getVisibleType(this, referencedPackageName, referencedTypeName);
        if (referencedType == null)
            throw new ParserException(this, "Unresolved referenced type '" + referencedTypeName + "'!");

        // check referenced type
        if (referencedType instanceof ConstType)
            throw new ParserException(this, "Invalid usage of constant '" + referencedType.getName() +
                    "' as a type!");
        if (referencedType instanceof SqlDatabaseType)
            throw new ParserException(this, "Invalid usage of SQL database '" + referencedType.getName() +
                    "' as a type!");
    }

    /**
     * Resolves base type from type reference or subtype.
     *
     * Note that this method does not resolve ArrayType and TypeInstantiation.
     *
     * @param type Generic Zserio type to resolve.
     *
     * @return The input parameter 'type' if 'type' is not type reference or subtype, otherwise base type of
     *         the type reference or subtype specified by input parameter 'type'.
     */
    static public ZserioType resolveBaseType(ZserioType type)
    {
        ZserioType baseType = type;

        if (baseType instanceof TypeReference)
            baseType = ((TypeReference)baseType).referencedType;

        if (baseType instanceof Subtype)
            baseType = ((Subtype)baseType).getTargetBaseType();

        return baseType;
    }

    /**
     * Resolves referenced type from type reference.
     *
     * @param type Generic Zserio type to resolve.
     *
     * @return The input parameter 'type' if 'type' is not type reference, otherwise referenced type of
     *         the type reference specified by input parameter 'type'.
     */
    static public ZserioType resolveType(ZserioType type)
    {
        ZserioType resolvedType = type;
        if (resolvedType instanceof TypeReference)
            resolvedType = ((TypeReference)resolvedType).referencedType;

        return resolvedType;
    }

    private static final long serialVersionUID = 8158308333230987942L;

    private final PackageName referencedPackageName = new PackageName();
    private String referencedTypeName = null;
    private ZserioType referencedType;

    private boolean checkNonParametrizedType;
}
