#ifndef GRAPH_REVERSE_ODD_LEVELS_OF_BINARY_TREE_H
#define GRAPH_REVERSE_ODD_LEVELS_OF_BINARY_TREE_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

struct TreeNode;
class ReverseOddLevelsOfBinaryTreeTask : public Task {
    struct TestCase {
        TreeNode* root;
        TreeNode* expect;

        TestCase(TreeNode* root_, TreeNode* expect_)
            : root(root_), expect(expect_) {}
    };

public:
    ~ReverseOddLevelsOfBinaryTreeTask();

    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode


#endif