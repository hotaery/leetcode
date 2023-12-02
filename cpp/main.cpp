#include "init/init.h"
#include "utils/regsitery.h"

#include <iostream>
#include <cstring>

static const char* proc_name = nullptr;

void usage() {
    std::cout << "usage: " 
              << proc_name << " <problem>\n"
              << "\tproblem: index of problem at leetcode.cn"
              << std::endl;
}

void init() {
    leetcode::InitGraph();
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

    init();
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