/**
 * @file 1822.sign-of-product.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/sign-of-the-product-of-an-array/
 * @version 0.1
 * @date 2023-09-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <numeric>
#include <vector>

class Solution {
  public:
    int arraySign(std::vector<int> &nums) {
        return std::accumulate(
            nums.begin(), nums.end(), 1, [](int sgn, int cur) {
                return sgn *= cur > 0 ? 1 : cur < 0 ? -1 : 0;
            });
    }
};
