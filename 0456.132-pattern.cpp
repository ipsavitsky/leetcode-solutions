/**
 * @file 0456.132-pattern.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/132-pattern/
 * @version 0.1
 * @date 2023-09-30
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <numeric>
#include <stack>
#include <vector>

class Solution {
  public:
    bool find132pattern(std::vector<int> &nums) {
        using val_type = std::remove_reference_t<decltype(nums)>::value_type;
        std::stack<val_type> num_stack;
        std::vector<val_type> mins;
        mins.reserve(nums.size());
        std::partial_sum(nums.cbegin(), nums.cend(), std::back_inserter(mins),
                         [](val_type a, val_type b) { return std::min(a, b); });
        using v_crit = std::vector<val_type>::const_reverse_iterator;
        v_crit nums_it = nums.rbegin();
        v_crit mins_it = mins.rbegin();
        while (nums_it != nums.rend() && mins_it != mins.rend()) {
            if (*nums_it < *mins_it) {
                continue;
            }

            while (!num_stack.empty() && num_stack.top() <= *mins_it) {
                num_stack.pop();
            }

            if (!num_stack.empty() && num_stack.top() < *nums_it) {
                return true;
            }
            num_stack.push(*nums_it);
            ++nums_it;
            ++mins_it;
        }
        return false;
    }
};
