/**
 * @file 0316.remove-duplicate-letters.cpp
 * @author Ilysa Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/remove-duplicate-letters
 * @version 0.1
 * @date 2023-09-26
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
  public:
    std::string removeDuplicateLetters(std::string s) {
        using s_it = std::string::iterator;
        using uchar = unsigned char;
        std::unordered_map<uchar, s_it> last_usage;

        for (s_it cur = s.begin(); cur != s.end(); ++cur) {
            last_usage[*cur] = cur;
        }

        std::unordered_set<uchar> visited;
        std::deque<s_it> res;

        for (s_it cur = s.begin(); cur != s.end(); ++cur) {
            if (!visited.contains(*cur)) {
                while (!res.empty() && *(res.back()) > *cur &&
                       cur < last_usage[*(res.back())]) {
                    visited.erase(*(res.back()));
                    res.pop_back();
                }
                res.push_back(cur);
                visited.insert(*cur);
            }
        }

        std::string res_s;
        res_s.reserve(s.size());
        std::transform(res.begin(), res.end(), std::back_inserter(res_s),
                       [](const s_it &cur) { return *cur; });

        return res_s;
    }
};
