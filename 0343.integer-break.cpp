/**
 * @file 0343.integer-break.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/integer-break/
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <cmath>

class Solution {
  public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }

        switch (n % 3) {
        case 0:
            return std::pow(3, n / 3);
        case 1:
            return std::pow(3, n / 3) * 4;
        case 2:
            return std::pow(3, n / 3) * 2;
        }
    }
};
