/**
 * @file 0389.find-the-difference.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/find-the-difference/
 * @version 0.1
 * @date 2023-09-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <string>

class Solution {
  public:
    char findTheDifference(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        std::string::iterator it =
            std::mismatch(s.begin(), s.end(), t.begin(), t.end()).second;
        return *it;
    }
};
