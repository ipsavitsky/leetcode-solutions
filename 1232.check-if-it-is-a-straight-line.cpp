/**
 * @file 1232.check-if-it-is-a-straight-line.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/check-if-it-is-a-straight-line/
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <vector>

class Solution {
  public:
    bool checkStraightLine(std::vector<std::vector<int>> &coordinates) {
        int dx = coordinates[0][0] - coordinates[1][0];
        int dy = coordinates[0][1] - coordinates[1][1];

        for (int i = 2; i < coordinates.size(); ++i) {
            if (dy * (coordinates[i][0] - coordinates[0][0]) !=
                dx * (coordinates[i][1] - coordinates[0][1])) {
                return false;
            }
        }
        return true;
    }
};
