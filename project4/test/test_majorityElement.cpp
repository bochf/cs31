#include <gtest/gtest.h>

#include <string>

using namespace std;
using namespace ::testing;

string majorityElement(const string array[], int n);

TEST(majorityElement, TestValid) {
  string array[] = {"AA", "BB", "BB", "BB", "cc", "dd", "ee"};

  EXPECT_EQ("BB", majorityElement(array, 5));
  EXPECT_EQ("BB", majorityElement(array, 4));
}

TEST(majorityElement, TestNegative) {
  string array[] = {"AA", "BB", "BB", "BB", "cc", "dd", "ee"};

  EXPECT_EQ("", majorityElement(array, -1));
  EXPECT_EQ("", majorityElement(array, 0));
  EXPECT_EQ("", majorityElement(array, 2));
}
