/**
 * @file 0799.champagne-tower.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/champagne-tower
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <vector>

class Solution {
  public:
    double champagneTower(int poured, int query_row, int query_glass) {
        std::vector<double> cur_row(1, poured);
        for (int i = 0; i < query_row; ++i) {
            std::vector<double> new_row(cur_row.size() + 1, 0);
            for (int j = 0; j < cur_row.size(); ++j) {
                new_row[j] += std::max((cur_row[j] - 1) / 2, 0.);
                new_row[j + 1] += std::max((cur_row[j] - 1) / 2, 0.);
            }
            cur_row = new_row;
        }
        return std::min(1., cur_row[query_glass]);
    }
};
