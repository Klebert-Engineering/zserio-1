package zserio.ast;

import java.math.BigInteger;
import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import zserio.antlr.ZserioParser;

/**
 * AST node for SQL constraints.
 */
public class SqlConstraint extends AstNodeBase
{
    /**
     * Constructor.
     *
     * @param location      AST node location.
     * @param constaintExpr Constraint expression.
     */
    public SqlConstraint(AstLocation location, Expression constraintExpr)
    {
        super(location);

        this.constraintExpr = constraintExpr;
    }

    @Override
    public void accept(ZserioAstVisitor visitor)
    {
        visitor.visitSqlConstraint(this);
    }

    @Override
    public void visitChildren(ZserioAstVisitor visitor)
    {
        constraintExpr.accept(visitor);
    }

    /**
     * Gets original SQL constraint expression.
     *
     * @return Original SQL constraint expression as has been specified in the Zserio.
     */
    public Expression getConstraintExpr()
    {
        return constraintExpr;
    }

    /**
     * Gets translated SQL constraint expression.
     *
     * @return SQL constraint expression with translated Zserio values.
     */
    public Expression getTranslatedConstraintExpr()
    {
        return translatedConstraintExpr;
    }

    /**
     * Gets translated SQL constraint expression for table field.
     *
     * @return SQL constraint expression with translated NOT NULL constraint or null
     *         if there is no translated SQL constraint for field.
     */
    public Expression getTranslatedFieldConstraintExpr()
    {
        return translatedFieldConstraintExpr;
    }

    /**
     * Indicates if the SQL constraint allows 'NULL' value.
     *
     * @return True if the SQL constraint allows 'NULL' value.
     */
    public boolean isNullAllowed()
    {
        return isNullAllowed;
    }

    /**
     * Indicates if the SQL constraint contains 'PRIMARY KEY'.
     *
     * @return true if this SQL constraint contains 'PRIMARY KEY'.
     */
    public boolean isPrimaryKey()
    {
        return isPrimaryKey;
    }

    /**
     * Gets list of primary key column names specified by this constraint.
     *
     * @return List of primary key column names.
     */
    public List<String> getPrimaryKeyColumnNames()
    {
        return Collections.unmodifiableList(primaryKeyColumnNames);
    }

    /**
     * Gets list of unique column names specified by this constraint.
     *
     * @return List of unique column names.
     */
    public List<String> getUniqueColumnNames()
    {
        return Collections.unmodifiableList(uniqueColumnNames);
    }

    /**
     * Creates default SQL constraint for table fields.
     *
     * This is used for table fields which have no SQL constraint specified in Zserio. If table field has
     * no SQL constraint, it should be translated to 'NOT NULL' constraint for SQLite (Zserio default behavior).
     *
     * @param pkg Package to use for created SQL constraint.
     *
     * @return Created default SQL constraint.
     */
    static SqlConstraint createDefaultFieldConstraint(Package pkg)
    {
        return new SqlConstraint(null, createStringLiteralExpression(pkg, ""));
    }

    /**
     * Resolves the SQL constraint.
     *
     * @param compoundType Compound type which owns the SQL constraint.
     */
    void resolve(CompoundType compoundType)
    {
        // store package of the owner
        pkg = compoundType.getPackage();

        // resolve all @-references
        final String sqlConstraintString = constraintExpr.getText();
        resolveConstraintReferences(compoundType, sqlConstraintString);
    }

    /**
     * Evaluates the SQL constraint.
     */
    void evaluate()
    {
        final String sqlConstraintString = constraintExpr.getText();
        primaryKeyColumnNames = extractColumnNames(sqlConstraintString, PRIMARY_KEY_CONSTRAINT);
        uniqueColumnNames = extractColumnNames(sqlConstraintString, UNIQUE_CONSTRAINT);
        isPrimaryKey = containsPrimaryKey(sqlConstraintString);

        // set translated constraint expression for table
        final String translatedConstraint = createTranslatedConstraint();
        translatedConstraintExpr = createStringLiteralExpression(pkg, translatedConstraint);

        // set translated constraint expression for table field
        translatedFieldConstraintExpr = createTranslatedFieldConstraintExpr(translatedConstraint);
    }

