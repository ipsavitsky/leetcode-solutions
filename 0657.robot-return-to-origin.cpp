/**
 * @file 0657.robot-return-to-origin.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/robot-return-to-origin
 * @version 0.1
 * @date 2023-09-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>
#include <tuple>

class Solution {
  public:
    bool judgeCircle(std::string moves) {
        std::tuple<int, int> coord = {0, 0};
        for (char c : moves) {
            switch (c) {
            case 'D':
                std::get<0>(coord)--;
                break;
            case 'U':
                std::get<0>(coord)++;
                break;
            case 'L':
                std::get<1>(coord)--;
                break;
            case 'R':
                std::get<1>(coord)++;
                break;
            }
        }
        return coord == std::tuple<int, int>{0, 0};
    }
};
