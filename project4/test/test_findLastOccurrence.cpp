#include <gtest/gtest.h>

#include <string>

using namespace std;
using namespace ::testing;

int findLastOccurrence(const string array[], int n, string target);

TEST(findLastOccurrence, TestValid) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_EQ(6, findLastOccurrence(array, 7, "15.0"));
  EXPECT_EQ(4, findLastOccurrence(array, 6, "15.0"));
}

TEST(findLastOccurrence, TestNegative) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_EQ(-1, findLastOccurrence(array, -10, "15.0"));
  EXPECT_EQ(-1, findLastOccurrence(array, 0, "15.0"));
  EXPECT_EQ(-1, findLastOccurrence(array, 5, "abcdef"));
}
