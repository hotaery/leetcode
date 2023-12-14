//https://leetcode.cn/problems/next-greater-element-iv
#include "array/next_greater_element_4.h"
#include "nlohmann/json.hpp"
#include "utils/operator.h"
#include "utils/print.h"

#include <queue>
#include <sstream>
#include <stack>
#include <string>

namespace leetcode {
namespace _2454 {
class Solution {
public:
    Solution(int i = 0) : i_(i) {}

    std::vector<int> secondGreaterElement(std::vector<int>& nums) {
        return priorityQueue(nums);
    }

    std::string name() {
        if (i_ == 0) {
            return "priority_queue";
        } else {
            return "dual stack";
        }
    }

private:
    std::vector<int> priorityQueue(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, -1);
        // 递减单调栈，保存第一个大于nums[i]的元素下标
        std::stack<int> st; 
        auto cmp = [](std::vector<int>& lhs, std::vector<int>& rhs) -> bool {
            if (lhs[0] > rhs[0]) {
                return true;
            } else if (lhs[0] == rhs[0]) {
                return lhs[1] < rhs[1];
            }
            return false;
        };
        // 使用小根堆保存单调栈中pop出来的元素
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < n; i++) {
            // q.top()[1]第一大元素在单调栈中，现在再次碰到一个大于q.top()[1]的元素，那么就找到
            // 第二大元素
            while (!q.empty() && q.top()[0] < nums[i]) {
                res[q.top()[1]] = nums[i];
                q.pop();
            }
            while (!st.empty() && nums[i] > nums[st.top()]) {
                // 找到st.top()第一大元素，将其放入q中，等待再次找到比其大的元素
                q.emplace(std::vector<int>{nums[st.top()], st.top()});
                st.pop(); 
            }
            st.push(i);
        }
        return res;
    }

private:
    int i_;
};
} // namespace _2454

std::shared_ptr<Task> NextGreaterElement4Task::create() {
    std::shared_ptr<NextGreaterElement4Task> task = std::make_shared<NextGreaterElement4Task>();
    task->InitTestCase();
    return task;
}

void NextGreaterElement4Task::run() {
    int failed = 0;
    std::vector<_2454::Solution> sols;
    sols.push_back(_2454::Solution(0));
    // sols.push_back(_2454::Solution(1));
    for (_2454::Solution& sol : sols) {
        for (TestCase& ts : test_case_list_) {
            std::vector<int> actual = sol.secondGreaterElement(ts.nums);
            if (actual != ts.expect) {
                std::cout << "TestCase:{\n"
                        << "\tnums:" << ts.nums << "\n"
                        << "}\n"
                        << "name:" << sol.name() << "\n"
                        << "expect:" << ts.expect << "\n"
                        << "actual:" << actual << "\n\n";
                failed++;
            }
        }
    }
    std::cout << "PASS:" << sols.size() * test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void NextGreaterElement4Task::InitTestCase() {
    const std::string test_case_str = R"([2,4,0,9,6]
[9,6,6,-1,-1]
[3,3]
[-1,-1])";
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
        std::vector<int> expect_ = nlohmann::json::parse(expect).get<std::vector<int>>();
        test_case_list_.emplace_back(nums_, expect_);
    }
}

} // namespace leetcode