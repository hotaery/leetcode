// https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description
#include "graph/reorder_routes_to_make_all_paths_lead_to_the_city_zero.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <string>
#include <sstream>

namespace leetcode {
namespace _1466 {

class Solution {
    typedef std::pair<int, int> Elem;
    typedef std::vector<std::vector<Elem>> Graph;
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        Graph graph(n);
        for (std::vector<int>& edge : connections) {
            int from = edge[0], to = edge[1];
            graph[from].emplace_back(to, -1); // out degree
            graph[to].emplace_back(from, 1); // in degree
        }
        return dfs(graph, 0, -1);
    }

private:
    int dfs(Graph& graph, int node, int parent) {
        int ans = 0;
        for (Elem& child : graph[node]) {
            if (child.first == parent) {
                continue;
            }
            if (child.second == -1) {
                ++ans;
            }
            ans += dfs(graph, child.first, node);
        }
        return ans;
    }
};

} // namespace _1466

ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask::ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask() {}
ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask::~ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask() {}

std::shared_ptr<Task> ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask::create() {
    std::shared_ptr<ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask> task = 
        std::make_shared<ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask>();
    task->InitTestCase();
    return task;
}

void ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask::run() {
    int failed = 0;
    _1466::Solution sol;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.minReorder(ts.n, ts.connections);
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tn:" << ts.n << "\n"
                    << "\tconnections:" << ts.connections << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask::InitTestCase() {
    const std::string test_case_str = R"(6
[[0,1],[1,3],[2,3],[4,0],[4,5]]
3
5
[[1,0],[1,2],[3,2],[3,4]]
2
3
[[1,0],[2,0]]
0)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string n;
        std::string connections;
        std::string expect;
        std::getline(stream, n);
        std::getline(stream, connections);
        std::getline(stream, expect);
        if (n.empty()) {
            assert(!stream);
            break;
        }

        int n_ = nlohmann::json::parse(n).get<int>();
        std::vector<std::vector<int>> connections_ = 
            nlohmann::json::parse(connections).get<std::vector<std::vector<int>>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(n_, connections_, expect_);
    }
}

} // namespace leetcode