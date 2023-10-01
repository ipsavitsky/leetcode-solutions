/**
 * @file 1275.find-winner-on-a-tic-tac-toe-game.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/reverse-words-in-a-string-iii
 * @version 0.1
 * @date 2023-10-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <array>
#include <string>
#include <vector>

class Solution {
  public:
    std::string tictactoe(std::vector<std::vector<int>> &moves) {
        enum class cell_state { unset, X, O };
        std::array<cell_state, 9> grid;
        std::fill(grid.begin(), grid.end(), cell_state::unset);
        bool is_A_turn = true;
        for (const std::vector<int> &move : moves) {
            grid[move[0] * 3 + move[1]] =
                is_A_turn ? cell_state::X : cell_state::O;
            is_A_turn = !is_A_turn;
        }

        cell_state initial_state;

        for (int i = 0; i < 3; ++i) {
            initial_state = grid[i];

            if (initial_state != cell_state::unset &&
                grid[3 + i] == initial_state && grid[6 + i] == initial_state) {
                return initial_state == cell_state::X ? "A" : "B";
            }

            initial_state = grid[3 * i];

            if (initial_state != cell_state::unset &&
                grid[3 * i + 1] == initial_state &&
                grid[3 * i + 2] == initial_state) {
                return initial_state == cell_state::X ? "A" : "B";
            }
        }

        initial_state = grid[4];
        if (initial_state != cell_state::unset &&
            ((grid[0] == initial_state && grid[8] == initial_state) ||
             (grid[2] == initial_state && grid[6] == initial_state))) {
            return initial_state == cell_state::X ? "A" : "B";
        } else {
            return std::find(grid.begin(), grid.end(), cell_state::unset) !=
                           grid.end()
                       ? "Pending"
                       : "Draw";
        }
    }
};
