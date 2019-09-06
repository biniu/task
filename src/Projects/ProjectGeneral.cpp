//
#include "ProjectGeneral.hpp"

#include <boost/log/trivial.hpp>

ProjectGeneral::ProjectGeneral(const std::string &project_name)
    : ProjectGeneral(project_name, "") {}

ProjectGeneral::ProjectGeneral(const std::string &project_name,
                               const std::string &project_description)
    : name(project_name), description(project_description) {
  creation_time = std::chrono::system_clock::now();
  BOOST_LOG_TRIVIAL(info) << "[PROJECT][" << name << "] -> created" ;
}

ProjectGeneral::~ProjectGeneral() {}

void ProjectGeneral::SetName(const std::string &project_name) {
  name = project_name;
}

void ProjectGeneral::SetDescription(const std::string &project_description) {
  description = project_description;
}

std::string ProjectGeneral::GetName() const { return name; }

std::string ProjectGeneral::GetDescription() const { return description; }

void ProjectGeneral::AddTask(TaskGeneral *task) {
  BOOST_LOG_TRIVIAL(info) << "[PROJECT][" << name << "] -> adding task ["
                          << task->GetName() << "]";
  task_vector.push_back(task);
}

std::ostream &operator<<(std::ostream &os, const ProjectGeneral &pg) {
  os << "Project: " << pg.name << std::endl;
  os << "Task list:" << std::endl;
  for (auto t : pg.task_vector)
    os << "\t" << t;

  return os;
}
