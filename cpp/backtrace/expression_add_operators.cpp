#include "backtrace/expression_add_operators.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <algorithm>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>

namespace leetcode {
namespace _282 {
class Solution {
    public:
    std::vector<std::string> addOperators(std::string num, int target) {
        int n = num.size();
        std::vector<char> op(n - 1, '\0');
        std::vector<std::string> ans;
        backtrace(op, 0, target, num, ans);
        return ans;
    }

private:
    bool isPrior(char op1, char op2) {
        static std::unordered_map<char, int> priority_map = {
            {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}
        };
        int op1_priority = priority_map[op1];
        int op2_priority = priority_map[op2];
        return op1_priority >= op2_priority;
    }

    std::pair<std::string, long long> calculate(const std::string& num, const std::vector<char>& op) {
        int n = op.size();
        std::stack<long long> s_int;
        std::stack<char> s_op;
        int prev = 0;
        std::string expression;
        for (int i = 0; i < n; i++) {
            if (!op[i]) {
                continue;
            }
            std::string s = num.substr(prev, i - prev + 1);
            expression.append(s);
            expression.push_back(op[i]);
            int val = 0;
            try {
                val = std::stoll(s);
            } catch(...) {
                std::cout << s << std::endl;
                return {"", -1};
            }
            while (!s_op.empty() && isPrior(s_op.top(), op[i])) {
                switch(s_op.top()) {
                    case '+': val = s_int.top() + val; break;
                    case '-': val = s_int.top() - val; break;
                    case '*': val = s_int.top() * val; break;
                    default: assert(false);
                }
                s_op.pop();
                s_int.pop();
            }
            s_int.push(val);
            s_op.push(op[i]);
            prev = i + 1;
        }
        std::string s = num.substr(prev, n - prev + 1);
        expression.append(s);
        int val = 0;
        try {
            val = std::stoll(s);
        } catch(...) {
            std::cout << s << std::endl;
            return {"", -1};
        }
        while (!s_op.empty()) {
            switch(s_op.top()) {
                case '+': val = s_int.top() + val; break;
                case '-': val = s_int.top() - val; break;
                case '*': val = s_int.top() * val; break;
                default: assert(false);
            }
            s_op.pop();
            s_int.pop();
        }
        return {expression, val};
    }
    

    void backtrace(std::vector<char>& op, int idx, 
                   int target, std::string& num, std::vector<std::string>& ans) {
        if (idx == op.size()) {
            auto p = calculate(num, op);
            if (p.second == target) {
                ans.push_back(p.first);
            }
            return;
        } 

        for (char i : std::vector<char>{'\0', '+', '-', '*'}) {
            if (num[idx] == '0' && (idx == 0 || op[idx-1] != '\0') && i == '\0') {
                continue;
            }
            op[idx] = i;
            backtrace(op, idx + 1, target, num, ans);
            op[idx] = '\0';
        }
    }
};

} // namespace _282

std::shared_ptr<Task> ExpressionAddOperatorsTask::create() {
    std::shared_ptr<ExpressionAddOperatorsTask> task = std::make_shared<ExpressionAddOperatorsTask>();
    task->InitTestCase();
    return task;
}

void ExpressionAddOperatorsTask::run() {
    _282::Solution sol;
    int failed = 0;
    for (TestCase& ts : test_case_list_) {
        std::vector<std::string> actual = sol.addOperators(ts.num, ts.target);
        std::sort(actual.begin(), actual.end());
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tnum:" << ts.num << "\n"
                    << "\ttarget:" << ts.target << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
        << "FAILED:" << failed << std::endl;
}

void ExpressionAddOperatorsTask::InitTestCase() {
    const std::string test_case_str = R"("123"
6
["1*2*3","1+2+3"]
"232"
8
["2*3+2","2+3*2"]
"3456237490"
9191
[]
"105"
5
["1*0+5","10-5"])";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string num;
        std::string target;
        std::string expect;
        std::getline(stream, num);
        std::getline(stream, target);
        std::getline(stream, expect);
        if (num.empty()) {
            assert(!stream);
            break;
        }

        std::string num_ = nlohmann::json::parse(num).get<std::string>();
        int target_ = nlohmann::json::parse(target).get<int>();
        std::vector<std::string> expect_ = 
            nlohmann::json::parse(expect).get<std::vector<std::string>>(); 
        std::sort(expect_.begin(), expect_.end());
        test_case_list_.emplace_back(num_, target_, expect_);
    }
}

} // namespace leetcode