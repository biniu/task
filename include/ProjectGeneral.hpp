

#ifndef PROJECTGENERAL
#define PROJECTGENERAL

#include <chrono>
#include <string>

class ProjectGeneral {
public:
  ProjectGeneral() = delete;
  ProjectGeneral(const std::string &project_name);
  ProjectGeneral(const std::string &project_name, const std::string &project_description);

  ProjectGeneral(const ProjectGeneral &src) = default;

  virtual ~ProjectGeneral();

private:
  std::string name;
  std::string description;

  std::chrono::time_point<std::chrono::system_clock> creation_time;
};

#endif //PROJECTGENERAL
