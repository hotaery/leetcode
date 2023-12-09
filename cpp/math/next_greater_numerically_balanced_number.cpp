// https://leetcode.cn/problems/next-greater-numerically-balanced-number/description
#include "math/next_greater_numerically_balanced_number.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <algorithm>
#include <sstream>
#include <string>

namespace leetcode {
namespace _2048 {
class Solution {
public:
    int nextBeautifulNumber(int n) {
        if (n <= 0) {
            return 1;
        }
        std::vector<int> digits = getDigit(n);
        std::vector<std::vector<int>> ans;
        std::vector<int> used(10, 0);
        backtrace(digits.size(), 1, used, ans);
        int ret = 0;
        bool found = false;
        for (std::vector<int>& curr : ans) {
            if (curr.back() < digits.back()) {
                continue;
            }
            std::vector<int> remain(10, 0);
            for (int i : curr) {
                remain[i] = i;
            }

            std::vector<int> curr_ans;
            bool succ = backtrace2(digits, digits.size()-1, false, remain, curr_ans);
            if (succ) {
                std::reverse(curr_ans.begin(), curr_ans.end());
                found = true;
                int val = 0;
                for (auto iter = curr_ans.rbegin(); iter != curr_ans.rend(); ++iter) {
                    val += *iter * std::pow(10, std::distance(iter, curr_ans.rend())-1);
                }
                ret = ret == 0 ? val : std::min(ret, val);
            }
        }
        if (!found) {
            return nextBeautifulNumber(std::pow(10, digits.size()));
        }
        return ret;
    }

private:
    std::vector<int> getDigit(int n) {
        std::vector<int> ans;
        while (n) {
            ans.push_back(n % 10);
            n /= 10;
        }
        return ans;
    }

    bool backtrace2(std::vector<int>& digits, int k, bool greater, 
                    std::vector<int>& remain, std::vector<int>& ret) {
        if (k < 0) {
            return true;
        }
        int start = digits[k];
        if (k == 0) {
            start += 1;
        }
        if (greater) {
            start = 1;
        }
        for (int i = start; i < 10; i++) {
            if (remain[i] <= 0) {
                continue;
            }
            ret.push_back(i);
            remain[i]--;
            if (!greater && i > start) {
                greater = true;
            }
            if (backtrace2(digits, k - 1, greater, remain, ret)) {
                return true;
            }
            remain[i]++;
            ret.pop_back();
        }
        return false;
    }

    void backtrace(int n, int m, std::vector<int>& used, std::vector<std::vector<int>>& ans) {
        if (n == 0) {
            std::vector<int> v;
            for (int i = 1; i <= 9; i++) {
                if (used[i]) {
                    v.push_back(i);
                }
            }
            if (!v.empty()) {
                ans.push_back(v);
            }
            return;
        }

        for (int i = m; i <= 9; i++) {
            if (used[i]) {
                continue;
            }
            if (i > n) {
                break;
            }
            used[i] = 1;
            backtrace(n - i, i + 1, used, ans);
            used[i] = 0;
        }
    }
};
} // namespace_2048

std::shared_ptr<Task> NextGreaterNumericallyBalancedNumberTask::create() {
    std::shared_ptr<NextGreaterNumericallyBalancedNumberTask> task = 
        std::make_shared<NextGreaterNumericallyBalancedNumberTask>();
    task->InitTestCase();
    return task;
}

void NextGreaterNumericallyBalancedNumberTask::run() {
    int failed = 0;
    _2048::Solution sol;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.nextBeautifulNumber(ts.n);
        if (ts.expect != actual) {
            std::cout << "TestCase:{\n"
                    << "\tn:" << ts.n << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void NextGreaterNumericallyBalancedNumberTask::InitTestCase() {
    const std::string test_case_str = R"(1
22
1000
1333
3000
3133
4567
14444
188
212)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string n;
        std::string expect;
        std::getline(stream, n);
        std::getline(stream, expect);
        if (n.empty()) {
            assert(!stream);
            break;
        }

        int n_ = nlohmann::json::parse(n).get<int>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(n_, expect_);
    }
}

} // namespace leetcode