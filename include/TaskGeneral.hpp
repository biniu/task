//

#ifndef TASKGENERAL
#define TASKGENERAL

#include <chrono>
#include <memory>
#include <string>

#include "ProjectGeneral.hpp"

class TaskGeneral {
public:
  TaskGeneral() = delete;
  TaskGeneral(const ProjectGeneral &project_ref, const std::string &task_name);
  TaskGeneral(const ProjectGeneral &project_ref, const std::string &task_name,
              const std::string &task_description);

  virtual ~TaskGeneral();

  void SetName(const std::string &task_name);
  void SetDescription(const std::string &task_description);

  std::string GetName();
  std::string GetDescription();

private:
  std::string name{""};
  std::string description{""};

  std::unique_ptr<ProjectGeneral> project;

  std::chrono::time_point<std::chrono::system_clock> creation_time;
};

#endif // TASKGENERAL
