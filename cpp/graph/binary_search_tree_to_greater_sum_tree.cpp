// https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree
#include "graph/binary_search_tree_to_greater_sum_tree.h"
#include "utils/binary_tree.h"
#include "utils/print.h"

#include <cassert>
#include <sstream>

namespace leetcode {
namespace _1038 {

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root, 0);
        return root;
    }

private:
    int dfs(TreeNode* root, int plus) {
        if (!root) {
            return 0;
        }
        int val = root->val;
        int right = dfs(root->right, plus);
        int left = dfs(root->left, right + val + plus);
        root->val += plus;
        root->val += right;
        return left + right + val;
    }
};

} // namespace _1038

BinarySearchTreeToGreaterSumTreeTask::~BinarySearchTreeToGreaterSumTreeTask() {
    for (TestCase& ts : test_case_list_) {
        DestroyBinaryTree(ts.root);
        DestroyBinaryTree(ts.expect);
    }
}

std::shared_ptr<Task> BinarySearchTreeToGreaterSumTreeTask::create() {
    std::shared_ptr<BinarySearchTreeToGreaterSumTreeTask> task = 
        std::make_shared<BinarySearchTreeToGreaterSumTreeTask>();
    task->InitTestCase();
    return task;
}

void BinarySearchTreeToGreaterSumTreeTask::run() {
    _1038::Solution sol;
    int failed = 0;
    for (TestCase& ts : test_case_list_) {
        TreeNode* actual = sol.bstToGst(ts.root);
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

void BinarySearchTreeToGreaterSumTreeTask::InitTestCase() {
    const std::string test_case_str = R"([4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
[0,null,1]
[1,null,1])";
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