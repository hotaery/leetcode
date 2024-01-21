#ifndef DP_SPLIT_ARRAY_LARGEST_SUM_H
#define DP_SPLIT_ARRAY_LARGEST_SUM_H

#include "utils/regsitery.h"

namespace leetcode {
class SplitArrayLargestSumTask : public Task {
    struct TestCase {
        std::vector<int> nums;
        int k;
        int expect;

        TestCase(const std::vector<int>& nums_, int k_, int expect_)
            : nums(nums_), k(k_), expect(expect_) {}
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