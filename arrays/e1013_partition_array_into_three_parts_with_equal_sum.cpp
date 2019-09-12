/*
** LeetCode: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
*/

#include <iostream>
#include <vector>

#include "test_runner.h"

class Solution {
public:
  // O(N) time, O(1) space
  // Runtime: 20 ms
  // Memory Usage: 12.3 MB
  bool canThreePartsEqualSum(vector<int>& A) {
    int target = 0;
    for (auto i : A) target+= i;

    if (target % 3 != 0) return false;

    target /= 3;

    int equalSumCounter = 0, equalSum = 0;
    for (auto i : A) {
      equalSum += i;
      if (equalSum == target) {
        equalSumCounter++;
        equalSum = 0;
      }
    }

    return equalSumCounter ==  3;
  }
};

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

void testSolution() {
  Solution s;
  {
    vector<int> v = {0,2,1,-6,6,-7,9,1,2,0,1};
    ASSERT(s.canThreePartsEqualSum(v) == true);
  }
  {
    vector<int> v = {0,2,1,-6,6,7,9,-1,2,0,1};
    ASSERT(s.canThreePartsEqualSum(v) == false);
  }
  {
    vector<int> v = {3,3,6,5,-2,2,5,1,-9,4};
    ASSERT(s.canThreePartsEqualSum(v) == true);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, testSolution);
  return 0;
}
