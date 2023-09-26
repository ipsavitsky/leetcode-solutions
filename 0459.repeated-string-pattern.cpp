/**
 * @file 0459.repeated-string-pattern.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/repeated-substring-pattern/
 * @version 0.1
 * @date 2023-09-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <regex>
#include <string>

class Solution {
  public:
    bool repeatedSubstringPattern(std::string s) {
        for (int i = 1; i <= s.size() / 2; ++i) {
            if (s.size() % i != 0) {
                continue;
            }
            std::string s_sub_s = s.substr(0, i);
            std::regex r("(" + s_sub_s + ")+");
            if (std::regex_match(s, r)) {
                return true;
            }
        }
        return false;
    }
};
