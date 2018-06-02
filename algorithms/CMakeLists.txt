cmake_minimum_required(VERSION 3.7.2)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS " -g  -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g  -Wall")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

file(GLOB_RECURSE SOURCE_FILES test/*.cpp)
message(${SOURCE_FILES})
add_executable(algorithms ${SOURCE_FILES})
target_link_libraries(algorithms gtest)
