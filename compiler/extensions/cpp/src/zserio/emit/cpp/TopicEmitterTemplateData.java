package zserio.emit.cpp;

import zserio.ast.TopicType;
import zserio.ast.ZserioType;
import zserio.emit.cpp.types.CppNativeType;

public class TopicEmitterTemplateData extends CompoundTypeTemplateData
{
    public TopicEmitterTemplateData(TemplateDataContext context, TopicType type)
    {
        super(context, type);

        final CppNativeTypeMapper cppNativeTypeMapper = context.getCppNativeTypeMapper();
        final CppNativeType valueNativeType =
	        cppNativeTypeMapper.getCppType(type.getValueType());

	addHeaderIncludesForType(valueNativeType);

	valueTypeName = valueNativeType.getFullName();
        topicNameParts = type.getTopicName().replace("\"", "").split("/");
    }

    public String getValueTypeName()
    {
        return valueTypeName;
    }

    public String[] getTopicNameParts()
    {
        return topicNameParts;
    }

    public int getNumWildcards()
    {
        int wildcards = 0;
	for (String part : topicNameParts)
            if (part.equals("+"))
	        wildcards++;

        return wildcards;
    }

    final String[] topicNameParts;
    final String valueTypeName;
}
