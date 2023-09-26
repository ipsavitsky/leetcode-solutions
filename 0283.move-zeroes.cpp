/**
 * @file 0283.move-zeroes.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/move-zeroes/
 * @version 0.1
 * @date 2023-09-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <vector>

class Solution {
  public:
    void moveZeroes(std::vector<int> &nums) {
        using v_it = std::vector<int>::iterator;
        v_it j = nums.begin();
        for (v_it i = nums.begin(); i != nums.end(); ++i) {
            if (*i != 0) {
                std::iter_swap(i, j);
                j++;
            }
        }
    }
};
