// https://leetcode.cn/problems/word-search-ii/description/
#include "backtrace/word_search_2.h"
#include "nlohmann/json.hpp"
#include "utils/operator.h"
#include "utils/print.h"

#include <algorithm>
#include <sstream>
#include <unordered_set>

namespace leetcode {
namespace _212 {

class Trie {
    struct Node {
        Node* next[26];
        bool end;

        Node() : end(false) {
            std::memset(next, 0, sizeof(Node*)*26);
        }
    };
public:
    typedef Node TrieNode;

    Trie() : root_(nullptr) {}
    ~Trie() {
        clear(root_);
    }

    void init(const std::vector<std::string>& words) {
        root_ = new Node;
        for (const std::string& word : words) {
            insert(word);
        }
    }

    TrieNode* getRoot() {
        return root_;
    }

    TrieNode* hasPrefix(TrieNode* node, char c) {
        Node* next = node->next[c - 'a'];
        return next;
    }

    bool isWord(TrieNode* node) {
        return node->end;
    }

private:
    void clear(Node* node) {
        if (!node) {
            return;
        } 
        for (int i = 0; i < 26; i++) {
            clear(node->next[i]);
        }
        delete node;
    }

    void insert(const std::string& word) {
        Node* node = root_;
        for (char c : word) {
            Node* next = node->next[c - 'a'];
            if (!next) {
                next = new Node;
                node->next[c - 'a'] = next;
            }
            node = next;
        }
        node->end = true;
    }

private:
    Node* root_;
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, 
                                       std::vector<std::string>& words) {
        Trie trie;
        trie.init(words);
        Trie::TrieNode* root = trie.getRoot();

        std::unordered_set<std::string> ans;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::string word;
                std::vector<std::vector<int>> visited(m, std::vector<int>(n));
                backtrace(trie, root, i, j, word, board, ans, visited);
            }
        }
        return std::vector<std::string>(ans.begin(), ans.end());
    }

private:
    void backtrace(Trie& trie, Trie::TrieNode* node, int i, int j,
                   std::string& word, 
                   std::vector<std::vector<char>>& board, 
                   std::unordered_set<std::string>& ans,
                   std::vector<std::vector<int>>& visited) {
        Trie::TrieNode* next = trie.hasPrefix(node, board[i][j]);
        if (!next) {
            return;
        }
        word.push_back(board[i][j]);
        visited[i][j] = 1;
        if (trie.isWord(next)) {
            ans.insert(word);
        }

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (inBound(x, y, board) && visited[x][y] == 0) {
                backtrace(trie, next, x, y, word, board, ans, visited);
            }
        }
        visited[i][j] = 0;
        word.pop_back();
    }

    bool inBound(int i, int j, std::vector<std::vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    static std::vector<int> dx;
    static std::vector<int> dy;
};

std::vector<int> Solution::dx = {-1, 0, 1, 0};
std::vector<int> Solution::dy = {0, -1, 0, 1};
} // namespace _212

WordSearch2Task::WordSearch2Task() {}
WordSearch2Task::~WordSearch2Task() {}

std::shared_ptr<Task> WordSearch2Task::create() {
    std::shared_ptr<WordSearch2Task> task = std::make_shared<WordSearch2Task>();
    task->InitTestCase();
    return task;
}

void WordSearch2Task::run() {
    _212::Solution sol;
    int failed = 0;

    for (TestCase& ts : test_case_list_) {
        std::vector<std::string> actual = sol.findWords(ts.board, ts.words);
        std::sort(actual.begin(), actual.end());
        if (actual != ts.expect) {
            std::cout << "TestCase:{\n"
                    << "\tboard:" << ts.board << "\n"
                    << "\twords:" << ts.words << "\n"
                    << "}\n"
                    << "expect:" << ts.expect << "\n"
                    << "actual:" << actual << "\n\n";
            failed++;
        }
    }
    std::cout << "PASS:" << test_case_list_.size() - failed << "\n"
            << "FAILED:" << failed << std::endl;
}

void WordSearch2Task::InitTestCase() {
    const std::string test_case_str = R"([["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]
["oath","pea","eat","rain","oathh"]
["oath","eat"]
[["a","b"],["c","d"]]
["abcb"]
[])";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string board;
        std::string words;
        std::string expect;
        std::getline(stream, board);
        std::getline(stream, words);
        std::getline(stream, expect);
        if (board.empty()) {
            assert(!stream);
            break;
        }

        std::vector<std::vector<std::string>> board_str_ = 
            nlohmann::json::parse(board).get<std::vector<std::vector<std::string>>>();
        std::vector<std::string> words_ = nlohmann::json::parse(words).get<std::vector<std::string>>();
        std::vector<std::string> expect_ = nlohmann::json::parse(expect).get<std::vector<std::string>>();
        std::vector<std::vector<char>> board_(board_str_.size(), std::vector<char>(board_str_[0].size()));
        std::transform(board_str_.begin(), board_str_.end(), board_.begin(), [](const std::vector<std::string>& vec) {
            std::vector<char> out(vec.size());
            std::transform(vec.begin(), vec.end(), out.begin(), [](const std::string& s) {
                return s[0];
            });
            return out;
        });
        std::sort(expect_.begin(), expect_.end());
        test_case_list_.emplace_back(board_, words_, expect_);
    }
}

} // namespace leetcode