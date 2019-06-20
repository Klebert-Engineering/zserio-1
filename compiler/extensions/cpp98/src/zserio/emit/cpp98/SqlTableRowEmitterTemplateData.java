package zserio.emit.cpp;

import java.util.ArrayList;
import java.util.List;

import zserio.ast.ZserioType;
import zserio.ast.Field;
import zserio.ast.SqlTableType;
import zserio.emit.common.ZserioEmitException;
import zserio.emit.cpp.types.CppNativeType;

public class SqlTableRowEmitterTemplateData extends CppTemplateData
{
    public SqlTableRowEmitterTemplateData(TemplateDataContext context, SqlTableType tableType,
            String tableRowName) throws ZserioEmitException
    {
        super(context);

        name = tableRowName;

        final CppNativeTypeMapper cppNativeTypeMapper = context.getCppNativeTypeMapper();
        final CppNativeType nativeType = cppNativeTypeMapper.getCppType(tableType);
        packageData = new PackageTemplateData(nativeType);

        final List<Field> tableFields = tableType.getFields();
        fields = new ArrayList<FieldTemplateData>(tableFields.size());
        for (Field tableField : tableFields)
        {
            final FieldTemplateData field = new FieldTemplateData(cppNativeTypeMapper, tableField, this);
            fields.add(field);
        }
    }

    public String getName()
    {
        return name;
    }

    public PackageTemplateData getPackage()
    {
        return packageData;
    }

    public Iterable<FieldTemplateData> getFields()
    {
        return fields;
    }

    public static class FieldTemplateData
    {
        public FieldTemplateData(CppNativeTypeMapper cppNativeTypeMapper, Field field,
                IncludeCollector includeCollector) throws ZserioEmitException
        {
            final ZserioType fieldType = field.getFieldType();
            final CppNativeType nativeFieldType = cppNativeTypeMapper.getCppType(fieldType);
            includeCollector.addHeaderIncludesForType(nativeFieldType);

            name = field.getName();
            cppTypeName = nativeFieldType.getFullName();
            cppArgumentTypeName = nativeFieldType.getArgumentTypeName();
            isSimpleType = nativeFieldType.isSimpleType();
        }

        public String getName()
        {
            return name;
        }

        public String getCppTypeName()
        {
            return cppTypeName;
        }

        public String getCppArgumentTypeName()
        {
            return cppArgumentTypeName;
        }

        public boolean getIsSimpleType()
        {
            return isSimpleType;
        }

        private final String name;
        private final String cppTypeName;
        private final String cppArgumentTypeName;
        private final boolean isSimpleType;
    }

    private final String name;
    private final PackageTemplateData packageData;
    private final List<FieldTemplateData> fields;
}
