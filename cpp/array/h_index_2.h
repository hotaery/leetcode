#ifndef ARRAY_H_INDEX_2_H
#define ARRAY_H_INDEX_2_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class HIndex2Task : public Task {
    struct TestCase {
        std::vector<int> citations;
        int expect;

        TestCase(const std::vector<int>& citations_, int expect_)
            : citations(citations_), expect(expect_) {}
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