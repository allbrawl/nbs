#ifndef BYTESTREAM_H
#define BYTESTREAM_H

#include <vector>
#include <cstdint>
#include <stddef.h>
#include "LogicLong.h"

class Bytestream
{
public:
    std::vector<uint8_t> messagePayload;
    size_t bitoffset;
    size_t offset;
    size_t length;
    int readInt();
    int readInt8();
    int readInt16();
    int readInt24();
    int readIntLittleEndian(); // Little Endian is pretty much the same as Big Endian, but the bytes are reversed.
    void readLong(LogicLong *logicLong);
    void readLongLong();
    void readShort();
    void readString();
    void writeInt(int value);
    void writeIntToByteArray(int value);
};

#endif