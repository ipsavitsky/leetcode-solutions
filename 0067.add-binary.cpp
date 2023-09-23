/**
 * @file 0067.add-binary.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/add-binary
 * @version 0.1
 * @date 2023-09-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <string>

class Solution {
  public:
    std::string addBinary(std::string a, std::string b) {
        using s_rit = std::string::reverse_iterator;
        s_rit a_it = a.rbegin(), b_it = b.rbegin();
        std::string res;
        res.reserve(a.size() + b.size());
        int cur = 0;
        while (a_it != a.rend() || b_it != b.rend() || cur > 0) {
            if (a_it != a.rend()) {
                cur += *a_it - '0';
                ++a_it;
            }
            if (b_it != b.rend()) {
                cur += *b_it - '0';
                ++b_it;
            }
            res.push_back(cur % 2 == 1 ? '1' : '0');
            cur >>= 1;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
