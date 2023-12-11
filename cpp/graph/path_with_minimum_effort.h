#ifndef GRAPH_PATH_WITH_MINIMUM_EFFORT_H
#define GRAPH_PATH_WITH_MINIMUM_EFFORT_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class PathWithMinimumEffortTask : public Task {
    struct TestCase {
        std::vector<std::vector<int>> heights;
        int expect;

        TestCase(const std::vector<std::vector<int>>& heights_, int expect_)
            : heights(heights_), expect(expect_) {}
    };

public:
    PathWithMinimumEffortTask();
    ~PathWithMinimumEffortTask();

    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif