// https://leetcode.cn/problems/word-ladder/description/
#include "graph/word_ladder.h"
#include "nlohmann/json.hpp"
#include "utils/print.h"
#include "utils/regsitery.h"

#include <queue>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace _127 {

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, 
                     std::vector<std::string>& wordList) {
        std::queue<std::pair<std::string, int>> q;
        q.emplace(beginWord, 0);
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        wordSet.erase(beginWord);
        while (!q.empty()) {
            auto elem = q.front();
            std::string word = elem.first;
            int step = elem.second;
            q.pop();
            if (word == endWord) {
                return step + 1;
            }

            for (int i = 0; i < word.size(); i++) {
                char old = word[i];
                for (int j = 0; j < 26; j++) {
                    word[i] = 'a' + j;
                    auto iter = wordSet.find(word);
                    if (iter != wordSet.end()) {
                        q.emplace(word, step + 1);
                        wordSet.erase(iter);
                    }
                }
                word[i] = old;
            }
        }

        return 0;
    }
};

} // namespace _127

WordLadderTask::WordLadderTask() {}

std::shared_ptr<Task> WordLadderTask::create() {
    std::shared_ptr<WordLadderTask> task = std::make_shared<WordLadderTask>();
    task->InitTestCase();
    return task;
}

void WordLadderTask::run() {
    _127::Solution sol;
    for (TestCase& test_case : testCaseList_) {
        int actual = sol.ladderLength(test_case.beginWord, test_case.endWord, test_case.wordList);
        if (actual != test_case.expect) {
            std::cout << "TestCase:{\n"
                      << "\tbeginWord:" << test_case.beginWord << "\n"
                      << "\tendWOrd:" << test_case.endWord << "\n"
                      << "\twordList:" << test_case.wordList << "\n}\n"
                      << "expect:" << test_case.expect << "\n"
                      << "actual:" << actual << "\n\n";

        }
    }
    std::cout.flush();
}

void WordLadderTask::InitTestCase() {
    const std::string test_case_str = R"("hit"
"cog"
["hot","dot","dog","lot","log","cog"]
5
"hit"
"cog"
["hot","dot","dog","lot","log"]
0)";
    std::istringstream stream(test_case_str);
    while (stream) {
        std::string beginWord;
        std::string endWord;
        std::string wordList;
        std::string expect;
        std::getline(stream, beginWord);
        std::getline(stream, endWord);
        std::getline(stream, wordList);
        std::getline(stream, expect);
        if (beginWord.empty()) {
            assert(!stream);
            break;
        }
        // std::cout << beginWord << "\n"
        //           << endWord << "\n"
        //           << wordList << "\n"
        //           << expect << std::endl; 
        std::string beginWord_ = nlohmann::json::parse(beginWord).get<std::string>();
        std::string endWord_ = nlohmann::json::parse(endWord).get<std::string>();
        std::vector<std::string> wordList_ = 
            nlohmann::json::parse(wordList).get<std::vector<std::string>>();
        int expect_ = nlohmann::json::parse(expect).get<int>();
        TestCase ts(beginWord_, endWord_, wordList_, expect_);
        testCaseList_.push_back(std::move(ts));
    }
}

} // namespace leetcode