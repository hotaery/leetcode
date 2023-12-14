#ifndef INIT_INIT_H
#define INIT_INIT_H

namespace leetcode {

void InitGraph();
void InitInterval();
void InitDP();
void InitMath();
void InitBacktrace();
void InitArray();
inline void Init() {
    InitGraph();
    InitInterval();
    InitDP();
    InitMath();
    InitBacktrace();
    InitArray();
}

} // namespace leetcode

#endif 