package zserio.ast;

import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

import zserio.tools.ZserioToolPrinter;

/**
 * AST node for service types.
 *
 * Topic types are Zserio types as well.
 */
public class TopicType extends CompoundType
{
    public TopicType(AstLocation location, Package pkg, String name,
                     DocComment docComment,
                     String topicName, TypeReference valueType)
    {
        super(location, pkg, name,
              new ArrayList<TemplateParameter>(),
              new ArrayList<Parameter>(),
              new ArrayList<Field>(),
              new ArrayList<Function>(), docComment);

        this.topicName = topicName;
        this.valueType = valueType;
    }

    @Override
    public void accept(ZserioAstVisitor visitor)
    {
        visitor.visitTopicType(this);
    }

    @Override
    public void visitChildren(ZserioAstVisitor visitor)
    {
        if (getDocComment() != null)
            getDocComment().accept(visitor);

        for (TemplateParameter templateParameter : getTemplateParameters())
            templateParameter.accept(visitor);

        for (Parameter parameter : getTypeParameters())
            parameter.accept(visitor);

        for (Function function : getFunctions())
            function.accept(visitor);

        if (getValueType() != null)
            getValueType().accept(visitor);
    }

    @Override
    TopicType instantiateImpl(String name, List<TemplateArgument> templateArguments,
                              Package instantiationPackage)
    {
        // TODO: Template parameters are not supported.

        return new TopicType(getLocation(), instantiationPackage, name, getDocComment(), topicName, valueType);
    }

    public String getTopicName()
    {
        return topicName;
    }

    public TypeReference getValueType()
    {
        return valueType;
    }

    private final String topicName;
    private final TypeReference valueType;

    private static final long serialVersionUID = 7339295016544090386L;
}
