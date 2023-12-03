#include "init/init.h"
#include "graph/binary_tree_maximum_path_sum.h"
#include "graph/word_ladder.h"
#include "interval/maximum_subarray.h"
#include "utils/regsitery.h"

namespace leetcode {

static WordLadderTask __dummy_word_ladder_task;
static BinaryTreeMaximumPathSumTask __dummy_binary_tree_maximum_path_sum_task;
static MaximumSubarrayTask __dummy_maximum_subarray_task;

void InitGraph() {
    TaskRegistery::GetInstance()->RegisterTask("124", &__dummy_binary_tree_maximum_path_sum_task);
    TaskRegistery::GetInstance()->RegisterTask("127", &__dummy_word_ladder_task);
    TaskRegistery::GetInstance()->RegisterTask("53", &__dummy_maximum_subarray_task);
}

} // leetcode