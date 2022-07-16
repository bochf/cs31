#include <gtest/gtest.h>

#include <string>

using namespace std;
using namespace ::testing;

bool hasReverse(const string array[], int n);

TEST(hasReverse, TestValid) {
  string array[] = {"AA", "BB", "BB", "BB", "cc", "dd", "ee"};

  EXPECT_TRUE(hasReverse(array, 4));
}

TEST(hasReverse, TestNegative) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_FALSE(hasReverse(array, -1));
  EXPECT_FALSE(hasReverse(array, 0));
  EXPECT_FALSE(hasReverse(array, 4));

  string array2[] = {"AA", "BB", "BB", "BB", "cc", "dd", "ee"};
  EXPECT_FALSE(hasReverse(array2, 2));
}
