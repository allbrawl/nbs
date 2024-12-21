#ifndef CHECKSUM_ENCODER_H
#define CHECKSUM_ENCODER_H

#include <cstdint>
#include <cstddef>
#include <string>
class ChecksumEncoder
{
public:
    int32_t checksum;
    int32_t checksum2;
    bool checksumEnabled = true;
    ~ChecksumEncoder()
    {
        checksum = 0;
        checksum2 = 0;
        checksumEnabled = true;
    }
    void enableChecksum(bool state);
    int getChecksum();
    void writeBoolean(bool value);
    void writeByte(uint8_t value);
    void ChecksumEncoder::writeBytes(const uint8_t *value, size_t length);
    void ChecksumEncoder::writeInt8(int8_t value);
    void ChecksumEncoder::writeInt16(int16_t value);
    void ChecksumEncoder::writeInt24(int32_t value);
    void ChecksumEncoder::writeInt(int32_t value);
    void ChecksumEncoder::writeLong(const uint8_t* bytestream, size_t length);
    void ChecksumEncoder::writeLongLong(int32_t high, int32_t low);
    void ChecksumEncoder::writeShort(int16_t value);
    void ChecksumEncoder::writeString(const std::string& value);
    void ChecksumEncoder::writeStringReference(const std::string& value);
    void ChecksumEncoder::writeVInt(int32_t value);
    void ChecksumEncoder::writeVLong(int32_t high, int32_t low);
    template <typename T>
    T rotr(T value, unsigned int count);
};
#endif