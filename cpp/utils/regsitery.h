#ifndef UTILS_REGISTERY_H
#define UTILS_REGISTERY_H

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

namespace leetcode {

class Task {
public:
    virtual ~Task();

    virtual void run() = 0;

    virtual std::shared_ptr<Task> create() = 0;
};

class TaskRegistery {
public:
    static TaskRegistery* GetInstance();

    TaskRegistery(const TaskRegistery&) = delete;
    TaskRegistery& operator=(const TaskRegistery&) = delete;
    ~TaskRegistery();

    bool RegisterTask(const std::string& name, Task* task);
    std::shared_ptr<Task> GetTask(const std::string& name) const;

private:
    TaskRegistery();

private:
    mutable std::mutex m_;
    std::unordered_map<std::string, Task*> registery_table_;
};

} // namespace leetcode 

#endif 