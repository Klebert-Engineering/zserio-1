package zserio.ast;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import zserio.tools.WarningsConfig;
import zserio.tools.ZserioToolPrinter;

/**
 * Implementation of ZserioAstVisitor which manages checking phase.
 */
public class ZserioAstChecker extends ZserioAstWalker
{
    /**
     * Constructor.
     *
     * @param warningsConfig Warnings config.
     * @param withGlobalRuleIdCheck Whether to check of rule id uniqueness between all packages.
     */
    public ZserioAstChecker(WarningsConfig warningsConfig, boolean withGlobalRuleIdCheck)
    {
        this.warningsConfig = warningsConfig;
        this.withGlobalRuleIdCheck = withGlobalRuleIdCheck;
    }

    @Override
    public void visitRoot(Root root)
    {
        root.visitChildren(this);
        root.check(withGlobalRuleIdCheck);

        for (ZserioType definedType : definedTypes)
        {
            final String definedTypeName = ZserioTypeUtil.getFullName(definedType);
            if (!usedTypeNames.contains(definedTypeName))
            {
                ZserioToolPrinter.printWarning(definedType, "Type '" + definedTypeName + "' is not used.",
                        warningsConfig, WarningsConfig.UNUSED);
            }
        }
    }

    @Override
    public void visitPackage(Package pkg)
    {
        currentPackage = pkg;
        pkg.visitChildren(this);
        pkg.check();
        currentPackage = null;
    }

    @Override
    public void visitConstant(Constant constant)
    {
        constant.visitChildren(this);
        constant.check();
    }

    @Override
    public void visitSubtype(Subtype subtype)
    {
        subtype.visitChildren(this);
        definedTypes.add(subtype);
        addUsedType(subtype.getTypeReference().getType());
    }

    @Override
    public void visitStructureType(StructureType structureType)
    {
        if (structureType.getTemplateParameters().isEmpty())
        {
            structureType.visitChildren(this);
            definedTypes.add(structureType);
            structureType.check(warningsConfig);
        }
        else
        {
            visitInstantiations(structureType);
        }
    }

    @Override
    public void visitChoiceType(ChoiceType choiceType)
    {
        if (choiceType.getTemplateParameters().isEmpty())
        {
            choiceType.visitChildren(this);
            definedTypes.add(choiceType);
            choiceType.check(warningsConfig);
        }
        else
        {
            visitInstantiations(choiceType);
        }
    }

    @Override
    public void visitUnionType(UnionType unionType)
    {
        if (unionType.getTemplateParameters().isEmpty())
        {
            unionType.visitChildren(this);
            definedTypes.add(unionType);
            unionType.check(warningsConfig);
        }
        else
        {
            visitInstantiations(unionType);
        }
    }

    @Override
    public void visitEnumType(EnumType enumType)
    {
        enumType.visitChildren(this);
        definedTypes.add(enumType);
        enumType.check();
    }

    @Override
    public void visitBitmaskType(BitmaskType bitmaskType)
    {
        bitmaskType.visitChildren(this);
        definedTypes.add(bitmaskType);
        bitmaskType.check();
    }

    @Override
    public void visitSqlTableType(SqlTableType sqlTableType)
    {
        if (sqlTableType.getTemplateParameters().isEmpty())
        {
            sqlTableType.visitChildren(this);
            definedTypes.add(sqlTableType);
            sqlTableType.check(warningsConfig);
        }
        else
        {
            visitInstantiations(sqlTableType);
        }
    }

    @Override
    public void visitSqlDatabaseType(SqlDatabaseType sqlDatabaseType)
    {
        sqlDatabaseType.visitChildren(this);
        sqlDatabaseType.check(warningsConfig);
    }

    @Override
    public void visitField(Field field)
    {
        field.visitChildren(this);
        field.check(currentPackage, warningsConfig);
    }

    @Override
    public void visitServiceType(ServiceType serviceType)
    {
        serviceType.visitChildren(this);
        serviceType.check();
    }

    @Override
    public void visitServiceMethod(ServiceMethod serviceMethod)
    {
        serviceMethod.visitChildren(this);
        serviceMethod.check();
    }

    @Override
    public void visitPubsubType(PubsubType pubsubType)
    {
        pubsubType.visitChildren(this);
        pubsubType.check();
    }

    @Override
    public void visitPubsubMessage(PubsubMessage pubsubMessage)
    {
        pubsubMessage.visitChildren(this);
        pubsubMessage.check();
    }

    @Override
    public void visitFunction(Function function)
    {
        function.visitChildren(this);
        function.check(warningsConfig);
    }

    @Override
    public void visitTypeInstantiation(TypeInstantiation typeInstantiation)
    {
        typeInstantiation.visitChildren(this);
        typeInstantiation.check(warningsConfig, currentTemplateInstantiation);
    }

    @Override
    public void visitTypeReference(TypeReference typeReference)
    {
        typeReference.visitChildren(this);
        addUsedType(typeReference.getType());
    }

    private void visitInstantiations(ZserioTemplatableType template)
    {
        for (ZserioTemplatableType instantiation : template.getInstantiations())
        {
            try
            {
                currentTemplateInstantiation = instantiation;
                instantiation.accept(this);
                currentTemplateInstantiation = null;
            }
            catch (ParserException e)
            {
                throw new InstantiationException(e, instantiation.getInstantiationReferenceStack());
            }
        }
    }

    private void addUsedType(ZserioType usedType)
    {
        if (!(usedType instanceof BuiltInType))
            usedTypeNames.add(ZserioTypeUtil.getFullName(usedType));
    }

    private final WarningsConfig warningsConfig;
    private final boolean withGlobalRuleIdCheck;

    private final Set<String> usedTypeNames = new HashSet<String>();
    private final List<ZserioType> definedTypes = new ArrayList<ZserioType>();

    private Package currentPackage = null;
    private ZserioTemplatableType currentTemplateInstantiation = null;
};
