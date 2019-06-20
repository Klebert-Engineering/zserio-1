package zserio.emit.cpp;

import java.util.ArrayList;
import java.util.List;

import zserio.ast.ZserioType;
import zserio.ast.Field;
import zserio.ast.SqlDatabaseType;
import zserio.ast.SqlTableType;
import zserio.ast.TypeReference;
import zserio.emit.common.ZserioEmitException;
import zserio.emit.cpp.types.CppNativeType;

public class SqlDatabaseEmitterTemplateData extends UserTypeTemplateData
{
    public SqlDatabaseEmitterTemplateData(TemplateDataContext context, SqlDatabaseType databaseType)
            throws ZserioEmitException
    {
        super(context, databaseType);

        final CppNativeTypeMapper cppNativeTypeMapper = context.getCppNativeTypeMapper();
        final List<Field> dbFields = databaseType.getFields();
        fields = new ArrayList<DatabaseField>(dbFields.size());
        for (Field dbField : dbFields)
            fields.add(new DatabaseField(cppNativeTypeMapper, dbField, this));
    }

    public Iterable<DatabaseField> getFields()
    {
        return fields;
    }

    public static class DatabaseField
    {
        public DatabaseField(CppNativeTypeMapper cppNativeTypeMapper, Field field,
                IncludeCollector includeCollector) throws ZserioEmitException
        {
            final CppNativeType nativeFieldType = cppNativeTypeMapper.getCppType(field.getFieldType());
            includeCollector.addHeaderIncludesForType(nativeFieldType);

            name = field.getName();
            cppTypeName = nativeFieldType.getFullName();
            getterName = AccessorNameFormatter.getGetterName(field);
            final ZserioType fieldBaseType = TypeReference.resolveBaseType(field.getFieldType());
            isWithoutRowIdTable = (fieldBaseType instanceof SqlTableType) ?
                    ((SqlTableType)fieldBaseType).isWithoutRowId() : false;
        }

        public String getName()
        {
            return name;
        }

        public String getCppTypeName()
        {
            return cppTypeName;
        }

        public String getGetterName()
        {
            return getterName;
        }

        public boolean getIsWithoutRowIdTable()
        {
            return isWithoutRowIdTable;
        }

        private final String  name;
        private final String  cppTypeName;
        private final String  getterName;
        private final boolean isWithoutRowIdTable;
    }

    private final List<DatabaseField> fields;
}
