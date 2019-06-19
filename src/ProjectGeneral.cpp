
#include "ProjectGeneral.hpp"

ProjectGeneral::ProjectGeneral(const std::string &name)
    : ProjectGeneral(name, "") {}

ProjectGeneral::ProjectGeneral(const std::string &name,
                               const std::string &description)
    : name(name), description(description) {
  creation_time = std::chrono::system_clock::now();
}
