// https://leetcode.cn/problems/longest-alternating-subarray
#include "array/longest_alternating_subarray.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <sstream>
#include <string>

namespace leetcode {
namespace _2765 {
class Solution {
public:
    int alternatingSubarray(std::vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            if (std::abs(diff) != 1) {
                ans = std::max(ans, i - start);
                start = i;
            } else {
                if (i % 2 == start % 2 && diff != -1) {
                    ans = std::max(ans, i - start);
                    start = i - 1;
                } else if (i % 2 != start % 2 && diff != 1) {
                    ans = std::max(ans, i - start);
                    start = i;
                }
            }
        }
        ans = std::max(ans, n - start);
        return ans > 1 ? ans : -1;
    }
};
} // namespace _2765

std::shared_ptr<Task> LongestAlternatingSubarrayTask::create() {
    std::shared_ptr<LongestAlternatingSubarrayTask> task(
        new LongestAlternatingSubarrayTask());
    task->InitTestCases();
    return task;
}

void LongestAlternatingSubarrayTask::run() {
    int failed = 0;
    _2765::Solution solution;
    for (auto& test_case : test_cases_) {
        auto result = solution.alternatingSubarray(test_case.nums);
        if (result != test_case.expect) {
            std::cout << "TestCase:{\n"
                    << "\tnums:" << test_case.nums << "\n"
                    << "}\n"
                    << "expect:" << test_case.expect << "\n"
                    << "actual:" << result << "\n\n";
            ++failed;
        }
    }
    std::cout << "PASS:" << test_cases_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void LongestAlternatingSubarrayTask::InitTestCases() {
    const std::string test_case_str = R"([2,3,4,3,4]
4
[4,5,6]
2
[21,9,5]
-1
[14,30,29,49,3,23,44,21,26,52]
-1)";
    std::istringstream iss(test_case_str);
    while (iss) {
        std::string nums;
        std::string expect;
        std::getline(iss, nums);
        std::getline(iss, expect);
        if (nums.empty() || expect.empty()) {
            assert(!iss);
            break;
        }
        std::vector<int> nums_ = nlohmann::json::parse(nums).get<std::vector<int>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_cases_.emplace_back(nums_, expect_);
    }
}

} // namespace leetcode