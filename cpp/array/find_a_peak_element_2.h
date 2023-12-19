#ifndef ARRAY_FIND_A_PEAK_ELEMENT_2_H
#define ARRAY_FIND_A_PEAK_ELEMENT_2_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class FindAPeakElement2Task : public Task {
    struct TestCase {
        std::vector<std::vector<int>> mat;
        std::vector<std::vector<int>> expect;

        TestCase(const std::vector<std::vector<int>>& mat_,
                const std::vector<std::vector<int>>& expect_)
            : mat(mat_), expect(expect_) {}
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