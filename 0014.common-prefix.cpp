/**
 * @file 14.common-prefix.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/longest-common-prefix/
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    std::string longestCommonPrefix(std::vector<std::string> &strs) {
        using uint = unsigned int;
        const std::string &first = strs[0];
        for (uint i = 0; i < strs[0].size(); ++i) {
            if (std::any_of(strs.begin(), strs.end(),
                            [&i, &first](const std::string &cur) {
                                return cur[i] != first[i];
                            })) {
                return std::string(first.begin(), std::next(first.begin(), i));
            }
        }
        return first;
    }
};