// https://leetcode.cn/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/
#include "dp/maximum_number_that_sum_of_the_price_ls_less_than_or_equak_to_k.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <iostream>
#include <sstream>

#include <cmath>


namespace leetcode {
namespace _100160 {

class Solution {
    typedef long long LL;
public:
    long long findMaximumNumber(long long k, int x) {
        // dp[i]表示位数为i+1的价值，即[1, 2^i-1]
        std::vector<LL> dp;
        dp.push_back(0);
        for (LL i = 1; dp.back() < k; i++) {
            LL price = 0;
            // 0xxx 或者 1xxx，其中xxx为[1-val-1]
            price += 2 * dp[i-1];
            if (i % x == 0) {
                price += ((LL)1 << (i-1));
            } 
            dp.push_back(price);
        }
        int n = dp.size();
        LL ans = 0;
        LL valued_one = 0;
        // [1, 2^(n-1)-1] > k => 说明n位数字的价值已经大于k，因此答案只能是n-1位数字 
        // 如果100,...,0是一个m位数字，那么其价值为dp[m-1]+(m%x==0)
        // 如果100,..,010,...,0是一个m位数字，并且只有两个1，低位1假设在t位，那么其价值
        //      100,...,00(m位) + 100,...,00(t位) + (pow(2,t-1) if m % x == 0)
        for (LL i = n; i > 0; i--) {
            // 计算1000,...,0(i位)的价值
            LL price = dp[i-1];
            if (i % x == 0) {
                price += 1;
            }
            price += valued_one * ((LL)1 << (i-1));
            if (k >= price) {
                ans += ((LL)1 << (i-1));
                k -= price;
                if (i % x == 0) {
                    valued_one++;
                }
            }
        }

        return ans;
    }
};

} // namepace _100160

std::shared_ptr<Task> 
MaximumNumberThatSumOfThePriceLsLessThanOrEqualToKTask::create() {
    std::shared_ptr<MaximumNumberThatSumOfThePriceLsLessThanOrEqualToKTask> task = 
        std::make_shared<MaximumNumberThatSumOfThePriceLsLessThanOrEqualToKTask>();
    task->InitTeseCase();
    return task;
}

void MaximumNumberThatSumOfThePriceLsLessThanOrEqualToKTask::run() {
    _100160::Solution sol;
    int failed = 0;
    for (TestCase& t : test_case_list_) {
        long long actual = sol.findMaximumNumber(t.k, t.x);
        if (actual != t.expect) {
            std::cout << "TestCase:{\n"
                    << "\tk:" << t.k << "\n"
                    << "\tx:" << t.x << "\n"
                    << "}\n"
                    << "expect:" << t.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void MaximumNumberThatSumOfThePriceLsLessThanOrEqualToKTask::InitTeseCase() {
    std::string test_case_str = R"(9
1
6
7
2
9
4096
6
4127
3278539330613
5
851568447023)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string k;
        std::string x;
        std::string expect;
        std::getline(stream, k);
        std::getline(stream, x);
        std::getline(stream, expect);
        if (k.empty()) {
            assert(!stream);
            break;
        }

        long long k_ = nlohmann::json::parse(k).get<long long>();
        int x_ = nlohmann::json::parse(x).get<int>();
        long long expect_ = nlohmann::json::parse(expect).get<long long>();
        test_case_list_.emplace_back(k_, x_, expect_);
    }
}

} // namespace leetcode