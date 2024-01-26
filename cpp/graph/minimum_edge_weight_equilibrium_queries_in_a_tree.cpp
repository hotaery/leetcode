// https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree
#include "graph/minimum_edge_weight_equilibrium_queries_in_a_tree.h"
#include "nlohmann/json.hpp"
#include "utils/operator.h"
#include "utils/print.h"

#include <queue>
#include <sstream>
#include <string>
using namespace std;

namespace leetcode {
namespace _2846 {
class Solution {
    typedef std::pair<int, int> PII;
    typedef std::vector<PII> VPII;
    typedef std::vector<VPII> VVPII;
public:
    std::vector<int> minOperationsQueries(int n, 
                                          std::vector<std::vector<int>>& edges, 
                                          std::vector<std::vector<int>>& queries) {
        VVPII graph(n, VPII());
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        std::vector<std::vector<int>> freq(n, std::vector<int>(27, 0));
        std::vector<int> visited(n);
        std::queue<int> q;
        q.push(0); // 0 is the root
        while (!q.empty()) {
            int parent = q.front();
            q.pop();
            visited[parent] = 1;
            for (auto& child : graph[parent]) {
                int c = child.first;
                int w = child.second;
                if (visited[c]) {
                    continue;
                }
                q.push(c);
                for (int i = 1; i < 27; i++) {
                    freq[c][i] = freq[parent][i];
                }
                freq[c][w]++;
            }
        }

        std::vector<int> depth(n);
        std::vector<std::vector<int>> parent(n, std::vector<int>());
        visited = std::vector<int>(n);
        std::function<void(int, int)> dfs = [&](int u, int p) {
            visited[u] = 1;
            parent[u].emplace_back(p);
            for (int d = 1; (1 << d) <= depth[u]; d++) {
                parent[u].emplace_back(
                    parent[parent[u][d - 1]][d - 1]);
            }
            for (auto& child : graph[u]) {
                int v = child.first;
                if (visited[v]) {
                    continue;
                }
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        };
        dfs(0, -1);

        std::function<int(int, int)> lca = [&](int u, int v) {
            if (u == 0 || v == 0) {
                return 0;
            }
            if (depth[u] < depth[v]) {
                std::swap(u, v);
            }
            int diff = depth[u] - depth[v];
            // 寻找u的第diff个祖先
            for (int i = parent[u].size() - 1; i >= 0 && diff; i--) {
                if (diff & (1 << i)) {
                    u = parent[u][i];
                    diff -= (1 << i);
                }
            }
            if (u == v) {
                return u;
            }
            while (parent[u][0] != parent[v][0]) {
                for (int i = parent[u].size() - 1; i >= 0; i--) { 
                    if (parent[u][i] != parent[v][i]) {
                        u = parent[u][i];
                        v = parent[v][i];
                        break;
                    }
                }
            }
            return parent[u][0];
        };

        int m = queries.size();
        std::vector<int> ans;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            int p = lca(u, v);
            int total = 0, max_freq = 0;
            for (int i = 1; i < 27; i++) {
                int t = freq[u][i] + freq[v][i] - 2 * freq[p][i];
                total += t;
                max_freq = std::max(max_freq, t);
            }
            ans.push_back(total - max_freq);
        }
        return ans;
    }
};
} // namespace _2846

std::shared_ptr<Task> MinimumEdgeWeightEquilibriumQueriesInATreeTask::create() {
    std::shared_ptr<MinimumEdgeWeightEquilibriumQueriesInATreeTask> task = 
        std::make_shared<MinimumEdgeWeightEquilibriumQueriesInATreeTask>();
    task->InitTestCase();
    return task;
}

void MinimumEdgeWeightEquilibriumQueriesInATreeTask::run() {
    _2846::Solution sln;
    int failed = 0;
    for (auto& test_case : test_cases_) {
        std::vector<int> actual = sln.minOperationsQueries(test_case.n, test_case.edges, test_case.queries);
        if (actual != test_case.expect) {
            std::cout << "TestCase:{\n"
                    << "\tn:" << test_case.n << "\n"
                    << "\tedges:" << test_case.edges << "\n"
                    << "\tqueries:" << test_case.queries << "\n"
                    << "}\n"
                    << "expect:" << test_case.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_cases_.size() - failed << "\n"
            << "FAIL:" << failed << std::endl;
}

void MinimumEdgeWeightEquilibriumQueriesInATreeTask::InitTestCase() {
    std::string test_case_str = R"(92
[[0,11,5],[14,0,5],[77,0,8],[37,0,1],[25,14,5],[79,0,2],[30,79,8],[6,14,3],[46,25,3],[66,37,8],[3,6,8],[60,14,5],[27,14,8],[52,6,5],[24,52,6],[33,0,9],[29,79,9],[9,14,9],[12,46,3],[68,11,9],[5,46,3],[51,14,7],[39,24,4],[16,24,6],[82,27,2],[8,51,3],[83,3,7],[65,33,4],[78,51,4],[84,5,2],[72,12,10],[63,0,2],[54,79,4],[88,14,4],[53,65,8],[43,79,7],[13,78,9],[34,14,9],[56,63,10],[42,16,6],[73,27,2],[18,8,1],[38,6,8],[7,38,7],[31,54,2],[20,84,4],[86,53,8],[41,86,9],[35,31,4],[57,29,7],[61,16,9],[2,88,6],[40,68,1],[15,43,7],[74,34,7],[71,5,3],[50,61,9],[91,83,5],[49,2,4],[47,88,10],[75,57,4],[44,0,3],[32,52,3],[62,3,2],[21,33,3],[81,71,5],[69,11,5],[85,25,1],[59,68,2],[28,57,4],[26,41,5],[36,71,8],[19,41,6],[17,41,4],[67,30,7],[64,20,10],[10,37,2],[80,0,8],[48,30,5],[70,33,6],[22,69,5],[89,9,4],[23,65,5],[55,72,2],[4,42,9],[76,52,4],[58,8,10],[45,89,4],[1,77,1],[90,5,6],[87,23,4]]
[[26,39]]
[8]
7
[[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]]
[[0,3],[3,6],[2,6],[0,6]]
[0,0,1,3]
8
[[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],[3,0,8],[7,0,2]]
[[4,6],[0,4],[6,5],[7,4]]
[1,2,2,3])";
    std::istringstream iss(test_case_str);
    while (iss) {
        std::string n;
        std::string edges;
        std::string queries;
        std::string expect;
        std::getline(iss, n);
        std::getline(iss, edges);
        std::getline(iss, queries);
        std::getline(iss, expect);
        if (n.empty()) {
            assert(!iss);
            break;
        }
        int n_ = nlohmann::json::parse(n).get<int>();
        std::vector<std::vector<int>> edges_ = nlohmann::json::parse(edges).get<
            std::vector<std::vector<int>>>();
        std::vector<std::vector<int>> queries_ = nlohmann::json::parse(queries).get<
            std::vector<std::vector<int>>>();
        std::vector<int> expect_ = nlohmann::json::parse(expect).get<std::vector<int>>();
        test_cases_.emplace_back(n_, edges_, queries_, expect_);
    }
}

} // namespace leetcode