/**
 * @file 1512.number-of-good-pairs.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/number-of-good-pairs/
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int numIdenticalPairs(std::vector<int> &nums) {
        std::unordered_map<int, unsigned int> freq;
        int good_pairs = 0;
        for (int num : nums) {
            good_pairs += freq[num];
            ++freq[num];
        }
        return good_pairs;
    }
};
