/**
 * @file 0119.pascals-triangle-ii.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/pascals-triangle-ii/
 * @version 0.1
 * @date 2023-10-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <cstdint>
#include <vector>

class Solution {
  public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res;
        res.reserve(rowIndex + 1);
        std::uint64_t prev = 1;
        res.push_back(prev);
        for (int k = 1; k <= rowIndex; k++) {
            std::uint64_t next_val = prev * (rowIndex - k + 1) / k;
            res.push_back(next_val);
            prev = next_val;
        }
        return res;
    }
};
