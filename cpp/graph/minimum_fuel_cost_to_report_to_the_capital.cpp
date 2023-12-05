// https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/description
#include "graph/minimum_fuel_cost_to_report_to_the_capital.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <string>
#include <sstream>
#include <utility>

namespace leetcode {
namespace _2477 {

class Solution {
public:
    long long minimumFuelCost(std::vector<std::vector<int>>& roads, int seats) {
        int n = roads.size() + 1; // n cities

        std::vector<std::vector<int>> graph(n); // adjacent matrix
        for (std::vector<int>& road : roads) {
            int u = road[0], v = road[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        return dfs(graph, seats, 0, -1).second;
    }

private:
    std::pair<int, long long> dfs(std::vector<std::vector<int>>& graph, int seats, 
                                  int root, int parent) {
        std::pair<int, long long> ans(1, 0);
        for (int child : graph[root]) {
            if (child == parent) {
                continue;
            }

            auto people_and_fuel = dfs(graph, seats, child, root);
            ans.first += people_and_fuel.first;
            ans.second += people_and_fuel.second;
            ans.second += (people_and_fuel.first + seats - 1) / seats;
        }
        return ans;
    }
};

} // namesapce _2477

MinimumFuelCostToReportToTheCapitalTask::MinimumFuelCostToReportToTheCapitalTask() {}
MinimumFuelCostToReportToTheCapitalTask::~MinimumFuelCostToReportToTheCapitalTask() {}

std::shared_ptr<Task> MinimumFuelCostToReportToTheCapitalTask::create() {
    std::shared_ptr<MinimumFuelCostToReportToTheCapitalTask> task =
        std::make_shared<MinimumFuelCostToReportToTheCapitalTask>();
    task->InitTestCase();
    return task;
}

void MinimumFuelCostToReportToTheCapitalTask::run() {
    _2477::Solution sol;
    int failed = 0;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.minimumFuelCost(ts.roads, ts.seats);
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\troads:" << ts.roads << "\n"
                    << "\tseats:" << ts.seats << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
              << "FAILED:" << failed << std::endl;
}

void MinimumFuelCostToReportToTheCapitalTask::InitTestCase() {
    const std::string test_case_str = R"([[0,1],[0,2],[0,3]]
5
3
[[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]]
2
7
[]
1
0
[[0,1],[0,2],[1,3],[1,4]]
5
4
[[0,1],[1,2]]
3
2)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string roads_str;
        std::string seats;
        std::string expect;
        std::getline(stream, roads_str);
        std::getline(stream, seats);
        std::getline(stream, expect);
        if (roads_str.empty()) {
            assert(!stream);
            break;
        }

        std::vector<std::vector<int>> roads = 
            nlohmann::json::parse(roads_str).get<std::vector<std::vector<int>>>();
        int seats_ = nlohmann::json::parse(seats).get<int>();
        int expect_ = nlohmann::json::parse(expect).get<int>();

        test_case_list_.emplace_back(roads, seats_, expect_);
    }
}

} // namespace leetcode