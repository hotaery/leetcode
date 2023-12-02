#ifndef GRAPH_WORD_LADDER_H
#define GRAPH_WORD_LADDER_H

#include "utils/regsitery.h"

#include <vector>

namespace leetcode {

class WordLadderTask : public Task {
    struct TestCase {
        std::string beginWord;
        std::string endWord;
        std::vector<std::string> wordList;
        int expect;

        TestCase(const std::string& beginWord_, 
                 const std::string& endWord_,
                 const std::vector<std::string>& wordList_,
                 int expect_)
            : beginWord(beginWord_)
            , endWord(endWord_)
            , wordList(wordList_)
            , expect(expect_) {}
    };
public:
    WordLadderTask();
    std::shared_ptr<Task> create() override;

    void run() override;

private:
    void InitTestCase();

private:
    std::vector<TestCase> testCaseList_;
};

} // namespace leetcode

#endif