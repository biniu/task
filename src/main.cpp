
#include <iostream>

#include <boost/log/trivial.hpp>

#include "TaskGeneral.hpp"
#include "ProjectGeneral.hpp"
#include "DBInterface.hpp"


int main() {
  BOOST_LOG_TRIVIAL(info) << "Hello World";

  ProjectGeneral project("project_1");

  TaskGeneral task_1("task_1");
  TaskGeneral task_2("task_2", "description");
  TaskGeneral task_3("task_3");

  project.AddTask(&task_1);
  project.AddTask(&task_2);
  project.AddTask(&task_3);

  DBInterface dbInterface("project");
  dbInterface.SaveProject(project);

  return 0;
}
