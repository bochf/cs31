#include <gtest/gtest.h>

#include <string>

using namespace std;
using namespace ::testing;

bool matchingValuesTogether(const string array[], int n);

TEST(matchingValuesTogether, TestValid) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_TRUE(matchingValuesTogether(array, 6));
  EXPECT_TRUE(matchingValuesTogether(array, 5));
}

TEST(matchingValuesTogether, TestNegative) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_FALSE(matchingValuesTogether(array, -10));
  EXPECT_FALSE(matchingValuesTogether(array, 0));
  EXPECT_FALSE(matchingValuesTogether(array, 7));
}
