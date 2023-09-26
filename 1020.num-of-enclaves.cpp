/**
 * @file 1020.num-of-enclaves.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/number-of-enclaves/
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <vector>

class Solution {
  private:
    void dfs(std::vector<std::vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

  public:
    int numEnclaves(std::vector<std::vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            dfs(grid, i, 0);
            dfs(grid, i, grid[0].size() - 1);
        }
        for (int j = 0; j < grid[0].size(); j++) {
            dfs(grid, 0, j);
            dfs(grid, grid.size() - 1, j);
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};