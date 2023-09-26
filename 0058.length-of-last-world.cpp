/**
 * @file 0058.length-of-last-world.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/length-of-last-word
 * @version 0.1
 * @date 2023-09-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <iterator>
#include <string>

class Solution {
  public:
    int lengthOfLastWord(std::string s) {
        std::string::reverse_iterator first_nonwhitespace = s.rbegin();
        while (std::isspace(*first_nonwhitespace))
            ++first_nonwhitespace;
        std::string::reverse_iterator first_space =
            std::find_if(first_nonwhitespace, s.rend(),
                         [](unsigned int c) { return std::isspace(c); });
        return std::distance(first_nonwhitespace, first_space);
    }
};
