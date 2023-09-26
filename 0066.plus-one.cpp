/**
 * @file 0066.plus-one.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/plus-one
 * @version 0.1
 * @date 2023-09-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <vector>

class Solution {
  public:
    std::vector<int> plusOne(std::vector<int> &digits) {
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (*it + 1 > 9) {
                *it = 0;
            } else {
                ++*it;
                break;
            }
        }
        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
