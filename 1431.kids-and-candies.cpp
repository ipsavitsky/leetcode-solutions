/**
 * @file 1431.kids-and-candies.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
 * @version 0.1
 * @date 2023-04-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <vector>

class Solution {
  public:
    std::vector<bool> kidsWithCandies(std::vector<int> candies,
                                      int extraCandies) {
        int max_candies = *std::max_element(candies.begin(), candies.end());
        std::vector<bool> res;
        res.reserve(candies.size());
        std::transform(candies.begin(), candies.end(), std::back_inserter(res),
                       [&max_candies, &extraCandies](int cur_candies) {
                           return cur_candies + extraCandies >= max_candies;
                       });
        return res;
    }
};