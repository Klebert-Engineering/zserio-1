package zserio.emit.cpp;

import antlr.collections.AST;
import zserio.ast.TopicType;
import zserio.tools.Parameters;

public class TopicEmitter extends CppDefaultEmitter
{
    public TopicEmitter(String outPathName, Parameters extensionParameters)
    {
        super(outPathName, extensionParameters);
    }

    @Override
    public void beginTopic(AST token) throws ZserioEmitCppException
    {
        if (!(token instanceof TopicType))
            throw new ZserioEmitCppException("Unexpected token type in beginTopic!");
        topicType = (TopicType)token;
    }

    public void endRoot() throws ZserioEmitCppException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        final Object templateData = new TopicEmitterTemplateData(templateDataContext, topicType);
        processSourceTemplate(TEMPLATE_SOURCE_NAME, templateData, topicType);
        processHeaderTemplate(TEMPLATE_HEADER_NAME, templateData, topicType);
    }

    private TopicType topicType;
    private static final String TEMPLATE_SOURCE_NAME = "Topic.cpp.ftl";
    private static final String TEMPLATE_HEADER_NAME = "Topic.h.ftl";
}
