#include "utils/binary_tree.h"
#include "nlohmann/json.hpp"

#include <queue>

namespace leetcode {

TreeNode* CreateBinaryTreeFromString(const std::string& data) {
    TreeNode* root = nullptr;
    nlohmann::json j = nlohmann::json::parse(data);
    assert(j.is_array());
    
    std::queue<TreeNode*> q;
    for (auto it = j.begin(); it != j.end(); ++it) {
        if (q.empty()) {
            assert(!it->is_null());
            root = new TreeNode(it->get<int>());
            q.push(root);
        } else {
            TreeNode* parent = q.front();
            if (!it->is_null()) {
                TreeNode* left = new TreeNode(it->get<int>());
                parent->left = left;
                q.push(left);
            }
            ++it;
            if (it == j.end()) {
                break;
            }
            if (it != j.end() && !it->is_null()) {
                TreeNode* right = new TreeNode(it->get<int>());
                parent->right = right;
                q.push(right);
            }
            q.pop();
        }
    }
    return root;
}

void DestroyBinaryTree(TreeNode* root) {
    if (!root) {
        return;
    }
    DestroyBinaryTree(root->left);
    DestroyBinaryTree(root->right);
    delete root;
}

std::string SerializeBinaryTree(const TreeNode* root) {
    nlohmann::json j = nlohmann::json::array({});
    std::queue<const TreeNode*> q;
    if (root) {
        q.push(root);
        j.push_back(root->val);
    }
    while (!q.empty()) {
        const TreeNode* parent = q.front();
        q.pop();
        if (parent->left) {
            q.push(parent->left);
        }
        if (parent->right) {
            q.push(parent->right);
        }
        if (parent->left) {
            j.push_back(parent->left->val);
        } else {
            if (!q.empty()) {
                j.push_back(nlohmann::json());
            }
        }
        if (parent->right) {
            j.push_back(parent->right->val);
        } else {
            if (!q.empty()) {
                j.push_back(nlohmann::json());
            }
        }
    }
    return j.dump();
}

} // namespace leetcode