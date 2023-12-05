#ifndef INIT_INIT_H
#define INIT_INIT_H

namespace leetcode {

void InitGraph();
void InitInterval();
void InitDP();
inline void Init() {
    InitGraph();
    InitInterval();
    InitDP();
}

} // namespace leetcode

#endif 