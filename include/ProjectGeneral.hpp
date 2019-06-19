

#ifndef _PROJECTGENERAL
#define _PROJECTGENERAL

#include <chrono>
#include <string>

class ProjectGeneral {
public:
  ProjectGeneral() = delete;
  ProjectGeneral(const std::string &name);
  ProjectGeneral(const std::string &name, const std::string &description);

  ProjectGeneral(const ProjectGeneral &src) = default;

  virtual ~ProjectGeneral() = default;

private:
  std::string name;
  std::string description;
  unsigned int id;

  std::chrono::time_point<std::chrono::system_clock> creation_time;
};

#endif //_PROJECTGENERAL
