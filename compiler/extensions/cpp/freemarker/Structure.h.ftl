<#include "FileHeader.inc.ftl">
<#include "CompoundConstructor.inc.ftl">
<#include "CompoundParameter.inc.ftl">
<#include "CompoundField.inc.ftl">
<#include "CompoundFunction.inc.ftl">
<@file_header generatorDescription/>

<@include_guard_begin package.path, name/>

#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/BitFieldUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/StringConvertUtil.h>
#include <zserio/PreWriteAction.h>
<#if withInspectorCode>
#include <zserio/inspector/BlobInspectorTree.h>
</#if>
<@system_includes headerSystemIncludes, false/>
<#if hasExternals>
#include <functional>
</#if>

<@user_includes headerUserIncludes, true/>
<@namespace_begin package.path/>

class ${name}
{
public:
<#if withWriterCode>
    <@compound_constructor_declaration compoundConstructorsData/>
</#if>
    <@compound_read_constructor_declaration compoundConstructorsData/>
<#if withInspectorCode>
    <@compound_read_tree_constructor_declaration compoundConstructorsData/>
</#if>
<#if needs_compound_initialization(compoundConstructorsData) || has_field_with_initialization(fieldList)>

    <@compound_copy_constructor_declaration compoundConstructorsData/>
    <@compound_assignment_operator_declaration compoundConstructorsData/>
</#if>
<#if hasExternals>

    ~${name}();
</#if>
<#if needs_compound_initialization(compoundConstructorsData) || needsChildrenInitialization>

    <#if needs_compound_initialization(compoundConstructorsData)>
    <@compound_initialize_declaration compoundConstructorsData/>
    </#if>
    <#if needsChildrenInitialization>
    <@compound_initialize_children_declaration/>
    </#if>
</#if>

    <@compound_parameter_accessors_declaration compoundParametersData/>
<#list fieldList as field>
<#if field.isComplexExternal>
    <@compound_external_field_accessors_declaration field/>
<#else>
    <@compound_field_accessors_declaration field/>
    <#if field.optional??>
    bool ${field.optional.indicatorName}() const;
    </#if>
</#if>

</#list>
    <@compound_functions_declaration compoundFunctionsData/>
    size_t bitSizeOf(size_t _bitPosition = 0) const;
<#if withWriterCode>
    size_t initializeOffsets(size_t _bitPosition);
</#if>

    bool operator==(const ${name}& other) const;
    int hashCode() const;

    void read(zserio::BitStreamReader& _in);
<#if withInspectorCode>
    void read(const zserio::BlobInspectorTree& _tree);
</#if>
<#if withWriterCode>
    void write(zserio::BitStreamWriter& _out,
            zserio::PreWriteAction _preWriteAction = zserio::ALL_PRE_WRITE_ACTIONS);
</#if>
<#if withInspectorCode>
    void write(zserio::BitStreamWriter& _out, zserio::BlobInspectorTree& _tree,
            zserio::PreWriteAction _preWriteAction = zserio::ALL_PRE_WRITE_ACTIONS);
</#if>

private:
<#if has_field_with_constraint(fieldList)>
    void checkConstraints();
</#if>
<#if withRangeCheckCode && has_field_with_range_check(fieldList)>
    void checkRanges();
</#if>
<#if has_field_with_constraint(fieldList) || (withRangeCheckCode && has_field_with_range_check(fieldList))>

</#if>
    <@compound_parameter_members compoundParametersData/>
    <@compound_constructor_members compoundConstructorsData/>
<#list fieldList as field>

<#if field.isComplexExternal>
    size_t m_${field.name}_SIZE = uint64_t();
    uint8_t* m_${field.name}_BUFFER = nullptr;
    std::function<void(zserio::BitStreamWriter&, zserio::PreWriteAction)> m_${field.name}_WRITER = nullptr;
    std::function<void(zserio::BitStreamReader&)> m_${field.name}_READER = nullptr;
    std::function<size_t(size_t)> m_${field.name}_BITSIZEOF = nullptr;
    std::function<size_t(size_t)> m_${field.name}_INITIALIZEOFFSET = nullptr;
<#if field.externalParameters?has_content>
    std::function<void(<#rt>
<#list field.externalParameters as parameter><#t>
${parameter.cppType} ${parameter.name}<#if parameter_has_next>, </#if><#t>
</#list>)> m_${field.name}_INITIALIZE = nullptr;
</#if>
 <#else>
    <#if field.optionalHolder??>${field.optionalHolder.cppTypeName}<#else>${field.cppTypeName}</#if> m_${field.name};
 </#if>
</#list>
};

<@namespace_end package.path/>

<@include_guard_end package.path, name/>
