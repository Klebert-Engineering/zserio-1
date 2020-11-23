<#ftl output_format="HTML">
<#include "doc_comment.inc.ftl">
<#include "compound.inc.ftl">
<#include "code.inc.ftl">
<#include "usedby.inc.ftl">
<#include "svg_diagram.inc.ftl">
<#assign indent = 5>
<#assign I>${""?left_pad(indent * 2)}</#assign>
<#assign structureHeading>
    <i>Structure</i><#if templateParameters?has_content> template</#if> ${symbol.name}<#t>
</#assign>

${I}<h2 class="anchor" id="${symbol.htmlLink.htmlAnchor}">
<#if docComments.isDeprecated>
${I}  <span class="deprecated">(deprecated) </span>
${I}  <del>${structureHeading}</del>
<#else>
${I}  ${structureHeading}
</#if>
${I}</h2>
    <@doc_comments docComments, indent, false/>

    <@code_table_begin indent/>
<#assign columnCount=(fields?has_content)?then(3, (functions?has_content)?then(2, 1))/>
${I}  <tr><td colspan=${columnCount}>struct ${symbol.name}<@compound_template_parameters templateParameters/><#rt>
        <#lt><@compound_parameters parameters/></td></tr>
${I}  <tr><td colspan=${columnCount}>{</td></tr>
      <@compound_fields fields, columnCount, indent+1/>
<#if functions?has_content>
    <#if fields?has_content>
${I}  <tr><td colspan=${columnCount}>&nbsp;</td></tr>
    </#if>
      <@compound_functions functions, columnCount, indent+1/>
</#if>
${I}  <tr><td colspan=${columnCount}>};</td></tr>
    <@code_table_end indent/>
    <@compound_member_details symbol, fields, indent/>
    <@compound_function_details symbol, functions, indent/>
    <@used_by symbol, usedBySymbols, indent/>
<#if collaborationDiagramSvg??>

    <@collaboration_diagram symbol, collaborationDiagramSvg, indent/>
</#if>
