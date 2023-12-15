// https://leetcode.cn/problems/contains-duplicate-iii/
#include "array/contains_duplicate_3.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"

#include <map>
#include <sstream>
#include <string>

namespace leetcode {
namespace _220 {
class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        std::map<int, int> m;
        int last = n;
        for (int i = n - 1; i >= 0; i--) {
            auto iter = m.lower_bound(nums[i] - valueDiff);
            if (iter != m.end() && iter->first <= nums[i] + valueDiff) {
                return true;
            }
            m[nums[i]]++;
            if (last - i > indexDiff) {
                auto iter = m.find(nums[last - 1]);
                iter->second--;
                if (iter->second == 0) {
                    m.erase(iter);
                }
                last--;
            }
        }
        return false;
    }
};
} // namespace _220

std::shared_ptr<Task> ContainsDuplicate3Task::create() {
    std::shared_ptr<ContainsDuplicate3Task> task = std::make_shared<ContainsDuplicate3Task>();
    task->InitTestCase();
    return task;
}

void ContainsDuplicate3Task::run() {
    int failed = 0;
    _220::Solution sol;
    for (TestCase& ts : test_case_list_) {
        bool actual = sol.containsNearbyAlmostDuplicate(ts.nums, ts.indexDiff, ts.valueDiff);
        if (ts.expect != actual) {
            failed++;
            std::cout << std::boolalpha << "TestCase{\n" 
                    << "\tnums:" << ts.nums << "\n"
                    << "\tindexDiff:" << ts.indexDiff << "\n"
                    << "\tvalueDiff:" << ts.valueDiff << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void ContainsDuplicate3Task::InitTestCase() {
    const std::string test_case_str = R"([1,2,3,1]
3
0
true
[1,5,9,1,5,9]
2
3
false)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string nums;
        std::string indexDiff;
        std::string valueDiff;
        std::string expect;
        std::getline(stream, nums);
        std::getline(stream, indexDiff);
        std::getline(stream, valueDiff);
        std::getline(stream, expect);
        if (nums.empty()) {
            assert(!stream);
            break;
        }

        std::vector<int> nums_ = nlohmann::json::parse(nums).get<std::vector<int>>();
        int indexDiff_ = nlohmann::json::parse(indexDiff).get<int>();
        int valueDiff_ = nlohmann::json::parse(valueDiff).get<int>();
        bool expect_ = nlohmann::json::parse(expect).get<bool>();
        test_case_list_.emplace_back(nums_, indexDiff_, valueDiff_, expect_);
    }
}

} // namespace leetcode