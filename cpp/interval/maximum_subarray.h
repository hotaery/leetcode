#ifndef INTERVAL_MAXIMUM_SUBARRAY_H
#define INTERVAL_MAXIMUM_SUBARRAY_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class MaximumSubarrayTask : public Task {
    struct TestCase {
        std::vector<int> nums;
        int expect;

        TestCase(const std::vector<int>& nums_, int expect_)
            : nums(nums_)
            , expect(expect_) {}
    };
public:
    MaximumSubarrayTask();
    ~MaximumSubarrayTask();

    std::shared_ptr<Task> create() override;

    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif