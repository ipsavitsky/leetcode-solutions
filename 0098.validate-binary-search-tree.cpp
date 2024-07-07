/**
 * @file 0098.simplify-path.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/validate-binary-search-tree/
 * @version 0.1
 * @date 2024-07-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <optional>
#include <tuple>

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
  public:
    bool isValidBST(TreeNode *root) {
        return isValidBST2(root, std::nullopt, std::nullopt);
    }

    bool isValidBST2(TreeNode *root, std::optional<int> min,
                     std::optional<int> max) {
        if (!root)
            return true;

        if ((min.has_value() && root->val <= *min) ||
            (max.has_value() && root->val >= *max))
            return false;

        return isValidBST2(root->left, min, root->val) &&
               isValidBST2(root->right, root->val, max);
    }
};
