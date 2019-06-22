

#include "DBInterface.hpp"

#include <algorithm>
#include <sqlite3.h>

DBInterface::DBInterface(const ProjectGeneral &project) {
  SetDBName(project);

  if (sqlite3_open(db_name.c_str(), &db_ptr)) {
    std::cout << "Can't open database: " << sqlite3_errmsg(db_ptr) << std::endl;
    sqlite3_close(db_ptr);
    // TODO(biniu) throw exception
  }
}

DBInterface::~DBInterface() { sqlite3_close(db_ptr); }

void DBInterface::SetDBName(const ProjectGeneral &project) {
  db_name = project.GetName();
  remove_if(db_name.begin(), db_name.end(), isspace);
  db_name += ".db";
}
