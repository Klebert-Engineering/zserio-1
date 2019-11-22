package templates.instantiate_imported_nested;

import templates.instantiate_imported_nested.pkg.*;

struct Nested<T>
{
    T value;
};

struct Test<T>
{
    Nested<T> value;
};
