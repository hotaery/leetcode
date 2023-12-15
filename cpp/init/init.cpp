#include "init/init.h"
#include "array/contains_duplicate_3.h"
#include "array/next_greater_element_4.h"
#include "array/stamping_the_grid.h"
#include "backtrace/word_search_2.h"
#include "dp/coin_change_2.h"
#include "dp/dungeon_game.h"
#include "dp/maximum_earnings_from_taxi.h"
#include "graph/binary_tree_maximum_path_sum.h"
#include "graph/binary_search_tree_to_greater_sum_tree.h"
#include "graph/minimum_fuel_cost_to_report_to_the_capital.h"
#include "graph/minimize_the_total_price_of_the_trips.h"
#include "graph/path_with_minimum_effort.h"
#include "graph/reorder_routes_to_make_all_paths_lead_to_the_city_zero.h"
#include "graph/reverse_odd_levels_of_binary_tree.h"
#include "graph/word_ladder.h"
#include "math/max_points_on_a_line.h"
#include "math/next_greater_numerically_balanced_number.h"
#include "interval/maximum_subarray.h"
#include "interval/the_skline_problem.h"
#include "utils/regsitery.h"

namespace leetcode {

static WordLadderTask __dummy_word_ladder_task;
static BinaryTreeMaximumPathSumTask __dummy_binary_tree_maximum_path_sum_task;
static MaximumSubarrayTask __dummy_maximum_subarray_task;
static BinarySearchTreeToGreaterSumTreeTask __dummy_binary_search_tree_to_greater_sum_tree_task;
static MinimumFuelCostToReportToTheCapitalTask __dummy_minimum_fuel_cost_to_report_to_the_capital_task;
static MinimizeTheTotalPriceOfTheTripsTask __dummy_minimize_the_total_price_of_the_trips_task;
static ReorderRoutesToMakeAllPathsLeadToTheCityZeroTask __dummy_reorder_routes_to_make_all_paths_lead_to_the_city_zero_task;
static PathWithMinimumEffortTask __dummy_path_with_minimum_effort_task;
static ReverseOddLevelsOfBinaryTreeTask __dummy_reverse_odd_levels_of_binary_tree_task;

void InitGraph() {
    TaskRegistery::GetInstance()->RegisterTask("124", &__dummy_binary_tree_maximum_path_sum_task);
    TaskRegistery::GetInstance()->RegisterTask("127", &__dummy_word_ladder_task);
    TaskRegistery::GetInstance()->RegisterTask("1038", &__dummy_binary_search_tree_to_greater_sum_tree_task);
    TaskRegistery::GetInstance()->RegisterTask("2477", &__dummy_minimum_fuel_cost_to_report_to_the_capital_task);
    TaskRegistery::GetInstance()->RegisterTask("2646", &__dummy_minimize_the_total_price_of_the_trips_task);
    TaskRegistery::GetInstance()->RegisterTask("1466", &__dummy_reorder_routes_to_make_all_paths_lead_to_the_city_zero_task);
    TaskRegistery::GetInstance()->RegisterTask("1631", &__dummy_path_with_minimum_effort_task);
    TaskRegistery::GetInstance()->RegisterTask("2415", &__dummy_reverse_odd_levels_of_binary_tree_task);
}

static TheSklineProblemTask __dummy_the_skline_problem_task;

void InitInterval() {
    TaskRegistery::GetInstance()->RegisterTask("53", &__dummy_maximum_subarray_task);
    TaskRegistery::GetInstance()->RegisterTask("218", &__dummy_the_skline_problem_task);
}

static CoinChange2Task __dummy_coin_change_2_task;
static DungeonGameTask __dummy_dungeon_game_task;
static MaximumEarningsFromTaxiTask __dummy_maximum_earnings_from_task_task;

void InitDP() {
    TaskRegistery::GetInstance()->RegisterTask("518", &__dummy_coin_change_2_task);
    TaskRegistery::GetInstance()->RegisterTask("174", &__dummy_dungeon_game_task);
    TaskRegistery::GetInstance()->RegisterTask("2008", &__dummy_maximum_earnings_from_task_task);
}

static MaxPointsOnALineTask __dummy_max_points_on_a_line_task;
static NextGreaterNumericallyBalancedNumberTask __dummy_next_greater_numerically_balanced_number_task;

void InitMath() {
    TaskRegistery::GetInstance()->RegisterTask("149", &__dummy_max_points_on_a_line_task);
    TaskRegistery::GetInstance()->RegisterTask("2048", &__dummy_next_greater_numerically_balanced_number_task);
}

static WordSearch2Task __dummy_word_search_2_task;

void InitBacktrace() {
    TaskRegistery::GetInstance()->RegisterTask("212", &__dummy_word_search_2_task);
}

static NextGreaterElement4Task __dummy_next_greater_element_4_task;
static StampingTheGridTask __dummy_stamping_the_grid_task;
static ContainsDuplicate3Task __dummy_contains_duplicate_3_task;

void InitArray() {
    TaskRegistery::GetInstance()->RegisterTask("220", &__dummy_contains_duplicate_3_task);
    TaskRegistery::GetInstance()->RegisterTask("2132", &__dummy_stamping_the_grid_task);
    TaskRegistery::GetInstance()->RegisterTask("2454", &__dummy_next_greater_element_4_task);
}

} // leetcode