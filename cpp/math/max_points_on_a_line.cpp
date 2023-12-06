// https://leetcode.cn/problems/max-points-on-a-line/description/
#include "math/max_points_on_a_line.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>

#include <cstdlib>
#include <cmath>

namespace leetcode {
namespace _149 {

class Solution {
    struct Hash {
        bool operator()(const std::vector<int>& vec) const {
            return std::hash<int>()(vec[0]) ^ std::hash<int>()(vec[1]);
        }
    };

    struct Equal {
        bool operator()(const std::vector<int>& lhs, const std::vector<int>& rhs) const {
            return lhs[0] == rhs[0] && lhs[1] == rhs[1];
        }
    };
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (ans >= n - i) {
                break;
            }
            std::unordered_map<std::vector<int>, int, Hash, Equal> cnt_map;
            for (int j = i + 1; j < n; j++) {
                std::vector<int> vec = {points[j][0] - points[i][0], points[j][1] - points[i][1]};
                if (vec[0] == 0) {
                    vec[1] = 1;
                } else if (vec[1] == 0) {
                    vec[0] = 1;
                } else {
                    if (vec[1] < 0) {
                        vec[0] = -vec[0];
                        vec[1] = -vec[1];
                    }
                    int gcd = std::__gcd(std::abs(vec[0]), std::abs(vec[1]));
                    vec[0] /= gcd;
                    vec[1] /= gcd;
                }
                cnt_map[vec]++;
            }
            for (auto& elem : cnt_map) {
                ans = std::max(ans, elem.second + 1);
            }
        }
        return ans;
    }
};

} // namespace _149

MaxPointsOnALineTask::MaxPointsOnALineTask() {}
MaxPointsOnALineTask::~MaxPointsOnALineTask() {}

std::shared_ptr<Task> MaxPointsOnALineTask::create() {
    std::shared_ptr<MaxPointsOnALineTask> task = std::make_shared<MaxPointsOnALineTask>();
    task->InitTestCase();
    return task;
}

void MaxPointsOnALineTask::run() {
    _149::Solution sol;
    int failed = 0;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.maxPoints(ts.points);
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tpoints:" << ts.points << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
        << "FAILED:" << failed << std::endl;
}

void MaxPointsOnALineTask::InitTestCase() {
    const std::string test_case_str = R"([[1,1],[2,2],[3,3]]
3
[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
4
[[0,0]]
1
[[-9,-651],[-4,-4],[-8,-582],[9,591],[-3,3]]
3)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string points;
        std::string expect;
        std::getline(stream, points);
        std::getline(stream, expect);
        if (points.empty()) {
            assert(!stream);
            break;
        }

        std::vector<std::vector<int>> points_ = 
            nlohmann::json::parse(points).get<std::vector<std::vector<int>>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(points_, expect_);
    }
}

} // namespace leetcode