<#include "FileHeader.inc.ftl">
<#include "ServiceFactory.inc.ftl">
<@file_header generatorDescription/>
<@system_includes cppSystemIncludes/>
<#assign uri_srv_nam><@uri_service_name name/></#assign>
<@user_include package.path, "${uri_srv_nam}.h"/>
<@user_include package.path, "${name}.h"/>
<@user_includes cppUserIncludes, false/>

<@namespace_begin package.path/>
std::unique_ptr<<@service_interface_name name/>> ${name}::createService(const std::string& host)
{
    // TODO Add support for gRPC and add cfg that allows to identify if 
    // URI based service or gRPC service should be generated
    return std::unique_ptr<${uri_srv_nam}>(new ${uri_srv_nam}(host));
}
<@namespace_end package.path/>
