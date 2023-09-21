/**
 * @file 0709.to-lower-case.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/to-lower-case
 * @version 0.1
 * @date 2023-09-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

class Solution {
  public:
    std::string toLowerCase(std::string s) {
        std::transform(
            s.begin(), s.end(), s.begin(),
            [](unsigned char cur) -> unsigned char { return tolower(cur); });
        return s;
    }
};
