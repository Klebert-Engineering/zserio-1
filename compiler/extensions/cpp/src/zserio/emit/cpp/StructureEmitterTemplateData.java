package zserio.emit.cpp;

import java.util.ArrayList;
import java.util.List;

import zserio.ast.StructureType;
import zserio.ast.TemplateParameter;
import zserio.emit.common.ZserioEmitException;

public class StructureEmitterTemplateData extends CompoundTypeTemplateData
{
    public StructureEmitterTemplateData(TemplateDataContext context, StructureType structureType)
            throws ZserioEmitException
    {
        super(context, structureType);

        templateParameters = new ArrayList<String>();
        for (TemplateParameter tparam: structureType.getTemplateParameters())
        {
            templateParameters.add(tparam.getName());
        }
        isTemplate = (templateParameters.size() > 0);

        nonOptionalSimpleFieldList = new ArrayList<CompoundFieldTemplateData>();
        for (CompoundFieldTemplateData fieldTemplateData : getFieldList())
        {
            if (fieldTemplateData.getOptional() == null && fieldTemplateData.getIsSimpleType())
                nonOptionalSimpleFieldList.add(fieldTemplateData);
        }
    }

    public boolean getIsTemplate()
    {
        return isTemplate;
    }

    public Iterable<String> getTemplateParameters()
    {
        return templateParameters;
    }

    public Iterable<CompoundFieldTemplateData> getNonOptionalSimpleFieldList()
    {
        return nonOptionalSimpleFieldList;
    }

    private final List<CompoundFieldTemplateData>   nonOptionalSimpleFieldList;
    private boolean                                 isTemplate;
    private final List<String>                      templateParameters;
}

