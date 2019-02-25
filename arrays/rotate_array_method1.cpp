/*
** Rotate Array by k steps to the right;
** https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
** time comlexity: O(k*n);
*/

#include <iostream>
#include <vector>
#include "test_runner.h"

using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    while (k > 0) {
      for (int i = nums.size() - 1; i > 0; --i) {
        swap(nums[i], nums[i - 1]);
      }
      --k;
    }
  }
};

void rotate_test() {
  Solution s;
  {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    vector<int> expected = {5, 6, 7, 1, 2, 3, 4};
    s.rotate(v, 3);
    ASSERT(v == expected);
  }
  {
    vector<int> v = {-1, -100, 3, 99};
    vector<int> expected = {3, 99, -1, -100};
    s.rotate(v, 2);
    ASSERT(v == expected);
  }
  {
    vector<int> v = {1, 2, 3};
    vector<int> expected = {1, 2, 3};
    s.rotate(v, 3);
    ASSERT(v == expected);
  }
  {
    vector<int> v = {1};
    vector<int> expected = {1};
    s.rotate(v, 4);
    ASSERT(v == expected);
  }
  {
    vector<int> v;
    vector<int> expected;
    s.rotate(v, 2);
    ASSERT(v == expected);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, rotate_test);
  return 0;
}
