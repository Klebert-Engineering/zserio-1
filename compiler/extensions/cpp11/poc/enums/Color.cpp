/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#include "Color.h"

#include "zserio/CppRuntimeException.h"
#include "zserio/StringConvertUtil.h"

// These are full specializations for Color enumeration
namespace zserio
{
    template<>
    size_t enumBitSizeOf<enumeration_types::bitfield_enum::Color>()
    {
        return 3;
    }

    template<>
    enumeration_types::bitfield_enum::Color enumRead<enumeration_types::bitfield_enum::Color>(
            zserio::BitStreamReader& in)
    {
       return rawValueToEnum<enumeration_types::bitfield_enum::Color>(static_cast<uint8_t>(in.readBits(3)));
    }

    template<>
    void enumWrite<enumeration_types::bitfield_enum::Color>(enumeration_types::bitfield_enum::Color value,
            zserio::BitStreamWriter& out, zserio::PreWriteAction)
    {
        out.writeBits(static_cast<uint8_t>(value), 3);
    }

    template<>
    std::string enumToString<enumeration_types::bitfield_enum::Color>(
            enumeration_types::bitfield_enum::Color value)
    {
        switch (value)
        {
        case enumeration_types::bitfield_enum::Color::NONE:
            return std::string("NONE");
        case enumeration_types::bitfield_enum::Color::RED:
            return std::string("RED");
        case enumeration_types::bitfield_enum::Color::BLUE:
            return std::string("BLUE");
        case enumeration_types::bitfield_enum::Color::BLACK:
            return std::string("BLACK");
        default:
            return std::string("UNKNOWN");
        }
    }

    template<>
    enumeration_types::bitfield_enum::Color rawValueToEnum<enumeration_types::bitfield_enum::Color>(uint8_t value)
    {
        switch (value)
        {
        case UINT8_C(0):
            return enumeration_types::bitfield_enum::Color::NONE;
        case UINT8_C(2):
            return enumeration_types::bitfield_enum::Color::RED;
        case UINT8_C(3):
            return enumeration_types::bitfield_enum::Color::BLUE;
        case UINT8_C(7):
            return enumeration_types::bitfield_enum::Color::BLACK;
        default:
            throw zserio::CppRuntimeException("Unknown value for enumeration Color: " +
                    zserio::convertToString(value) + "!");
        }
    }

    template<>
    std::vector<enumeration_types::bitfield_enum::Color> getEnumValues<enumeration_types::bitfield_enum::Color>()
    {
        return std::vector<enumeration_types::bitfield_enum::Color>{
            {enumeration_types::bitfield_enum::Color::NONE,
            enumeration_types::bitfield_enum::Color::RED,
            enumeration_types::bitfield_enum::Color::BLUE,
            enumeration_types::bitfield_enum::Color::BLACK} };
    }
}
