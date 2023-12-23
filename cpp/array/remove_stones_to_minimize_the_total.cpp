#include "array/remove_stones_to_minimize_the_total.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <queue>
#include <sstream>
#include <string>

namespace leetcode {
namespace _1962 {
class Solution {
public:
    int minStoneSum(std::vector<int>& piles, int k) {
        std::priority_queue<int> q;
        int sum = 0;
        for (int i : piles) {
            q.push(i);
            sum += i;
        }

        while (k) {
            int t = q.top();
            q.pop();
            int half = std::floor(t / 2);
            q.push(t - half);
            sum -= half;
            k--;
        }
        return sum;
    }
};
} // namespace _1962

std::shared_ptr<Task> RemoveStonesToMinimizeTheTotalTask::create() {
    std::shared_ptr<RemoveStonesToMinimizeTheTotalTask> task = 
        std::make_shared<RemoveStonesToMinimizeTheTotalTask>();
    task->InitTestCase();
    return task;
}

void RemoveStonesToMinimizeTheTotalTask::run() {
    int failed = 0;
    _1962::Solution sol;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.minStoneSum(ts.piles, ts.k);
        if (ts.expect != actual) {
            failed++;
            std::cout << "TestCase{\n" 
                    << "\tpiles:" << ts.piles << "\n"
                    << "\tk:" << ts.k << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void RemoveStonesToMinimizeTheTotalTask::InitTestCase() {
    const std::string test_case_str = R"([5,4,9]
2
12
[4,3,6,7]
3
12)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string piles;
        std::string k;
        std::string expect;
        std::getline(stream, piles);
        std::getline(stream, k);
        std::getline(stream, expect);
        if (piles.empty()) {
            assert(!stream);
            break;
        }

        std::vector<int> piles_ = nlohmann::json::parse(piles).get<std::vector<int>>();
        int k_ = nlohmann::json::parse(k).get<int>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(piles_, k_, expect_);
    }
}


} // namespace leetcode