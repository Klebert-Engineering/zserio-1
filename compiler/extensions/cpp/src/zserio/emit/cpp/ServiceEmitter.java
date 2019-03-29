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

        if (getWithUriServiceCode()) {
            // TODO Generate factory also when gRPC service is generated
            // as soon as factory actually supports gRPC based services
        	generateServiceFactory(serviceType);
            generateUriServiceSources(serviceType);
        }

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

    class UriServiceTemplateData extends ServiceEmitterTemplateData
    {
        public UriServiceTemplateData(TemplateDataContext context, ServiceType serviceType)
                throws ZserioEmitException
        {
            super(context, serviceType);
        }

        @Override
        public String getName() { return "Uri_" + super.getName(); }
    }

    class ServiceFactoryTemplateData extends ServiceEmitterTemplateData
    {
        public ServiceFactoryTemplateData(TemplateDataContext context, ServiceType serviceType) throws ZserioEmitException
        {
            super(context, serviceType);
        }

        @Override
        public String getName() {
            return super.getName() + "Factory";
        }
    }

    private void generateServiceInterface(ServiceType serviceType) throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        final ServiceEmitterTemplateData templateData =
            new ServiceInterfaceTemplateData(templateDataContext, serviceType);
        processHeaderTemplate(TEMPLATE_ISERVICE_SOURCE_NAME, templateData, serviceType);
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

    private void generateUriServiceSources(ServiceType serviceType) throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        final ServiceEmitterTemplateData templateData =
            new UriServiceTemplateData(templateDataContext, serviceType);
        processSourceTemplate(TEMPLATE_URI_SOURCE_NAME, templateData, serviceType);
        processHeaderTemplate(TEMPLATE_URI_HEADER_NAME, templateData, serviceType);
    }

    private void generateServiceFactory(ServiceType serviceType) throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        final ServiceFactoryTemplateData templateData =
			new ServiceFactoryTemplateData(templateDataContext, serviceType);
        processSourceTemplate(TEMPLATE_SERVICE_FACTORY_SOURCE_NAME,  templateData, serviceType);
        processHeaderTemplate(TEMPLATE_SERVICE_FACTORY_HEADER_NAME, templateData, serviceType);
    }

    private static final String TEMPLATE_ISERVICE_SOURCE_NAME = "IService.h.ftl";

    private static final String TEMPLATE_SERVICE_FACTORY_SOURCE_NAME = "ServiceFactory.cpp.ftl";
    private static final String TEMPLATE_SERVICE_FACTORY_HEADER_NAME = "ServiceFactory.h.ftl";
    private static final String TEMPLATE_URI_SOURCE_NAME = "UriService.cpp.ftl";
    private static final String TEMPLATE_URI_HEADER_NAME = "UriService.h.ftl";

    private static final String TEMPLATE_GRPC_SOURCE_NAME = "Service.cpp.ftl";
    private static final String TEMPLATE_GRPC_HEADER_NAME = "Service.h.ftl";
    private static final String TRAITS_TEMPLATE_HEADER_NAME = "GrpcSerializationTraits.h.ftl";
    private static final String TRAITS_OUTPUT_FILE_NAME_ROOT = "GrpcSerializationTraits";
	
	private final Set<CompoundType> rpcTypes = new TreeSet<CompoundType>();
}
