//
#include "ProjectGeneral.hpp"

ProjectGeneral::ProjectGeneral(const std::string &project_name)
    : ProjectGeneral(project_name, "") {}

ProjectGeneral::ProjectGeneral(const std::string &project_name,
                               const std::string &project_description)
    : name(project_name), description(project_description) {
  creation_time = std::chrono::system_clock::now();
}

ProjectGeneral::~ProjectGeneral() {}

void ProjectGeneral::SetName(const std::string &project_name) {
  name = project_name;
}

void ProjectGeneral::SetDescription(const std::string &project_description) {
  description = project_description;
}

std::string ProjectGeneral::GetName() {
  return name;
}

std::string ProjectGeneral::GetDescription() {
  return description;
}
