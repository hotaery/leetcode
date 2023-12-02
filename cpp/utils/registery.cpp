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

TaskRegistery* TaskRegistery::GetInstance() {
    static TaskRegistery tr;
    return &tr;
}

} // namespace leetcode