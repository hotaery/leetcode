//https://leetcode.cn/problems/coin-change-ii/description/
#include "dp/coin_change_2.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <string>
#include <sstream>

namespace leetcode {
namespace _518 {

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        std::vector<int> dp(amount+1);
        dp[0] = 1;
        // NOTICE: outer loop coins so could avoid repeat combination.
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin];
            }
        }
        return dp.back();
    }
};

} // namespace _518

CoinChange2Task::CoinChange2Task() {}
CoinChange2Task::~CoinChange2Task() {}

std::shared_ptr<Task> CoinChange2Task::create() {
    std::shared_ptr<CoinChange2Task> task = std::make_shared<CoinChange2Task>();
    task->InitTestCase();
    return task;
}

void CoinChange2Task::run() {
    _518::Solution sol;
    int failed = 0;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.change(ts.amount, ts.coins);
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tcoins:" << ts.coins << "\n"
                    << "\tamount:" << ts.amount << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void CoinChange2Task::InitTestCase() {
    std::string test_case_str = R"(5
[1,2,5]
4
3
[2]
0
10
[10]
1)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string amount;
        std::string coins;
        std::string expect;
        std::getline(stream, amount);
        std::getline(stream, coins);
        std::getline(stream, expect);
        if (amount.empty()) {
            assert(!stream);
            break;
        }

        int amount_ = nlohmann::json::parse(amount).get<int>();
        std::vector<int> coins_ = nlohmann::json::parse(coins).get<std::vector<int>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(coins_, amount_, expect_);
    }
}

} // namespace leetcode