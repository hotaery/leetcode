#ifndef ARRAY_MAXIMUM_NUMBER_OF_ALLOYS_H
#define ARRAY_MAXIMUM_NUMBER_OF_ALLOYS_H

#include "utils/regsitery.h"

namespace leetcode {
class MaximumNumberOfAlloysTask : public Task {
    struct TestCase {
        int n;
        int k;
        int budget;
        std::vector<std::vector<int>> composition;
        std::vector<int> stock;
        std::vector<int> cost;
        int expect;

        TestCase(int n, int k, int budget, std::vector<std::vector<int>> composition, 
                 std::vector<int> stock, std::vector<int> cost, int expect)
            : n(n), k(k), budget(budget), composition(composition), stock(stock), cost(cost), expect(expect) {}
    };
public:
    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_cases_;
};
} // namespace leetcode

#endif