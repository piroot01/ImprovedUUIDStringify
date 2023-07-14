#include "UUID.h"
#include <Poco/UUID.h>
#include <Poco/Types.h>
#include <Poco/ByteOrder.h>
#include <cstring>


namespace MyPoco {


UUID::UUID(const char* bytes, Poco::UUID::Version version)
{
    Poco::UInt32 i32;
    Poco::UInt16 i16;
    std::memcpy(&i32, bytes, sizeof(i32));
    _timeLow = Poco::ByteOrder::fromNetwork(i32);
    bytes += sizeof(i32);
    std::memcpy(&i16, bytes, sizeof(i16));
    _timeMid = Poco::ByteOrder::fromNetwork(i16);
    bytes += sizeof(i16);
    std::memcpy(&i16, bytes, sizeof(i16));
    _timeHiAndVersion = Poco::ByteOrder::fromNetwork(i16);
    bytes += sizeof(i16);
    std::memcpy(&i16, bytes, sizeof(i16));
    _clockSeq = Poco::ByteOrder::fromNetwork(i16);
    bytes += sizeof(i16);
    std::memcpy(_node, bytes, sizeof(_node));

    _timeHiAndVersion &= 0x0FFF;
    _timeHiAndVersion |= (version << 12);
    _clockSeq &= 0x3FFF;
    _clockSeq |= 0x8000;
}


std::string UUID::toString() const
{
    std::string result;
    result.reserve(32);
    appendHex(result, _timeLow);
    appendHex(result, _timeMid);
    appendHex(result, _timeHiAndVersion);
    appendHex(result, _clockSeq);
    for (Poco::UInt8 i = 0; i < sizeof(_node); ++i)
        appendHex(result, _node[i]);
    return result;
}


} // namespace MyPoco
