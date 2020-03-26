package sql_tables.subtyped_table;

struct Student
{
    uint16      identifier;
    string      name;
};

sql_table TestTable
{
    int32       id sql "PRIMARY KEY NOT NULL";
    Student     student;
};

subtype TestTable SubtypedTable;
