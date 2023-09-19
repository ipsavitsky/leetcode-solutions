/**
 * @file 0028.find-the-index-of-the-first-occurence-of-string.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/simplify-path/
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
    int strStr(std::string haystack, std::string needle) {
        std::string::iterator it = std::search(haystack.begin(), haystack.end(),
                                               needle.begin(), needle.end());
        return it == haystack.end() ? -1 : std::distance(haystack.begin(), it);
    }
};
