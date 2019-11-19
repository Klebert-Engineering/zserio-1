package zserio.emit.python;

import java.util.ArrayList;
import java.util.List;

import zserio.ast.Rpc;
import zserio.ast.ServiceType;
import zserio.ast.ZserioType;
import zserio.emit.common.ZserioEmitException;
import zserio.emit.python.types.PythonNativeType;

public final class ServiceEmitterTemplateData extends UserTypeTemplateData
{
    public ServiceEmitterTemplateData(TemplateDataContext context, ServiceType serviceType)
            throws ZserioEmitException
    {
        super(context, serviceType);

        final PythonNativeMapper pythonTypeMapper = context.getPythonNativeMapper();

        final PythonNativeType nativeServiceType = pythonTypeMapper.getPythonType(serviceType);
        // keep Zserio default formatting to ensure that all languages have same name of rpc methods
        servicePackageName = nativeServiceType.getPackageName().toString();

        final Iterable<Rpc> rpcList = serviceType.getRpcList();
        for (Rpc rpc : rpcList)
        {
            final RpcTemplateData templateData = new RpcTemplateData(pythonTypeMapper, rpc, this);
            this.rpcList.add(templateData);
        }

        importPackage("zserio");
        importPackage("grpc");
    }

    public String getServicePackageName()
    {
        return servicePackageName;
    }

    public Iterable<RpcTemplateData> getRpcList()
    {
        return rpcList;
    }

    public static class RpcTemplateData
    {
        public RpcTemplateData(PythonNativeMapper typeMapper, Rpc rpc, ImportCollector importCollector)
                throws ZserioEmitException
        {
            name = rpc.getName();

            final ZserioType responseType = rpc.getResponseType();
            final PythonNativeType pythonResponseType = typeMapper.getPythonType(responseType);
            importCollector.importType(pythonResponseType);
            responseTypeFullName = pythonResponseType.getFullName();
            responseStreaming = rpc.hasResponseStreaming() ? "stream" : "unary";

            final ZserioType requestType = rpc.getRequestType();
            final PythonNativeType pythonRequestType = typeMapper.getPythonType(requestType);
            importCollector.importType(pythonRequestType);
            requestTypeFullName = pythonRequestType.getFullName();
            requestStreaming = rpc.hasRequestStreaming() ? "stream" : "unary";
        }

        public String getName()
        {
            return name;
        }

        public String getResponseTypeFullName()
        {
            return responseTypeFullName;
        }

        public String getRequestTypeFullName()
        {
            return requestTypeFullName;
        }

        public String getRequestStreaming()
        {
            return requestStreaming;
        }

        public String getResponseStreaming()
        {
            return responseStreaming;
        }

        private final String name;
        private final String responseTypeFullName;
        private final String responseStreaming;
        private final String requestTypeFullName;
        private final String requestStreaming;
    }

    private final String servicePackageName;
    private final List<RpcTemplateData> rpcList = new ArrayList<RpcTemplateData>();
}
