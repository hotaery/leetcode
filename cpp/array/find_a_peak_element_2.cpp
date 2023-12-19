// https://leetcode.cn/problems/find-a-peak-element-ii
#include "array/find_a_peak_element_2.h"
#include "nlohmann/json.hpp"
#include "utils/operator.h"
#include "utils/print.h"

#include <algorithm>
#include <sstream>
#include <string>

namespace leetcode {
namespace _1901 {
class Solution {
public:
    std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int l = 0, r = m - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int col = std::max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if (mat[mid][col] > mat[mid + 1][col]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return std::vector<int>{l, std::max_element(mat[l].begin(), mat[l].end()) - mat[l].begin()};
    }
};
} // namespace _1901

std::shared_ptr<Task> FindAPeakElement2Task::create() {
    std::shared_ptr<FindAPeakElement2Task> task = std::make_shared<FindAPeakElement2Task>();
    task->InitTestCase();
    return task;
}

void FindAPeakElement2Task::run() {
    int failed = 0;
    _1901::Solution sol;
    for (TestCase& ts : test_case_list_) {
        std::vector<int> actual = sol.findPeakGrid(ts.mat);
        auto iter = std::find(ts.expect.begin(), ts.expect.end(), actual);
        if (iter == ts.expect.end()) {
            std::cout << "TestCase:{\n"
                    << "\tmat:" << ts.mat << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void FindAPeakElement2Task::InitTestCase() {
    const std::string test_case_str = R"([[1,4],[3,2]]
[[0,1],[1,0]]
[[10,20,15],[21,30,14],[7,16,32]]
[[1,1],[2,2]])";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string mat;
        std::string expect;
        std::getline(stream, mat);
        std::getline(stream, expect);
        if (mat.empty()) {
            assert(!stream);
            break;
        }

        std::vector<std::vector<int>> mat_ = 
            nlohmann::json::parse(mat).get<std::vector<std::vector<int>>>();
        std::vector<std::vector<int>> expect_ = 
            nlohmann::json::parse(expect).get<std::vector<std::vector<int>>>();
        test_case_list_.emplace_back(mat_, expect_);
    }
}

} // namespace leetcode