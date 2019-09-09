<#include "FileHeader.inc.ftl">
<@file_header generatorDescription/>
<@system_includes cppSystemIncludes, false/>
#include "<@include_path package.path, "${name}.h"/>"
#include <zserio/UrlClient.h>
<@user_includes cppUserIncludes, false/>

<@namespace_begin package.path/>
${name}::${name}(const std::string& host): host_(host)
{}
<#list rpcList as rpc>
void ${name}::${rpc.name}(const ${rpc.requestTypeFullName}& request, ${rpc.responseTypeFullName}& response) 
{
    std::string uri = host_ + "/${rpc.name}";
    <#list rpc.requestFieldNames  as name>
    uri += "/" + zserio::to_string(request.get${name[0]?upper_case}${name[1..]}());
    </#list>
    zserio::UrlClient client;
    auto data = client.fetchResource(uri);
    zserio::BitStreamReader reader(static_cast<uint8_t*>(data.data()), data.size());
    response.read(reader);
}
</#list>
<@namespace_end package.path/>

