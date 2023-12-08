#ifndef BACKTRACE_WORD_SEARCH_2_H
#define BACKTRACE_WORD_SEARCH_2_H

#include "utils/regsitery.h"

#include <string>
#include <vector>

namespace leetcode {

class WordSearch2Task : public Task {
    struct TestCase {
        std::vector<std::vector<char>> board;
        std::vector<std::string> words;
        std::vector<std::string> expect;

        TestCase(const std::vector<std::vector<char>>& board_, 
                const std::vector<std::string>& words_,
                const std::vector<std::string>& expect_)
            : board(board_), words(words_), expect(expect_) {}
    };
public:
    WordSearch2Task();
    ~WordSearch2Task();

    std::shared_ptr<Task> create() override;
    void run() override;

private: 
    void InitTestCase();

private:
    std::vector<TestCase> test_case_list_;
};

} // namespace leetcode

#endif