include_directories (${project3_SOURCE_DIR}/libs)

add_executable (test-parser test_parser.cpp)
target_link_libraries (test-parser parser GTest::gtest_main)
