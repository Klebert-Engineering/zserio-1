<#include "FileHeader.inc.ftl">
<@file_header generatorDescription/>

<@include_guard_begin package.path, name/>
<@user_includes headerUserIncludes, true/>
// TODO Generate these includes instead of listing them explicitely
#include "${name?replace("Uri_", "I")}.h"
#include <string>
<@namespace_begin package.path/>

class ${name}: public ${name?replace("Uri_", "I")} 
{
public:
    ${name}(const std::string& host);
<#list rpcList as rpc>
    void ${rpc.name}(const ${rpc.requestTypeFullName}& request, ${rpc.responseTypeFullName}& response) override;
</#list>
private: 
    std::string host_;
};

<@namespace_end package.path/>
<@include_guard_end package.path, name/>

