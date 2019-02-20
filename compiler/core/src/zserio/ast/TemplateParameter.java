package zserio.ast;

import java.math.BigInteger;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

import antlr.collections.AST;
import zserio.antlr.ZserioParserTokenTypes;
import zserio.antlr.util.BaseTokenAST;
import zserio.antlr.util.ParserException;

/**
 * AST node for template parameters.
 */
public class TemplateParameter extends TokenAST
{
    /**
     * Gets Zserio type associated with the field.
     *
     * @return Zserio type associated with the field as has been specified in Zserio.
     */
    public ZserioType getFieldType()
    {
        return fieldType;
    }

    /**
     * Gets the name of the field.
     *
     * @return Returns name of the field.
     */
    public String getName()
    {
        return name;
    }

    @Override
    protected boolean evaluateChild(BaseTokenAST child) throws ParserException
    {
        final AST firstChildOfChild = child.getFirstChild();

        switch (child.getType())
        {
        case ZserioParserTokenTypes.TEMPLATE_PARAMETER:
            break;

        case ZserioParserTokenTypes.ID:
            name = child.getText();
            break;

        default:
	    return false;
        }

        return true;
    }

    @Override
    protected void check() throws ParserException
    {
        // check field name
        //if (compoundType.getPackage().getVisibleType(this, PackageName.EMPTY, getName()) != null)
        //    throw new ParserException(this, "'" + getName() + "' is a defined type in this package!");
    }

    /**
     * Sets the compound type which is owner of the field.
     *
     * @param compoundType Owner to set.
     */
    protected void setCompoundType(CompoundType compoundType)
    {
        this.compoundType = compoundType;
    }

    public static final String SEPARATOR = ".";

    private static final long serialVersionUID = 4009186108710189367L;

    private CompoundType compoundType = null;
    private ZserioType fieldType = null;
    private String name = null;
}
