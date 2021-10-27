/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#ifndef ZSERIO_ENUMS_H_INC
#define ZSERIO_ENUMS_H_INC

#include <cstddef>
#include <type_traits>

#include "zserio/ITypeInfo.h"

// This should be implemented in runtime library header.
namespace zserio
{

// forward declarations
class BitStreamReader;
class BitStreamWriter;

/**
 * Enum traits for Zserio enums.
 */
template <typename T>
struct EnumTraits
{
};

/**
 * Gets type info for the given enum type.
 *
 * \return Enum type info.
 */
template <typename T>
const ITypeInfo& enumTypeInfo();

/**
 * Gets ordinal number of the given enum item.
 *
 * \param value Enum item.
 *
 * \return Ordinal number of the enum item.
 */
template <typename T>
size_t enumToOrdinal(T value);

/**
 * Converts the given raw value to an appropriate enum item.
 *
 * \param rawValue Raw value of the proper underlying type.
 *
 * \return Enum item corresponding to the rawValue.
 *
 * \throw CppRuntimeException when the rawValue doesn't match to any enum item.
 */
template <typename T>
T valueToEnum(typename std::underlying_type<T>::type rawValue);

/**
 * Gets the underlying raw value of the given enum item.
 *
 * \param value Enum item.
 *
 * \return Raw value.
 */
template <typename T>
constexpr typename std::underlying_type<T>::type enumToValue(T value)
{
    return static_cast<typename std::underlying_type<T>::type>(value);
}

/**
 * Gets the name of the given enum item.
 *
 * \param value Enum item.
 *
 * \return Name of the enum item.
 */
template <typename T>
const char* enumToString(T value)
{
    return EnumTraits<T>::names[enumToOrdinal(value)];
}

/**
 * Initializes packing context for the given enum item.
 *
 * \param contextNode Packing context node.
 * \param value Enum item.
 */
template <typename PACKING_CONTEXT_NODE, typename T>
void initPackingContext(PACKING_CONTEXT_NODE& contextNode, T value);

/**
 * Gets bit size of the given enum item.
 *
 * Note that T can be varuint, so bitSizeOf cannot return constant value and depends on the concrete item.
 *
 * \param value Enum item.
 *
 * \return Bit size of the enum item.
 */
template <typename T>
size_t bitSizeOf(T value);

/**
 * Gets bit size of the given enum item when it's inside a packed array.
 *
 * Note that T can be varuint, so bitSizeOf cannot return constant value and depends on the concrete item.
 *
 * \param contextNode Packing context node.
 * \param value Enum item.
 *
 * \return Bit size of the enum item.
 */
template <typename PACKING_CONTEXT_NODE, typename T>
size_t bitSizeOf(PACKING_CONTEXT_NODE& contextNode, T value);

/**
 * Initializes offsets for the enum item.
 *
 * Note that T can be varuint, so initializeOffsets cannot return constant value and
 * depends on the concrete item.
 *
 * \param bitPosition Current bit position.
 * \param value Enum item.
 *
 * \return Updated bit position which points to the first bit after the enum item.
 */
template <typename T>
size_t initializeOffsets(size_t bitPosition, T value);

/**
 * Initializes offsets for the enum item when it's inside a packed array.
 *
 * Note that T can be varuint, so initializeOffsets cannot return constant value and
 * depends on the concrete item.
 *
 * \param contextNode Packing context node.
 * \param bitPosition Current bit position.
 * \param value Enum item.
 *
 * \return Updated bit position which points to the first bit after the enum item.
 */
template <typename PACKING_CONTEXT_NODE, typename T>
size_t initializeOffsets(PACKING_CONTEXT_NODE& contextNode, size_t bitPosition, T value);

/**
 * Reads an enum item.
 *
 * \param in Bit stream reader.
 *
 * \return Enum item read from the bit stream.
 */
template <typename T>
T read(BitStreamReader& in);

/**
 * Reads an enum item which is inside a packed array.
 *
 * \param contextNode Packing context node.
 * \param in Bit stream reader.
 *
 * \return Enum item read from the bit stream.
 */
template <typename T, typename PACKING_CONTEXT_NODE>
T read(PACKING_CONTEXT_NODE& contextNode, BitStreamReader& in);

/**
 * Writes the enum item to the given bit stream.
 *
 * \param out Bit stream writer.
 * \param value Enum item to write.
 */
template <typename T>
void write(BitStreamWriter& out, T value);

/**
 * Writes the enum item which is inside a packed array to the given bit stream.
 *
 * \param contextNode Packing context node.
 * \param out Bit stream writer.
 * \param value Enum item to write.
 */
template <typename PACKING_CONTEXT_NODE, typename T>
void write(PACKING_CONTEXT_NODE& contextNode, BitStreamWriter& out, T value);

} // namespace zserio

#endif // ZSERIO_ENUMS_H_INC
