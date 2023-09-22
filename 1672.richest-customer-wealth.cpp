/**
 * @file 1672.richest-customer-wealth.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/richest-customer-wealth
 * @version 0.1
 * @date 2023-09-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    int maximumWealth(std::vector<std::vector<int>> &accounts) {
        std::vector<int> balances;
        balances.reserve(accounts.size());
        std::transform(accounts.begin(), accounts.end(),
                       std::back_inserter(balances),
                       [](const std::vector<int> &cur) {
                           return std::accumulate(cur.begin(), cur.end(), 0);
                       });
        return *std::max_element(balances.begin(), balances.end());
    }
};
