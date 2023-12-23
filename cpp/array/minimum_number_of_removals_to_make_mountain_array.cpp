#include "array/minimum_number_of_removals_to_make_mountain_array.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <sstream>
#include <stack>
#include <string>

namespace leetcode {
namespace _1671 {
class Solution {
public:
    int minimumMountainRemovals(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> left(n), right(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    left[i] = std::max(left[i], 1 + left[j]);
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    right[i] = std::max(right[i], 1 + right[j]);
                }
            }
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (left[i] == 0 || right[i] == 0) {
                continue;
            }
            ans = std::min(ans, i - left[i] + n - i - 1 - right[i]);
        }
        return ans;
    }
};
} // namespace _1671

std::shared_ptr<Task> MinimumNumberOfRemovalsToMakeMountainArrayTask::create() {
    std::shared_ptr<MinimumNumberOfRemovalsToMakeMountainArrayTask> task = 
        std::make_shared<MinimumNumberOfRemovalsToMakeMountainArrayTask>();
    task->InitTestCase();
    return task;
}

void MinimumNumberOfRemovalsToMakeMountainArrayTask::run() {
    int failed = 0;
    _1671::Solution sol;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.minimumMountainRemovals(ts.nums);
        if (ts.expect != actual) {
            failed++;
            std::cout << "TestCase{\n" 
                    << "\nums:" << ts.nums << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void MinimumNumberOfRemovalsToMakeMountainArrayTask::InitTestCase() {
    const std::string test_case_str = R"([1,3,1]
0
[2,1,1,5,6,2,3,1]
3)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string nums;
        std::string expect;
        std::getline(stream, nums);
        std::getline(stream, expect);
        if (nums.empty()) {
            assert(!stream);
            break;
        }

        std::vector<int> nums_ = nlohmann::json::parse(nums).get<std::vector<int>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(nums_, expect_);
    }
}

} // namespace leetcode