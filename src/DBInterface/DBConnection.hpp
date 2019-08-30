#ifndef DBCONNECTION
#define DBCONNECTION

class DBConnection {
public:

  virtual DBConnection& GetConnection() = 0;
  virtual ~DBConnection() = 0;

  DBConnection(DBConnection const &) = delete;
  void operator=(DBConnection const &) = delete;

  virtual bool operator==(const DBConnection& a) const = 0;
  virtual bool operator!=(const DBConnection& a) const = 0;

private:
  DBConnection();
};

#endif // DBCONNECTION
