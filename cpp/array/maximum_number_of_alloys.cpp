// https://leetcode.cn/problems/maximum-number-of-alloys
#include "array/maximum_number_of_alloys.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <sstream>
#include <string>

namespace leetcode {
namespace _2861 {
class Solution {
    typedef long long LL;
public:
    int maxNumberOfAlloys(int n, int k, int budget, 
                          std::vector<std::vector<int>>& composition, 
                          std::vector<int>& stock, 
                          std::vector<int>& cost) {
        LL ans = 0;
        for (int i = 0; i < k; i++) {
            LL left = -1, min_com = -1;
            for (int j = 0; j < n; j++) {
                if (composition[i][j] > 0) {
                    if (left == -1) {
                        left = stock[j] / composition[i][j];
                    } else {
                        left = std::min(left, (LL)stock[j] / composition[i][j]);
                    }
                }
                min_com = min_com == -1 ? composition[i][j] : std::min(min_com, (LL)composition[i][j]);
            }
            LL right = left + budget / min_com;
            while (left <= right) {
                LL budget_tmp = budget;
                LL mid = left + (right - left) / 2;
                for (int j = 0; j < n && budget_tmp >= 0; j++) {
                    LL need = composition[i][j] * mid - stock[j];
                    if (need > 0) {
                        budget_tmp -= cost[j] * need;
                    }
                }
                if (budget_tmp >= 0) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans = std::max(ans, std::min(left, right));
        }
        return ans;
    }
};
} // namespace _2861

std::shared_ptr<Task> MaximumNumberOfAlloysTask::create() {
    std::shared_ptr<MaximumNumberOfAlloysTask> task = std::make_shared<MaximumNumberOfAlloysTask>();
    task->InitTestCase();
    return task;
}

void MaximumNumberOfAlloysTask::run() {
    _2861::Solution sln;
    int failed = 0;
    for (auto& test_case : test_cases_) {
        int actual = sln.maxNumberOfAlloys(test_case.n, test_case.k, test_case.budget, 
                                           test_case.composition, test_case.stock, test_case.cost);
        if (actual != test_case.expect) {
            std::cout  << "TestCase:{\n}"
                    << "\tn:" << test_case.n << "\n"
                    << "\tk:" << test_case.k << "\n"
                    << "\tbudget:" << test_case.budget << "\n"
                    << "\tcomposition:" << test_case.composition << "\n"
                    << "\tstock:" << test_case.stock << "\n"
                    << "\tcost:" << test_case.cost << "\n"
                    << "}\n"
                    << "expect:" << test_case.expect << "\n"
                    << "actual:" << actual << "\n\n";
            ++failed;
        }
    }
    std::cout << "PASS:" << test_cases_.size() - failed << "\n"
              << "FAIL:" << failed << std::endl;
}

void MaximumNumberOfAlloysTask::InitTestCase() {
    std::string test_case_str = R"(3
2
15
[[1,1,1],[1,1,10]]
[0,0,0]
[1,2,3]
2
3
2
15
[[1,1,1],[1,1,10]]
[0,0,100]
[1,2,3]
5
2
3
10
[[2,1],[1,2],[1,1]]
[1,1]
[5,5]
2)";
    std::istringstream iss(test_case_str);
    while (iss) {
        std::string n;
        std::string k;
        std::string budget;
        std::string composition;
        std::string stock;
        std::string cost;
        std::string expect;
        std::getline(iss, n);
        std::getline(iss, k);
        std::getline(iss, budget);
        std::getline(iss, composition);
        std::getline(iss, stock);
        std::getline(iss, cost);
        std::getline(iss, expect);
        if (n.empty()) {
            assert(!iss);
            break;
        }
        int n_ = nlohmann::json::parse(n).get<int>();
        int k_ = nlohmann::json::parse(k).get<int>();
        int budget_ = nlohmann::json::parse(budget).get<int>();
        std::vector<std::vector<int>> composition_ = 
            nlohmann::json::parse(composition).get<std::vector<std::vector<int>>>();
        std::vector<int> stock_ = nlohmann::json::parse(stock).get<std::vector<int>>();
        std::vector<int> cost_ = nlohmann::json::parse(cost).get<std::vector<int>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_cases_.emplace_back(n_, k_, budget_, composition_, stock_, cost_, expect_);
    }
}

} // namespace leetcode