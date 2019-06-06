/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>

#include "Coord.h"


Coord::Coord()
{
}

Coord::Coord(zserio::BitStreamReader& in)
{
    read(in);
}

Coord::Coord(uint32_t _x, uint32_t _y)
:   m_x(_x), m_y(_y)
{}

uint32_t Coord::getX() const
{
    return m_x;
}

void Coord::setX(uint32_t _x)
{
    m_x = _x;
}

uint32_t Coord::getY() const
{
    return m_y;
}

void Coord::setY(uint32_t _y)
{
    m_y = _y;
}

size_t Coord::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(32);
    endBitPosition += UINT8_C(32);

    return endBitPosition - bitPosition;
}

size_t Coord::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(32);
    endBitPosition += UINT8_C(32);

    return endBitPosition;
}

bool Coord::operator==(const Coord& other) const
{
    if (this != &other)
    {
        return
                (m_x == other.m_x) &&
                (m_y == other.m_y);
    }

    return true;
}

int Coord::hashCode() const
{
    int result = zserio::HASH_SEED;

    result = zserio::calcHashCode(result, m_x);
    result = zserio::calcHashCode(result, m_y);

    return result;
}

void Coord::read(zserio::BitStreamReader& in)
{
    m_x = (uint32_t)in.readBits(UINT8_C(32));
    m_y = (uint32_t)in.readBits(UINT8_C(32));
}

void Coord::write(zserio::BitStreamWriter& out, zserio::PreWriteAction)
{
    out.writeBits(m_x, UINT8_C(32));
    out.writeBits(m_y, UINT8_C(32));
}

