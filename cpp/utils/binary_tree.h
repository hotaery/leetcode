#ifndef UTILS_BINARY_TREE_H
#define UTILS_BINARY_TREE_H

#include <string>

namespace leetcode {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* CreateBinaryTreeFromString(const std::string& data);

void DestroyBinaryTree(TreeNode* root);

std::string SerializeBinaryTree(const TreeNode* root);

} // namespace leetcode

#endif