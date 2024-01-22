// https://leetcode.cn/problems/maximum-swap/description/
#include "math/maximum_swap.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

namespace leetcode {
namespace _670 {
class Solution {
public:
    int maximumSwap(int num) {
        std::vector<int> nums;
        int tmp = num;
        while (tmp) {
            nums.push_back(tmp % 10);
            tmp /= 10;
        }
        int n = nums.size();
        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](int i, int j) {
            if (nums[i] != nums[j]) {
                return nums[i] < nums[j];
            } else {
                return i < j;
            }
        });
        for (int i = n - 1; i >=0; i--) {
            if (idx[i] != i) {
                int j = i;
                while (j > 0 && nums[idx[j]] == nums[idx[j-1]]) {
                    j--;
                }
                std::swap(nums[i], nums[idx[j]]);
                break;
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = ans * 10 + nums[i];
        }
        return ans;
    }
};
} // namespace _670

std::shared_ptr<Task> MaximumSwapTask::create() {
    std::shared_ptr<MaximumSwapTask> task = std::make_shared<MaximumSwapTask>();
    task->InitTestCase();
    return task;
}

void MaximumSwapTask::run() {
    int failed = 0;
    _670::Solution sol;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.maximumSwap(ts.num);
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tnum:" << ts.num << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
        << "FAILED:" << failed << std::endl;
}

void MaximumSwapTask::InitTestCase() {
    const std::string test_case_str = R"(2736
7236
9973
9973
1993
9913
98368
98863)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string num;
        std::string expect;
        std::getline(stream, num);
        std::getline(stream, expect);
        if (num.empty()) {
            assert(!stream);
            break;
        }

        int num_ = nlohmann::json::parse(num).get<int>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(num_, expect_);
    }
}

} // namespace leetcode
 