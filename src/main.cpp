
#include <iostream>

#include "ProjectGeneral.hpp"
#include "TaskGeneral.hpp"

int main() {

  ProjectGeneral project("Project_1");

  project.AddTask(TaskGeneral("task_1"));
  project.AddTask(TaskGeneral("task_2"));
  project.AddTask(TaskGeneral("task_3"));
  project.AddTask(TaskGeneral("task_4"));

  std::cout << project << std::endl;

  return 0;
}
