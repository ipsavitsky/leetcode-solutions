/**
 * @file 0905.sort-array-by-parity.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/sort-array-by-parity/
 * @version 0.1
 * @date 2023-09-28
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<int> sortArrayByParity(std::vector<int> &nums) {
        using v_it = std::vector<int>::iterator;
        v_it pos_it = nums.begin();
        while (pos_it != nums.end() && *pos_it % 2 == 0) {
            ++pos_it;
        }
        for (v_it rolling_it = pos_it; rolling_it != nums.end(); ++rolling_it) {
            if (*rolling_it % 2 == 0) {
                std::iter_swap(pos_it, rolling_it);
                ++pos_it;
            }
        }
        return std::move(nums);
    }
};
