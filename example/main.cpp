#include "UUID.h"
#include "UUIDGenerator.h"
#include <iostream>

int main()
{
    MyPoco::UUIDGenerator generator;
    MyPoco::UUID uuid = generator.createRandom();

    std::cout << uuid.toString() << '\n';

    return 0;
}
