package zserio.extension.python.types;

/**
 * Native Python array type mapping for integral types with fixed bit size.
 */
public class NativeFixedSizeIntArrayType extends NativeArrayType
{
    public NativeFixedSizeIntArrayType(String traitsName)
    {
        super(traitsName, true, false);
    }
}
