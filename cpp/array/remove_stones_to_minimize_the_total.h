#ifndef ARRAY_REMOVE_STONES_TO_MINIMIZE_THE_TOTAL_H
#define ARRAY_REMOVE_STONES_TO_MINIMIZE_THE_TOTAL_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class RemoveStonesToMinimizeTheTotalTask : public Task {
    struct TestCase {
        std::vector<int> piles;
        int k;
        int expect;

        TestCase(const std::vector<int>& piles_, int k_, int expect_)
            : piles(piles_), k(k_), expect(expect_) {}
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