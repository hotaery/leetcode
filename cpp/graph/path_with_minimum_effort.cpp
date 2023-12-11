// https://leetcode.cn/problems/path-with-minimum-effort/description/
#include "graph/path_with_minimum_effort.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <algorithm>
#include <sstream>
#include <string>

namespace leetcode {
namespace _1631 {
class UnionSet {
public:
    UnionSet(int n) : parent_(n), size_(n, 1) {
        std::iota(parent_.begin(), parent_.end(), 0);
    }

    int find(int x) {
        if (parent_[x] == x) {
            return x;
        }
        parent_[x] = find(parent_[x]);
        return parent_[x];
    }

    void merge(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if (xp == yp) {
            return;
        }
        if (size_[xp] > size_[yp]) {
            std::swap(x, y);
        }
        parent_[xp] = yp;
        size_[yp] += size_[xp];
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

private:
    std::vector<int> parent_;
    std::vector<int> size_;
};

class Solution {
    struct Edge {
        int u;
        int v;
        int w;
        Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
    };
public:
    Solution(int i = 0) : i_(i) {}

    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        if (i_ == 0) {
            return unionSet(heights);
        } else {
            return binarySearch(heights);
        }
    }

    std::string name() {
        if (i_ == 0) {
            return "union set";
        } else {
            return "binary search";
        }
    }

private:
    int unionSet(std::vector<std::vector<int>>& heights) {
        std::vector<Edge> edges;
        int m = heights.size(), n = heights[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int u = i * n + j;
                if (i > 0) {
                    // top
                    int v = u - n;
                    edges.emplace_back(u, v, std::abs(heights[i][j] - heights[i-1][j]));
                }
                if (j > 0) {
                    // left
                    int v = u - 1;
                    edges.emplace_back(u, v, std::abs(heights[i][j] - heights[i][j-1]));
                }
            }
        }
        std::sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.w < rhs.w;
        });

        UnionSet us(m * n);
        int ans = 0;
        for (const Edge& edge : edges) {
            us.merge(edge.u, edge.v);
            if (us.isConnected(0, m * n - 1)) {
                ans = edge.w;
                break;
            }
        }
        return ans;
    }

    int binarySearch(std::vector<std::vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int min_val = heights[0][0], max_val = heights[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                min_val = std::min(min_val, heights[i][j]);
                max_val = std::max(max_val, heights[i][j]);
            }
        }
        int min_cost = 0, max_cost = max_val - min_val;
        while (min_cost <= max_cost) {
            int mid_cost = (min_cost + max_cost) / 2;
            bool succ = dfs(heights, 0, 0, mid_cost);
            if (succ) {
                max_cost = mid_cost - 1;
            } else {
                min_cost = mid_cost + 1;
            }
        }
        return min_cost;
    }

    bool dfs(std::vector<std::vector<int>>& heights, int i, int j, int cost) {
        if (i == heights.size() - 1 && j == heights[0].size() - 1) {
            return true;
        }

        heights[i][j] = -heights[i][j];
        bool ans = false;
        for (int k = 0; k < 4 && !ans; k++) {
            int x = i + dx_[k], y = j + dy_[k];
            if (inBound(heights, x, y) && heights[x][y] > 0 && 
                std::abs(heights[x][y] + heights[i][j]) <= cost) {
                ans = dfs(heights, x, y, cost);
            }
        }
        heights[i][j] = -heights[i][j];
        return ans;
    }

    bool inBound(std::vector<std::vector<int>>& heights, int i, int j) {
        return i >= 0 && i < heights.size() && j >= 0 && j < heights[0].size();
    }

    static std::vector<int> dx_;
    static std::vector<int> dy_;
    int i_;
};

std::vector<int> Solution::dx_ = {-1, 0, 1, 0};
std::vector<int> Solution::dy_ = {0, -1, 0, 1};

} // namespace _1631

PathWithMinimumEffortTask::PathWithMinimumEffortTask() {}
PathWithMinimumEffortTask::~PathWithMinimumEffortTask() {}

std::shared_ptr<Task> PathWithMinimumEffortTask::create() {
    std::shared_ptr<PathWithMinimumEffortTask> task = 
        std::make_shared<PathWithMinimumEffortTask>();
    task->InitTestCase();
    return task;
}

void PathWithMinimumEffortTask::run() {
    int failed = 0;
    std::vector<_1631::Solution> sols;
    sols.push_back(_1631::Solution(0));
    sols.push_back(_1631::Solution(1));
    for (_1631::Solution& sol : sols) {
        for (TestCase& ts : test_case_list_) {
            int actual = sol.minimumEffortPath(ts.heights);
            if (actual != ts.expect) {
                std::cout << "TestCase:{\n"
                        << "\theights:" << ts.heights << "\n"
                        << "}\n"
                        << "name:" << sol.name() << "\n"
                        << "expect:" << ts.expect << "\n"
                        << "actual:" << actual << "\n\n";
                failed++;
            }
        }
    }
    std::cout << "PASS:" << test_case_list_.size() * sols.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void PathWithMinimumEffortTask::InitTestCase() {
    const std::string test_case_str = R"([[1,2,2],[3,8,2],[5,3,5]]
2
[[1,2,3],[3,8,4],[5,3,5]]
1
[[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
0
[[3]]
0)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string heights;
        std::string expect;
        std::getline(stream, heights);
        std::getline(stream, expect);
        if (heights.empty()) {
            assert(!stream);
            break;
        }

        std::vector<std::vector<int>> heights_ = 
            nlohmann::json::parse(heights).get<std::vector<std::vector<int>>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(heights_, expect_);
    }
}

} // namespace leetcode
