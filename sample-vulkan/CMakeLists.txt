cmake_minimum_required(VERSION 3.10)

project(vk)

set(CMAKE_CXX_STANDARD 17)
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )

find_package(vulkan REQUIRED)
add_executable(vk main.cpp)
target_link_libraries(vk Vulkan::Vulkan)
