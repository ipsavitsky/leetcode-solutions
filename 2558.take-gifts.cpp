/**
 * @file 2558.take-gifts.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/take-gifts-from-the-richest-pile/
 * @version 0.1
 * @date 2023-04-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <cmath>
#include <numeric>
#include <vector>

class Solution {
  public:
    long long pickGifts(std::vector<int> &gifts, int k) {
        for (int i = 0; i < k; ++i) {
            std::vector<int>::iterator m_iter =
                std::max_element(gifts.begin(), gifts.end());
            *m_iter = std::sqrt(*m_iter);
        }
        return std::accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};