#ifndef INTERVAL_SKLINE_PROBLEM_H
#define INTERVAL_SKLINE_PROBLEM_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class TheSklineProblemTask : public Task {
    struct TestCase {
        std::vector<std::vector<int>> buildings;
        std::vector<std::vector<int>> expect;

        TestCase(const std::vector<std::vector<int>>& buildings_, 
                 const std::vector<std::vector<int>>& expect_)
            : buildings(buildings_), expect(expect_) {}
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