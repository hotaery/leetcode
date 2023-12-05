#ifndef GRAPH_MINIMUM_FUEL_COST_TO_REPORT_TO_THE_CAPITAL_H
#define GRAPH_MINIMUM_FUEL_COST_TO_REPORT_TO_THE_CAPITAL_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class MinimumFuelCostToReportToTheCapitalTask : public Task {
    struct TestCase {
        std::vector<std::vector<int>> roads;
        int seats;
        long long expect;

        TestCase(const std::vector<std::vector<int>>& roads_,
                 int seats_, long long expect_)
            : roads(roads_)
            , seats(seats_)
            , expect(expect_) {}
    };
public:
    MinimumFuelCostToReportToTheCapitalTask();
    ~MinimumFuelCostToReportToTheCapitalTask();

    std::shared_ptr<Task> create() override;

    void run() override;

private:
   void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif