#ifndef LOGICLONG_H
#define LOGICLONG_H

#include "Bytestream.h"

class LogicLong
{
public:
    int high, low;
    LogicLong(int high, int low)
    {
        this->high = high;
        this->low = low;
    }
    void decode(Bytestream *stream)
    {
        high = stream->readInt();
        low = stream->readInt();
    }
    void encode(Bytestream *stream);
    static int getLowerInt(int longLong);
    static int getHigherInt(int longLong);
    int getLong();
    int hashCode();
    void toLong();
};
#endif