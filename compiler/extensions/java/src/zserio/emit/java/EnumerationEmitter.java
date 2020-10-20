package zserio.emit.java;

import zserio.ast.EnumType;
import zserio.emit.common.ZserioEmitException;
import zserio.tools.Parameters;

class EnumerationEmitter extends JavaDefaultEmitter
{
    public EnumerationEmitter(JavaExtensionParameters javaParameters, Parameters extensionParameters)
    {
        super(javaParameters, extensionParameters);
    }

    @Override
    public void beginEnumeration(EnumType enumType) throws ZserioEmitException
    {
        Object templateData = new EnumerationEmitterTemplateData(getTemplateDataContext(), enumType);
        processTemplate(TEMPLATE_NAME, templateData, enumType);
    }

    private static final String TEMPLATE_NAME = "Enumeration.java.ftl";
}
