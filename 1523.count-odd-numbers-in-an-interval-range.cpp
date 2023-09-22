/**
 * @file 1523.count-odd-numbers-in-an-interval-range.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
 * @version 0.1
 * @date 2023-09-22
 *
 * @copyright Copyright (c) 2023
 *
 */
class Solution {
  public:
    int countOdds(int low, int high) {
        return (high - low + (high % 2 != 0 ? 1 : 0)) / 2 +
               (low % 2 != 0 ? 1 : 0);
    }
};
