/**
 * @file 1456.max-vowels.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <numeric>
#include <string>
#include <unordered_set>

class Solution {
  private:
    const std::unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

    bool is_vowel(char checking) { return VOWELS.count(checking) != 0; }

  public:
    int maxVowels(std::string s, int k) {
        std::string_view s_2{s.c_str(), s.size()};
        std::string_view window = s_2.substr(0, k);
        int number_of_vowels = std::accumulate(
            window.begin(), window.end(), 0, [this](int sum, char cur) {
                return sum + (is_vowel(cur) ? 1 : 0);
            });
        int max_number_of_vowels = number_of_vowels;

        for (int i = 1; i < s_2.size() - k + 1; ++i) {
            char first_char = window[0];
            if (is_vowel(first_char))
                --number_of_vowels;
            window = s_2.substr(i, k);
            if (is_vowel(*std::prev(window.end())))
                ++number_of_vowels;

            max_number_of_vowels =
                std::max(max_number_of_vowels, number_of_vowels);
        }
        return max_number_of_vowels;
    }
};
