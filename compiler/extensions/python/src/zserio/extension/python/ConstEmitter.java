package zserio.extension.python;

import zserio.ast.Constant;
import zserio.extension.common.OutputFileManager;
import zserio.extension.common.ZserioExtensionException;

public class ConstEmitter extends PythonDefaultEmitter
{
    public ConstEmitter(OutputFileManager outputFileManager, PythonExtensionParameters pythonParameters)
    {
        super(outputFileManager, pythonParameters);
    }

    @Override
    public void beginConst(Constant constant) throws ZserioExtensionException
    {
        final Object templateData = new ConstEmitterTemplateData(getTemplateDataContext(), constant);
        processSourceTemplate(TEMPLATE_SOURCE_NAME, templateData, constant.getPackage(), constant.getName());
    }

    private static final String TEMPLATE_SOURCE_NAME = "Constant.py.ftl";
}
