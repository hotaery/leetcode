// https://leetcode.cn/problems/maximum-subarray/description/
#include "interval/maximum_subarray.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <climits>
#include <functional>

namespace leetcode {
namespace _53 {

class Solution {
public:
    Solution(int i = 1) : i_(i) {}

    int maxSubArray(std::vector<int>& nums) {
        if (i_ == 0) {
            return greedy(nums);
        } else {
            return divideAndConquer(nums);
        }
    }

    std::string name() {
        if (i_ == 0) {
            return "greedy";
        } else {
            return "divide and conquer";
        }
    }

private:
    int greedy(std::vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int sum = nums[0] < 0 ? 0 : nums[0];

        for (int i = 1; i < n; i++) {
            sum += nums[i];
            ans = std::max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }

    int divideAndConquer(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> start(n), end(n);
        start[0] = nums[0];
        for (int i = 1; i < n; i++) {
            start[i] = std::max(nums[i], start[i-1] + nums[i]);
        }
        end[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            end[i] = std::max(nums[i], end[i+1]+nums[i]);
        }

        std::function<int(int, int)> divide_and_conquer = [&](int left, int right) -> int {
            if (right - left == 1) {
                return nums[left];
            }
            int mid = left + (right - left) / 2;
            int left_sum = divide_and_conquer(left, mid);
            int right_sum = divide_and_conquer(mid, right);
            int ans = std::max(left_sum, right_sum);
            ans = std::max(ans, start[mid-1] + end[mid]);
            return ans;
        };

        return divide_and_conquer(0, n);
    }

    int i_;
};

} // namespace _53

MaximumSubarrayTask::MaximumSubarrayTask() {}
MaximumSubarrayTask::~MaximumSubarrayTask() {}

std::shared_ptr<Task> MaximumSubarrayTask::create() {
    std::shared_ptr<MaximumSubarrayTask> task = std::make_shared<MaximumSubarrayTask>();
    task->InitTestCase();
    return task;
}

void MaximumSubarrayTask::run() {
    std::vector<_53::Solution> solution_list;
    for (int i = 0; i < 2; i++) {
        solution_list.emplace_back(i);
    }
    int failed = 0;
    for (TestCase& ts : test_case_list_) {
        for (_53::Solution& sol : solution_list) {
            int actual = sol.maxSubArray(ts.nums);
            if (actual != ts.expect) {
                std::cout << "TestCase:{\n"
                        << "\tnums:" << ts.nums << "\n"
                        << "}\n"
                        << "solution:" << sol.name() << "\n"
                        << "expect:" << ts.expect << "\n"
                        << "actual:" << actual << "\n\n";
                failed++;
            } 
        }
    }
    std::cout << "PASS:" << solution_list.size() * test_case_list_.size() - failed << "\n"
              << "FAILED:" << failed << std::endl;
}

void MaximumSubarrayTask::InitTestCase() {
    const std::string test_case_str = R"([-2,1,-3,4,-1,2,1,-5,4]
6
[1]
1
[5,4,-1,7,8]
23)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string nums_str;
        std::string expect;
        std::getline(stream, nums_str);
        std::getline(stream, expect);
        if (nums_str.empty()) {
            assert(!stream);
            break;
        }
        std::vector<int> nums = nlohmann::json::parse(nums_str).get<std::vector<int>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(nums, expect_);
    }
}

} // namespace leetcode