#include <gtest/gtest.h>

#include <string>

using namespace std;
using namespace ::testing;

bool hasDuplicates(const string array[], int n);

TEST(hasDuplicates, TestValid) {
  string array[] = {"AA", "BB", "BB", "BB", "cc", "dd", "ee"};

  EXPECT_TRUE(hasDuplicates(array, 4));
  EXPECT_TRUE(hasDuplicates(array, 3));
}

TEST(hasDuplicates, TestNegative) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_FALSE(hasDuplicates(array, -1));
  EXPECT_FALSE(hasDuplicates(array, 0));
  EXPECT_FALSE(hasDuplicates(array, 2));
}
