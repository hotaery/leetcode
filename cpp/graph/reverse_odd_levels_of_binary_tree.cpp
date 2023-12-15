// https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/description
#include "graph/reverse_odd_levels_of_binary_tree.h"
#include "nlohmann/json.hpp"
#include "utils/binary_tree.h"
#include "utils/print.h"

#include <queue>
#include <sstream>
#include <string>

namespace leetcode {
namespace _2415 {
    using std::swap;
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::vector<TreeNode*> level = {root};
        bool is_odd = false;
        while (!level.empty()) {
            std::vector<TreeNode*> next_level;
            int num = 2 * level.size();
            int idx = 0;
            is_odd = !is_odd;
            for (TreeNode* node : level) {
                if (!node->left) {
                    assert(!node->right);
                    assert(next_level.empty());
                    break;
                }
                next_level.push_back(node->left);
                idx++;
                if (idx > level.size() && is_odd) {
                    swap(next_level.back()->val, next_level[num - idx]->val);
                }
                next_level.push_back(node->right);
                idx++;
                if (idx > level.size() && is_odd) {
                    swap(next_level.back()->val, next_level[num - idx]->val);
                }
            }
            swap(level, next_level);
        }
        return root;
    }
};
} // namespace _2415

ReverseOddLevelsOfBinaryTreeTask::~ReverseOddLevelsOfBinaryTreeTask() {
    for (TestCase& ts : test_case_list_) {
        DestroyBinaryTree(ts.root);
        DestroyBinaryTree(ts.expect);
    }
    test_case_list_.clear();
}

std::shared_ptr<Task> ReverseOddLevelsOfBinaryTreeTask::create() {
    std::shared_ptr<ReverseOddLevelsOfBinaryTreeTask> task = 
        std::make_shared<ReverseOddLevelsOfBinaryTreeTask>();
    task->InitTestCase();
    return task;
}

void ReverseOddLevelsOfBinaryTreeTask::run() {
    _2415::Solution sol;
    int failed = 0;
    for (TestCase& ts : test_case_list_) {
        TreeNode* actual = sol.reverseOddLevels(ts.root);
        if (!BinaryTreeEqual(actual, ts.expect)) {
            failed++;
            std::cout << "testcase:{\n"
                    << "\troot:" << ts.root << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void ReverseOddLevelsOfBinaryTreeTask::InitTestCase() {
    const std::string test_case_str = R"([2,3,5,8,13,21,34]
[2,5,3,8,13,21,34]
[7,13,11]
[7,11,13]
[0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
[0,2,1,0,0,0,0,2,2,2,2,1,1,1,1])";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string tree_str;
        std::string expect;
        std::getline(stream, tree_str);
        std::getline(stream, expect);
        if (tree_str.empty()) {
            assert(!stream);
            break;
        }
        TreeNode* root = CreateBinaryTreeFromString(tree_str);
        TreeNode* expect_ = CreateBinaryTreeFromString(expect);
        test_case_list_.emplace_back(root, expect_);
    }
}

} // namespace leetcode