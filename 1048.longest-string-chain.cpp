/**
 * @file 1048.longest-string-chain.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/longest-string-chain
 * @version 0.1
 * @date 2023-09-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    using v_it = std::vector<std::string>::const_iterator;

  private:
    std::unordered_map<std::string, int> memoized_values = {};

  public:
    bool is_predecessor(const std::string &a, const std::string &b) {
        auto [p1, p2] = std::mismatch(a.begin(), a.end(), b.begin(), b.end());
        ++p2;
        return std::equal(p1, a.end(), p2, b.end());
    }

    int find_longest_chain_mem(const std::vector<std::string> &words,
                               const v_it &start_word, int cur_len) {
        if (this->memoized_values.count(*start_word) != 0) {
            return this->memoized_values[*start_word] + cur_len;
        }
        int res = find_longest_chain(words, start_word, cur_len);
        this->memoized_values[*start_word] = res - cur_len;
        return res;
    }

    int find_longest_chain(const std::vector<std::string> &words,
                           const v_it &start_word, int cur_len) {
        std::vector<int> results;
        for (v_it next_iterator = words.begin(); next_iterator != words.end();
             ++next_iterator) {
            if (is_predecessor(*start_word, *next_iterator)) {
                int sub_len =
                    find_longest_chain_mem(words, next_iterator, cur_len + 1);
                results.push_back(sub_len);
            }
        }
        if (results.empty()) {
            return cur_len + 1;
        } else {
            return *std::max_element(results.begin(), results.end());
        }
    }

    int longestStrChain(std::vector<std::string> &words) {
        std::vector<int> results;
        for (v_it cur = words.begin(); cur != words.end(); ++cur) {
            int cur_res = find_longest_chain_mem(words, cur, 0);
            results.push_back(cur_res);
        }
        return *std::max_element(results.begin(), results.end());
    }
};

