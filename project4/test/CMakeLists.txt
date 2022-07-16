include_directories (${project4_SOURCE_DIR}/libs)

add_executable (test-array test_array.cpp)
target_link_libraries (test-array array GTest::gtest_main)
