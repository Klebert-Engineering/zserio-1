package zserio.emit.cpp.types;

import java.math.BigInteger;
import zserio.ast.PackageName;

public class NativeBooleanType extends NativeIntegralType
{
    public NativeBooleanType()
    {
        super(PackageName.EMPTY, "bool");
    }

    @Override
    public BigInteger getLowerBound()
    {
        return BigInteger.ZERO;
    }

    @Override
    public BigInteger getUpperBound()
    {
        return BigInteger.ONE;
    }

    @Override
    public boolean isSigned()
    {
        return false;
    }

    @Override
    public int getBitCount()
    {
        return 1;
    }

    @Override
    public String formatLiteral(String value)
    {
        return formatLiteral(!value.equals("0"));
    }

    public String formatLiteral(boolean value)
    {
        return (value) ? "true" : "false";
    }
}
