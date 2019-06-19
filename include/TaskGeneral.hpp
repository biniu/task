//

#ifndef TASKGENERAL
#define TASKGENERAL

#include <chrono>
#include <string>

class TaskGeneral {
public:
  TaskGeneral() = delete;
  explicit TaskGeneral(const std::string &task_name);
  TaskGeneral(const std::string &task_name, const std::string &task_description);

  virtual ~TaskGeneral();

  void SetName(const std::string &task_name);
  void SetDescription(const std::string &task_description);

  std::string GetName();
  std::string GetDescription();

private:
  std::string name{""};
  std::string description{""};

  std::chrono::time_point<std::chrono::system_clock> creation_time;
};

#endif //TASKGENERAL
