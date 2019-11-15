package zserio.emit.python;

import java.util.Set;
import java.util.TreeSet;
import java.util.List;
import java.util.ArrayList;

import zserio.ast.PackageName;
import zserio.ast.ZserioType;

public class ApiEmitterTemplateData extends PythonTemplateData
{
    public ApiEmitterTemplateData(TemplateDataContext context, PackageName packageName)
    {
        super(context);
        this.packageName = packageName;
    }

    public PackageName getPackageName()
    {
        return packageName;
    }

    public String getPackagePath()
    {
        return PythonFullNameFormatter.getFullName(packageName);
    }

    public Iterable<String> getSubpackages()
    {
        return subpackages;
    }

    public Iterable<String> getModules()
    {
        return modules;
    }

    public Iterable<String> getSymbols()
    {
        return symbols;
    }

    public Iterable<String> getTypes()
    {
        return types;
    }

    public void addSubpackage(String subpackage)
    {
        subpackages.add(subpackage);
    }

    public void addModule(ZserioType zserioType)
    {
        modules.add(zserioType.getName());
    }

    public void addSymbol(String symbolName)
    {
        symbols.add(symbolName);
    }

    public void addType(ZserioType zserioType)
    {
        types.add(zserioType.getName());
    }

    final PackageName packageName;
    final Set<String> subpackages = new TreeSet<String>();
    final List<String> modules = new ArrayList<String>();
    final List<String> symbols = new ArrayList<String>();
    final List<String> types = new ArrayList<String>();
}
