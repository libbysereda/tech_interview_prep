/*
** LeetCode: https://leetcode.com/problems/sort-array-by-parity/
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
  // using two pointers approach: in-place algorithm, swap only if necessary
  // Runtime: 24 ms
  // Memory Usage: 9.7 MB
  vector<int> sortArrayByParity(vector<int>& A) {
    int l = 0, r  = A.size() - 1;

    while (l < r) {
      if (A[l] % 2 > A[r] % 2) {
        swap(A[l++], A[r--]);
      }

      while (A[l] % 2 == 0 && l < r) l++;
      while (A[r] % 2 == 1 && l < r) r--;
    }

    return A;
  }

  // using two pointers approach: in-place algorithm
  // Runtime: 20 ms
  // Memory Usage: 9.6 MB
  vector<int> sortArrayByParity1(vector<int>& A) {
    size_t length = A.size();

    for (size_t slow, fast = 0; fast < length; fast++) {
      if (A[fast] % 2 == 0) {
        swap(A[slow++], A[fast]);
      }
    }

    return A;
  }

  // additional memory usage
  // Runtime: 20 ms
  // Memory Usage: 10.4 MB
  vector<int> sortArrayByParity2(vector<int>& A) {
    vector<int> first;
    vector<int> last;

    for (int i : A) {
      i % 2 == 0 ? first.push_back(i) : last.push_back(i);
    }

    for (int i : last) {
      first.push_back(i);
    }

    return first;
  }
};

void testSolution() {
  Solution s;
  {
    vector<int> v = {3, 1, 2, 4};
    vector<int> expected = {4, 2, 1, 3};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
  {
    vector<int> v = {3};
    vector<int> expected = {3};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
  {
    vector<int> v = {};
    vector<int> expected = {};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
  {
    vector<int> v = {3, 1, 7};
    vector<int> expected = {3, 1, 7};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
  {
    vector<int> v = {2, 8, 10};
    vector<int> expected = {2, 8, 10};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
  {
    vector<int> v = {3, 2, 4};
    vector<int> expected = {4, 2, 3};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
  {
    vector<int> v = {3, 1, 2};
    vector<int> expected = {2, 1, 3};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
  {
    vector<int> v = {2, 4, 3, 1};
    vector<int> expected = {2, 4, 3, 1};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, testSolution);
  return 0;
}
