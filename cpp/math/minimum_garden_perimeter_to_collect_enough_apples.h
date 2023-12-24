#ifndef MATH_MINIMUM_GARDEN_PERIMETER_TO_COLLECT_ENOUGH_APPLES_H
#define MATH_MINIMUM_GARDEN_PERIMETER_TO_COLLECT_ENOUGH_APPLES_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class MinimumGardenPerimeterToCollectEnoughApplesTask : public Task {
    struct TestCase {
        long long neededApples;
        long long expect;

        TestCase(long long neededApples_, long long expect_)
            : neededApples(neededApples_), expect(expect_) {}
    };
public:
    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

}

#endif