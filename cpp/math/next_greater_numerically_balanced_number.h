#ifndef MATH_NEXT_GREATER_NUMERICALLY_BALANCED_NUMBER_H
#define MATH_NEXT_GREATER_NUMERICALLY_BALANCED_NUMBER_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class NextGreaterNumericallyBalancedNumberTask : public Task {
    struct TestCase {
        int n;
        int expect;

        TestCase(int n_, int expect_) : n(n_), expect(expect_) {}
    };
public:
    NextGreaterNumericallyBalancedNumberTask() = default;
    ~NextGreaterNumericallyBalancedNumberTask() {}

    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif