/*
Remove duplicates from a sorted array using in-place algorithm and return the new length
Problem source: LeetCode
Problem link: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
*/

#include <iostream>
#include <vector>

#include "test_runner.h"

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() < 2) return nums.size();
      int slow = 0;
      for (int fast = 1; fast < nums.size(); ++fast) {
        if (nums[slow] != nums[fast]) nums[++slow] = nums[fast];
      }
      return ++slow;
    }
};

void testSolution() {
  Solution s;
  {
    vector <int> v = {1, 1, 2};
    ASSERT(s.removeDuplicates(v) == 2);
  }
  {
    vector <int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    ASSERT(s.removeDuplicates(v) == 5);
  }
  {
    vector <int> v = {0, 1, 2, 3};
    ASSERT(s.removeDuplicates(v) == 4);
  }
  {
    vector <int> v = {0, 0, 0, 0};
    ASSERT(s.removeDuplicates(v) == 1);
  }
  {
    vector <int> v = {1};
    ASSERT(s.removeDuplicates(v) == 1);
  }
  {
    vector <int> v = {};
    ASSERT(s.removeDuplicates(v) == 0);
  }
  {
    vector <int> v = {1, 2, 2, 2, 5};
    ASSERT(s.removeDuplicates(v) == 3);
  }
  {
    vector <int> v = {1, 1, 2, 3, 4, 5, 5};
    ASSERT(s.removeDuplicates(v) == 5);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, testSolution);
  return 0;
}
