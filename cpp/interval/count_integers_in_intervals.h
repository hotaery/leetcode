#ifndef INTERVAL_COUNT_INTEGERS_IN_INTERVALS_H
#define INTERVAL_COUNT_INTEGERS_IN_INTERVALS_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class CountIntegersInIntervalsTask : public Task {
    struct TestCase {
        std::vector<std::string> ops;
        std::vector<std::vector<int>> args;
        std::vector<int> expect;

        TestCase(const std::vector<std::string>& ops_, 
                const std::vector<std::vector<int>>& args_,
                const std::vector<int>& expect_)
            : ops(ops_), args(args_), expect(expect_) {}
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