#ifndef GRAPH_REORDER_ROUTES_TO_MAKE_ALL_PATHS_LEAD_TO_THE_CITY_ZERO_H
#define GRAPH_REORDER_ROUTES_TO_MAKE_ALL_PATHS_LEAD_TO_THE_CITY_ZERO_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask : public Task {
    struct TestCase {
        int n;
        std::vector<std::vector<int>> connections;
        int expect;

        TestCase(int n_, const std::vector<std::vector<int>>& connections_, int expect_)
            : n(n_), connections(connections_), expect(expect_) {}
    };
public:
    ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask();
    ~ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask();

    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif