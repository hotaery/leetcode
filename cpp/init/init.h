#ifndef INIT_INIT_H
#define INIT_INIT_H

namespace leetcode {

void InitGraph();
void InitInterval();
inline void Init() {
    InitGraph();
    InitInterval();
}

} // namespace leetcode

#endif 