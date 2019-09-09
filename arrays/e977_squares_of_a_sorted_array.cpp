/*
* LeetCode: https://leetcode.com/problems/squares-of-a-sorted-array/
*/

#include <iostream>
#include <vector>

#include "test_runner.h"

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  // brute force approach - Runtime: 96 ms, Memory Usage: 13.4 MB
  vector<int> sortedSquares(vector<int>& A) {
    size_t length = A.size();

    for (size_t i = 0; i < length; i++) {
      A[i] = A[i] * A[i];
    }

    sort(A.begin(), A.end());

    return A;
  }
};

void testSolution() {
  Solution s;
  {
    vector<int> v = {-4, -1, 0, 2, 3, 10};
    vector<int> expected = {0, 1, 4, 9, 16, 100};
    ASSERT_EQUAL(s.sortedSquares(v), expected);
  }
  {
    vector<int> v = {0, 2, 3, 10};
    vector<int> expected = {0, 4, 9, 100};
    ASSERT_EQUAL(s.sortedSquares(v), expected);
  }
  {
    vector<int> v;
    vector<int> expected;
    ASSERT_EQUAL(s.sortedSquares(v), expected);
  }
  {
    vector<int> v = {-3, -3, -3};
    vector<int> expected = {9, 9, 9};
    ASSERT_EQUAL(s.sortedSquares(v), expected);
  }
  {
    vector<int> v = {-3, -3, 1, 10};
    vector<int> expected = {1, 9, 9, 100};
    ASSERT_EQUAL(s.sortedSquares(v), expected);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, testSolution);
  return 0;
}
