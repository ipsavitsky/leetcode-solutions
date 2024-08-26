/**
 * @file 0590.n-ary-tree-postorder-traversal.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/n-ary-tree-postorder-traversal/
 * @version 0.1
 * @date 2024-08-26
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <vector>

// Definition for a Node.
class Node {
  public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    std::vector<int> postorder(Node *root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<int> result;

        for (auto child : root->children) {
            std::vector<int> a = postorder(child);
            result.insert(result.end(), a.begin(), a.end());
        }

        result.push_back(root->val);
        return result;
    }
};
