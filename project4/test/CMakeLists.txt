include_directories (${project4_SOURCE_DIR}/libs)

add_executable (test-array 
                test_countFloatingPointValues.cpp
                test_findLastOccurrence.cpp
                test_hasDuplicates.cpp
                test_hasReverse.cpp
                test_locateMaximum.cpp
                test_majorityElement.cpp
                test_matchingValuesTogether.cpp
                test_replaceAll.cpp)
target_link_libraries (test-array array GTest::gtest_main)
add_test (NAME test-array COMMAND test-array)
