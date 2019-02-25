/*
* Problem #121 https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
* Problem source: LeetCode
*/

#include <iostream>
#include "test_runner.h"
#include <vector>

class Solution {
public:
  int maxProfit(const vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int min_value = prices[0], day = 0;

    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] < min_value) {
        min_value = prices[i];
        day = i;
      }
    }

    int max_value = min_value;

    for (int i = ++day; i < prices.size(); ++i) {
      if (prices[i] > max_value) {
        max_value = prices[i];
      }
    }

    return max_value - min_value;
  }
};

void maxProfitTest() {
  Solution s;
  {
    vector<int> v;
    ASSERT(s.maxProfit(v) == 0);
  }
  {
    vector<int> v = {1};
    ASSERT(s.maxProfit(v) == 0);
  }
  {
    vector<int> v = {7, 1, 5, 3, 6, 4};
    ASSERT(s.maxProfit(v) == 5);
  }
  {
    vector<int> v = {7, 6, 4, 3, 1};
    ASSERT(s.maxProfit(v) == 0);
  }
  {
    vector<int> v = {4, 4, 4};
    ASSERT(s.maxProfit(v) == 0);
  }
  {
    vector<int> v = {2, 4, 1};
    ASSERT(s.maxProfit(v) == 2);
  }
}

int main() {
 TestRunner tr;
 RUN_TEST(tr, maxProfitTest);
 return 0;
}
