package zserio.emit.cpp.types;
import zserio.ast.PackageName;

public class NativeUnboundTemplateType extends CppNativeType {
    public NativeUnboundTemplateType(String name)
    {
        super(NO_PACKAGE_NAME, name, false);
    }

    private static final PackageName NO_PACKAGE_NAME = new PackageName.Builder().addId("").get();
}
