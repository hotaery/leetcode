#ifndef DP_MAXIMUM_NUMBER_THAT_SUM_OF_THE_PRICE_LS_LESS_THAN_OR_EQUAL_TO_K_H
#define DP_MAXIMUM_NUMBER_THAT_SUM_OF_THE_PRICE_LS_LESS_THAN_OR_EQUAL_TO_K_H

#include "utils/regsitery.h"

namespace leetcode {

class MaximumNumberThatSumOfThePriceLsLessThanOrEqualToKTask : public Task {
    struct TestCase {
        long long k;
        int x;
        long long expect;

        TestCase(long long k_, long long x_, long long expect_)
            : k(k_), x(x_), expect(expect_) {}
    };
public:
    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTeseCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif