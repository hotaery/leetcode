#ifndef MATH_NUMBER_OF_BURGERS_WITH_NO_WASTE_OF_INGREDIENTS_H
#define MATH_NUMBER_OF_BURGERS_WITH_NO_WASTE_OF_INGREDIENTS_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class NumberOfBurgersWithNoWasteOfIngredientsTask : public Task {
    struct TestCase {
        int tomatoSlices;
        int cheeseSlices;
        std::vector<int> expect;

        TestCase(int tomatoSlices_, int cheeseSlices_,
                 const std::vector<int>& expect_)
            : tomatoSlices(tomatoSlices_), cheeseSlices(cheeseSlices_)
            , expect(expect_) {}
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