    /**
     * Instantiate the sql constraint.
     *
     * @param templateParameters Template parameters.
     * @param templateArguments Template arguments.
     *
     * @return New sql constraint instantiated from this using the given template arguments.
     */
    SqlConstraint instantiate(List<TemplateParameter> templateParameters,
            List<TemplateArgument> templateArguments)
    {
        final Expression instantiatedConstraintExpr =
                getConstraintExpr().instantiate(templateParameters, templateArguments);

        return new SqlConstraint(getLocation(), instantiatedConstraintExpr);
    }

    private void resolveConstraintReferences(CompoundType compoundType, String sqlConstraintString)
    {
        int startIndex = 0;
        int referenceIndex = sqlConstraintString.indexOf(CONSTRAINT_REFERENCE_ESCAPE);
        while (referenceIndex >= 0)
        {
            translatedConstraintStrings.add(sqlConstraintString.substring(startIndex, referenceIndex));

            final int endIndex = findEndOfConstraintReference(sqlConstraintString, referenceIndex + 1);
            final String referencedText = sqlConstraintString.substring(referenceIndex + 1, endIndex);
            final SymbolReference symbolReference = new SymbolReference(this, referencedText);
            symbolReference.resolve(compoundType.getPackage(), compoundType);
            constraintReferences.add(new AbstractMap.SimpleEntry<SymbolReference, String>(symbolReference,
                    referencedText));

            startIndex = endIndex;
            referenceIndex = sqlConstraintString.indexOf(CONSTRAINT_REFERENCE_ESCAPE, startIndex);
        }

        if (startIndex < sqlConstraintString.length())
            translatedConstraintStrings.add(sqlConstraintString.substring(startIndex));
    }

    private static int findEndOfConstraintReference(String sqlConstrainString, int startIndex)
    {
        int endIndex = startIndex;
        while (endIndex < sqlConstrainString.length())
        {
            final char c = sqlConstrainString.charAt(endIndex);
            if (c != '.' && c != '_' && !Character.isLetterOrDigit(sqlConstrainString.charAt(endIndex)))
                break;

            endIndex++;
        }

        return endIndex;
    }

    private static List<String> extractColumnNames(String sqlConstraintString, String constraintName)
    {
        final ArrayList<String> columnNames = new ArrayList<String>();
        final int constraintIndex = sqlConstraintString.toUpperCase(Locale.ENGLISH).indexOf(constraintName);
        if (constraintIndex > -1)
        {
            final int leftBracketIndex = sqlConstraintString.indexOf('(', constraintIndex);
            if (leftBracketIndex > -1)
            {
                final int rightBracketIndex = sqlConstraintString.indexOf(')', leftBracketIndex);
                if (rightBracketIndex > -1)
                {
                    final String[] cols = sqlConstraintString.substring(leftBracketIndex + 1,
                            rightBracketIndex).split(",");
                    for (int i = 0; i < cols.length; i++ )
                        columnNames.add(cols[i].trim());
                }
            }
        }

        return columnNames;
    }

    private static boolean containsPrimaryKey(String sqlConstraintString)
    {
        return (sqlConstraintString.toUpperCase(Locale.ENGLISH).indexOf(PRIMARY_KEY_CONSTRAINT) > -1);
    }

    private String createTranslatedConstraint()
    {
        final StringBuilder stringBuilder = new StringBuilder();
        int numUsedReferences = 0;
        for (String translatedConstraintString : translatedConstraintStrings)
        {
            stringBuilder.append(translatedConstraintString);
            if (numUsedReferences < constraintReferences.size())
            {
                final Map.Entry<SymbolReference, String> referenceEntry =
                        constraintReferences.get(numUsedReferences);
                final SymbolReference symbolReference = referenceEntry.getKey();
                final AstNode referencedSymbol = symbolReference.getReferencedSymbol();

                // used to call evaluation explicitly because the symbol does not have to be evaluated yet
                final ZserioAstEvaluator evaluator = new ZserioAstEvaluator();

                if (referencedSymbol instanceof Constant)
                {
                    final Constant referencedConstant = (Constant)referencedSymbol;
                    referencedConstant.accept(evaluator);

                    final BigInteger value = referencedConstant.getValueExpression().getIntegerValue();
                    if (value == null)
                        throw new ParserException(this, "Reference '" + referenceEntry.getValue() +
                                "' refers to non-integer constant!");

                    stringBuilder.append(value.toString());
                }
                else if (referencedSymbol instanceof EnumItem)
                {
                    // referenced type should be the EnumType
                    final ZserioType referencedEnumType = symbolReference.getReferencedType();
                    referencedEnumType.accept(evaluator);

                    stringBuilder.append(((EnumItem)referencedSymbol).getValue().toString());
                }
                else
                {
                    throw new ParserException(this, "Reference '" + referenceEntry.getValue() +
                            "' does refer to neither enumeration type nor constant!");
                }

                numUsedReferences++;
            }
        }

        return stringBuilder.toString();
    }

