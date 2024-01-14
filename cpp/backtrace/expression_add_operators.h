#ifndef BACKTRACE_EXPRESSION_ADD_OPERATORS_H
#define BACKTRACE_EXPRESSION_ADD_OPERATORS_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class ExpressionAddOperatorsTask : public Task {
    struct TestCase {
        std::string num;
        int target;
        std::vector<std::string> expect;

        TestCase(const std::string& num_, int target_, 
                const std::vector<std::string>& expect_)
            : num(num_), target(target_), expect(expect_) {}
    };

public:
    std::shared_ptr<Task> create() override;
    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif