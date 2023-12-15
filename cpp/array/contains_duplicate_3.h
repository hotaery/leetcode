#ifndef ARRAY_CONTAINS_DUPLICATE_3_H
#define ARRAY_CONTAINS_DUPLICATE_3_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class ContainsDuplicate3Task : public Task {
    struct TestCase {
        std::vector<int> nums;
        int indexDiff;
        int valueDiff;
        bool expect;

        TestCase(const std::vector<int>& nums_, int indexDiff_, int valueDiff_, bool expect_)
            : nums(nums_), indexDiff(indexDiff_), valueDiff(valueDiff_), expect(expect_) {}
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