/**
 * @file 724.pivot-index.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/find-pivot-index
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <vector>
#include <numeric>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        for (std::vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); ++it) {
            int left_sum = std::accumulate(nums.cbegin(), it, 0);
            int right_sum = std::accumulate(std::next(it), nums.cend(), 0);
            if (left_sum == right_sum) {
                return std::distance(nums.cbegin(), it);
            }
        }
        return -1;
    }
};