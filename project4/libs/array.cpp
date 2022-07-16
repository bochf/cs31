#include <string>

using namespace std;

////////////////////////////
// private functions

/**
 * @brief partitioning the array, random pickup a pivot, move all the
 * elements greater than the pivot to the right side and all the elements
 * less than the pivot to the left side.
 * To avoid string copy, move the index of the string instead
 *
 * @param idx, the array of the index of the original string list
 * @param start, the index of the leftmost element
 * @param end, the index of the right most element
 * @param strList, the original string list
 *
 * @return the position of the pivot
 */
int partition(int idx[], int start, int end, const string strList[]) {
  int pivot = idx[start];
  while (start < end) {
    // from right to left, search an element less than pivot
    while (start < end && strList[idx[end]] >= strList[pivot]) {
      --end;
    }
    // either found a string less than pivot or start == end
    idx[start] = idx[end];

    // from left to right, search an element greater than pivot
    while (start < end && strList[idx[start]] <= strList[pivot]) {
      ++start;
    }
    // either found a string greater than pivot or start == end
    idx[end] = idx[start];
  }

  idx[start] = pivot;
  return start;
}

/**
 * @brief sort the strList, to avoid string copy, the result is stored int the
 * index list
 *
 * @param idx, the array of the index of the original string list
 * @param start, the index of the leftmost element
 * @param end, the index of the right most element
 * @param strList, the original string list
 */
void quickSort(int idx[], int start, int end, const string strList[]) {
  if (start < end) {
    int pivot = partition(idx, start, end, strList);
    quickSort(idx, start, pivot - 1, strList);
    quickSort(idx, pivot + 1, end, strList);
  }
}

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

int locateMaximum(const string array[], int n) {
  if (n <= 0)
    return -1;

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
  while (i < n) {
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
  if (n <= 0)
    return false;

  for (int i = 0; i < n; ++i) {
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
    return "";

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
  if (n <= 0)
    return false;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (reverseEq(array[i], array[j])) {
        return true;
      }
    }
  }

  return false;
}

int findLastOccurrence(const string array[], int n, string target) {
  if (n <= 0)
    return -1;
}

int countFloatingPointValues(const string array[], int n) {
  if (n <= 0)
    return -1;
}

int replaceAll(string array[], int n, char letterToReplace, char letterToFill) {
  if (n <= 0)
    return -1;
}
