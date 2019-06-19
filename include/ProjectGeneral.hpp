//

#ifndef PROJECTGENERAL
#define PROJECTGENERAL

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "TaskGeneral.hpp"

class ProjectGeneral {
public:
  ProjectGeneral() = delete;
  explicit ProjectGeneral(const std::string &project_name);
  ProjectGeneral(const std::string &project_name,
                 const std::string &project_description);

  ProjectGeneral(const ProjectGeneral &src) = default;

  virtual ~ProjectGeneral();

  void SetName(const std::string &project_name);
  void SetDescription(const std::string &project_description);

  std::string GetName() const;
  std::string GetDescription() const;

  void AddTask(const TaskGeneral &task);

  friend std::ostream &operator<<(std::ostream &os, const ProjectGeneral &pg);

private:
  std::string name{""};
  std::string description{""};

  std::chrono::time_point<std::chrono::system_clock> creation_time;

  std::vector<TaskGeneral> task_vector;
};

#endif // PROJECTGENERAL
