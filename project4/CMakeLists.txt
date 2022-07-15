cmake_minimum_required (VERSION 3.18)
project (project4)

set(CMAKE_BUILD_TYPE Debug)

find_package (GTest REQUIRED)

add_subdirectory (libs)
add_subdirectory (test)

enable_testing ()
add_test (NAME Test COMMAND test-parser)
