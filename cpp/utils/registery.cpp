#include "utils/regsitery.h"

#include <iostream>

namespace leetcode {

Task::~Task() {}

TaskRegistery::TaskRegistery() {}
TaskRegistery::~TaskRegistery() {
    std::lock_guard<std::mutex> lck(m_);
    registery_table_.clear();
}

bool TaskRegistery::RegisterTask(const std::string& name,
                                 Task* task) {
    std::lock_guard<std::mutex> lck(m_);
    return registery_table_.emplace(name, task).second;
}

std::shared_ptr<Task> TaskRegistery::GetTask(const std::string& name) const {
    std::lock_guard<std::mutex> lck(m_);
    auto iter = registery_table_.find(name);
    if (iter == registery_table_.end()) {
        return nullptr;
    }
    return iter->second->create();
}

std::vector<std::string> TaskRegistery::ListTask() const {
    std::vector<std::string> tasks;
    std::lock_guard<std::mutex> lck(m_);
    for (auto iter = registery_table_.begin(); iter != registery_table_.end(); ++iter) {
        tasks.push_back(iter->first);
    }
    return tasks;
}

TaskRegistery* TaskRegistery::GetInstance() {
    static TaskRegistery tr;
    return &tr;
}

} // namespace leetcode