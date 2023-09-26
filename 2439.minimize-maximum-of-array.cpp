/**
 * @file 2439.minimize-maximum-of-array.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/minimize-maximum-of-array/
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
  public:
    int minimizeArrayValue(std::vector<int> &nums) {
        using uint = unsigned int;
        uint prefix_sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            ans = std::max(ans, prefix_sum + i / (i + 1));
        }
        return ans;
    }
};