
#include "DBInterface.hpp"

DBInterface::DBInterface(const std::string &project) {
  file_name = project;
  ofs = std::fstream(file_name, std::ios_base::app);
  // oa = boost::archive::text_oarchive(ofs);
}

void DBInterface::SaveProject(const ProjectGeneral &project) {
  boost::archive::text_oarchive oa(ofs);
  oa << project;
}

void DBInterface::LoadProject() const {

  std::ifstream ifs(file_name);
  boost::archive::text_iarchive ia(ifs);

  TaskGeneral task_1;
  ia >> task_1;

  std::cout << task_1;
}