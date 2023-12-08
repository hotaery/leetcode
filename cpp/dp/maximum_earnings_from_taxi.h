#ifndef DP_MAXIMUM_EARNINGS_FROM_TAXI_H
#define DP_MAXIMUM_EARNINGS_FROM_TAXI_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class MaximumEarningsFromTaxiTask : public Task {
    struct TestCase {
        int n;
        std::vector<std::vector<int>> rides;
        long long expect;

        TestCase(int n_, const std::vector<std::vector<int>>& rides_, long long expect_)
            : n(n_), rides(rides_), expect(expect_) {}
    };
public:
    MaximumEarningsFromTaxiTask();
    ~MaximumEarningsFromTaxiTask();

    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif