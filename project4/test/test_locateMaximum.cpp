#include <gtest/gtest.h>

#include <string>

using namespace std;
using namespace ::testing;

int locateMaximum(const string array[], int n);

TEST(locateMaximum, TestValid) {
  string array[] = {"AA", "BB", "BB", "BB", "cc", "dd", "ee"};

  EXPECT_EQ(5, locateMaximum(array, 6));
  EXPECT_EQ(4, locateMaximum(array, 5));
  EXPECT_EQ(6, locateMaximum(array, 7));
}

TEST(locateMaximum, TestNegative) {
  string array[] = {"AA", "BB", "BB", "BB", "cc", "dd", "ee"};

  EXPECT_EQ(-1, locateMaximum(array, -1));
  EXPECT_EQ(-1, locateMaximum(array, 0));
}
