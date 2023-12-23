#ifndef ARRAY_MINIMUM_NUMBER_OF_REMOVALS_TO_MAKE_MOUNTAIN_ARRAY_H
#define ARRAY_MINIMUM_NUMBER_OF_REMOVALS_TO_MAKE_MOUNTAIN_ARRAY_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class MinimumNumberOfRemovalsToMakeMountainArrayTask : public Task {
    struct  TestCase {
        std::vector<int> nums;
        int expect;

        TestCase(const std::vector<int>& nums_, int expect_)
            : nums(nums_), expect(expect_) {}
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