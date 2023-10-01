/**
 * @file 0557.reverse-words-in-string-3.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * @version 0.1
 * @date 2023-10-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <cctype>
#include <string>

class Solution {
  public:
    std::string reverseWords(std::string s) {
        using s_it = std::string::iterator;
        s_it cur = s.begin();
        while (cur <= s.end()) {
            s_it space_it = std::find_if(
                cur, s.end(), [](unsigned char c) { return std::isspace(c); });
            std::reverse(cur, space_it);
            cur = space_it + 1;
        }
        return s;
    }
};
