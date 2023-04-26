/**
 * @file 1046.last-stone-weight.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/last-stone-weight/
 * @version 0.1
 * @date 2023-04-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <algorithm>
#include <vector>

class Solution {
  public:
    int lastStoneWeight(std::vector<int> &stones) {
        auto begin_it = stones.begin();
        while (std::distance(begin_it, stones.end()) > 1) {
            std::nth_element(begin_it, std::next(stones.begin()), stones.end(),
                             std::greater{});
            
            if (*begin_it == *std::next(begin_it)) {
                begin_it = std::next(begin_it, 2);
            } else {
                *begin_it -= *std::next(begin_it);
                std::swap(*begin_it, *std::next(begin_it));
                ++begin_it;
            }
        }
        return std::distance(begin_it, stones.end()) > 0 ? *begin_it : 0;
    }
};
