package zserio.extension.python;

import zserio.extension.common.ExpressionFormatter;
import zserio.extension.common.ExpressionFormattingPolicy;
import zserio.extension.common.PackedTypesCollector;

/**
 * Template data context for choices and unions which creates proper formatting policy.
 */
public final class ChoiceTemplateDataContext extends TemplateDataContext
{
    public ChoiceTemplateDataContext(
            PythonExtensionParameters pythonParameters, PackedTypesCollector packedTypesCollector)
    {
        super(pythonParameters, packedTypesCollector);
    }

    @Override
    public ExpressionFormatter getPythonExpressionFormatter(ImportCollector importCollector)
    {
        final ExpressionFormattingPolicy expressionFormattingPolicy =
                new PythonChoiceExpressionFormattingPolicy(this, importCollector);

        return new ExpressionFormatter(expressionFormattingPolicy);
    }

    @Override
    public ExpressionFormatter getPythonOwnerIndirectExpressionFormatter(ImportCollector importCollector)
    {
        final ExpressionFormattingPolicy expressionFormattingPolicy =
                new PythonChoiceExpressionFormattingPolicy(
                        this, importCollector, TemplateDataContext.PYTHON_OWNER_PREFIX);

        return new ExpressionFormatter(expressionFormattingPolicy);
    }
}
