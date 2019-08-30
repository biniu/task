

// #include "DBInterface.hpp"

// #include <algorithm>
// #include <iostream>

// #include <sqlite3.h>

// sqlite3 *DBConnection::db_ptr = nullptr;

// static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
//   int i;
//   for (i = 0; i < argc; i++) {
//     printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//   }
//   printf("\n");
//   return 0;
// }

// DBConnection::DBConnection() {
//   if (sqlite3_open(DBConnection::dbName.c_str(), &DBConnection::db_ptr) != 0) {
//     std::cout << "Can't open database: " << sqlite3_errmsg(DBConnection::db_ptr)
//               << std::endl;
//     sqlite3_close(DBConnection::db_ptr);
//     // TODO(biniu) throw exception
//   }
// }

// DBConnection::~DBConnection() { sqlite3_close(DBConnection::db_ptr); }

// DBConnection &DBConnection::GetConnection() {
//   static DBConnection instance;
//   return instance;
// }

// bool DBConnection::operator==(const DBConnection &a) const {
//   return (this->db_ptr == a.db_ptr);
// }

// bool DBConnection::operator!=(const DBConnection &a) const {
//   return !((*this) == a);
// }

// void *DBConnection::RunQuery(const std::string &query) const {
//   char *zErrMsg = 0;

//   char *data;
//   // rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);
//   int rc = sqlite3_exec(DBConnection::db_ptr, query.c_str(), callback, (void *)data,
//                         &zErrMsg);

//   if (rc != SQLITE_OK) {
//     fprintf(stderr, "SQL error: %s\n", zErrMsg);
//     sqlite3_free(zErrMsg);
//   } else {
//     fprintf(stdout, "Table created successfully\n");
//   }

//   return (void *)data;
// }

// // // DBConnection::DBConnection(const std::string &dbname) {
// // // sqlite3* DBConnection::GetConnection(const std::string &dbName) {
// // //   if (sqlite3_open(dbName.c_str(), &db_ptr)) {
// // //     std::cout << "Can't open database: " << sqlite3_errmsg(db_ptr) <<
// // //     std::endl; sqlite3_close(db_ptr);
// // //     // TODO(biniu) throw exception
// // //   }
// // // }

// // // DBConnection::~DBConnection() { sqlite3_close(db_ptr); }

// // DBInterface& DBInterface::GetConnection() {
// //   static DBInterface instance;
// //   return instance;
// // }

// // // DBInterface::DBInterface(const ProjectGeneral &project) {
// // //   //
// // // }

// // DBInterface::~DBInterface() {}

// // // void DBInterface::SetDBName(const ProjectGeneral &project) {
// // //   db_name = project.GetName();
// // //   remove_if(db_name.begin(), db_name.end(), isspace);
// // //   db_name += ".db";
// // // }
