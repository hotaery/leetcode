#include "init/init.h"
#include "utils/print.h"
#include "utils/regsitery.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

static const char* proc_name = nullptr;

void usage() {
    std::cout << "usage: " 
              << proc_name << " list|<problem>\n"
              << "\tlist: list all solved porblems\n"
              << "\tproblem: index of problem at leetcode.cn"
              << std::endl;
}

int main(int argc, char* argv[]) {
    char* curr = strtok(argv[0], "/");
    while (curr) {
        proc_name = curr;
        curr = strtok(nullptr, "/");
    }

    if (argc != 2) {
        usage();
        return -1;
    }

    leetcode::Init(); 
    if (std::strcmp(argv[1], "list") == 0) {
        std::vector<std::string> task_list = 
            leetcode::TaskRegistery::GetInstance()->ListTask();
        std::sort(task_list.begin(), task_list.end(), [](const std::string& lhs, const std::string& rhs) {
            return std::stoi(lhs) < std::stoi(rhs);
        });
        std::cout << "total:" << task_list.size() << "\n";
        leetcode::operator<<(std::cout, task_list) << std::endl; 
        return 0;
    }

    std::string problem = argv[1];
    std::shared_ptr<leetcode::Task> task = 
        leetcode::TaskRegistery::GetInstance()->GetTask(problem);
    if (!task) {
        std::cout << problem << " has not registered, please check parameter" << std::endl;
        return -1;
    }

    task->run();
    return 0;
}