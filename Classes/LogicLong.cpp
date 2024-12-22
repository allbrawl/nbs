#include "LogicLong.h"
#include "Bytestream.h"

void LogicLong::decode(Bytestream *stream)
{
    high = stream->readInt();
    low = stream->readInt();
}

void LogicLong::encode(Bytestream *stream)
{
    stream->writeInt(high);
    stream->writeInt(low);
}

int LogicLong::getHigherInt(int longLong)
{
    return longLong >> 32;
}

int LogicLong::getLowerInt(int longLong)
{
    return longLong & 0xFFFFFFFF; // 0xFFFFFFFF is a hexadecimal number that represents 32 bits.
}