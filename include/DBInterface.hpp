#ifndef DBINTERFACE
#define DBINTERFACE

#include <sqlite3.h>
#include <string>
#include <memory>

#include "ProjectGeneral.hpp"
#include "TaskGeneral.hpp"


class DBInterface {
public:
  DBInterface(const ProjectGeneral &project);
  ~DBInterface();

  // void SaveTask(const TaskGeneral &task);

private:
  void SetDBName(const ProjectGeneral &project);

  sqlite3 *db_ptr{nullptr};
  std::string db_name;
};

#endif // DBINTERFACE
