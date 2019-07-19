cmake_minimum_required(VERSION 3.0)

# Creates the file compile_commands.json in the build directory.
set (CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.227.tar.gz"
    SHA1 "808b778a443fcdf19c2d18fea8fa4bb59d16596a"
)

project(MyTest)

hunter_add_package(sqlite3)

find_package(sqlite3 CONFIG REQUIRED)

add_library (sqlite_modern_cpp INTERFACE)
target_include_directories(sqlite_modern_cpp INTERFACE hdr/)

file(GLOB SOURCES  ${CMAKE_SOURCE_DIR}/*.cpp)

add_executable(my_test ${SOURCES})
target_link_libraries(my_test sqlite3::sqlite3)

