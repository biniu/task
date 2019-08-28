

#include "gtest/gtest.h"

#include <iostream>

#include "DBInterface.hpp"


namespace {

class DBConnectionTest : public ::testing::Test {
protected:
  DBConnectionTest() {}

  ~DBConnectionTest() override {}

  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(DBConnectionTest, CheckIfDBConnectionIsSingleton) {
  DBConnection &instance_1 = DBConnection::GetConnection();
  DBConnection &instance_2 = DBConnection::GetConnection();
  DBConnection &instance_3 = DBConnection::GetConnection();
  DBConnection &instance_4 = DBConnection::GetConnection();

  EXPECT_EQ(instance_1, instance_2);
  EXPECT_EQ(instance_1, instance_3);
  EXPECT_EQ(instance_1, instance_4);
}

TEST_F(DBConnectionTest, DoesXyz) {
  DBConnection &instance_1 = DBConnection::GetConnection();

  const std::string sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

  instance_1.RunQuery(sql);
}

} // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
