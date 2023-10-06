/**
 * @file 0229.majority-element-ii.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/majority-element-ii/
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> majorityElement(std::vector<int> &nums) {
        std::unordered_map<int, int> calc;

        for (const int n : nums) {
            ++calc[n];
        }

        std::vector<int> res;
        for (auto [num, ctn] : calc) {
            if (ctn > nums.size() / 3) {
                res.push_back(num);
            }
        }

        return res;
    }
};
