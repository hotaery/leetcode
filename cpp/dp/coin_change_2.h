#ifndef DP_COIN_CHANGE_2_H
#define DP_COIN_CHANGE_2_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class CoinChange2Task : public Task {
    struct TestCase {
        std::vector<int> coins;
        int amount;
        int expect;

        TestCase(const std::vector<int>& coins_, int amount_, int expect_)
            : coins(coins_), amount(amount_), expect(expect_) {}
    };
public:
    CoinChange2Task();
    ~CoinChange2Task();

    std::shared_ptr<Task> create() override;

    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

}

#endif