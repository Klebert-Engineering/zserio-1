package zserio.emit.doc;

import java.util.ArrayList;
import java.util.List;

import zserio.ast.ServiceMethod;
import zserio.ast.ServiceType;
import zserio.emit.common.ZserioEmitException;

public class ServiceTemplateData extends DocTemplateData
{
    public ServiceTemplateData(TemplateDataContext context, ServiceType serviceType) throws ZserioEmitException
    {
        super(context, serviceType, serviceType.getName());

        packageName = serviceType.getPackage().getPackageName().toString();
        for (ServiceMethod method : serviceType.getMethodList())
            methodList.add(new MethodTemplateData(context, serviceType, method));
    }

    public String getPackageName()
    {
        return packageName;
    }

    public Iterable<MethodTemplateData> getMethodList()
    {
        return methodList;
    }

    public static class MethodTemplateData
    {
        public MethodTemplateData(TemplateDataContext context, ServiceType serviceType,
                ServiceMethod serviceMethod) throws ZserioEmitException
        {
            name = serviceMethod.getName();
            anchorName = DocEmitterTools.getAnchorName(serviceType, name);
            requestSymbol = SymbolTemplateDataCreator.createData(context, serviceMethod.getRequestType());
            responseSymbol = SymbolTemplateDataCreator.createData(context, serviceMethod.getResponseType());
            docComments = new DocCommentsTemplateData(context, serviceMethod.getDocComments());
        }

        public String getName()
        {
            return name;
        }

        public String getAnchorName()
        {
            return anchorName;
        }

        public SymbolTemplateData getRequestSymbol()
        {
            return requestSymbol;
        }

        public SymbolTemplateData getResponseSymbol()
        {
            return responseSymbol;
        }

        public DocCommentsTemplateData getDocComments()
        {
            return docComments;
        }

        private final String name;
        private final String anchorName;
        private final SymbolTemplateData requestSymbol;
        private final SymbolTemplateData responseSymbol;
        private final DocCommentsTemplateData docComments;
    }

    private final String packageName;
    private final List<MethodTemplateData> methodList = new ArrayList<MethodTemplateData>();
}
