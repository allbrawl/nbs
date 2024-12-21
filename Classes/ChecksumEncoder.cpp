#include "ChecksumEncoder.h"

void ChecksumEncoder::enableChecksum(bool state)
{
    if (!checksumEnabled || state)
    {
        if (!checksumEnabled && state)
        {
            checksum = checksum2;
        }
        checksumEnabled = state;
    }
    else
    {
        checksum2 = checksum;
        checksumEnabled = false;
    }
}

int ChecksumEncoder::getChecksum()
{
    if (checksumEnabled)
    {
        return checksum;
    }
    else
    {
        return checksum2;
    }
}
template <typename T>
T ChecksumEncoder::rotr(T value, unsigned int count)
{
    const unsigned int numBits = sizeof(T) * 8;
    count %= numBits;
    return (value >> count) | (value << (numBits - count));
}

void ChecksumEncoder::writeBoolean(bool value)
{
    int integer = value ? 13 : 7;
    checksum = integer + rotr(checksum, 31);
}

void ChecksumEncoder::writeByte(uint8_t value)
{
    checksum = rotr(checksum, 31) + value + 11;
}
void ChecksumEncoder::writeBytes(const uint8_t* value, size_t length)
{
    int integer = value ? length + 38 : 37;
    checksum = rotr(checksum, 31) + integer;
}
void ChecksumEncoder::writeInt8(int8_t value)
{
    checksum = rotr(checksum, 31) + value + 11;
}

void ChecksumEncoder::writeInt16(int16_t value)
{
    checksum = rotr(checksum, 31) + value + 19;
}

void ChecksumEncoder::writeInt24(int32_t value)
{
    checksum = (value & 0xFFFFFF) + rotr(checksum, 31) + value + 21;
}

void ChecksumEncoder::writeInt(int32_t value)
{
    checksum = rotr(checksum, 31) + value + 9;
}
void ChecksumEncoder::writeLong(const uint8_t* bytestream, size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        checksum = rotr(checksum, 31) + bytestream[i] + 67;
    }
}

void ChecksumEncoder::writeLongLong(int32_t high, int32_t low)
{
    checksum = low + rotr(high + rotr(checksum, 31) + 67, 31) + 91;
}

void ChecksumEncoder::writeShort(int16_t value)
{
    checksum = rotr(checksum, 31) + value + 19;
}

void ChecksumEncoder::writeString(const std::string& value)
{
    checksum = rotr(checksum, 31);
    if (!value.empty())
    {
        checksum += value.length() + 28;
    }
    else
    {
        checksum += 27;
    }
}

void ChecksumEncoder::writeStringReference(const std::string& value)
{
    checksum = value.length() + rotr(checksum, 31) + 38;
}

void ChecksumEncoder::writeVInt(int32_t value)
{
    checksum = value + rotr(checksum, 31) + 33;
}

void ChecksumEncoder::writeVLong(int32_t high, int32_t low)
{
    checksum = low + rotr(high + rotr(checksum, 31) + 65, 31) + 88;
}
