#ifndef ARRAY_NEXT_GREATER_ELEMENT_4_H
#define ARRAY_NEXT_GREATER_ELEMENT_4_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class NextGreaterElement4Task : public Task {
    struct TestCase {
        std::vector<int> nums;
        std::vector<int> expect;

        TestCase(const std::vector<int>& nums_, const std::vector<int>& expect_)
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
