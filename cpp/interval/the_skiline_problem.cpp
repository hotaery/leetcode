// https://leetcode.cn/problems/the-skyline-problem/
#include "interval/the_skline_problem.h"
#include "nlohmann/json.hpp"
#include "utils/operator.h"
#include "utils/print.h"

#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <utility>

namespace leetcode {

using std::vector;
using std::pair;

namespace _218 {
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        std::sort(buildings.begin(), buildings.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });

        // 所有建筑物的边界处的横坐标
        std::vector<int> boundaries;
        for (auto& building : buildings) {
            boundaries.push_back(building[0]);
            boundaries.push_back(building[1]);
        }
        std::sort(boundaries.begin(), boundaries.end());
        std::vector<std::vector<int>> ret;
        int n = buildings.size();
        // 寻找该横坐标对应的最大高度
        auto cmp = [](const pair<int, int>& a, 
                      const pair<int, int>& b) -> bool { 
            return a.second < b.second; 
        };
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        int idx = 0;
        for (int boundary : boundaries) {
            while (idx < n && buildings[idx][0] <= boundary) {
                que.emplace(buildings[idx][1], buildings[idx][2]);
                idx++;
            }
            while (!que.empty() && que.top().first <= boundary) {
                que.pop();
            }

            int maxn = que.empty() ? 0 : que.top().second;
            if (ret.size() == 0 || maxn != ret.back()[1]) {
                ret.push_back({boundary, maxn});
            }
        }
        return ret;
    }
};
} // namespace _218

std::shared_ptr<Task> TheSklineProblemTask::create() {
    std::shared_ptr<TheSklineProblemTask> task = std::make_shared<TheSklineProblemTask>();
    task->InitTestCase();
    return task;
}

void TheSklineProblemTask::run() {
    int failed = 0;
    _218::Solution sol;
    for (TestCase& ts : test_case_list_) {
        std::vector<std::vector<int>> actual = sol.getSkyline(ts.buildings);
        if (ts.expect != actual) {
            std::cout << "TestCase:{\n"
                    << "\tbuildings:" << ts.buildings << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void TheSklineProblemTask::InitTestCase() {
    const std::string test_case_str = R"([[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
[[0,2,3],[2,5,3]]
[[0,3],[5,0]])";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string buildings;
        std::string expect;
        std::getline(stream, buildings);
        std::getline(stream, expect);
        if (buildings.empty()) {
            assert(!stream);
            break;
        }
        std::vector<std::vector<int>> buildings_ = 
            nlohmann::json::parse(buildings).get<std::vector<std::vector<int>>>();
        std::vector<std::vector<int>> expect_ = 
            nlohmann::json::parse(expect).get<std::vector<std::vector<int>>>();
        test_case_list_.emplace_back(buildings_, expect_);
    }
}

} // namespace leetcode