/**
 * @file 2405.optimal-substring.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/optimal-partition-of-string/
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <array>
#include <iostream>

class Solution {
  public:
    int partitionString(std::string s) {
        using uchar = unsigned char;
        using uint = unsigned int;
        std::array<bool, 256> presence;
        std::fill(presence.begin(), presence.end(), false);
        uint res = 1;
        for (uchar a : s) {
            if (presence[a]) {
                ++res;
                std::fill(presence.begin(), presence.end(), false);
            }
            presence[a] = true;
        }
        return res;
    }
};
