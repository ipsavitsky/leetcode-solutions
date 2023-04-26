/**
 * @file 0205.isomorphic-string.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/isomorphic-strings/
 * @version 0.1
 * @date 2023-04-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <unordered_map>

class Solution {
  public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> replacement_chars;
        if (s.size() != t.size()) {
            return false;
        }

        using uint = unsigned int;
        for (uint i = 0; i < s.size(); ++i) {
            if (replacement_chars.count(s[i]) > 0 &&
                replacement_chars[s[i]] != t[i]) {
                return false;
            } else if (replacement_chars.count(s[i]) == 0 &&
                       std::find_if(replacement_chars.cbegin(),
                                    replacement_chars.cend(),
                                    [&t, i](auto &&p) {
                                        return p.second == t[i];
                                    }) != replacement_chars.cend()) {
                return false;
            } else {
                replacement_chars[s[i]] = t[i];
            }
        }
        return true;
    }
};