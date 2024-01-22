#ifndef MATH_MAXIMUM_SWAP_H
#define MATH_MAXIMUM_SWAP_H

#include "utils/regsitery.h"

namespace leetcode {
class MaximumSwapTask : public Task {
    struct TestCase {
        int num;
        int expect;

        TestCase(int num_, int expect_) : num(num_), expect(expect_) {}
    };
public:
    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};
} // namespace leetcode

#endif