package zserio.extension.python;

import zserio.ast.Subtype;
import zserio.extension.common.OutputFileManager;
import zserio.extension.common.PackedTypesCollector;
import zserio.extension.common.ZserioExtensionException;

/**
 * Subtype emitter.
 */
final class SubtypeEmitter extends PythonDefaultEmitter
{
    public SubtypeEmitter(OutputFileManager outputFileManager, PythonExtensionParameters pythonParameters,
            PackedTypesCollector packedTypesCollector)
    {
        super(outputFileManager, pythonParameters, packedTypesCollector);
    }

    @Override
    public void beginSubtype(Subtype subtype) throws ZserioExtensionException
    {
        final SubtypeEmitterTemplateData templateData =
                new SubtypeEmitterTemplateData(getTemplateDataContext(), subtype);
        processSourceTemplate(TEMPLATE_SOURCE_NAME, templateData, subtype);
    }

    private static final String TEMPLATE_SOURCE_NAME = "Subtype.py.ftl";
}
