#ifndef DBINTERFACE
#define DBINTERFACE

#include <string>
#include <fstream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "TaskGeneral.hpp"
#include "ProjectGeneral.hpp"

class DBInterface {
public:
  DBInterface() = delete;
  DBInterface(const std::string &project);
  ~DBInterface() = default;

  void SaveProject(const ProjectGeneral &project);
  void LoadProject() const;

private:
  std::fstream ofs;
  std::string file_name;
  // void SetDBName(const std::string &project);
};

#endif // DBINTERFACE
