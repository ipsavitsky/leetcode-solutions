/**
 * @file 1041.robot-bounded-circle.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/robot-bounded-in-circle/submissions/
 * @version 0.1
 * @date 2023-10-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>

enum class Direction { north = 0, east = 1, south = 2, west = 3 };

const std::unordered_map<Direction, Direction> lt = {
    {Direction::east, Direction::north},
    {Direction::north, Direction::west},
    {Direction::west, Direction::south},
    {Direction::south, Direction::east}};

const std::unordered_map<Direction, Direction> rt = {
    {Direction::east, Direction::south},
    {Direction::north, Direction::east},
    {Direction::west, Direction::north},
    {Direction::south, Direction::west}};

class Robot {
  private:
    std::tuple<int, int> coords{0, 0};
    Direction cur_dir = Direction::north;

  public:
    void turn_left() { cur_dir = lt.at(cur_dir); }

    void turn_right() { cur_dir = rt.at(cur_dir); }

    void move_forward() {
        switch (cur_dir) {
        case Direction::north:
            --std::get<0>(coords);
            break;
        case Direction::east:
            ++std::get<1>(coords);
            break;
        case Direction::south:
            ++std::get<0>(coords);
            break;
        case Direction::west:
            --std::get<1>(coords);
            break;
        }
        std::cout << "cur_dir = " << static_cast<int>(cur_dir) << std::endl;
        std::cout << "move_forward(): " << std::get<0>(coords) << ", "
                  << std::get<1>(coords) << std::endl;
    }

    bool is_home() { return coords == decltype(coords){0, 0}; }
};

class Solution {
  public:
    bool isRobotBounded(std::string instructions) {
        Robot robot;
        for (int i = 0; i < 4; ++i) {
            for (unsigned char c : instructions) {
                switch (c) {
                case 'G':
                    robot.move_forward();
                    break;
                case 'L':
                    robot.turn_left();
                    break;
                case 'R':
                    robot.turn_right();
                    break;
                }
            }

            if (robot.is_home()) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    std::cout << sol.isRobotBounded("GL") << std::endl;
}
