#ifndef UUID_INDLUDED
#define UUID_INDLUDED


#include <Poco/UUID.h>


namespace MyPoco {


class UUID : public Poco::UUID
{
public:
    std::string toString() const;

protected:
    UUID(const char* bytes, Poco::UUID::Version version);

private:
    Poco::UInt32 _timeLow;
    Poco::UInt16 _timeMid;
    Poco::UInt16 _timeHiAndVersion;
    Poco::UInt16 _clockSeq;
    Poco::UInt8  _node[6];

    friend class UUIDGenerator;
};


} // namespace MyPoco

#endif
