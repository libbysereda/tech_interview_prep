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
  // using two pointers approach: in-place algorithm
  vector<int> sortArrayByParity(vector<int>& A) {
    size_t length = A.size();

    for (size_t slow, fast = 0; fast < length; fast++) {
      if (A[fast] % 2 == 0) {
        swap(A[slow++], A[fast]);
      }
    }

    return A;
  }

  // additional memory usage
  vector<int> sortArrayByParity1(vector<int>& A) {
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
    vector<int> expected = {2, 4, 3, 1};
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
    vector<int> expected = {2, 4, 3};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
  {
    vector<int> v = {3, 1, 2};
    vector<int> expected = {2, 1, 3};
    ASSERT_EQUAL(s.sortArrayByParity(v), expected);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, testSolution);
  return 0;
}
