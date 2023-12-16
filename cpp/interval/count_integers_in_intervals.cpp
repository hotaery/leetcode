// https://leetcode.cn/problems/count-integers-in-intervals
#include "interval/count_integers_in_intervals.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"
#include "utils/operator.h"

#include <set>
#include <sstream>
#include <string>
#include <utility>

namespace leetcode {
namespace _2276 {
class CountIntervals {
    struct Interval {
        int left;
        int right;

        Interval(int l, int r) : left(l), right(r) {}

        int count() const {
            return right - left + 1;
        }

        bool operator<(const Interval& rhs) const {
            return left <  rhs.left;
        }
    };
public:
    CountIntervals() {
        count_ = 0;
    }
    
    void add(int left, int right) {
        auto start = intervals_.lower_bound(Interval(left, -1));
        if (start != intervals_.begin()) {
            auto iter = start;
            --iter;
            if (iter->right >= left) {
                start = iter;
            }
        } 
        if (start == intervals_.end() || start->left > right) {
            Interval interval(left, right);
            count_ += interval.count();
            intervals_.insert(interval);
            return;
        }
        auto end = intervals_.upper_bound(Interval(right, -1));
        left = std::min(left, start->left);
        while (start != end) {
            right = std::max(right, start->right);
            count_ -= start->count();
            start = intervals_.erase(start);
        }
        Interval interval(left, right);
        count_ += interval.count();
        intervals_.insert(interval);
    }
    
    int count() {
        return count_;
    }

private:
    std::set<Interval> intervals_;
    int count_;
};
} // namespace _2276

std::shared_ptr<Task> CountIntegersInIntervalsTask::create() {
    std::shared_ptr<CountIntegersInIntervalsTask> task = 
        std::make_shared<CountIntegersInIntervalsTask>();
    task->InitTestCase();
    return task;
}

void CountIntegersInIntervalsTask::run() {
    int failed = 0;
    for (TestCase& ts : test_case_list_) {
        _2276::CountIntervals* ci = NULL;
        std::unique_ptr<_2276::CountIntervals> ci_guard;
        std::vector<int> actual;
        int idx = 0;
        for (std::string& op : ts.ops) {
            if (op == "CountIntervals") {
                ci_guard.reset(new _2276::CountIntervals);
                ci = ci_guard.get();
            } else if (op == "add") {
                ci->add(ts.args[idx][0], ts.args[idx][1]);
            } else if (op == "count") {
                actual.push_back(ci->count());
            } else {
                assert(false);
            }
            idx++;
        }
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tops:" << ts.ops << "\n"
                    << "\targs:" << ts.args << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void CountIntegersInIntervalsTask::InitTestCase() {
    const std::string test_case_str = R"(["CountIntervals","add","add","count","add","count"]
[[],[2,3],[7,10],[],[5,8],[]]
[6,8]
["CountIntervals","count","add","add","count","count","add"]
[[],[],[39,44],[13,49],[],[],[47,50]]
[0,37,37]
["CountIntervals","add","add","count"]
[[],[5,10],[3,5],[]]
[8])";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string ops;
        std::string args;
        std::string expect;
        std::getline(stream, ops);
        std::getline(stream, args);
        std::getline(stream, expect);
        if (ops.empty()) {
            assert(!stream);
            break;
        }

        std::vector<std::string> ops_ = nlohmann::json::parse(ops).get<std::vector<std::string>>();
        std::vector<std::vector<int>> args_ = 
            nlohmann::json::parse(args).get<std::vector<std::vector<int>>>();
        std::vector<int> expect_ = nlohmann::json::parse(expect).get<std::vector<int>>();
        test_case_list_.emplace_back(ops_, args_, expect_);
    }
}

} // namespace leetcode