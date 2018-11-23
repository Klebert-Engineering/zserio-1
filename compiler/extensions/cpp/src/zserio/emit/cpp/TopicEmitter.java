package zserio.emit.cpp;

import antlr.collections.AST;
import zserio.ast.TopicType;
import zserio.tools.Parameters;
import zserio.emit.common.ZserioEmitException;

public class TopicEmitter extends CppDefaultEmitter
{
    public TopicEmitter(String outPathName, Parameters extensionParameters)
    {
        super(outPathName, extensionParameters);
    }

    @Override
    public void beginTopic(TopicType token) throws ZserioEmitException
    {
        topicType = token;
    }

    public void endRoot() throws ZserioEmitException
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
