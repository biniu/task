#ifndef DBINTERFACE
#define DBINTERFACE

#include <memory>
#include <sqlite3.h>
#include <string>

#include "ProjectGeneral.hpp"
#include "TaskGeneral.hpp"

class DBConnection {
public:
  DBConnection() = delete;
  DBConnection(const std::string &dbName);
  ~DBConnection();


private:
  sqlite3 *db_ptr{nullptr};
}

class DBInterface {
public:
  DBInterface(const ProjectGeneral &project);
  ~DBInterface();

  // void SaveTask(const TaskGeneral &task);

private:
  void SetDBName(const ProjectGeneral &project);

  // sqlite3 *db_ptr{nullptr};
  std::string db_name;
};

#endif // DBINTERFACE
