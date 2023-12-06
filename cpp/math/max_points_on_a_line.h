#ifndef MATH_MAX_POINTS_ON_A_LINE
#define MATH_MAX_POINTS_ON_A_LINE

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class MaxPointsOnALineTask : public Task {
    struct TestCase {
        std::vector<std::vector<int>> points;
        int expect;

        TestCase(const std::vector<std::vector<int>>& points_, int expect_)
            : points(points_), expect(expect_) {}
    };
public:
    MaxPointsOnALineTask();
    ~MaxPointsOnALineTask();

    std::shared_ptr<Task> create() override;

    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif