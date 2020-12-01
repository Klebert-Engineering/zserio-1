<#ftl output_format="HTML">
<#include "doc_comment.inc.ftl">
<#include "code.inc.ftl">
<#include "symbol.inc.ftl">
<#include "usedby.inc.ftl">
<#include "svg_diagram.inc.ftl">
<#assign indent = 5>
<#assign I>${""?left_pad(indent * 2)}</#assign>

${I}<h2 class="anchor" id="${symbol.htmlLink.htmlAnchor}">
${I}  <span<#if docComments.isDeprecated> class="deprecated"</#if>>Bitmask ${symbol.name}</span>
${I}</h2>
    <@doc_comments docComments, indent/>

    <@code_table_begin indent/>
${I}  <thead>
${I}    <tr><td colspan=2>
${I}      bitmask <@symbol_reference typeSymbol/> ${symbol.name}
          <@doc_button indent+2/>
${I}    </td></tr>
${I}    <tr><td colspan=2>{</td></tr>
${I}  </thead>
<#list values as value>
${I}  <tbody class="anchor-group" id="${value.symbol.htmlLink.htmlAnchor}">
    <#if value.docComments.commentsList?has_content>
${I}    <tr class="doc"><td colspan=2 class="indent">
          <@doc_comments value.docComments, indent+3, true/>
${I}    </td></tr>
    </#if>
${I}    <tr>
${I}      <td class="indent"><@symbol_reference value.symbol/></td>
${I}      <td class="value-expression">= ${value.value}<#if value_has_next>,</#if></td>
${I}    </tr>
${I}  </tbody>
</#list>
${I}  <tfoot>
${I}    <tr><td colspan=2>};</td></tr>
${I}  </tfoot>
    <@code_table_end indent/>
    <@used_by symbol, usedBySymbols, indent/>
<#if collaborationDiagramSvgUrl??>

    <@collaboration_diagram symbol, collaborationDiagramSvgUrl, indent/>
</#if>
