#include "math/number_of_burgers_with_no_waste_of_ingredients.h"
#include "nlohmann/json.hpp"
#include "utils/operator.h"
#include "utils/print.h"

#include <sstream>
#include <string>

namespace leetcode {
namespace _1276 {
class Solution {
public:
    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x = tomatoSlices - 2 * cheeseSlices;
        if (x < 0 || x % 2 || x / 2 > cheeseSlices) {
            return {};
        }

        int jumbo = x / 2, small = cheeseSlices - jumbo;
        return {jumbo, small};
    }
};

} // namespace _1276

std::shared_ptr<Task> NumberOfBurgersWithNoWasteOfIngredientsTask::create() {
    std::shared_ptr<NumberOfBurgersWithNoWasteOfIngredientsTask> task = std::make_shared<NumberOfBurgersWithNoWasteOfIngredientsTask>();
    task->InitTestCase();
    return task;
}

void NumberOfBurgersWithNoWasteOfIngredientsTask::run() {
    _1276::Solution sol;
    int failed = 0;
    for (TestCase& ts : test_case_list_) {
        std::vector<int> actual = sol.numOfBurgers(ts.tomatoSlices, ts.cheeseSlices);
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\ttomatoSlices:" << ts.tomatoSlices << "\n"
                    << "\tcheeseSlices:" << ts.cheeseSlices << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
        << "FAILED:" << failed << std::endl;
}

void NumberOfBurgersWithNoWasteOfIngredientsTask::InitTestCase() {
    const std::string test_case_str = R"(16
7
[1,6]
17
4
[]
4
17
[])";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string tomatoSlices;
        std::string cheeseSlices;
        std::string expect;
        std::getline(stream, tomatoSlices);
        std::getline(stream, cheeseSlices);
        std::getline(stream, expect);
        if (tomatoSlices.empty()) {
            assert(!stream);
            break;
        }

        int tomatoSlices_ = nlohmann::json::parse(tomatoSlices).get<int>();
        int cheeseSlices_ = nlohmann::json::parse(cheeseSlices).get<int>();
        std::vector<int> expect_ = 
            nlohmann::json::parse(expect).get<std::vector<int>>();
        test_case_list_.emplace_back(tomatoSlices_, cheeseSlices_, expect_);
    }
}

} // namespace leetcode