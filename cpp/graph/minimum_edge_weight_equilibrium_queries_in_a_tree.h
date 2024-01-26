#ifndef GRAPH_MINIMUM_EDGE_WEIGHT_EQUILIBRIUM_QUERIES_IN_A_TREE_H
#define GRAPH_MINIMUM_EDGE_WEIGHT_EQUILIBRIUM_QUERIES_IN_A_TREE_H

#include "utils/regsitery.h"

namespace leetcode {
class MinimumEdgeWeightEquilibriumQueriesInATreeTask : public Task {
    struct TestCase {
        int n;
        std::vector<std::vector<int>> edges;
        std::vector<std::vector<int>> queries;
        std::vector<int> expect;

        TestCase(int n, const std::vector<std::vector<int>>& edges,
                 const std::vector<std::vector<int>>& queries,
                 const std::vector<int>& expect)
            : n(n), edges(edges), queries(queries), expect(expect) {}
    };
public:
    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_cases_;
};
} // namespace leetcode

#endif