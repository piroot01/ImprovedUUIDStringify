#include "UUID.h"
#include "UUIDGenerator.h"
#include <Poco/RandomStream.h>
#include <array>


namespace MyPoco {


UUID UUIDGenerator::createRandom()
{
    char buffer[16];
    Poco::RandomInputStream ris;
    ris.read(buffer, sizeof(buffer));
    return UUID(buffer, Poco::UUID::Version::UUID_RANDOM);
}


} // namespace MyPoco
