// https://leetcode.cn/problems/minimize-the-total-price-of-the-trips
#include "graph/minimize_the_total_price_of_the_trips.h"
#include <nlohmann/json.hpp>
#include "utils/print.h"

#include <string>
#include <sstream>
#include <utility>

namespace leetcode {
namespace _2646 {

class Solution {
public:
    int minimumTotalPrice(int n, std::vector<std::vector<int>>& edges, 
                          std::vector<int>& price, 
                          std::vector<std::vector<int>>& trips) {
        std::vector<std::vector<int>> graph(n);
        for (std::vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        std::vector<int> freq(n);
        for (std::vector<int>& trip : trips) {
            int start = trip[0], end = trip[1];
            dfs(graph, start, end, -1, freq);
        }
        auto ans = dp(graph, freq, 0, -1, price);
        return std::min(ans.first, ans.second);
    }

private:
    bool dfs(std::vector<std::vector<int>>& graph, int start, 
             int end, int parent, std::vector<int>& freq) {
        freq[start]++;
        if (start == end) {
            return true;
        }
        for (int child : graph[start]) {
            if (child == parent) {
                continue;
            }
            bool find = dfs(graph, child, end, start, freq);
            if (find) {
                return true;
            }
        }
        freq[start]--;
        return false;
    }

    std::pair<int, int> dp(std::vector<std::vector<int>>& graph, std::vector<int>& freq, 
                           int node, int parent, std::vector<int>& price) {
        std::pair<int, int> ans = std::make_pair(
            price[node] * freq[node], price[node] * freq[node] / 2);
        
        for (int child : graph[node]) {
            if (child == parent) {
                continue;
            }
            auto child_ans = dp(graph, freq, child, node, price);
            ans.first += std::min(child_ans.first, child_ans.second);
            ans.second += child_ans.first;
        }
        return ans;
    } 
};

} // namespace _2646

MinimizeTheTotalPriceOfTheTripsTask::MinimizeTheTotalPriceOfTheTripsTask() {}
MinimizeTheTotalPriceOfTheTripsTask::~MinimizeTheTotalPriceOfTheTripsTask() {}

std::shared_ptr<Task> MinimizeTheTotalPriceOfTheTripsTask::create() {
    std::shared_ptr<MinimizeTheTotalPriceOfTheTripsTask> task =
        std::make_shared<MinimizeTheTotalPriceOfTheTripsTask>();
    task->InitTestCase();
    return task;
}

void MinimizeTheTotalPriceOfTheTripsTask::run() {
    int failed = 0;
    _2646::Solution sol;

    for (TestCase& ts : test_case_list_) {
        int actual = sol.minimumTotalPrice(ts.n, ts.edges, ts.prices, ts.trips);
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tn:" << ts.n << "\n"
                    << "\tedges:" << ts.edges << "\n"
                    << "\tprice:" << ts.prices << "\n"
                    << "\ttrips:" << ts.trips << "\n"
                    << "}" << "\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
        << "FAILED:" << failed << std::endl;
}

void MinimizeTheTotalPriceOfTheTripsTask::InitTestCase() {
    const std::string test_case_str = R"(4
[[0,1],[1,2],[1,3]]
[2,2,10,6]
[[0,3],[2,1],[2,3]]
23
2
[[0,1]]
[2,2]
[[0,0]]
1)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string n;
        std::string edges;
        std::string price;
        std::string trips;
        std::string expect;
        std::getline(stream, n);
        std::getline(stream, edges);
        std::getline(stream, price);
        std::getline(stream, trips);
        std::getline(stream, expect);
        if (n.empty()) {
            assert(!stream);
            break;
        }

        int n_ = nlohmann::json::parse(n).get<int>();
        std::vector<std::vector<int>> edges_ = 
            nlohmann::json::parse(edges).get<std::vector<std::vector<int>>>();
        std::vector<int> price_ = nlohmann::json::parse(price).get<std::vector<int>>();
        std::vector<std::vector<int>> trips_ = 
            nlohmann::json::parse(trips).get<std::vector<std::vector<int>>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(n_, edges_, price_, trips_, expect_);
    }
}

} // namespace leetcode