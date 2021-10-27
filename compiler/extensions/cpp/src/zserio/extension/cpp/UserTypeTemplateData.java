package zserio.extension.cpp;

import zserio.ast.ZserioType;
import zserio.ast.ZserioTypeUtil;
import zserio.extension.common.ZserioExtensionException;
import zserio.extension.cpp.types.CppNativeType;

public class UserTypeTemplateData extends CppTemplateData
{
    public UserTypeTemplateData(TemplateDataContext context, ZserioType type) throws ZserioExtensionException
    {
        super(context);

        nativeType = context.getCppNativeMapper().getCppType(type);
        schemaTypeName = ZserioTypeUtil.getFullName(type);
        packageData = new PackageTemplateData(nativeType);
    }

    public String getName()
    {
        return nativeType.getName();
    }

    public String getFullName()
    {
        return nativeType.getFullName();
    }

    public String getSchemaTypeName()
    {
        return schemaTypeName;
    }

    public PackageTemplateData getPackage()
    {
        return packageData;
    }

    private final CppNativeType nativeType;
    private final String schemaTypeName;
    private final PackageTemplateData packageData;
}
