// https://leetcode.cn/problems/maximum-earnings-from-taxi/description/
#include "dp/maximum_earnings_from_taxi.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <sstream>
#include <string>
#include <unordered_map>

namespace leetcode {
namespace _2008 {

class Solution {
public:
    long long maxTaxiEarnings(int n, std::vector<std::vector<int>>& rides) {
        std::vector<long long> dp(n+1);
        std::unordered_map<int, std::vector<std::vector<int>>> rides_map;
        for (std::vector<int>& ride : rides) {
            rides_map[ride[0]].push_back(ride);
        }
        long long ans = 0;
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = dp[i+1];
            auto iter = rides_map.find(i);
            if (iter != rides_map.end()) {
                for (std::vector<int>& ride : iter->second) {
                    dp[i] = std::max(dp[i], ride[1] - ride[0] + ride[2] + dp[ride[1]]);
                }
            }
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};

} // namespace _2008

MaximumEarningsFromTaxiTask::MaximumEarningsFromTaxiTask() {}
MaximumEarningsFromTaxiTask::~MaximumEarningsFromTaxiTask() {}

std::shared_ptr<Task> MaximumEarningsFromTaxiTask::create() {
    std::shared_ptr<MaximumEarningsFromTaxiTask> task = 
        std::make_shared<MaximumEarningsFromTaxiTask>();
    task->InitTestCase();
    return task;
}

void MaximumEarningsFromTaxiTask::run() {
    int failed = 0;
    _2008::Solution sol;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.maxTaxiEarnings(ts.n, ts.rides);
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tn:" << ts.n << "\n"
                    << "\trides:" << ts.rides << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void MaximumEarningsFromTaxiTask::InitTestCase() {
    const std::string test_case_str = R"(5
[[2,5,4],[1,5,1]]
7
20
[[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
20
5
[[2,3,4],[4,5,1]]
7)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string n;
        std::string rides;
        std::string expect;
        std::getline(stream, n);
        std::getline(stream, rides);
        std::getline(stream, expect);
        if (n.empty()) {
            assert(!stream);
            break;
        }

        int n_ = nlohmann::json::parse(n).get<int>();
        std::vector<std::vector<int>> rides_ = 
            nlohmann::json::parse(rides).get<std::vector<std::vector<int>>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(n_, rides_, expect_);
    }
}

} // namespace leetcode