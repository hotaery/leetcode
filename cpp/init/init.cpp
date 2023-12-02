#include "init/init.h"
#include "graph/word_ladder.h"
#include "utils/regsitery.h"

namespace leetcode {

static WordLadderTask __dummy_word_ladder_task;

void InitGraph() {
    TaskRegistery::GetInstance()->RegisterTask("127", &__dummy_word_ladder_task);
}

} // leetcode