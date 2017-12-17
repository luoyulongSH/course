cmake_minimum_required(VERSION 3.8)
project(view_demo)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(/usr/local/include)
include_directories(src/activity)
include_directories(src/util)
include_directories(src/view)


link_directories(/usr/local/lib)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(view_demo ${SOURCE_FILES})
target_link_libraries(view_demo ${OpenCV_LIBS} boost_filesystem boost_system)
