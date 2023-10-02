/**
 * @file 1502.can-make-arithmetic-progression-from-sequence.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief
 * https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    bool canMakeArithmeticProgression(std::vector<int> &arr) {
        std::sort(arr.begin(), arr.end());
        std::adjacent_difference(arr.begin(), arr.end(), arr.begin());
        return std::all_of(std::next(arr.begin()), arr.end(),
                           [&arr](int cur) { return cur == arr.back(); });
    }
};
