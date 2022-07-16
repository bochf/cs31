#include <gtest/gtest.h>

#include <string>

using namespace std;
using namespace ::testing;

int countFloatingPointValues(const string array[], int n);

TEST(countFloatingPointValues, TestValid) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_EQ(5, countFloatingPointValues(array, 7));
  EXPECT_EQ(3, countFloatingPointValues(array, 4));
  EXPECT_EQ(4, countFloatingPointValues(array, 5));
}

TEST(countFloatingPointValues, TestNegative) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_EQ(-1, countFloatingPointValues(array, -1));
  EXPECT_EQ(-1, countFloatingPointValues(array, 0));
}
