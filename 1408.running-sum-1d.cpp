/**
 * @file 1408.running-sum-1d.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/running-sum-of-1d-array
 * @version 0.1
 * @date 2023-04-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <numeric>
#include <vector>

class Solution {
  public:
    std::vector<int> runningSum(std::vector<int> &nums) {
        std::vector<int> res;
        res.reserve(nums.size());
        std::partial_sum(nums.begin(), nums.end(), std::back_inserter(res));
        return res;
    }
};