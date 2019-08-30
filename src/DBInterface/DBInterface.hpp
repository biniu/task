#ifndef DBINTERFACE
#define DBINTERFACE

#include <string>

class DBInterface {
public:
  DBInterface(const std::string &project);
  ~DBInterface();

  // virtual void AddTask();
  // virtual GetTasks();

private:
  // void SetDBName(const std::string &project);
};

#endif // DBINTERFACE
l