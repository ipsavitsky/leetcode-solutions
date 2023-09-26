/**
 * @file 0389.find-the-difference.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/find-the-difference/
 * @version 0.1
 * @date 2023-09-25
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <numeric>
#include <string>

class Solution {
  public:
    char findTheDifference(std::string s, std::string t) {
        int sum_s = std::accumulate(s.begin(), s.end(), 0);
        int sum_t = std::accumulate(t.begin(), t.end(), 0);
        return sum_t - sum_s;
    }
};
