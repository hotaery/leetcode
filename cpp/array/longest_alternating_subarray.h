#ifndef ARRAY_LONGEST_ALTERNATING_SUBARRAY_H

#include "utils/regsitery.h"

namespace leetcode {
class LongestAlternatingSubarrayTask : public Task {
    struct TestCase {
        std::vector<int> nums;
        int expect;

        TestCase(std::vector<int> nums_, int expect_)
            : nums(nums_), expect(expect_) {}
    };
public:
    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCases();

private:
    std::vector<TestCase> test_cases_;
};
} // namespace leetcode

#endif 