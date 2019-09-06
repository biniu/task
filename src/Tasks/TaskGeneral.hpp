//

#ifndef TASKGENERAL
#define TASKGENERAL

#include <chrono>
#include <iostream>
#include <string>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class TaskGeneral {
public:
  TaskGeneral() = default;
  explicit TaskGeneral(const std::string &task_name);
  TaskGeneral(const std::string &task_name,
              const std::string &task_description);

  void SetName(const std::string &task_name);
  void SetDescription(const std::string &task_description);

  std::string GetName() const;
  std::string GetDescription() const;

  friend std::ostream &operator<<(std::ostream &os, const TaskGeneral &tg);

private:
  std::string name{""};
  std::string description{""};

  std::chrono::time_point<std::chrono::system_clock> creation_time;

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar &name;
    ar &description;
    // ar &creation_time;
  }
};

#endif // TASKGENERAL
