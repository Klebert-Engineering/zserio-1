<#include "FileHeader.inc.ftl"/>
<@file_header generatorDescription/>
<@all_imports packageImports symbolImports typeImports/>

class Service(zserio.ServiceInterface):
    def __init__(self) -> None:
        self._methodMap = {
<#list methodList as method>
            "${method.name}": self._${method.name}Method<#if method?has_next>,</#if>
</#list>
        }

    def call_method(self, method_name: str, request_data: bytes, context: typing.Any = None) -> bytes:
        method = self._methodMap.get(method_name)
        if not method:
            raise zserio.ServiceException("${serviceFullName}: Method '%s' does not exist!" % method_name)
        return method(request_data, context)
<#list methodList as method>

    def _${method.name}Impl(self, request: ${method.requestTypeFullName}, context: typing.Any = None) -> ${method.responseTypeFullName}:
        raise NotImplementedError()
</#list>
<#list methodList as method>

    def _${method.name}Method(self, requestData: bytes, context: typing.Any) -> bytes:
        reader = zserio.BitStreamReader(requestData)
        request = ${method.requestTypeFullName}.fromReader(reader)

        response = self._${method.name}Impl(request, context)

        writer = zserio.BitStreamWriter()
        response.write(writer)
        return writer.byte_array
</#list>

    SERVICE_FULL_NAME = "${serviceFullName}"
    METHOD_NAMES = [
<#list methodList as method>
        "${method.name}"<#if method?has_next>,</#if>
</#list>
    ]

class Client:
    def __init__(self, service: zserio.ServiceInterface) -> None:
        self._service = service
<#list methodList as method>

    def ${method.name}Method(self, request: ${method.requestTypeFullName}, context: typing.Any = None) -> ${method.responseTypeFullName}:
        writer = zserio.BitStreamWriter()
        request.write(writer)
        requestData = writer.byte_array

        responseData = self._service.call_method("${method.name}", requestData, context)

        reader = zserio.BitStreamReader(responseData)
        response = ${method.responseTypeFullName}.fromReader(reader)
        return response
</#list>
