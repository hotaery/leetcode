#ifndef ARRAY_BEAUTIFUL_TOWERS_H
#define ARRAY_BEAUTIFUL_TOWERS_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class BeautifulTowers2Task : public Task {
    struct TestCase {
        std::vector<int> maxHeights; 
        long long expect;

        TestCase(const std::vector<int>& maxHeights_, long long expect_)
            : maxHeights(maxHeights_), expect(expect_) {}
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