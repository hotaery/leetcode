#ifndef GRAPH_MINIMIZE_THE_TOTAL_PRICE_OF_THE_TRIPS_H
#define GRAPH_MINIMIZE_THE_TOTAL_PRICE_OF_THE_TRIPS_H
 
#include "utils/regsitery.h"
 
#include <vector>
 
namespace leetcode {

class MinimizeTheTotalPriceOfTheTripsTask : public Task {
    struct TestCase {
        int n;
        std::vector<std::vector<int>> edges;
        std::vector<int> prices;
        std::vector<std::vector<int>> trips;
        int expect;

        TestCase(int n_, const std::vector<std::vector<int>>& edges_,
                 const std::vector<int>& prices_,
                 const std::vector<std::vector<int>>& trips_, int expect_)
            : n(n_), edges(edges_), prices(prices_)
            , trips(trips_), expect(expect_) {}
    };
public:
    MinimizeTheTotalPriceOfTheTripsTask();
    ~MinimizeTheTotalPriceOfTheTripsTask();

    std::shared_ptr<Task> create() override;

    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif 