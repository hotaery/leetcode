#ifndef DP_GUNGEON_GAME_H
#define DP_GUNGEON_GAME_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class DungeonGameTask : public Task {
    struct TestCase {
        std::vector<std::vector<int>> dungeon;
        int expect;

        TestCase(const std::vector<std::vector<int>>& dungeon_, int expect_)
            : dungeon(dungeon_), expect(expect_) {}
    };
public:
    DungeonGameTask();
    ~DungeonGameTask();

    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif