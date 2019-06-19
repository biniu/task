//

#include "TaskGeneral.hpp"

TaskGeneral::TaskGeneral(const std::string &task_name)
    : TaskGeneral(task_name, "") {}

TaskGeneral::TaskGeneral(const std::string &task_name,
                         const std::string &task_description)
    : name(task_name), description(task_description) {
  creation_time = std::chrono::system_clock::now();
}

TaskGeneral::~TaskGeneral() {}

void TaskGeneral::SetName(const std::string &task_name) { name = task_name; }

void TaskGeneral::SetDescription(const std::string &task_description) {
  description = task_description;
}

std::string TaskGeneral::GetName() { return name; }

std::string TaskGeneral::GetDescription() { return description; }
