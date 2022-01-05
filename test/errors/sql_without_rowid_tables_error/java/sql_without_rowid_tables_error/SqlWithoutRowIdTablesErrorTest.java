package sql_without_rowid_tables_error;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import java.io.IOException;

import test_utils.ZserioErrors;

public class SqlWithoutRowIdTablesErrorTest
{
    @BeforeAll
    public static void readZserioErrors() throws IOException
    {
        zserioErrors = new ZserioErrors();
    }

    @Test
    public void noPrimaryKeyColumn()
    {
        final String error = "no_primary_key_column_error.zs:4:11: " +
                "No primary key in without rowid table 'WrongWithoutRowIdTable'!";
        assertTrue(zserioErrors.isPresent(error));
    }

    private static ZserioErrors zserioErrors;
}
