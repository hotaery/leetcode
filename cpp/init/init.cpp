#include "dp/coin_change_2.h"
#include "init/init.h"
#include "graph/binary_tree_maximum_path_sum.h"
#include "graph/binary_search_tree_to_greater_sum_tree.h"
#include "graph/minimum_fuel_cost_to_report_to_the_capital.h"
#include "graph/minimize_the_total_price_of_the_trips.h"
#include "graph/word_ladder.h"
#include "math/max_points_on_a_line.h"
#include "interval/maximum_subarray.h"
#include "utils/regsitery.h"

namespace leetcode {

static WordLadderTask __dummy_word_ladder_task;
static BinaryTreeMaximumPathSumTask __dummy_binary_tree_maximum_path_sum_task;
static MaximumSubarrayTask __dummy_maximum_subarray_task;
static BinarySearchTreeToGreaterSumTreeTask __dummy_binary_search_tree_to_greater_sum_tree_task;
static MinimumFuelCostToReportToTheCapitalTask __dummy_minimum_fuel_cost_to_report_to_the_capital_task;
static MinimizeTheTotalPriceOfTheTripsTask __dummy_minimize_the_total_price_of_the_trips_task;

void InitGraph() {
    TaskRegistery::GetInstance()->RegisterTask("124", &__dummy_binary_tree_maximum_path_sum_task);
    TaskRegistery::GetInstance()->RegisterTask("127", &__dummy_word_ladder_task);
    TaskRegistery::GetInstance()->RegisterTask("1038", &__dummy_binary_search_tree_to_greater_sum_tree_task);
    TaskRegistery::GetInstance()->RegisterTask("2477", &__dummy_minimum_fuel_cost_to_report_to_the_capital_task);
    TaskRegistery::GetInstance()->RegisterTask("2646", &__dummy_minimize_the_total_price_of_the_trips_task);
}

void InitInterval() {
    TaskRegistery::GetInstance()->RegisterTask("53", &__dummy_maximum_subarray_task);
}

static CoinChange2Task __dummy_coin_change_2_task;

void InitDP() {
    TaskRegistery::GetInstance()->RegisterTask("518", &__dummy_coin_change_2_task);
}

static MaxPointsOnALineTask __dummy_max_points_on_a_line_task;

void InitMath() {
    TaskRegistery::GetInstance()->RegisterTask("149", &__dummy_max_points_on_a_line_task);
}

} // leetcode