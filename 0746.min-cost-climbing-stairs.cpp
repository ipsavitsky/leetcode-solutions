/**
 * @file 0746.min-cost-climbing-stairs.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/min-cost-climbing-stairs/
 * @version 0.1
 * @date 2023-10-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <cstddef>
#include <cstdint>
#include <vector>

class Solution {
  public:
    int minCostClimbingStairs(std::vector<int> &cost) {
        std::size_t n = cost.size();
        std::uint64_t prev1 = 0, prev2 = 0;

        for (int i = 2; i <= n; i++) {
            int current_cost =
                std::min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = current_cost;
        }

        return prev1;
    }
};
