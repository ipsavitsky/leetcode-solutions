/**
 * @file 0287.find-duplicate-number.cpp
 * @author Ilysa Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/find-the-duplicate-number
 * @version 0.1
 * @date 2023-09-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>

class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        for (auto it = nums.cbegin(); it != std::prev(nums.cend()); ++it) {
            if (*it == *(it + 1)) {
                return *it;
            }
        }
        return 0;
    }
};
