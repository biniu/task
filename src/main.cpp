
#include <iostream>

#include "ProjectGeneral.hpp"
#include "TaskGeneral.hpp"
#include "DBInterface.hpp"

int main() {



  ProjectGeneral project("Project_1");

  DBInterface dbinterface(project);

  project.AddTask(TaskGeneral("task_1"));
  project.AddTask(TaskGeneral("task_2"));
  project.AddTask(TaskGeneral("task_3"));
  project.AddTask(TaskGeneral("task_4"));

  // dbinterface.SaveTask(TaskGeneral("task_1"));
  // dbinterface.SaveTask(TaskGeneral("task_2"));
  // dbinterface.SaveTask(TaskGeneral("task_3"));
  // dbinterface.SaveTask(TaskGeneral("task_4"));

  std::cout << project << std::endl;

  return 0;
}
