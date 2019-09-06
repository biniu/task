
#include <iostream>

#include "TaskGeneral.hpp"
#include "ProjectGeneral.hpp"
#include "DBInterface.hpp"


int main() {
  std::cout << "project" << std::endl;

  ProjectGeneral project("project_1");

  TaskGeneral task_1("task_1");
  TaskGeneral task_2("task_2", "description");
  TaskGeneral task_3("task_3");

  project.AddTask(&task_1);
  project.AddTask(&task_2);
  project.AddTask(&task_3);
  // std::cout << task_1 << std::endl;
  // std::cout << task_2 << std::endl;
  // std::cout << task_3 << std::endl;

  DBInterface dbInterface("project");
  dbInterface.SaveProject(project);
  // dbInterface.GetTasks();
  // dbInterface.AddTask(task_1);
  // dbInterface.AddTask(task_2);
  // dbInterface.AddTask(task_3);

  return 0;
}
