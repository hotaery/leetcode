// https://leetcode.cn/problems/stamping-the-grid/description
#include "array/stamping_the_grid.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <algorithm>
#include <sstream>
#include <string>
#include <utility>

namespace leetcode {
namespace _2132 {
class Solution {
public:
    bool possibleToStamp(std::vector<std::vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> prefix(m + 1, std::vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i+1][j+1] = prefix[i][j+1] + prefix[i+1][j] - prefix[i][j] + grid[i][j];
            }
        }

        std::vector<std::vector<int>> diff(m + 2, std::vector<int>(n + 2));
        for (int i = 1; i + stampHeight - 1 <= m; i++) {
            for (int j = 1; j + stampWidth - 1 <= n; j++) {
                int x = i + stampHeight - 1;
                int y = j + stampWidth - 1;
                if (prefix[x][y] - prefix[x][j - 1] - prefix[i - 1][y] + prefix[i - 1][j - 1] == 0) {
                    diff[i][j]++;
                    diff[i][y + 1]--;
                    diff[x + 1][j]--;
                    diff[x + 1][y + 1]++;
                }
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                if (diff[i][j] == 0 && grid[i - 1][j - 1] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
}; 
} // namespace _2132

std::shared_ptr<Task> StampingTheGridTask::create() {
    std::shared_ptr<StampingTheGridTask> task = std::make_shared<StampingTheGridTask>();
    task->InitTestCase();
    return task;
}

void StampingTheGridTask::run() {
    int failed = 0;
    _2132::Solution sol;
    for (TestCase& ts : test_case_list_) {
        auto grid = ts.grid;
        bool actual = sol.possibleToStamp(grid, ts.stampHeight, ts.stampWidth);
        if (ts.expect != actual) {
            failed++;
            std::cout << "TestCase{\n" 
                    << "\tgrid:" << ts.grid << "\n"
                    << "\tstampHeight:" << ts.stampHeight << "\n"
                    << "\tstampWidth:" << ts.stampWidth << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void StampingTheGridTask::InitTestCase() {
    const std::string test_case_str = R"([[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]]
4
3
true
[[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]
2
2
false
[[0,0,0,0,0],[0,0,0,0,0],[0,0,1,0,0],[0,0,0,0,1],[0,0,0,1,1]]
2
2
false)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string grid;
        std::string stampHeight;
        std::string stampWidth;
        std::string expect;
        std::getline(stream, grid);
        std::getline(stream, stampHeight);
        std::getline(stream, stampWidth);
        std::getline(stream, expect);
        if (grid.empty()) {
            assert(!stream);
            break;
        }

        std::vector<std::vector<int>> grid_ = nlohmann::json::parse(grid).get<std::vector<std::vector<int>>>();
        int stampHeight_ = nlohmann::json::parse(stampHeight).get<int>();
        int stampWidth_ = nlohmann::json::parse(stampWidth).get<int>();
        bool expect_ = nlohmann::json::parse(expect).get<bool>();
        test_case_list_.emplace_back(grid_, stampHeight_, stampWidth_, expect_);
    }
}

} // namespace leetcode