    private Expression createTranslatedFieldConstraintExpr(String translatedConstraint)
    {
        // unlike SQLite, the default column constraint in Zserio is 'NOT NULL' and NULL-constraints have to be
        // explicitly set
        String fieldConstraint = translatedConstraint;

        // skip quotes
        if (fieldConstraint.length() > 1)
            fieldConstraint = fieldConstraint.substring(1, fieldConstraint.length() - 1);

        // remove duplicated white spaces to be able detect NOT_NULL_CONSTRAINT/DEFAULT_NULL_CONSTRAINT properly
        fieldConstraint = fieldConstraint.replaceAll("\\s+", " ");

        // trim leading and trailing whitespace
        fieldConstraint = fieldConstraint.trim();

        if (!fieldConstraint.contains(NOT_NULL_CONSTRAINT))
        {
            // there is no NOT_NULL_CONSTRAINT
            if (fieldConstraint.contains(DEFAULT_NULL_CONSTRAINT))
            {
                // there is DEFAULT_NULL_CONSTRAINT => null is allowed
                isNullAllowed = true;
            }
            else
            {
                // there is no NOT_NULL_CONSTRAINT and no DEFAULT_NULL_CONSTRAINT
                if (!fieldConstraint.contains(NULL_CONSTRAINT))
                {
                    // and there is no NULL_CONSTRAINT => add NOT_NULL_CONSTRAINT constraint (default in Zserio)
                    if (!fieldConstraint.isEmpty())
                        fieldConstraint = fieldConstraint.concat(" ");
                    fieldConstraint = fieldConstraint.concat(NOT_NULL_CONSTRAINT);
                }
                else
                {
                    // and there is NULL_CONSTRAINT => remove NULL_CONSTRAINT constraint (unknown for SQLite)
                    fieldConstraint = fieldConstraint.replace(NULL_CONSTRAINT, "");

                    // trim leading and trailing whitespace
                    fieldConstraint = fieldConstraint.trim();

                    // null is allowed
                    isNullAllowed = true;
                }
            }
        }

        return (fieldConstraint.isEmpty()) ? null :
            createStringLiteralExpression(pkg, "\"" + fieldConstraint + "\"");
    }

    private static Expression createStringLiteralExpression(Package pkg, String stringLiteral)
    {
        return new Expression(null, pkg, ZserioParser.STRING_LITERAL, stringLiteral,
                Expression.ExpressionFlag.NONE);
    }

    private static final String PRIMARY_KEY_CONSTRAINT = "PRIMARY KEY";
    private static final String UNIQUE_CONSTRAINT = "UNIQUE";
    private static final String NOT_NULL_CONSTRAINT = "NOT NULL";
    private static final String NULL_CONSTRAINT = "NULL";
    private static final String DEFAULT_NULL_CONSTRAINT = "DEFAULT NULL";
    private static final String CONSTRAINT_REFERENCE_ESCAPE = "@";

    private final Expression constraintExpr;

    private final List<String> translatedConstraintStrings = new ArrayList<String>();
    private final List<Map.Entry<SymbolReference, String>> constraintReferences =
            new ArrayList<Map.Entry<SymbolReference, String>>();
    private Package pkg;

    private Expression translatedConstraintExpr = null;
    private Expression translatedFieldConstraintExpr = null;

    private List<String> primaryKeyColumnNames = new ArrayList<String>();
    private List<String> uniqueColumnNames = new ArrayList<String>();

    private boolean isNullAllowed = false;
    private boolean isPrimaryKey = false;
}
