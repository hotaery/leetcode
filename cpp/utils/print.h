#ifndef UTILS_PRINT_H
#define UTILS_PRINT_H

#include <iostream>
#include <type_traits>
#include <vector>

namespace leetcode {

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i + 1 != vec.size()) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

struct TreeNode;
std::ostream& operator<<(std::ostream& os, const TreeNode* root);
    
} // namespace leetcode 

#endif