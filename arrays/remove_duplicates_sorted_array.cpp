/*
Remove duplicates from a sorted array using in-place algorithm and return the new length
Problem source: LeetCode
Problem link: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
*/

#include <iostream>
#include <vector>
#include "test_runner.h"

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int cur = 0;

    for (int next = 1; next < nums.size(); ++next) {
      if (nums[cur] != nums[next]) nums[++cur] = nums[next];
    }

    return ++cur;
  }
};


void testRemoveDuplicates() {
  Solution s;
  {
    vector<int> v = {1, 1, 2};
    ASSERT(2 == s.removeDuplicates(v));
  }
  {
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    ASSERT(5 == s.removeDuplicates(v));
  }
  {
    vector<int> v = {};
    ASSERT(0 == s.removeDuplicates(v));
  }
  {
    vector<int> v = {1, 1};
    ASSERT(1 == s.removeDuplicates(v));
  }
  {
    vector<int> v = {1, 2, 3};
    ASSERT(3 == s.removeDuplicates(v));
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, testRemoveDuplicates);
  return 0;
}
