// https://leetcode.cn/problems/dungeon-game/description/
#include "dp/dungeon_game.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <sstream>
#include <string>

namespace leetcode {
namespace _174 {

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        std::vector<int> dp(n);
        dp[n-1] = dungeon[m-1][n-1] >= 0 ? 1 : -dungeon[m-1][n-1] + 1;
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = std::max(dp[i+1] - dungeon[m-1][i], 1);
        }
        for (int i = m - 2; i >= 0; i--) {
            dp[n-1] = std::max(dp[n-1] - dungeon[i][n-1], 1);
            for (int j = n - 2; j >= 0; j--) {
                dp[j] = std::max(dp[j] - dungeon[i][j], 1);
                dp[j] = std::min(dp[j], std::max(dp[j + 1] - dungeon[i][j], 1));
            }
        }
        return dp[0];
    }
};

} // namespace _174

DungeonGameTask::DungeonGameTask() {}
DungeonGameTask::~DungeonGameTask() {}

std::shared_ptr<Task> DungeonGameTask::create() {
    std::shared_ptr<DungeonGameTask> task = std::make_shared<DungeonGameTask>();
    task->InitTestCase();
    return task;
}

void DungeonGameTask::run() {
    int failed = 0;
    _174::Solution sol;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.calculateMinimumHP(ts.dungeon);
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tdungeon:" << ts.dungeon << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void DungeonGameTask::InitTestCase() {
    const std::string test_case_str = R"([[-2,-3,3],[-5,-10,1],[10,30,-5]]
7
[[0]]
1)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string dungeon;
        std::string expect;
        std::getline(stream, dungeon);
        std::getline(stream, expect);
        if (dungeon.empty()) {
            assert(!stream);
            break;
        }

        std::vector<std::vector<int>> dungeon_ = 
            nlohmann::json::parse(dungeon).get<std::vector<std::vector<int>>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(dungeon_, expect_);
    }
}

} // namespace leetcode