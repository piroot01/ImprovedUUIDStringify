set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O3")

find_package(Poco REQUIRED Foundation)

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

target_link_libraries(${PROJECT_NAME} Poco::Foundation)
