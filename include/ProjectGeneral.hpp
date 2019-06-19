

#ifndef PROJECTGENERAL
#define PROJECTGENERAL

#include <chrono>
#include <string>

class ProjectGeneral {
public:
  ProjectGeneral() = delete;
  explicit ProjectGeneral(const std::string &project_name);
  ProjectGeneral(const std::string &project_name, const std::string &project_description);

  ProjectGeneral(const ProjectGeneral &src) = default;

  virtual ~ProjectGeneral();

  void SetName(const std::string &project_name);
  void SetDescription(const std::string &project_description);

  std::string GetName();
  std::string GetDescription();

private:
  std::string name{""};
  std::string description{""};

  std::chrono::time_point<std::chrono::system_clock> creation_time;
};

#endif //PROJECTGENERAL
