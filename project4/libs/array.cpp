#include <string>

using namespace std;

////////////////////////////
// private functions

/**
 * @brief compare 2 strings are reverse equal
 *
 * @param str1, the first string
 * @param str2, the second string
 *
 * @return true if str1 and str2 are reverse equal
 */
bool reverseEq(const string &str1, const string &str2) {
  int len = str1.size();
  if (str2.size() != len) {
    return false;
  }

  int i = 0;
  for (int i = 0; i < --len; ++i) {
    if (str1[i] != str2[len - i]) {
      return false;
    }
  }

  return true;
}

/**
 * @brief check a string is a valid floating point format
 * a valid floating point is /(?:\+|-?\d+\.?\d*)/
 * - optional leading sign + or -
 * - mandatory integral part composed with digits 0-9
 * - optional decimal point .
 * - optional decimal part composed with digits 0-9
 *
 * @param str, the input string
 *
 * @return true if valid
 */
bool isFloat(const string &str) {
  if (str.empty()) {
    return false;
  }

  // devide the string into to integral part and decimal part
  // each part should contain only digits 0-9
  int integral = 0;            // start of integral part
  int decimal = str.find('.'); // position of decimal point

  if (str[0] == '+' || str[0] == '-') {
    integral = 1;
  }

  if (decimal ==
      string::npos) { // decimal point, whole string should be an integer
    decimal = str.size();
  }

  // check the integral part
  for (; integral < decimal; ++integral) {
    if (str[integral] < '0' || str[integral] > '9') {
      return false;
    }
  }

  // check the decimal part if exists
  ++decimal;
  for (; decimal < str.size(); ++decimal) {
    if (str[decimal] < '0' || str[decimal] > '9') {
      return false;
    }
  }

  return true;
}

////////////////////////////
// public functions

int locateMaximum(const string array[], int n) {
  if (n <= 0) {
    return -1;
  }

  int max = 0;
  for (int index = 1; index < n; ++index) {
    if (array[max] < array[index]) {
      max = index;
    }
  }

  return max;
}

bool matchingValuesTogether(const string array[], int n) {
  if (n <= 0)
    return false;

  int i = 0;
  while (i < n - 1) {
    // compare array[i] to rest of the strings in the list
    for (int j = i + 1; j < n; ++j) {
      if (array[i] == array[j]) { // found duplicated string
        if (j == i + 1) {
          i = j;
        } else {
          return false;
        }
      }
    }
    ++i;
  }

  return true;
}

bool hasDuplicates(const string array[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (array[i] == array[j]) {
        return true;
      }
    }
  }

  return false;
}

string majorityElement(const string array[], int n) {
  if (n <= 0)
  {
    return "";
  }

  // find a majority candidate
  int major_idx = 0; // majority candidate index
  int count = 1;     // times the candicate appears
  for (int i = 1; i < n; ++i) {
    if (array[major_idx] == array[i]) {
      ++count;
    } else {
      --count;
    }
    if (0 == count) {
      major_idx = i;
      count = 1;
    }
  }

  // check the candidate is really a majority
  count = 0;
  for (int i = 0; i < n; ++i) {
    if (array[i] == array[major_idx]) {
      ++count;
    }
  }

  return count > n / 2 ? array[major_idx] : "";
}

bool hasReverse(const string array[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (reverseEq(array[i], array[j])) {
        return true;
      }
    }
  }

  return false;
}

int findLastOccurrence(const string array[], int n, string target) {
  for (int i = n - 1; i >= 0; --i) {
    if (target == array[i]) {
      return i;
    }
  }

  return -1;
}

int countFloatingPointValues(const string array[], int n) {
  if (n <= 0)
    return -1;

  int count = 0;
  for (int i = 0; i < n; ++i) {
    count += isFloat(array[i]) ? 1 : 0;
  }

  return count;
}

int replaceAll(string array[], int n, char letterToReplace, char letterToFill) {
  if (n <= 0)
    return -1;

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < array[i].size(); ++j) {
      if (array[i][j] == letterToReplace) {
        array[i][j] = letterToFill;
        ++count;
      }
    }
  }

  return count;
}
