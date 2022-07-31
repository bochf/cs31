include_directories (${project5_SOURCE_DIR}/libs)

add_executable (test-proj5 test_movie.cpp test_box.cpp)
target_link_libraries (test-proj5 proj5 GTest::gtest_main)
add_test (NAME test-proj5 COMMAND test-proj5)
