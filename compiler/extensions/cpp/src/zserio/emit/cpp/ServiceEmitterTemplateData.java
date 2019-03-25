package zserio.emit.cpp;

import java.util.List;
import java.util.ArrayList;

import zserio.ast.*;
import zserio.emit.common.ZserioEmitException;
import zserio.emit.cpp.types.CppNativeType;

public class ServiceEmitterTemplateData extends UserTypeTemplateData
{
    public ServiceEmitterTemplateData(TemplateDataContext context, ServiceType serviceType)
            throws ZserioEmitException
    {
        super(context, serviceType);

        final CppNativeTypeMapper cppTypeMapper = context.getCppNativeTypeMapper();
        Iterable<Rpc> rpcList = serviceType.getRpcList();
        for (Rpc rpc : rpcList)
        {
            addHeaderIncludesForType(cppTypeMapper.getCppType(rpc.getResponseType()));
            addHeaderIncludesForType(cppTypeMapper.getCppType(rpc.getRequestType()));
            final RpcTemplateData templateData = new RpcTemplateData(cppTypeMapper, rpc);
            this.rpcList.add(templateData);

            if (templateData.getNoStreaming())
            {
                noStreamingRpcList.add(templateData);
                noOrResponseOnlyStreamingRpcList.add(templateData);
            }
            else if (templateData.getResponseOnlyStreaming())
            {
                responseOnlyStreamingRpcList.add(templateData);
                noOrResponseOnlyStreamingRpcList.add(templateData);
            }
        }
    }

    public Iterable<RpcTemplateData> getRpcList()
    {
        return rpcList;
    }

    public Iterable<RpcTemplateData> getNoStreamingRpcList()
    {
        return noStreamingRpcList;
    }

    public Iterable<RpcTemplateData> getResponseOnlyStreamingRpcList()
    {
        return responseOnlyStreamingRpcList;
    }

    public Iterable<RpcTemplateData> getNoOrResponseOnlyStreamingRpcList()
    {
        return noOrResponseOnlyStreamingRpcList;
    }

    public static class RpcTemplateData
    {
        public RpcTemplateData(CppNativeTypeMapper typeMapper, Rpc rpc) throws ZserioEmitException
        {
            name = rpc.getName();

            final ZserioType responseType = rpc.getResponseType();
            CppNativeType type = typeMapper.getCppType(responseType);
            responseTypeFullName = type.getFullName();
            hasResponseStreaming = rpc.hasResponseStreaming();

            final ZserioType requestType = rpc.getRequestType();
            type = typeMapper.getCppType(requestType);
            requestTypeFullName = type.getFullName();
            hasRequestStreaming = rpc.hasRequestStreaming();

            if (requestType instanceof TypeReference)
            {
               TypeReference tr = (TypeReference)requestType;
               ZserioType t = tr.getReferencedType();
               if (t instanceof CompoundType)
               {
                   CompoundType c = (CompoundType)t;
                   for (Field f: c.getFields())
                   {
                       requestFieldNames.add(f.getName());
                   }
               }
            }

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

        public boolean getNoStreaming()
        {
            return !hasRequestStreaming && !hasResponseStreaming;
        }

        public boolean getRequestOnlyStreaming()
        {
            return hasRequestStreaming && !hasResponseStreaming;
        }

        public boolean getResponseOnlyStreaming()
        {
            return !hasRequestStreaming && hasResponseStreaming;
        }

        public List<String> getRequestFieldNames()
        {
            return requestFieldNames;
        }

        private final String name;
        private final String responseTypeFullName;
        private final List<String> requestFieldNames = new ArrayList<>();
        private final boolean hasResponseStreaming;
        private final String requestTypeFullName;
        private final boolean hasRequestStreaming;
    }

    private final List<RpcTemplateData> rpcList = new ArrayList<RpcTemplateData>();
    private final List<RpcTemplateData> noStreamingRpcList = new ArrayList<RpcTemplateData>();
    private final List<RpcTemplateData> responseOnlyStreamingRpcList = new ArrayList<RpcTemplateData>();
    private final List<RpcTemplateData> noOrResponseOnlyStreamingRpcList = new ArrayList<RpcTemplateData>();
}
