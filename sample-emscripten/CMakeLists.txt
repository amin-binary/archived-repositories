cmake_minimum_required(VERSION 3.0)

# Creates the file compile_commands.json in the build directory.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/.cmake")
include(".cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.227.tar.gz"
    SHA1 "808b778a443fcdf19c2d18fea8fa4bb59d16596a"
)

project(chart-wasm)

# hunter_add_package(sqlite3)
# find_package(sqlite3 CONFIG REQUIRED)

# add_library (sample_lib INTERFACE)
# target_include_directories(sample_lib INTERFACE hdr/)

file(GLOB SOURCES  ${CMAKE_SOURCE_DIR}/*.cc)
add_executable(chart-wasm ${SOURCES})

# target_link_libraries(my_test sqlite3::sqlite3)

