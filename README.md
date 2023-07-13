# Better UUID to String

This repository contains an improved version of the UUID generator and associated toString() function, based on the Poco library.

## Overview

The code provides an implementation of a universally unique identifier (UUID) generator. The generated UUIDs are random, based on the Poco library's UUID generator. In addition, the toString() function has been improved for better string representation of the generated UUIDs.

## Code Example

Here is an example of how to use the custom UUID generator and toString() function:

```cpp
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
```
