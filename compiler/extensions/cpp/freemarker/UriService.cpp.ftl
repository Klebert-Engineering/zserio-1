<#include "FileHeader.inc.ftl">
<@file_header generatorDescription/>
<@system_includes cppSystemIncludes/>
#include <zserio/UrlClient.h>
<@user_include package.path, "${name}.h"/>
<@user_includes cppUserIncludes, false/>

namespace std
{
// Just there to support same code for plain number and 
// string fields
std::string to_string(const std::string& str)
{
    return str;
}
}

<@namespace_begin package.path/>
${name}::${name}(const std::string& host): host_(host)
{}
<#list rpcList as rpc>
void ${name}::${rpc.name}(const ${rpc.requestTypeFullName}& request, ${rpc.responseTypeFullName}& response) 
{
    std::string uri = host_;
    <#list rpc.requestFieldNames  as name>
    uri += "/" + std::to_string(request.get${name[0]?upper_case}${name[1..]}());
    </#list>
    zserio::UrlClient client;
    auto data = client.fetchResource(uri);
    zserio::BitStreamReader reader(static_cast<uint8_t*>(data.data()), data.size());
    response.read(reader);
}
</#list>
<@namespace_end package.path/>

