/**
 * @file 1372.longest-zigzag.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  private:
    void dfs(TreeNode *root, int &ans, int left, int right) {
        if (root == nullptr) {
            return;
        }
        ans = std::max(ans, std::max(left, right));
        dfs(root->left, ans, right + 1, 0);
        dfs(root->right, ans, 0, left + 1);
    }

  public:
    int longestZigZag(TreeNode *root) {
        int ans = 0;
        dfs(root, ans, 0, 0);
        return ans;
    }
};