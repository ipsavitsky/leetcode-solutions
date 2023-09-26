/**
 * @file 1491.average-salary-excluding-minimum-and-maximum-salary.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief
 * https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
 * @version 0.1
 * @date 2023-09-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    double average(std::vector<int> &salary) {
        const auto [min, max] =
            std::minmax_element(salary.begin(), salary.end());
        unsigned int sum = std::accumulate(salary.begin(), salary.end(), 0);
        return (sum - *min - *max) / static_cast<double>(salary.size() - 2);
    }
};
