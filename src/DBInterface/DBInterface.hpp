#ifndef DBINTERFACE
#define DBINTERFACE

#include <memory>
#include <sqlite3.h>
#include <string>

// #include "ProjectGeneral.hpp"
// #include "TaskGeneral.hpp"

class DBConnection {
public:

  static DBConnection& GetConnection();
  virtual ~DBConnection();

  DBConnection(DBConnection const &) = delete;
  void operator=(DBConnection const &) = delete;

  // friend bool operator==(const DBConnection& a, const DBConnection& b);
  // friend bool operator!=(const DBConnection& a, const DBConnection& b);

  bool operator==(const DBConnection& a) const;
  bool operator!=(const DBConnection& a) const;
private:
  DBConnection();

  // TODO(biniu) : find more elastic solutions
  const std::string dbName = "test.db";
  static sqlite3 *db_ptr;
};

// sqlite3 *DBConnection::db_ptr = nullptr;

// class DBInterface {
// public:
//   DBInterface(const ProjectGeneral &project);
//   ~DBInterface();

//   // void SaveTask(const TaskGeneral &task);

// private:
//   void SetDBName(const ProjectGeneral &project);

//   // sqlite3 *db_ptr{nullptr};
//   std::string db_name;
// };

#endif // DBINTERFACE
