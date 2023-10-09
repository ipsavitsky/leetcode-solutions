/**
 * @file 0034.find-first-and-last-position-of-element-in-sorted-array.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * @version 0.1
 * @date 2023-10-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <iterator>
#include <vector>

using v_cit = std::vector<int>::const_iterator;

int iter_to_index(const std::vector<int> &range, v_cit iter, int target) {
    return (iter < range.cend()) && (iter >= range.cbegin()) &&
                   (*iter == target)
               ? std::distance(range.cbegin(), iter)
               : -1;
}

class Solution {
  public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        auto [first_it, last_it] =
            std::equal_range(nums.cbegin(), nums.cend(), target);
        if (std::distance(nums.cbegin(), last_it) > 0) {
            --last_it;
        }
        return std::vector<int>{iter_to_index(nums, first_it, target),
                                iter_to_index(nums, last_it, target)};
    }
};
