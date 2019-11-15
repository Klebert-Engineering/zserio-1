package zserio.emit.java;

import zserio.ast.EnumItem;
import zserio.ast.EnumType;
import zserio.emit.common.ZserioEmitException;
import zserio.emit.java.types.JavaNativeType;

/**
 * Formatting policy for Java expressions.
 *
 * This policy does work for everything except for case labels.
 */
public class JavaExpressionFormattingPolicy extends JavaDefaultExpressionFormattingPolicy
{
    public JavaExpressionFormattingPolicy(JavaNativeMapper javaNativeMapper)
    {
        super(javaNativeMapper);
    }

    @Override
    protected String getIdentifierForTypeEnum(EnumType resolvedType, JavaNativeMapper javaNativeMapper)
            throws ZserioEmitException
    {
        final JavaNativeType javaType = javaNativeMapper.getJavaType(resolvedType);

        return javaType.getFullName();
    }

    @Override
    protected String getIdentifierForEnumItem(EnumItem enumItem)
    {
        return enumItem.getName();
    }

    @Override
    protected String getDotSeparatorForEnumItem()
    {
        return ".";
    }

    @Override
    protected String getAccessPrefixForCompoundType()
    {
        return "";
    }
}
