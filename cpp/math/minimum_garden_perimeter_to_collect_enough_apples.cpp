#include "math/minimum_garden_perimeter_to_collect_enough_apples.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <sstream>
#include <string>

#include <cmath>

namespace leetcode {
namespace _1954 {

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long left = 1, right = 100000;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long apples = 0;
            long long first = 0, last = 0;
            if (mid % 2) {
                first = (1 + mid) / 2 * mid;
            } else {
                first = mid / 2 * (1 + mid);
            }
            last = first + (mid + 1) * mid;
            if ((mid + 1) % 2) {
                apples = (first + last) / 2 * (mid + 1);
            } else {
                apples = (mid + 1) / 2 * (first + last);
            }
            apples *= 4;
            apples -= 4 * first;
            if (apples < neededApples) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return 2 * left * 4;
    }
};

} // namespace _1954

std::shared_ptr<Task> MinimumGardenPerimeterToCollectEnoughApplesTask::create() {
    std::shared_ptr<MinimumGardenPerimeterToCollectEnoughApplesTask> task = 
        std::make_shared<MinimumGardenPerimeterToCollectEnoughApplesTask>();
    task->InitTestCase();
    return task;
}

void MinimumGardenPerimeterToCollectEnoughApplesTask::run() {
    int failed = 0;
    _1954::Solution sol;
    for (TestCase& ts : test_case_list_) {
        int actual = sol.minimumPerimeter(ts.neededApples);
        if (ts.expect != actual) {
            failed++;
            std::cout << "TestCase{\n" 
                    << "\tneededApples:" << ts.neededApples << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void MinimumGardenPerimeterToCollectEnoughApplesTask::InitTestCase() {
    const std::string test_case_str = R"(1
8
13
16
1000000000
5040
100000000000000
233920)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string neededApples;
        std::string expect;
        std::getline(stream, neededApples);
        std::getline(stream, expect);
        if (neededApples.empty()) {
            assert(!stream);
            break;
        }

        long long neededApples_ = nlohmann::json::parse(neededApples).get<long long>();
        long long expect_ = nlohmann::json::parse(expect).get<long long>();
        test_case_list_.emplace_back(neededApples_, expect_);
    }
}


} // namespace leetcode