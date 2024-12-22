#include "Bytestream.h"
#include "ChecksumEncoder.h"

int Bytestream::readInt()
{
    bitoffset = 0;
    int result = (messagePayload[offset] << 24);
    result += (messagePayload[offset + 1] << 16);
    result += (messagePayload[offset + 2] << 8);
    result += (messagePayload[offset + 3]);
    offset += 4;
    return result;
}

int Bytestream::readInt8()
{
    bitoffset = 0;
    return messagePayload[offset++];
}

int Bytestream::readInt16()
{
    bitoffset = 0;
    int result = (messagePayload[offset] << 8);
    result += (messagePayload[offset + 1]);
    offset += 2;
    return result;
}

int Bytestream::readInt24()
{
    bitoffset = 0;
    int result = (messagePayload[offset] << 16);
    result += (messagePayload[offset + 1] << 8);
    result += (messagePayload[offset + 2]);
    offset += 3;
    return result;
}

int Bytestream::readIntLittleEndian()
{
    bitoffset = 0;
    int result = (messagePayload[offset]);
    result += (messagePayload[offset + 1] << 8);
    result += (messagePayload[offset + 2] << 16);
    result += (messagePayload[offset + 3] << 24);
    offset += 4;
    return result;
}

void Bytestream::writeIntToByteArray(int value)
{
    messagePayload.push_back((value >> 24) & 0xFF);
    messagePayload.push_back((value >> 16) & 0xFF);
    messagePayload.push_back((value >> 8) & 0xFF);
    messagePayload.push_back(value & 0xFF);
}

void Bytestream::writeInt(int value)
{
    ChecksumEncoder checksumEncoder;
    checksumEncoder.writeInt(value);
    writeIntToByteArray(value);
}

void Bytestream::readLong(LogicLong *logicLong)
{
    bitoffset = 0;
    int high = readInt();
    int low = readInt();
    logicLong->high = high;
    logicLong->high = high;
}

void Bytestream::readLongLong()
{
    bitoffset = 0;
    int high = readInt();
    int low = readInt();
}