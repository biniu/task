
#include "ProjectGeneral.hpp"

ProjectGeneral::ProjectGeneral(const std::string &project_name)
    : ProjectGeneral(project_name, "") {}

ProjectGeneral::ProjectGeneral(const std::string &project_name,
                               const std::string &project_description)
    : name(project_name), description(project_description) {
  creation_time = std::chrono::system_clock::now();
}
