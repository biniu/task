//

#include "TaskGeneral.hpp"

TaskGeneral::TaskGeneral(const ProjectGeneral &project_ref,
                         const std::string &task_name)
    : TaskGeneral(project_ref, task_name, "") {}

TaskGeneral::TaskGeneral(const ProjectGeneral &project_ref,
                         const std::string &task_name,
                         const std::string &task_description)
    : name(task_name), description(task_description) {
  project = std::make_unique<ProjectGeneral>(project_ref);
  creation_time = std::chrono::system_clock::now();
}

TaskGeneral::~TaskGeneral() {}

void TaskGeneral::SetName(const std::string &task_name) { name = task_name; }

void TaskGeneral::SetDescription(const std::string &task_description) {
  description = task_description;
}

std::string TaskGeneral::GetName() { return name; }

std::string TaskGeneral::GetDescription() { return description; }
