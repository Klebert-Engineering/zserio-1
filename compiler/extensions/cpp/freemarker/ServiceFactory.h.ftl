<#include "FileHeader.inc.ftl">
<#include "ServiceFactory.inc.ftl">
<@file_header generatorDescription/>

<@include_guard_begin package.path, name/>
<@user_includes headerUserIncludes, true/>
// TODO Generate these includes instead of listing them explicitely
#include "<@service_interface_name name/>.h"
#include <memory>
#include <string>
<@namespace_begin package.path/>

class ${name}
{
public:
    ${name}() = default;
    ~${name}() = default;
    std::unique_ptr<<@service_interface_name name/>> createService(const std::string& host);
};

<@namespace_end package.path/>
<@include_guard_end package.path, name/>


