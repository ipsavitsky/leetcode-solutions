/**
 * @file 0880.decoded-string-at-index.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/decoded-string-at-index/
 * @version 0.1
 * @date 2023-09-28
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>
#include <vector>

class Solution {
  public:
    std::string decodeAtIndex(std::string s, int k) {
        unsigned long long length = 0;

        using s_it = std::string::iterator;
        s_it cur = s.begin();
        s_it prev = cur;

        for (s_it cur = s.begin(); cur < s.end(); ++cur) {
            if (isdigit(*cur)) {
                length *= *cur - '0';
            } else {
                length++;
            }
        }

        using rs_it = std::reverse_iterator<s_it>;

        for (rs_it rcur = s.rbegin(); rcur != s.rend(); ++rcur) {
            if (isdigit(*rcur)) {
                length /= (*rcur - '0');
                k %= length;
            } else {
                if (k == 0 || k == length) {
                    return std::string(1, *rcur);
                }
                --length;
            }
        }

        return "";
    }
};
