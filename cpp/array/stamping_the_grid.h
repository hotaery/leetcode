#ifndef ARRAY_STAMPING_THE_GRID_H
#define ARRAY_STAMPING_THE_GRID_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class StampingTheGridTask : public Task {
    struct TestCase {
        std::vector<std::vector<int>> grid;
        int stampHeight;
        int stampWidth;
        bool expect;

        TestCase(const std::vector<std::vector<int>>& grid_, int stampHeight_, 
                int stampWidth_, bool expect_)
            : grid(grid_), stampHeight(stampHeight_), stampWidth(stampWidth_), expect(expect_) {}
    };

public:
    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif