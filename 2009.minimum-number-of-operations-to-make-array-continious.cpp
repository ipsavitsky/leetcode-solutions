/**
 * @file 2009.minimum-number-of-operations-to-make-array-continious.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief
 * https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
 * @version 0.1
 * @date 2023-10-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <vector>

class Solution {
  public:
    int minOperations(std::vector<int> &nums) {
        using v_cit = std::vector<int>::const_iterator;
        std::size_t len = nums.size();
        std::uint64_t res = len;
        std::sort(nums.begin(), nums.end());
        v_cit last = std::unique(nums.begin(), nums.end());
        v_cit right = nums.cbegin();
        for (v_cit left = nums.cbegin(); left < last; ++left) {
            while (right < last && *right < *left + len) {
                ++right;
            }
            std::uint64_t cnt = std::distance(left, right);
            res = std::min(res, len - cnt);
        }
        return res;
    }
};
