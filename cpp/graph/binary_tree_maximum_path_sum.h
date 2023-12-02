#ifndef GRAPH_BINARY_TREE_MAXIMUM_PATH_SUM_H
#define GRAPH_BINARY_TREE_MAXIMUM_PATH_SUM_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

struct TreeNode;
class BinaryTreeMaximumPathSumTask : public Task {
    struct TestCase {
        TreeNode* root;
        int expect;

        TestCase(TreeNode* root_, int expect_)
            : root(root_)
            , expect(expect_) {}
    };
public:
    BinaryTreeMaximumPathSumTask();
    ~BinaryTreeMaximumPathSumTask();

    std::shared_ptr<Task> create() override;

    void run() override;

private:
    void InitTestCase();

    std::vector<TestCase> test_case_list_;
};

}

#endif