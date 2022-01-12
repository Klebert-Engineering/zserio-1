<#include "FileHeader.inc.ftl"/>
<#if withTypeInfoCode>
    <#include "TypeInfo.inc.ftl"/>
</#if>
<@file_header generatorDescription/>
<@future_annotations/>
<@all_imports packageImports symbolImports typeImports/>

class ${name}:
<#if withTypeInfoCode>
    @staticmethod
    def type_info() -> zserio.typeinfo.TypeInfo:
        method_list: typing.List[zserio.typeinfo.MemberInfo] = [
    <#list methodList as method>
            <@member_info_method method method?has_next/>
    </#list>
        ]
        attribute_list = {
            zserio.typeinfo.TypeAttribute.METHODS : method_list
        }

        return zserio.typeinfo.TypeInfo('${schemaTypeName}', ${name}, attributes=attribute_list)

</#if>
    class Service(zserio.ServiceInterface):
        def __init__(self) -> None:
            self._method_map = {
<#list methodList as method>
                self._METHOD_NAMES[${method?index}]: self._${method.snakeCaseName}_method<#if method?has_next>,</#if>
</#list>
            }

        def call_method(self, method_name: str, request_data: bytes, context: typing.Any = None) -> zserio.ServiceData:
            method = self._method_map.get(method_name)
            if not method:
                raise zserio.ServiceException(f"${serviceFullName}: Method '{method_name}' does not exist!")

            return method(request_data, context)

        @property
        def service_full_name(self) -> str:
            return self._SERVICE_FULL_NAME

        @property
        def method_names(self) -> typing.List:
            return self._METHOD_NAMES
<#list methodList as method>

        def _${method.snakeCaseName}_impl(self, request: ${method.requestTypeFullName}, <#rt>
                <#lt>context: typing.Any = None) -> ${method.responseTypeFullName}:
            raise NotImplementedError()
</#list>
<#list methodList as method>

        def _${method.snakeCaseName}_method(self, request_data: bytes, context: typing.Any) -> zserio.ServiceData:
            reader = zserio.BitStreamReader(request_data)
            request = ${method.requestTypeFullName}.from_reader(reader)

            return zserio.ServiceData(self._${method.snakeCaseName}_impl(request, context))
</#list>

        _SERVICE_FULL_NAME = "${serviceFullName}"
        _METHOD_NAMES = [
<#list methodList as method>
            "${method.name}"<#if method?has_next>,</#if>
</#list>
        ]

    class Client:
        def __init__(self, service_client: zserio.ServiceClientInterface) -> None:
            self._service_client = service_client
<#list methodList as method>

        def ${method.clientMethodName}(self, request: ${method.requestTypeFullName}, <#rt>
                <#lt>context: typing.Any = None) -> ${method.responseTypeFullName}:
            response_data = self._service_client.call_method("${method.name}", zserio.ServiceData(request), context)
            reader = zserio.BitStreamReader(response_data)
            response = ${method.responseTypeFullName}.from_reader(reader)

            return response
</#list>
