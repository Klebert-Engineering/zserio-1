package zserio.ast;

import antlr.collections.AST;
import zserio.antlr.ZserioParserTokenTypes;
import zserio.antlr.util.BaseTokenAST;
import zserio.antlr.util.ParserException;

/**
 * AST node for template parameters.
 */
public class TemplateSymbol extends CompoundType
{
    @Override
    public Package getPackage()
    {
        return new Package();
    }

    @Override
    public Iterable<ZserioType> getUsedTypeList()
    {
        throw new InternalError("TemplateSymbol.getUsedTypeList() is not implemented!");
    }

    @Override
    public void callVisitor(ZserioTypeVisitor visitor)
    {
        visitor.visitTemplateSymbol(this);
    }

    @Override
    public String getName()
    {
        return name;
    }

    @Override
    protected boolean evaluateChild(BaseTokenAST child) throws ParserException
    {
        switch (child.getType())
        {
        case ZserioParserTokenTypes.ID:
            name = child.getText();
            break;

        default:
	    return false;
        }

        return true;
    }

    public static final String SEPARATOR = ".";

    private static final long serialVersionUID = 4009186108710189367L;

    private String name = null;
}
