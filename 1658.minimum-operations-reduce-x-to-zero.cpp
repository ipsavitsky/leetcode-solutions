/**
 * @file 1658.minimum-operations-reduce-x-to-zero.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
 * @version 0.1
 * @date 2023-09-20
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <numeric>
#include <vector>

class Solution {
  public:
    int minOperations(std::vector<int> &nums, int x) {
        int n = nums.size();
        int target = std::accumulate(nums.begin(), nums.end(), 0);
        target -= x;

        if (target == 0)
            return n;

        int max_len = 0, cur_sum = 0;
        auto left_it = nums.begin();

        for (auto right_it = nums.begin(); right_it != nums.end(); ++right_it) {
            cur_sum += *right_it;
            while (left_it <= right_it && cur_sum > target) {
                cur_sum -= *left_it;
                left_it++;
            }
            if (cur_sum == target) {
                max_len = std::max(
                    max_len,
                    static_cast<int>(std::distance(left_it, right_it) + 1));
            }
        }
        return max_len ? n - max_len : -1;
    }
};
