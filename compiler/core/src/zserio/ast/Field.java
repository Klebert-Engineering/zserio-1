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
import zserio.ast.doc.DocCommentToken;

/**
 * AST node for fields.
 */
public class Field extends TokenAST
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
     * Gets referenced Zserio type associated with the field.
     *
     * In case that the field is an array, this methods gets the element type.
     * If the type is a an instantiation, it returns it's referenced type.
     *
     * Result is either a built-in type or a type reference.
     *
     * @return Referenced Zserio type associated with the field.
     */
    public ZserioType getFieldReferencedType()
    {
        ZserioType referencedType = fieldType;

        // get array element type
        if (fieldType instanceof ArrayType)
            referencedType = ((ArrayType)referencedType).getElementType();

        // get instantiated type
        if (referencedType instanceof TypeInstantiation)
            referencedType = ((TypeInstantiation)referencedType).getReferencedType();

        return referencedType;
    }

    /**
     * Gets a list of parameters used in the field.
     *
     * This method is useful only for fields of type "type instantiation" as no other fields can have
     * parameters.
     *
     * The order of the returned items is the order of the parameters.
     *
     * @return A list of parameters or empty list if a field has no parameters.
     */
    public List<TypeInstantiation.InstantiatedParameter> getInstantiatedParameters()
    {
        final ZserioType resolvedFieldType = TypeReference.resolveType(fieldType);
        if (!(resolvedFieldType instanceof TypeInstantiation))
            return new LinkedList<TypeInstantiation.InstantiatedParameter>();

        return ((TypeInstantiation)resolvedFieldType).getInstantiatedParameters();
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

    /**
     * Gets flag which indicates if the field is optional.
     *
     * @return true if the field is has been defined using "optional" keyword in Zserio or if the field
     *         has optional clause.
     */
    public boolean getIsOptional()
    {
        return isAutoOptional || optionalClauseExpr != null;
    }

    public boolean getIsTemplateSymbol()
    {
        return isTemplateSymbol;
    }

    public boolean getIsExternal()
    {
        return isExternal;
    }

    public List<Parameter> getParameters()
    {
        final ZserioType resolvedFieldType = TypeReference.resolveType(fieldType);
        if (!(resolvedFieldType instanceof CompoundType))
            return new LinkedList<Parameter>();

        return ((CompoundType)resolvedFieldType).getParameters();
    }

    /**
     * Gets initializer expression associated with the field.
     *
     * @return Initializer expression or null if no initializer expression has been specified.
     */
    public Expression getInitializerExpr()
    {
        return initializerExpr;
    }

    /**
     * Gets optional clause expression associated with the field.
     *
     * @return Optional clause expression or null if no optional clause expression has been specified.
     */
    public Expression getOptionalClauseExpr()
    {
        return optionalClauseExpr;
    }

    /**
     * Gets constraint expression associated with the field.
     *
     * @return Constraint expression or null if no constraint expression has been specified.
     */
    public Expression getConstraintExpr()
    {
        return constraintExpr;
    }

    /**
     * Gets offset expression associated with the field.
     *
     * @return Offset expression or null if no offset expression has been specified.
     */
    public Expression getOffsetExpr()
    {
        return offsetExpr;
    }

    /**
     * Gets alignment expression associated with the field.
     *
     * @return Alignment expression or null if no alignment expression has been specified.
     */
    public Expression getAlignmentExpr()
    {
        return alignmentExpr;
    }

    /**
     * Gets SQL constraint associated with the field.
     *
     * Even if SQL constraint is not specified in Zserio, this method returns valid SQL constraint which
     * corresponds to Zserio SQL constraint default behavior.
     *
     * @return SQL constraint.
     */
    public SqlConstraint getSqlConstraint()
    {
        return sqlConstraint;
    }

    /**
     * Gets flag which indicates if the field has been defined using "sql_virtual" keyword in Zserio.
     *
     * @return true if the field is virtual column in SQL table.
     */
    public boolean getIsVirtual()
    {
        return isVirtual;
    }

    /**
     * Gets the list of Zserio types referenced by all expressions of the field.
     *
     * @param clazz Zserio type to use.
     *
     * @return List of referenced Zserio types of given type.
     */
    public <T extends ZserioType> Set<T> getReferencedTypes(Class<? extends T> clazz)
    {
        final Set<T> referencedTypes = new HashSet<T>();

        // check direct expressions
        if (optionalClauseExpr != null)
            referencedTypes.addAll(optionalClauseExpr.getReferencedSymbolObjects(clazz));
        if (constraintExpr != null)
            referencedTypes.addAll(constraintExpr.getReferencedSymbolObjects(clazz));
        if (offsetExpr != null)
            referencedTypes.addAll(offsetExpr.getReferencedSymbolObjects(clazz));
        if (alignmentExpr != null)
            referencedTypes.addAll(alignmentExpr.getReferencedSymbolObjects(clazz));

        ZserioType checkedType = fieldType;
        if (checkedType instanceof ArrayType)
        {
            // check array fields which have expressions as well
            final ArrayType arrayType = (ArrayType)checkedType;
            final Expression lengthExpression = arrayType.getLengthExpression();
            if (lengthExpression != null)
                referencedTypes.addAll(lengthExpression.getReferencedSymbolObjects(clazz));

            checkedType = arrayType.getElementType();
        }

        if (checkedType instanceof TypeInstantiation)
        {
            // check type instantiations which have expressions in arguments
            final TypeInstantiation typeInstantiation = (TypeInstantiation)checkedType;
            for (TypeInstantiation.InstantiatedParameter instantiatedParameter :
                    typeInstantiation.getInstantiatedParameters())
            {
                final Expression argumentExpression = instantiatedParameter.getArgumentExpression();
                referencedTypes.addAll(argumentExpression.getReferencedSymbolObjects(clazz));
            }
        }
        else if (checkedType instanceof BitFieldType)
        {
            // check bit fields which have expressions as well
            final Expression lengthExpression = ((BitFieldType)checkedType).getLengthExpression();
            referencedTypes.addAll(lengthExpression.getReferencedSymbolObjects(clazz));
        }

        return referencedTypes;
    }

    /**
     * Gets documentation comment associated to this field.
     *
     * @return Documentation comment token associated to this field.
     */
    public DocCommentToken getDocComment()
    {
        return tokenWithDoc != null ? tokenWithDoc.getHiddenDocComment() : null;
    }

    @Override
    protected boolean evaluateChild(BaseTokenAST child) throws ParserException
    {
        final AST firstChildOfChild = child.getFirstChild();

        switch (child.getType())
        {
        case ZserioParserTokenTypes.ID:
            name = child.getText();
            break;

        case ZserioParserTokenTypes.OPTIONAL:
            isAutoOptional = true;
            evaluateDocComment((TokenAST)child);
            break;

        case ZserioParserTokenTypes.EXTERN:
            isExternal = true;
            break;

        case ZserioParserTokenTypes.ASSIGN:
            if (!(firstChildOfChild instanceof Expression))
                return false;
            initializerExpr = (Expression)firstChildOfChild;
            break;

        case ZserioParserTokenTypes.IF:
            if (!(firstChildOfChild instanceof Expression))
                return false;
            optionalClauseExpr = (Expression)firstChildOfChild;
            break;

        case ZserioParserTokenTypes.COLON:
            if (!(firstChildOfChild instanceof Expression))
                return false;
            constraintExpr = (Expression)firstChildOfChild;
            break;

        case ZserioParserTokenTypes.OFFSET:
            if (!(firstChildOfChild instanceof Expression))
                return false;
            offsetExpr = (Expression)firstChildOfChild;
            evaluateDocComment((TokenAST)child);
            break;

        case ZserioParserTokenTypes.ALIGN:
            if (!(firstChildOfChild instanceof Expression))
                return false;
            alignmentExpr = (Expression)firstChildOfChild;
            evaluateDocComment((TokenAST)child);
            break;

        case ZserioParserTokenTypes.SQL:
            if (!(child instanceof SqlConstraint))
                return false;
            sqlConstraint = (SqlConstraint)child;
            sqlConstraint.setCompoundType(compoundType);
            break;

        case ZserioParserTokenTypes.SQL_VIRTUAL:
            if (!(child instanceof TokenAST))
                return false;
            isVirtual = true;
            evaluateDocComment((TokenAST)child);
            break;

        case ZserioParserTokenTypes.STRUCTURE:
            // allow nested structure-keyword for externals only
            if (!isExternal)
                return false;
            fieldType = (ZserioType)child;
            break;

        case ZserioParserTokenTypes.TEMPLATE_SYMBOL:
            isTemplateSymbol = true;
            break;

        default:
            if (fieldType != null || !(child instanceof ZserioType))
                return false;
            fieldType = (ZserioType)child;
            evaluateDocComment((TokenAST)child);
            break;
        }

        return true;
    }

    @Override
    protected void check() throws ParserException
    {
        // check field name
        if (compoundType.getPackage().getVisibleType(this, PackageName.EMPTY, getName()) != null)
            throw new ParserException(this, "'" + getName() + "' is a defined type in this package!");

        // check initializer expression type
        if (initializerExpr != null)
        {
            // check expression type
            final ZserioType fieldBaseType = TypeReference.resolveBaseType(fieldType);
            ExpressionUtil.checkExpressionType(initializerExpr, fieldBaseType);

            // check if expression requires owner context (contains field, parameter or function)
            if (initializerExpr.requiresOwnerContext())
                throw new ParserException(initializerExpr, "Initializer must be a constant expression!");

            // check integer initializer range
            ExpressionUtil.checkIntegerExpressionRange(initializerExpr, fieldBaseType, name);
        }

        // check optional expression type
        if (optionalClauseExpr != null)
        {
            if (optionalClauseExpr.getExprType() != Expression.ExpressionType.BOOLEAN)
                throw new ParserException(optionalClauseExpr, "Optional expression for field '" +
                        getName() + "' is not boolean!");

            if (isAutoOptional)
                throw new ParserException(optionalClauseExpr, "Auto optional field '" + getName() +
                        "' cannot contain if clause!");
        }

        // check constraint expression type
        if (constraintExpr != null && constraintExpr.getExprType() != Expression.ExpressionType.BOOLEAN)
            throw new ParserException(constraintExpr, "Constraint expression for field '" +
                    getName() + "' is not boolean!");

        // check offset expression type
        if (offsetExpr != null)
        {
            final ZserioType exprZserioType = offsetExpr.getExprZserioType();
            if (!(exprZserioType instanceof IntegerType) || ((IntegerType)exprZserioType).isSigned())
                throw new ParserException(offsetExpr, "Offset expression for field '" + getName() +
                        "' is not an unsigned integer type!");
        }

        // check alignment expression type
        if (alignmentExpr != null)
        {
            final BigInteger alignmentValue = alignmentExpr.getIntegerValue();
            if (alignmentValue == null || alignmentValue.compareTo(BigInteger.ZERO) < 0)
                throw new ParserException(alignmentExpr, "Alignment expression for field '" + getName() +
                        "' is not positive integer!");
        }
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

    /**
     * Evaluates hidden doc comment within the AST subtree of the given comment.
     *
     * Traverses only left most path in the AST subtree (i.e. only first children) and takes the last found
     * comment. All other comments are marked as not used.
     * \note Note that "priority" of comments is given by order of children in the Field token,
     *       which is given in the parser grammar.
     *
     * @param token Token to be searched for documentation comments.
     * @throws ParserException In case of invalid AST token.
     */
    private void evaluateDocComment(TokenAST token) throws ParserException
    {
        TokenAST currentToken = token;

        while (currentToken != null)
        {
            if (currentToken.evaluateHiddenDocComment(compoundType))
            {
                if (tokenWithDoc != null)
                    tokenWithDoc.setDocCommentNotUsed();
                tokenWithDoc = currentToken;
            }

            currentToken = (TokenAST)currentToken.getFirstChild();
        }
    }

    public static final String SEPARATOR = ".";

    private static final long serialVersionUID = 4009186108710189367L;

    private CompoundType compoundType = null;
    private ZserioType fieldType = null;
    private String name = null;
    private boolean isAutoOptional = false;
    private boolean isExternal = false;
    private boolean isTemplateSymbol = false;
    private Expression initializerExpr = null;
    private Expression optionalClauseExpr = null;
    private Expression constraintExpr = null;
    private Expression offsetExpr = null;
    private Expression alignmentExpr = null;
    private SqlConstraint sqlConstraint = SqlConstraint.createDefaultFieldConstraint();
    private boolean isVirtual = false;
    private TokenAST tokenWithDoc = null;
}
