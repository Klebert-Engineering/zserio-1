package zserio.emit.cpp.types;

import zserio.ast.PackageName;
import zserio.ast.TemplateParameter;
import java.util.List;

public class NativeCompoundType extends CppNativeType
{
    public NativeCompoundType(PackageName packageName,
                              String name,
                              String includeFileName,
                              List<TemplateParameter> params)
    {
        super(packageName, name, false);
        tParams = params;
        addUserIncludeFile(includeFileName);
    }

    public String getTypeSuffix()
    {
        String typSuffix = "";
        if (!tParams.isEmpty())
        {
            typSuffix = "<";
            for (TemplateParameter p: tParams)
            {
                if (typSuffix.length() > 1)
                    typSuffix += ",";
                typSuffix += p.getName();
            }
            typSuffix += ">";
        }
        return typSuffix;
    }

    private List<TemplateParameter> tParams = null;
}
