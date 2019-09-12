/*
** https://leetcode.com/problems/max-consecutive-ones/
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
  // Runtime: 16 ms
  // Memory Usage: 11.5 MB
  // O(N) time, O(1) space
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ones_counter = 0, max_ones = 0;
    for (int i : nums) {
      i == 1 ? max_ones = max(++ones_counter, max_ones) : ones_counter = 0;
    }
    return max_ones;
  }
};

void testSolution() {
  Solution s;
  {
    vector<int> v = {1, 1, 0, 1, 1};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 2);
  }
  {
    vector<int> v = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 3);
  }
  {
    vector<int> v = {};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 0);
  }
  {
    vector<int> v = {0, 0, 0, 0};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 0);
  }
  {
    vector<int> v = {1, 1, 1, 1};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 4);
  }
  {
    vector<int> v = {1, 1, 1, 0, 1};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 3);
  }
  {
    vector<int> v = {1, 1, 0, 1, 1, 1};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 3);
  }
  {
    vector<int> v = {0, 1, 0, 1, 0};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 1);
  }
  {
    vector<int> v = {0, 1, 1, 1, 0};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 3);
  }
  {
    vector<int> v = {0, 1, 1, 1, 0, 1, 1, 1, 1, 0};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 4);
  }
  {
    vector<int> v = {1, 1, 0, 1};
    ASSERT_EQUAL(s.findMaxConsecutiveOnes(v), 2);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, testSolution);
  return 0;
}
