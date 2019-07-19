cmake_minimum_required(VERSION 3.12)
OPTION(ENABLE_TESTS "enable tests" ON)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
include(HunterGate)
include(Catch)
include(cotire)

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.86.tar.gz"
    SHA1 "786a19c93b24308cb4b77c00415b70837cae5b9e"
)

project(exchange-api)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

hunter_add_package(Boost COMPONENTS system)
hunter_add_package(Catch)
# hunter_add_package(OpenSSL)

find_package(Boost CONFIG REQUIRED system)
find_package(Catch2 CONFIG REQUIRED)
# find_package(OpenSSL REQUIRED)

file(GLOB EXCHANGE_API_SOURCES    ${CMAKE_SOURCE_DIR}/src/*.cc)
add_library (exchange-api ${EXCHANGE_API_SOURCES})
target_include_directories(exchange-api PUBLIC hdr/)
target_link_libraries(
  exchange-api PUBLIC
  Boost::system
  # OpenSSL::SSL
  # OpenSSL::Crypto
)
cotire(exchange-api)

if(ENABLE_TESTS)
  enable_testing()
  file(GLOB TEST_SOURCES ${CMAKE_SOURCE_DIR}/t/*.cc)

  add_executable(t ${TEST_SOURCES})
  target_link_libraries(t PUBLIC Catch2::Catch exchange-api)
  catch_discover_tests(t)
endif() 
