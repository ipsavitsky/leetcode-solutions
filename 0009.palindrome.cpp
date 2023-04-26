/**
 * @file 0009.palindrome.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/palindrome-number/
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>

class Solution {
  public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        return std::equal(s.cbegin(), s.cbegin() + s.size() / 2, s.crbegin());
    }
};