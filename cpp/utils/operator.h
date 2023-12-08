#ifndef UTILS_OPERATOR_H
#define UTILS_OPERATOR_H

#include <algorithm>
#include <vector>

namespace leetcode {

template <typename T>
bool operator==(const std::vector<T>& lhs, const std::vector<T>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (int i = 0; i < lhs.size(); i++) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool operator!=(const std::vector<T>& lhs, const std::vector<T>& rhs) {
    return !(lhs == rhs);
}

} // namespace leetcode

#endif