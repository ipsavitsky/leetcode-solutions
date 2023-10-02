/**
 * @file 2038.remove-colored-pieces-if-both-neighbors-are-the-same-color.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief
 * https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <span>
#include <string>

class Solution {
  public:
    bool winnerOfGame(std::string colors) {
        if (colors.size() < 3) {
            return false;
        }

        const std::span str_s{colors};
        const std::string A_str = "AAA", B_str = "BBB";
        int win_ctr = 0;
        for (std::size_t offset = 0; offset < colors.size() - 2; ++offset) {
            const auto window = str_s.subspan(offset, 3);
            if (std::equal(window.begin(), window.end(), A_str.begin(),
                           A_str.end())) {
                ++win_ctr;
            } else if (std::equal(window.begin(), window.end(), B_str.begin(),
                                  B_str.end())) {
                --win_ctr;
            }
        }
        return win_ctr > 0;
    }
};
