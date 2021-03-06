package zserio.emit.doc;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import zserio.ast.Root;
import zserio.ast.SqlDatabaseType;
import zserio.emit.common.ZserioEmitException;
import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateException;

/**
 * Emits the DOT file with overview of all databases and tables with connections.
 */
public class DbOverviewDotEmitter extends DefaultDocEmitter
{
    /**
     * Creates an instance of the Database Overview Dot emitter.
     *
     * @param docPath              Path to the root of generated documentation.
     * @param dotLinksPrefix       Prefix for doc links or null to use links to locally generated doc.
     * @param withSvgDiagrams True to enable dot files conversion to svg format.
     * @param dotExecutable        Dot executable to use for conversion or null to use dot exe on path.
     */
    public DbOverviewDotEmitter(String docPath, String dotLinksPrefix, boolean withSvgDiagrams,
                                String dotExecutable)
    {
        databases = new ArrayList<SqlDatabaseType>();
        this.docPath = docPath;
        this.dotLinksPrefix = (dotLinksPrefix == null) ? ".." : dotLinksPrefix;
        this.withSvgDiagrams = withSvgDiagrams;
        this.dotExecutable = dotExecutable;
    }

    @Override
    public void beginSqlDatabase(SqlDatabaseType sqlDatabaseType)
    {
        databases.add(sqlDatabaseType);
    }

    @Override
    public void endRoot(Root root) throws ZserioEmitException
    {
        final File outputFile = DocEmitterTools.getDbOverviewDotFile(docPath);
        emit(outputFile);
        if (withSvgDiagrams)
        {
            if (!DotFileConvertor.convertToSvg(dotExecutable, outputFile,
                                               DocEmitterTools.getDbOverviewSvgFile(docPath)))
                throw new ZserioEmitException("Failure to convert '" + outputFile + "' to SVG format!");
        }
    }

    private void emit(File outputFile) throws ZserioEmitException
    {
        try
        {
            Configuration fmConfig = new Configuration(Configuration.VERSION_2_3_28);
            fmConfig.setClassForTemplateLoading(DbOverviewDotEmitter.class, "/freemarker/");

            Template fmTemplate = fmConfig.getTemplate("doc/db_overview.dot.ftl");

            openOutputFile(outputFile);
            fmTemplate.process(new DbOverviewDotTemplateData(databases, dotLinksPrefix), writer);
            writer.close();
        }
        catch (IOException exception)
        {
            throw new ZserioEmitException(exception.getMessage());
        }
        catch (TemplateException exception)
        {
            throw new ZserioEmitException(exception.getMessage());
        }
    }

    private final List<SqlDatabaseType> databases;
    private final String                docPath;
    private final String                dotLinksPrefix;
    private final boolean               withSvgDiagrams;
    private final String                dotExecutable;
}
