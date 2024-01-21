#include "init/init.h"
#include "array/beautiful_towers_2.h"
#include "array/contains_duplicate_3.h"
#include "array/find_a_peak_element_2.h"
#include "array/h_index_2.h"
#include "array/minimum_number_of_removals_to_make_mountain_array.h"
#include "array/next_greater_element_4.h"
#include "array/remove_stones_to_minimize_the_total.h"
#include "array/stamping_the_grid.h"
#include "backtrace/expression_add_operators.h"
#include "backtrace/word_search_2.h"
#include "dp/coin_change_2.h"
#include "dp/dungeon_game.h"
#include "dp/maximum_earnings_from_taxi.h"
#include "dp/maximum_number_that_sum_of_the_price_ls_less_than_or_equak_to_k.h"
#include "dp/split_array_largest_sum.h"
#include "graph/binary_tree_maximum_path_sum.h"
#include "graph/binary_search_tree_to_greater_sum_tree.h"
#include "graph/minimum_fuel_cost_to_report_to_the_capital.h"
#include "graph/minimize_the_total_price_of_the_trips.h"
#include "graph/path_with_minimum_effort.h"
#include "graph/reorder_routes_to_make_all_paths_lead_to_the_city_zero.h"
#include "graph/reverse_odd_levels_of_binary_tree.h"
#include "graph/word_ladder.h"
#include "math/max_points_on_a_line.h"
#include "math/minimum_garden_perimeter_to_collect_enough_apples.h"
#include "math/next_greater_numerically_balanced_number.h"
#include "math/number_of_burgers_with_no_waste_of_ingredients.h"
#include "interval/count_integers_in_intervals.h"
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

static CountIntegersInIntervalsTask __dummy_count_integers_in_intervals_task;
static TheSklineProblemTask __dummy_the_skline_problem_task;

void InitInterval() {
    TaskRegistery::GetInstance()->RegisterTask("53", &__dummy_maximum_subarray_task);
    TaskRegistery::GetInstance()->RegisterTask("218", &__dummy_the_skline_problem_task);
    TaskRegistery::GetInstance()->RegisterTask("2276", &__dummy_count_integers_in_intervals_task);
}

static CoinChange2Task __dummy_coin_change_2_task;
static DungeonGameTask __dummy_dungeon_game_task;
static MaximumEarningsFromTaxiTask __dummy_maximum_earnings_from_task_task;
static MaximumNumberThatSumOfThePriceLsLessThanOrEqualToKTask __dummy_maximum_number_that_sum_of_the_price_ls_less_than_or_euqal_to_k_task;
static SplitArrayLargestSumTask __dummy_split_aray_largest_sum_task;

void InitDP() {
    TaskRegistery::GetInstance()->RegisterTask("518", &__dummy_coin_change_2_task);
    TaskRegistery::GetInstance()->RegisterTask("174", &__dummy_dungeon_game_task);
    TaskRegistery::GetInstance()->RegisterTask("410", &__dummy_split_aray_largest_sum_task);
    TaskRegistery::GetInstance()->RegisterTask("2008", &__dummy_maximum_earnings_from_task_task);
    TaskRegistery::GetInstance()->RegisterTask("100160", &__dummy_maximum_number_that_sum_of_the_price_ls_less_than_or_euqal_to_k_task);
}

static MaxPointsOnALineTask __dummy_max_points_on_a_line_task;
static NextGreaterNumericallyBalancedNumberTask __dummy_next_greater_numerically_balanced_number_task;
static MinimumGardenPerimeterToCollectEnoughApplesTask __dummy_minimum_garden_perimeter_to_collect_enough_apples_task;
static NumberOfBurgersWithNoWasteOfIngredientsTask __dummy_number_of_burgers_with_no_waste_of_ingredients_task;

void InitMath() {
    TaskRegistery::GetInstance()->RegisterTask("149", &__dummy_max_points_on_a_line_task);
    TaskRegistery::GetInstance()->RegisterTask("1276", &__dummy_number_of_burgers_with_no_waste_of_ingredients_task);
    TaskRegistery::GetInstance()->RegisterTask("1954", &__dummy_minimum_garden_perimeter_to_collect_enough_apples_task);
    TaskRegistery::GetInstance()->RegisterTask("2048", &__dummy_next_greater_numerically_balanced_number_task);
}

static WordSearch2Task __dummy_word_search_2_task;
static ExpressionAddOperatorsTask __dummy_expression_add_operators_task;

void InitBacktrace() {
    TaskRegistery::GetInstance()->RegisterTask("212", &__dummy_word_search_2_task);
    TaskRegistery::GetInstance()->RegisterTask("282", &__dummy_expression_add_operators_task);
}

static NextGreaterElement4Task __dummy_next_greater_element_4_task;
static StampingTheGridTask __dummy_stamping_the_grid_task;
static ContainsDuplicate3Task __dummy_contains_duplicate_3_task;
static FindAPeakElement2Task __dummy_find_a_peak_element_2_task;
static HIndex2Task __dummy_h_index_2_task;
static BeautifulTowers2Task __dummy_beautiful_towers_2_task;
static MinimumNumberOfRemovalsToMakeMountainArrayTask __dummy_minimum_number_of_removals_to_make_mountain_array_task;
static RemoveStonesToMinimizeTheTotalTask __dummy_remove_stones_to_minimize_the_total_task;

void InitArray() {
    TaskRegistery::GetInstance()->RegisterTask("220", &__dummy_contains_duplicate_3_task);
    TaskRegistery::GetInstance()->RegisterTask("275", &__dummy_h_index_2_task);
    TaskRegistery::GetInstance()->RegisterTask("1671", &__dummy_minimum_number_of_removals_to_make_mountain_array_task);
    TaskRegistery::GetInstance()->RegisterTask("1901", &__dummy_find_a_peak_element_2_task);
    TaskRegistery::GetInstance()->RegisterTask("1962", &__dummy_remove_stones_to_minimize_the_total_task);
    TaskRegistery::GetInstance()->RegisterTask("2132", &__dummy_stamping_the_grid_task);
    TaskRegistery::GetInstance()->RegisterTask("2454", &__dummy_next_greater_element_4_task);
    TaskRegistery::GetInstance()->RegisterTask("2866", &__dummy_beautiful_towers_2_task);
}

} // leetcode