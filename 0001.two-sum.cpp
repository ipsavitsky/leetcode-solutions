/**
 * @file 0001.two-sum.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/two-sum/
 * @version 0.1
 * @date 2023-04-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iterator>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        for (std::vector<int>::const_iterator f = nums.cbegin();
             f != nums.cend(); ++f) {
            for (std::vector<int>::const_iterator s = std::next(f);
                 s != nums.cend(); ++s) {
                if (target == *f + *s) {
                    return std::vector<int>{
                        static_cast<int>(std::distance(nums.cbegin(), f)),
                        static_cast<int>(std::distance(nums.cbegin(), s))};
                }
            }
        }
        return {};
    }
};