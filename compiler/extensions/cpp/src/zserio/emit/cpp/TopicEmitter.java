package zserio.emit.cpp;

import java.util.ArrayList;
import java.util.List;
import zserio.ast.Root;
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
        topicTypes.add(token);
    }

    @Override
    public void endRoot(Root root) throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        for (TopicType topicType : topicTypes)
        {
            final TopicEmitterTemplateData templateData =
                    new TopicEmitterTemplateData(templateDataContext, topicType);
            processSourceTemplate(TEMPLATE_SOURCE_NAME, templateData, topicType);
            processHeaderTemplate(TEMPLATE_HEADER_NAME, templateData, topicType);
        }
    }

    private final List<TopicType> topicTypes = new ArrayList<TopicType>();
    private static final String TEMPLATE_SOURCE_NAME = "Topic.cpp.ftl";
    private static final String TEMPLATE_HEADER_NAME = "Topic.h.ftl";
}
