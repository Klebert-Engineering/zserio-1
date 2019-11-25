<#include "FileHeader.inc.ftl">

<@file_header generatorDescription/>
// INFO This is just a PoC - there is not yet any 
// error/status handling reflected in the generated interfaces

<@include_guard_begin package.path, name/>

<@user_includes headerUserIncludes, true/>
<@namespace_begin package.path/>

class ${name}
{
public:
    virtual ~${name}() = default;

    static constexpr char const* service_full_name()
    {
        return "<#if package.name?has_content>${package.name}.</#if>${name}";
    }

<#list rpcList as rpc>
    virtual void ${rpc.name}(const ${rpc.requestTypeFullName}& request, ${rpc.responseTypeFullName}& response) = 0;
</#list>
};

<@namespace_end package.path/>

<@include_guard_end package.path, name/>

