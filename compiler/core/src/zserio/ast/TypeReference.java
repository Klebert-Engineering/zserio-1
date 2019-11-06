package zserio.ast;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * AST node for type reference.
 */
public class TypeReference extends AstNodeBase
{
    /**
     * Constructor from built-in type.
     *
     * @param location           AST node location.
     * @param ownerPackage       Owner package.
     * @param builtinType        Built-in type to be referenced.
     */
    public TypeReference(AstLocation location, Package ownerPackage, BuiltInType builtinType)
    {
        super(location);

        this.ownerPackage = ownerPackage;
        referencedPackageName = PackageName.EMPTY;
        referencedTypeName = builtinType.getName();
        templateArguments = new ArrayList<TemplateArgument>();
        type = builtinType;
        isResolved = true; // TODO[Mi-L@][typeref] Hack for built-in types.
    }

    /**
     * Constructor from a user defined type.
     *
     * @param location               AST node location.
     * @param ownerPackage           Owner package.
     * @param referencedPackageName  Referenced package name.
     * @param referencedTypeName     Name of the referenced type.
     * @param templateArguments      List of template arguments used for the referenced template instantiation.
     */
    public TypeReference(AstLocation location, Package ownerPackage, PackageName referencedPackageName,
            String referencedTypeName, List<TemplateArgument> templateArguments)
    {
        super(location);

        this.ownerPackage = ownerPackage;
        this.referencedPackageName = referencedPackageName;
        this.referencedTypeName = referencedTypeName;
        this.templateArguments = templateArguments;
    }

    @Override
    public void accept(ZserioAstVisitor visitor)
    {
        visitor.visitTypeReference(this);
    }

    @Override
    public void visitChildren(ZserioAstVisitor visitor)
    {
        if (type instanceof BuiltInType)
            ((BuiltInType)type).accept(visitor);

        for (TemplateArgument templateArgument : templateArguments)
            templateArgument.accept(visitor);
    }

    /**
     * Gets the referenced type.
     *
     * @return Zserio type which is referenced by this type reference.
     */
    public ZserioType getType()
    {
        return type;
    }

    /**
     * Gets base type reference - i.e. the type reference got by resolving subtypes.
     *
     * @return Type reference to Zserio base type.
     */
    public TypeReference getBaseTypeReference()
    {
        if (type instanceof Subtype)
            return ((Subtype)type).getBaseTypeReference();
        if (type instanceof InstantiateType)
            return ((InstantiateType)type).getTypeReference();
        return this;
    }

    /**
     * Gets template arguments.
     *
     * @return Actual template parameters.
     */
    public List<TemplateArgument> getTemplateArguments()
    {
        return Collections.unmodifiableList(templateArguments);
    }

    /**
     * Gets referenced package name.
     *
     * @return Package name.
     */
    public PackageName getReferencedPackageName()
    {
        return referencedPackageName;
    }

    /**
     * Gets referenced type name.
     *
     * @return Type name.
     */
    public String getReferencedTypeName()
    {
        return referencedTypeName;
    }

    /**
     * Resolves this reference to the corresponding referenced type.
     */
    void resolve(boolean isTemplateArgument)
    {
        if (isResolved)
            return;

        // resolve referenced type
        type = ownerPackage.getVisibleType(this, referencedPackageName, referencedTypeName);
        if (type == null)
        {
            throw new ParserException(this, "Unresolved referenced type '" +
                    ZserioTypeUtil.getReferencedFullName(this) + "'!");
        }

        // check referenced type
        if (type instanceof ConstType && !isTemplateArgument)
            throw new ParserException(this, "Invalid usage of constant '" + type.getName() +
                    "' as a type!");
        if (type instanceof SqlDatabaseType)
            throw new ParserException(this, "Invalid usage of SQL database '" + type.getName() +
                    "' as a type!");
        if (type instanceof TemplatableType)
        {
            final TemplatableType template = (TemplatableType)type;
            if (!template.getTemplateParameters().isEmpty() && templateArguments.isEmpty())
                throw new ParserException(this,
                        "Missing template arguments for template '" + getReferencedTypeName() + "'!");
        }

        isResolved = true;
    }

    /**
     * Resolves the type instantiation.
     *
     * @param instantiation Type instantiation to resolve this reference to.
     */
    void resolveInstantiation(ZserioTemplatableType instantiation)
    {
        type = instantiation;
    }

    /**
     * Instantiate the type reference.
     *
     * @param templateParameters Template parameters.
     * @param templateArguments Template arguments.
     *
     * @return New type reference instantiated from this using the given template arguments.
     */
    TypeReference instantiate(List<TemplateParameter> templateParameters,
            List<TemplateArgument> templateArguments)
    {
        if (getReferencedPackageName().isEmpty()) // may be a template parameter
        {
            final int index = TemplateParameter.indexOf(templateParameters, referencedTypeName);
            if (index != -1)
            {
                if (!getTemplateArguments().isEmpty())
                    throw new ParserException(this, "Template parameter cannot be used as a template!");

                final TypeReference typeReference = templateArguments.get(index).getTypeReference();

                return typeReference.instantiateImpl(getLocation(), typeReference.templateArguments,
                        templateParameters, templateArguments);
            }
        }

        // instantiate template arguments first
        final List<TemplateArgument> instantiatedTemplateArguments = new ArrayList<TemplateArgument>();
        for (TemplateArgument templateArgument : getTemplateArguments())
        {
            instantiatedTemplateArguments.add(
                    templateArgument.instantiate(templateParameters, templateArguments));
        }

        return instantiateImpl(getLocation(), instantiatedTemplateArguments,
                templateParameters, templateArguments);
    }

    private TypeReference instantiateImpl(AstLocation location,
            List<TemplateArgument> instantiatedTemplateArguments,
            List<TemplateParameter> templateParameters, List<TemplateArgument> passedTemplateArguments)
    {
        if (type instanceof BuiltInType) // TODO[Mi-L@][typeref] Hack for built-in types.
        {
            if (type instanceof BitFieldType)
            {
                return new TypeReference(location, ownerPackage,
                        ((BitFieldType)type).instantiate(templateParameters, passedTemplateArguments));
            }
            else if (type instanceof ArrayType)
            {
                return new TypeReference(location, ownerPackage,
                        ((ArrayType)type).instantiate(templateParameters, passedTemplateArguments));
            }
            else
            {
                return new TypeReference(location, ownerPackage, (BuiltInType)type);
            }
        }
        else
        {
            return new TypeReference(location, ownerPackage, referencedPackageName, referencedTypeName,
                    instantiatedTemplateArguments);
        }
    }

    private final Package ownerPackage;
    private final PackageName referencedPackageName;
    private final String referencedTypeName;
    private final List<TemplateArgument> templateArguments;

    private ZserioType type = null;
    private boolean isResolved = false;
}