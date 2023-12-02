#include "graph/binary_tree_maximum_path_sum.h"
#include "nlohmann/json.hpp"
#include "utils/binary_tree.h"
#include "utils/print.h"

#include <climits>

namespace leetcode {
namespace _124 {

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* root, int& ans) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        ans = std::max(ans, root->val);
        if (root->left) {
            ans = std::max(ans, left);
            ans = std::max(ans, left + root->val);
        } 
        if (root->right) {
            ans = std::max(ans, right);
            ans = std::max(ans, right + root->val);
        }
        ans = std::max(ans, left + right + root->val);
        return std::max(std::max(left, right) + root->val, root->val);
    }
};

} // namespace _124

BinaryTreeMaximumPathSumTask::BinaryTreeMaximumPathSumTask() {}

BinaryTreeMaximumPathSumTask::~BinaryTreeMaximumPathSumTask() {
    for (TestCase& t : test_case_list_) {
        DestroyBinaryTree(t.root);
    }
}

std::shared_ptr<Task> BinaryTreeMaximumPathSumTask::create() {
    std::shared_ptr<BinaryTreeMaximumPathSumTask> task = std::make_shared<BinaryTreeMaximumPathSumTask>();
    task->InitTestCase();
    return task;
}

void BinaryTreeMaximumPathSumTask::run() {
    _124::Solution sol;
    int failed = 0;
    for (TestCase& t : test_case_list_) {
        int actual = sol.maxPathSum(t.root);
        if (actual != t.expect) {
            std::cout << "TestCase:{\n"
                      << "\ttree:" << t.root << "\n"
                      << "}\n"
                      << "expect:" << t.expect << "\n"
                      << "actual:" << actual << "\n\n";
            ++failed;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
              << "FAILED:" << failed << "\n";
    std::cout.flush();
}

void BinaryTreeMaximumPathSumTask::InitTestCase() {
    const std::string test_case_str = R"([1,2,3]
6
[-10,9,20,null,null,15,7]
42
[-3]
-3
[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
16)";
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
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(root, expect_);
    }
}

} // namespace leetcode