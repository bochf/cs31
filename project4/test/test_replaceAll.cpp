#include <gtest/gtest.h>

#include <string>

using namespace std;
using namespace ::testing;

int replaceAll(string array[], int n, char letterToReplace, char letterToFill);

TEST(replaceAll, TestValid) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_EQ(3, replaceAll(array, 7, '.', 'z'));
  EXPECT_EQ("-55z", array[3]);
  EXPECT_EQ("15z0", array[4]);
  EXPECT_EQ("15z0", array[6]);

  string array2[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};
  EXPECT_EQ(0, replaceAll(array2, 7, 'Z', 'z'));

  EXPECT_EQ(1, replaceAll(array2, 4, '.', 'z'));
  EXPECT_EQ("-55z", array2[3]);
}

TEST(replaceAll, TestNegative) {
  string array[] = {"55", "4A", "+35", "-55.", "15.0", "A12A", "15.0"};

  EXPECT_EQ(-1, replaceAll(array, -1, '.', 'z'));
  EXPECT_EQ(-1, replaceAll(array, 0, '.', 'z'));
}
