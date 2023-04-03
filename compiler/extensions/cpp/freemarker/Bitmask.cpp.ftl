<#include "FileHeader.inc.ftl">
<#include "TypeInfo.inc.ftl">
<@file_header generatorDescription/>

#include <zserio/HashCodeUtil.h>
#include <zserio/StringConvertUtil.h>
<#if upperBound??>
#include <zserio/CppRuntimeException.h>
</#if>
<#if withTypeInfoCode>
#include <zserio/TypeInfo.h>
    <#if withReflectionCode>
<@type_includes types.anyHolder/>
<@type_includes types.reflectableFactory/>
    </#if>
</#if>
<@system_includes cppSystemIncludes/>

<@user_include package.path, "${name}.h"/>
<@user_includes cppUserIncludes, false/>
<@namespace_begin package.path/>

<#macro bitmask_array_traits arrayTraits fullName bitSize>
    ${arrayTraits.name}<#t>
    <#if arrayTraits.isTemplated>
            <${fullName}::underlying_type><#t>
    </#if>
    (<#if arrayTraits.requiresElementFixedBitSize>${bitSize.value}</#if>)<#t>
</#macro>
${name}::${name}(::zserio::BitStreamReader& in) :
        m_value(readValue(in))
{}

${name}::${name}(${types.packingContextNode.name}& contextNode, ::zserio::BitStreamReader& in) :
        m_value(readValue(contextNode, in))
{}
<#if upperBound??>

${name}::${name}(underlying_type value) :
        m_value(value)
{
    if (m_value > ${upperBound})
        throw ::zserio::CppRuntimeException("Value for bitmask '${name}' out of bounds: ") << value << "!";
}
</#if>
<#if withTypeInfoCode>

const ${types.typeInfo.name}& ${name}::typeInfo()
{
    using allocator_type = ${types.allocator.default};

    <@underlying_type_info_type_arguments_var "underlyingTypeArguments", bitSize!/>

    <@item_info_array_var "values", values/>

    static const ::zserio::BitmaskTypeInfo<allocator_type> typeInfo = {
        ::zserio::makeStringView("${schemaTypeName}"),
        <@type_info underlyingTypeInfo/>, underlyingTypeArguments, values
    };

    return typeInfo;
}
    <#if withReflectionCode>

${types.reflectablePtr.name} ${name}::reflectable(const ${types.allocator.default}& allocator) const
{
    class Reflectable : public ::zserio::ReflectableBase<${types.allocator.default}>
    {
    public:
        explicit Reflectable(${fullName} bitmask) :
                ::zserio::ReflectableBase<${types.allocator.default}>(${fullName}::typeInfo()),
                m_bitmask(bitmask)
        {}

        size_t bitSizeOf(size_t bitPosition) const override
        {
            return m_bitmask.bitSizeOf(bitPosition);
        }

        void write(::zserio::BitStreamWriter&<#if withWriterCode> writer</#if>) const override
        {
            <#if withWriterCode>
            m_bitmask.write(writer);
            <#else>
            throw ::zserio::CppRuntimeException("Reflectable '${name}': ") <<
                    "Writer code is disabled by -withoutWriterCode zserio option!";
            </#if>
        }

        ${types.anyHolder.name} getAnyValue(const ${types.allocator.default}& allocator) const override
        {
            return ${types.anyHolder.name}(m_bitmask, allocator);
        }

        ${types.anyHolder.name} getAnyValue(const ${types.allocator.default}& allocator) override
        {
            return ${types.anyHolder.name}(m_bitmask, allocator);
        }

        <#-- bitmask is always unsigned -->
        ${underlyingTypeInfo.typeFullName} getUInt${underlyingTypeInfo.typeNumBits}() const override
        {
            return m_bitmask.getValue();
        }

        uint64_t toUInt() const override
        {
            return m_bitmask.getValue();
        }

        double toDouble() const override
        {
            return static_cast<double>(toUInt());
        }

        ${types.string.name} toString(
                const ${types.allocator.default}& allocator = ${types.allocator.default}()) const override
        {
            return m_bitmask.toString(allocator);
        }

    private:
        ${fullName} m_bitmask;
    };

    return ::std::allocate_shared<Reflectable>(allocator, *this);
}
    </#if>
</#if>

void ${name}::createPackingContext(${types.packingContextNode.name}& contextNode)
{
    contextNode.createContext();
}

void ${name}::initPackingContext(${types.packingContextNode.name}& contextNode) const
{
    contextNode.getContext().init(<@bitmask_array_traits underlyingTypeInfo.arrayTraits, fullName, bitSize!/>,
            m_value);
}

size_t ${name}::bitSizeOf(size_t) const
{
<#if runtimeFunction.arg??>
    return ${runtimeFunction.arg};
<#else>
    return ::zserio::bitSizeOf${runtimeFunction.suffix}(m_value);
</#if>
}

size_t ${name}::bitSizeOf(${types.packingContextNode.name}& contextNode, size_t) const
{
    return contextNode.getContext().bitSizeOf(
            <@bitmask_array_traits underlyingTypeInfo.arrayTraits, fullName, bitSize!/>,
            m_value);
}
<#if withWriterCode>

size_t ${name}::initializeOffsets(size_t bitPosition) const
{
    return bitPosition + bitSizeOf(bitPosition);
}

size_t ${name}::initializeOffsets(${types.packingContextNode.name}& contextNode, size_t bitPosition) const
{
    return bitPosition + bitSizeOf(contextNode, bitPosition);
}
</#if>

uint32_t ${name}::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;
    result = ::zserio::calcHashCode(result, m_value);
    return result;
}
<#if withWriterCode>

void ${name}::write(::zserio::BitStreamWriter& out) const
{
    out.write${runtimeFunction.suffix}(m_value<#if runtimeFunction.arg??>, ${runtimeFunction.arg}</#if>);
}

void ${name}::write(${types.packingContextNode.name}& contextNode, ::zserio::BitStreamWriter& out) const
{
    contextNode.getContext().write(
            <@bitmask_array_traits underlyingTypeInfo.arrayTraits, fullName, bitSize!/>,
            out, m_value);
}
</#if>

${types.string.name} ${name}::toString(const ${types.string.name}::allocator_type& allocator) const
{
    ${types.string.name} result(allocator);
<#list values as value>
    <#if !value.isZero>
    if ((*this & ${name}::Values::${value.name}) == ${name}::Values::${value.name})
        result += result.empty() ? "${value.name}" : " | ${value.name}";
    <#else>
        <#assign zeroValueName=value.name/><#-- may be there only once -->
    </#if>
</#list>
<#if zeroValueName??>
    if (result.empty() && m_value == 0)
        result += "${zeroValueName}";
</#if>

    return ::zserio::toString<${types.string.name}::allocator_type>(m_value, allocator) + "[" + result + "]";
}

${name}::underlying_type ${name}::readValue(::zserio::BitStreamReader& in)
{
    return static_cast<underlying_type>(in.read${runtimeFunction.suffix}(${runtimeFunction.arg!}));
}

${name}::underlying_type ${name}::readValue(${types.packingContextNode.name}& contextNode,
        ::zserio::BitStreamReader& in)
{
    return contextNode.getContext().read(
            <@bitmask_array_traits underlyingTypeInfo.arrayTraits, fullName, bitSize!/>, in);
}
<@namespace_end package.path/>
