// https://leetcode.cn/problems/h-index-ii
#include "array/h_index_2.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <sstream>
#include <string>

namespace leetcode {
namespace _275 {
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (citations[mid] >= n - mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (citations[l] >= n - l) {
            return n - l;
        }
        return 0;
    }
};
} // namespace _275

std::shared_ptr<Task> HIndex2Task::create() {
    std::shared_ptr<HIndex2Task> task = std::make_shared<HIndex2Task>();
    task->InitTestCase();
    return task;
}

void HIndex2Task::run() {
    int failed = 0;
    _275::Solution sol;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.hIndex(ts.citations);
        if (actual != ts.expect) {
            failed++;
            std::cout << "TestCase:{\n"
                    << "\tcitations:" << ts.citations << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void HIndex2Task::InitTestCase() {
    const std::string test_case_str = R"([0,1,3,5,6]
3
[1,2,100]
2
[0]
0
[0,0]
0)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string citations;
        std::string expect;
        std::getline(stream, citations);
        std::getline(stream, expect);
        if (citations.empty()) {
            assert(!stream);
            break;
        }

        std::vector<int> citations_ = nlohmann::json::parse(citations).get<std::vector<int>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(citations_, expect_);
    }
}

} // namespace leetcode