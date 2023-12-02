#include "utils/print.h"

namespace leetcode {

std::ostream& operator<<(std::ostream& os, const TreeNode* root) {
    os << SerializeBinaryTree(root);
    return os;
}

} // namespace leetcode