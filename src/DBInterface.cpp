

#include "DBInterface.hpp"

#include <algorithm>
#include <sqlite3.h>

DBConnection::DBConnection(const std::string &dbname) {
  if (sqlite3_open(dbname.c_str(), &db_ptr)) {
    std::cout << "Can't open database: " << sqlite3_errmsg(db_ptr) << std::endl;
    sqlite3_close(db_ptr);
    // TODO(biniu) throw exception
  }
}

DBConnection::~DBConnection() { sqlite3_close(db_ptr); }

DBInterface::DBInterface(const ProjectGeneral &project) {
  //
}

DBInterface::~DBInterface() {}

void DBInterface::SetDBName(const ProjectGeneral &project) {
  db_name = project.GetName();
  remove_if(db_name.begin(), db_name.end(), isspace);
  db_name += ".db";
}
