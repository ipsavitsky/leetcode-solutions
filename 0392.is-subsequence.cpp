/**
 * @file 0392.is-subsequence.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/is-subsequence/
 * @version 0.1
 * @date 2023-04-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>

class Solution {
  public:
    bool isSubsequence(std::string s, std::string t) {
        std::string::const_iterator s_iter = s.cbegin();
        std::string::const_iterator t_iter = t.cbegin();

        while (s_iter != s.cend() && t_iter != t.cend()) {
            if (*s_iter == *t_iter) {
                ++s_iter;
            }
            ++t_iter;
        }

        return s_iter == s.cend();
    }
};