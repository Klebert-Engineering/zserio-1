package zserio.ast;

import zserio.antlr.ZserioParserTokenTypes;
import zserio.antlr.util.BaseTokenAST;
import zserio.antlr.util.ParserException;

/**
 * AST node for service types.
 *
 * Topic types are Zserio types as well.
 */
public class TopicType extends CompoundType
{
    public TopicType()
    {
    }

    @Override
    public void callVisitor(ZserioTypeVisitor visitor)
    {
        visitor.visitTopicType(this);
    }

    @Override
    protected boolean evaluateChild(BaseTokenAST child) throws ParserException
    {
        switch (child.getType())
        {
        case ZserioParserTokenTypes.ID:
            if (!(child instanceof IdToken))
                return false;
            setName(child.getText());
            break;

	case ZserioParserTokenTypes.STRING_LITERAL:
	    if (topicName != null)
                return false;
            topicName = child.getText();
            break;

        default:
            if (!(child instanceof ZserioType))
                return false;
            valueType = (ZserioType)child;
	    break;
        }

        return true;
    }

    @Override
    protected void evaluate() throws ParserException
    {
        evaluateHiddenDocComment(this);
        setDocComment(getHiddenDocComment());
    }

    public String getTopicName()
    {
        return topicName;
    }

    public ZserioType getValueType()
    {
        return valueType;
    }

    private String topicName;
    private ZserioType valueType;

    private static final long serialVersionUID = 7339295016544090386L;
}
