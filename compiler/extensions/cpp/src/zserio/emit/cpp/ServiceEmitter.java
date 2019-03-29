package zserio.emit.cpp;

import java.util.ArrayList;
import java.util.List;
import zserio.ast.Root;
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
        serviceTypes.add(serviceType);
    }

    @Override
    public void endRoot(Root root) throws ZserioEmitException
    {
        if (serviceTypes.isEmpty() || (!getWithGrpcCode() && !getWithUriServiceCode()))
            return;

        generateServiceInterface();

        if (getWithUriServiceCode()) {
            // TODO Generate factory also when gRPC service is generated
            // as soon as factory actually supports gRPC based services
            generateServiceFactory();
            generateUriServiceSources();
        }

        if (getWithGrpcCode())
            generateGrpcServiceSources();
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

    private void generateServiceInterface() throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        for (ServiceType serviceType : serviceTypes)
        {
            final ServiceEmitterTemplateData templateData =
                    new ServiceInterfaceTemplateData(templateDataContext, serviceType);
            processHeaderTemplate(TEMPLATE_ISERVICE_SOURCE_NAME, templateData, serviceType, templateData.getName());
        }
    }

    private void generateGrpcServiceSources() throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        for (ServiceType serviceType : serviceTypes)
        {
            final ServiceEmitterTemplateData templateData =
                    new ServiceEmitterTemplateData(templateDataContext, serviceType);
            processSourceTemplate(TEMPLATE_GRPC_SOURCE_NAME, templateData, serviceType);
            processHeaderTemplate(TEMPLATE_GRPC_HEADER_NAME, templateData, serviceType);
        }

        final GrpcSerializationTraitsTemplateData traitsTemplateData =
                new GrpcSerializationTraitsTemplateData(templateDataContext, serviceTypes);
        processHeaderTemplateToRootDir(TRAITS_TEMPLATE_HEADER_NAME, traitsTemplateData,
                TRAITS_OUTPUT_FILE_NAME_ROOT);

    }

    private void generateUriServiceSources() throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        for (ServiceType serviceType : serviceTypes)
        {
            final ServiceEmitterTemplateData templateData =
                    new UriServiceTemplateData(templateDataContext, serviceType);
            processSourceTemplate(TEMPLATE_URI_SOURCE_NAME, templateData, serviceType, templateData.getName());
            processHeaderTemplate(TEMPLATE_URI_HEADER_NAME, templateData, serviceType, templateData.getName());
        }
    }

    private void generateServiceFactory() throws ZserioEmitException
    {
        final TemplateDataContext templateDataContext = getTemplateDataContext();
        for (ServiceType serviceType : serviceTypes)
        {
            final ServiceFactoryTemplateData templateData =
                    new ServiceFactoryTemplateData(templateDataContext, serviceType);
            processSourceTemplate(TEMPLATE_SERVICE_FACTORY_SOURCE_NAME,  templateData, serviceType, templateData.getName());
            processHeaderTemplate(TEMPLATE_SERVICE_FACTORY_HEADER_NAME, templateData, serviceType, templateData.getName());
        }
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

    private final List<ServiceType> serviceTypes = new ArrayList<ServiceType>();
}
