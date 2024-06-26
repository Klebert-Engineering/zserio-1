package zserio.extension.doc;

import java.util.ArrayList;
import java.util.List;

import zserio.ast.AstNode;
import zserio.ast.BitmaskType;
import zserio.ast.BitmaskValue;
import zserio.ast.ChoiceCase;
import zserio.ast.ChoiceCaseExpression;
import zserio.ast.ChoiceDefault;
import zserio.ast.ChoiceType;
import zserio.ast.DocComment;
import zserio.ast.EnumItem;
import zserio.ast.EnumType;
import zserio.ast.Expression;
import zserio.ast.ZserioType;
import zserio.extension.common.ExpressionFormatter;
import zserio.extension.common.ZserioExtensionException;

/**
 * FreeMarker template data for choices in the package used by Package emitter.
 */
public final class ChoiceTemplateData extends CompoundTypeTemplateData
{
    public ChoiceTemplateData(PackageTemplateDataContext context, ChoiceType choiceType)
            throws ZserioExtensionException
    {
        super(context, choiceType);

        final ExpressionFormatter docExpressionFormatter = context.getExpressionFormatter();
        selectorExpression = docExpressionFormatter.formatGetter(choiceType.getSelectorExpression());

        caseMembers = new ArrayList<CaseMemberTemplateData>();
        for (ChoiceCase choiceCase : choiceType.getChoiceCases())
            caseMembers.add(new CaseMemberTemplateData(context, choiceType, choiceCase));

        defaultMember = (choiceType.getChoiceDefault() != null)
                ? new DefaultMemberTemplateData(context, choiceType)
                : null;
    }

    public String getSelectorExpression()
    {
        return selectorExpression;
    }

    public Iterable<CaseMemberTemplateData> getCaseMemberList()
    {
        return caseMembers;
    }

    public DefaultMemberTemplateData getDefaultMember()
    {
        return defaultMember;
    }

    public static final class CaseMemberTemplateData
    {
        public CaseMemberTemplateData(PackageTemplateDataContext context, ChoiceType choiceType,
                ChoiceCase choiceCase) throws ZserioExtensionException
        {
            caseList = new ArrayList<CaseTemplateData>();
            final Iterable<ChoiceCaseExpression> caseExpressions = choiceCase.getExpressions();
            for (ChoiceCaseExpression caseExpression : caseExpressions)
                caseList.add(new CaseTemplateData(context, choiceType, choiceCase,
                        caseExpression.getExpression(), caseExpression.getDocComments()));

            field = (choiceCase.getField() != null)
                    ? new FieldTemplateData(context, choiceType, choiceCase.getField())
                    : null;
        }

        public Iterable<CaseTemplateData> getCaseList()
        {
            return caseList;
        }

        public FieldTemplateData getField()
        {
            return field;
        }

        private final List<CaseTemplateData> caseList;
        private final FieldTemplateData field;
    }

    public static final class CaseTemplateData
    {
        public CaseTemplateData(PackageTemplateDataContext context, ChoiceType choiceType,
                ChoiceCase choiceCase, Expression caseExpression, List<DocComment> docComments)
                throws ZserioExtensionException
        {
            final ExpressionFormatter docExpressionFormatter = context.getExpressionFormatter();
            final String expression = docExpressionFormatter.formatGetter(caseExpression);

            symbol = SymbolTemplateDataCreator.createData(context, choiceType, choiceCase, expression, "case");
            expressionSymbol = SymbolTemplateDataCreator.createData(context, caseExpression);

            this.docComments = new DocCommentsTemplateData(context, docComments);

            final AstNode caseExpressionObject = caseExpression.getExprSymbolObject();
            final ZserioType selectorExpressionType = choiceType.getSelectorExpression().getExprZserioType();
            if (caseExpressionObject instanceof EnumItem && selectorExpressionType instanceof EnumType ||
                    caseExpressionObject instanceof BitmaskValue &&
                            selectorExpressionType instanceof BitmaskType)
            {
                final SymbolTemplateData memberSymbol = SymbolTemplateDataCreator.createData(
                        context, selectorExpressionType, caseExpressionObject);
                final SymbolTemplateData typeSymbol =
                        SymbolTemplateDataCreator.createData(context, selectorExpressionType);
                seeSymbol = new SeeSymbolTemplateData(memberSymbol, typeSymbol);
            }
            else
            {
                seeSymbol = null;
            }
        }

        public SymbolTemplateData getExpressionSymbol()
        {
            return expressionSymbol;
        }

        public SymbolTemplateData getSymbol()
        {
            return symbol;
        }

        public DocCommentsTemplateData getDocComments()
        {
            return docComments;
        }

        public SeeSymbolTemplateData getSeeSymbol()
        {
            return seeSymbol;
        }

        private final SymbolTemplateData symbol;
        private final SymbolTemplateData expressionSymbol;
        private final DocCommentsTemplateData docComments;
        private final SeeSymbolTemplateData seeSymbol;
    }

    public static final class DefaultMemberTemplateData
    {
        public DefaultMemberTemplateData(PackageTemplateDataContext context, ChoiceType choiceType)
                throws ZserioExtensionException
        {
            final ChoiceDefault choiceDefault = choiceType.getChoiceDefault();
            field = (choiceDefault.getField() == null)
                    ? null
                    : new FieldTemplateData(context, choiceType, choiceDefault.getField());
            symbol = SymbolTemplateDataCreator.createData(context, choiceType, choiceDefault, "default");
            docComments = new DocCommentsTemplateData(context, choiceDefault.getDocComments());
        }

        public FieldTemplateData getField()
        {
            return field;
        }

        public SymbolTemplateData getSymbol()
        {
            return symbol;
        }

        public DocCommentsTemplateData getDocComments()
        {
            return docComments;
        }

        private final FieldTemplateData field;
        private final SymbolTemplateData symbol;
        private final DocCommentsTemplateData docComments;
    }

    private final String selectorExpression;
    private final List<CaseMemberTemplateData> caseMembers;
    private final DefaultMemberTemplateData defaultMember;
}
