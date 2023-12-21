// https://leetcode.cn/problems/beautiful-towers-ii
#include "array/beautiful_towers_2.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <sstream>
#include <stack>
#include <string>

namespace leetcode {

using std::vector;
using std::stack;
using std::max;

namespace _2866 {
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long n = maxHeights.size();
        stack<int> s;
        vector<long long> left(n), right(n);
        for (long long i = 0; i < n; i++) {
            while (!s.empty() && maxHeights[i] < maxHeights[s.top()]) {
                s.pop();
            }
            if (s.empty()) {
                left[i] = (i + 1) * maxHeights[i];
            } else {
                left[i] = left[s.top()] + (i - s.top()) * maxHeights[i];
            }
            s.push(i);
        }
        s = stack<int>();
        for (long long i = n - 1; i >= 0; i--) {
            while (!s.empty() && maxHeights[i] < maxHeights[s.top()]) {
                s.pop();
            }
            if (s.empty()) {
                right[i] = (n - i) * maxHeights[i];
            } else {
                right[i] = right[s.top()] + (s.top() - i) * maxHeights[i];
            }
            s.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(left[i] + right[i] - maxHeights[i], ans);
        }
        return ans;
    }
};
} // namespace_2866

std::shared_ptr<Task> BeautifulTowers2Task::create() {
    std::shared_ptr<BeautifulTowers2Task> task = std::make_shared<BeautifulTowers2Task>();
    task->InitTestCase();
    return task;
}

void BeautifulTowers2Task::run() {
    int failed = 0;
    _2866::Solution sol;
    for (TestCase& ts : test_case_list_) {
        long long actual = sol.maximumSumOfHeights(ts.maxHeights);
        if (ts.expect != actual) {
            failed++;
            std::cout << "TestCase{\n" 
                    << "\tmaxHeights:" << ts.maxHeights << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void BeautifulTowers2Task::InitTestCase() {
    const std::string test_case_str = R"([5,3,4,1,1]
13
[6,5,3,9,2,7]
22
[3,2,5,5,2,3]
18
[1]
1)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string maxHeights;
        std::string expect;
        std::getline(stream, maxHeights);
        std::getline(stream, expect);
        if (maxHeights.empty()) {
            assert(!stream);
            break;
        }

        std::vector<int> maxHeights_ = nlohmann::json::parse(maxHeights).get<std::vector<int>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        test_case_list_.emplace_back(maxHeights_, expect_);
    }
}

} // namespace leetcode