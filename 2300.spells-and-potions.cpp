/**
 * @file 2300.spells-and-potions.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
 * @version 0.1
 * @date 2023-04-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    std::vector<int> successfulPairs(std::vector<int> &spells,
                                     std::vector<int> &potions,
                                     long long success) {
        std::sort(potions.begin(), potions.end());
        std::vector<int> pairs;
        pairs.reserve(spells.size());
        for (int spell : spells) {
            std::vector<int>::iterator f_p =
                std::lower_bound(potions.begin(), potions.end(), success,
                                 [spell](long cur_pot, long long succ) {
                                     return spell * cur_pot < succ;
                                 });
            pairs.push_back(std::distance(f_p, potions.end()));
        }
        return pairs;
    }
};
