<#macro service_interface_name factory_name>
I${factory_name?replace("Factory", "")}</#macro>

<#macro uri_service_name factory_name>
Uri_${factory_name?replace("Factory", "")}</#macro>
