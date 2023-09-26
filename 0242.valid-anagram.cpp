/**
 * @file 0242.valid-anagram.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/valid-anagram/
 * @version 0.1
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <string>

class Solution {
  public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return std::equal(s.begin(), s.end(), t.begin(), t.end());
    }
};
