cmake_minimum_required (VERSION 3.18)
project (project4)

set(CMAKE_BUILD_TYPE Debug)

find_package (GTest REQUIRED)
enable_testing ()

add_subdirectory (libs)
add_subdirectory (test)

