package zserio.emit.cpp;

import java.util.Set;
import java.util.TreeSet;

import zserio.ast.CompoundType;
import zserio.ast.Rpc;
import zserio.ast.ServiceType;
import zserio.emit.common.ZserioEmitException;
import zserio.tools.Parameters;

public class ServiceEmitter extends CppDefaultEmitter
{
    public ServiceEmitter(String outPathName, Parameters extensionParameters)
    {
        super(outPathName, extensionParameters);
    }

    @Override
    public void beginService(ServiceType serviceType) throws ZserioEmitException
    {
        if (!getWithGrpcCode() && !getWithUriServiceCode())
            return;

        generateServiceInterface(serviceType);

        if (getWithUriServiceCode())
            generateUriServiceSources(serviceType);

        if (getWithGrpcCode())
            generateGrpcServiceSources(serviceType);
    }

    class ServiceInterfaceTemplateData extends ServiceEmitterTemplateData
    {
        public ServiceInterfaceTemplateData(TemplateDataContext context, ServiceType serviceType)
                throws ZserioEmitException
        {
            super(context, serviceType);
        }

        @Override
        public String getName() { return "I" + super.getName(); }
    }

    private void generateServiceInterface(ServiceType serviceType) throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        final ServiceEmitterTemplateData templateData =
            new ServiceInterfaceTemplateData(templateDataContext, serviceType);
        processHeaderTemplate(TEMPLATE_ISERVICE_SOURCE_NAME, templateData, serviceType.getPackage().getPackageName(), templateData.getName());
    }

    private void generateGrpcServiceSources(ServiceType serviceType) throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        final ServiceEmitterTemplateData templateData =
            new ServiceEmitterTemplateData(templateDataContext, serviceType);
        processSourceTemplate(TEMPLATE_GRPC_SOURCE_NAME, templateData, serviceType);
        processHeaderTemplate(TEMPLATE_GRPC_HEADER_NAME, templateData, serviceType);

        addRpcTypes(serviceType.getRpcList());
    }

    public Set<CompoundType> getRpcTypes()
    {
        return rpcTypes;
    }

    private void addRpcTypes(Iterable<Rpc> rpcList)
    {
        for (Rpc rpc : rpcList)
        {
            rpcTypes.add(rpc.getRequestType());
            rpcTypes.add(rpc.getResponseType());
        }
    }

    private void generateUriServiceSources(ServiceType serviceType)
    {
        // TODO
    }

    private static final String TEMPLATE_ISERVICE_SOURCE_NAME = "IService.h.ftl";
    private static final String TEMPLATE_GRPC_SOURCE_NAME = "Service.cpp.ftl";
    private static final String TEMPLATE_GRPC_HEADER_NAME = "Service.h.ftl";
    private static final String TRAITS_TEMPLATE_HEADER_NAME = "GrpcSerializationTraits.h.ftl";
    private static final String TRAITS_OUTPUT_FILE_NAME_ROOT = "GrpcSerializationTraits";
	
	private final Set<CompoundType> rpcTypes = new TreeSet<CompoundType>();
}
