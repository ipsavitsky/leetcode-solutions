/**
 * @file 1768.merge-strings.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/merge-strings-alternately/
 * @version 0.1
 * @date 2023-04-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <string>

class Solution {
  public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string res;
        res.reserve(word1.size() + word2.size());
        std::string::const_iterator w1_it = word1.cbegin();
        std::string::const_iterator w2_it = word2.cbegin();
        while (w1_it != word1.cend() || w2_it != word2.cend()) {
            if (w1_it != word1.cend()) {
                res.push_back(*w1_it);
                ++w1_it;
            }
            if (w2_it != word1.cend()) {
                res.push_back(*w1_it);
                ++w2_it;
            }
        }
        return res;
    }
};