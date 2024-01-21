#include "dp/split_array_largest_sum.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <algorithm>
#include <sstream>
#include <string>

namespace leetcode {
namespace _410 {
class Solution {
public:
    Solution(int i = 0) : i_(i) {}

    std::string name() {
        switch(i_) {
        case 0: return "binary search";
        case 1: return "dp";
        default: abort();
        }
    }

    int splitArray(std::vector<int>& nums, int k) {
        if (i_ == 0) {
            return binarySearch(nums, k);
        } else {
            return dynamicProgramming(nums, k);
        }
    }

private:
    int binarySearch(std::vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = std::accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) {
            left = std::max(left, nums[i]);
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = 0;
            int split = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                if (sum > mid) {
                    split += 1;
                    sum = nums[i];
                }
            }
            if (split < k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int dynamicProgramming(std::vector<int>& nums, int k) {
        int n = nums.size();
        // dp[i][j] 表示[0, ..., i] 拆成j个子数组
        std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1, -1));
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][1] = dp[i-1][1] + nums[i]; 
        }
        for (int i = 2; i <= k; i++) {
            for (int j = i - 1; j < n; j++) {
                int len = j + 1;
                int sum = 0;
                for (int t = j; t >= i - 1; t--) {
                    sum += nums[t];
                    if (dp[j][i] == -1) {
                        dp[j][i] = std::max(sum, dp[t-1][i-1]);
                    } else {
                        dp[j][i] = std::min(dp[j][i], std::max(sum, dp[t-1][i-1]));
                    }
                }       
            }
        }

        return dp[n-1][k];
    }

private:
    int i_;
};
} // namespace _410

std::shared_ptr<Task> SplitArrayLargestSumTask::create() {
    std::shared_ptr<SplitArrayLargestSumTask> task = std::make_shared<SplitArrayLargestSumTask>();
    task->InitTestCase();
    return task;
}

void SplitArrayLargestSumTask::run() {
    std::vector<_410::Solution> sols;
    for (int i = 0; i < 2; i++) {
        sols.push_back(_410::Solution(i));
    }
    int failed = 0;
    for (auto sol : sols) {
        for (TestCase& ts : test_case_list_) {
            int actual = sol.splitArray(ts.nums, ts.k);
            if (actual != ts.expect) {
                std::cout << "TestCase:{\n"
                        << "\tnums:" << ts.nums << "\n"
                        << "\tk:" << ts.k << "\n"
                        << "}\n"
                        << "solution:" << sol.name() << "\n"
                        << "expect:" << ts.expect << "\n"
                        << "actual:" << actual << "\n\n";
                failed++;
            }
        }
    }
    std::cout << "PASS:" << sols.size() * test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void SplitArrayLargestSumTask::InitTestCase() {
    std::string test_case_str = R"([7,2,5,10,8]
2
18
[1,2,3,4,5]
2
9
[1,4,4]
3
4)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string nums;
        std::string k;
        std::string expect;
        std::getline(stream, nums);
        std::getline(stream, k);
        std::getline(stream, expect);
        if (nums.empty()) {
            assert(!stream);
            break;
        }

        int k_ = nlohmann::json::parse(k).get<int>();
        std::vector<int> nums_ = nlohmann::json::parse(nums).get<std::vector<int>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(nums_, k_, expect_);
    }
}


} // namespace leetcode