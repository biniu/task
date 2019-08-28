

#include "DBInterface.hpp"

#include <algorithm>
#include <iostream>

#include <sqlite3.h>

sqlite3 *DBConnection::db_ptr = nullptr;

DBConnection::DBConnection() {
  if (sqlite3_open(DBConnection::dbName.c_str(), &DBConnection::db_ptr) != 0) {
    std::cout << "Can't open database: " << sqlite3_errmsg(DBConnection::db_ptr)
              << std::endl;
    sqlite3_close(DBConnection::db_ptr);
    // TODO(biniu) throw exception
  }
}

DBConnection::~DBConnection() { sqlite3_close(DBConnection::db_ptr); }

DBConnection &DBConnection::GetConnection() {
  static DBConnection instance;
  return instance;
}

bool DBConnection::operator==(const DBConnection& a) const {
  return (this->db_ptr == a.db_ptr);
}

bool DBConnection::operator!=(const DBConnection& a) const {
  return !((*this) == a);
}

// // DBConnection::DBConnection(const std::string &dbname) {
// // sqlite3* DBConnection::GetConnection(const std::string &dbName) {
// //   if (sqlite3_open(dbName.c_str(), &db_ptr)) {
// //     std::cout << "Can't open database: " << sqlite3_errmsg(db_ptr) <<
// //     std::endl; sqlite3_close(db_ptr);
// //     // TODO(biniu) throw exception
// //   }
// // }

// // DBConnection::~DBConnection() { sqlite3_close(db_ptr); }

// DBInterface& DBInterface::GetConnection() {
//   static DBInterface instance;
//   return instance;
// }

// // DBInterface::DBInterface(const ProjectGeneral &project) {
// //   //
// // }

// DBInterface::~DBInterface() {}

// // void DBInterface::SetDBName(const ProjectGeneral &project) {
// //   db_name = project.GetName();
// //   remove_if(db_name.begin(), db_name.end(), isspace);
// //   db_name += ".db";
// // }
