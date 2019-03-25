<#include "FileHeader.inc.ftl">
<@file_header generatorDescription/>
<@system_includes cppSystemIncludes/>
<@user_include package.path, "${name}.h"/>
<@user_includes cppUserIncludes, false/>

<@namespace_begin package.path/>
${name}::${name}(const std::string& host): host_(host)
{}
<#list rpcList as rpc>
void ${name}::${rpc.name}(const ${rpc.requestTypeFullName}& request, ${rpc.responseTypeFullName}& response) 
{
  //TODO
}
</#list>
<@namespace_end package.path/>

