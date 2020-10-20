package zserio.emit.java;

import zserio.ast.SqlDatabaseType;
import zserio.emit.common.ZserioEmitException;
import zserio.tools.Parameters;

class SqlDatabaseEmitter extends JavaDefaultEmitter
{
    public SqlDatabaseEmitter(JavaExtensionParameters javaParameters, Parameters extensionParameters)
    {
        super(javaParameters, extensionParameters);
    }

    @Override
    public void beginSqlDatabase(SqlDatabaseType sqlDatabaseType) throws ZserioEmitException
    {
        if (getWithSqlCode())
        {
            final Object templateData = new SqlDatabaseEmitterTemplateData(getTemplateDataContext(),
                    sqlDatabaseType);
            processTemplate(TEMPLATE_NAME, templateData, sqlDatabaseType);
        }
    }

    private static final String TEMPLATE_NAME = "SqlDatabase.java.ftl";
}
