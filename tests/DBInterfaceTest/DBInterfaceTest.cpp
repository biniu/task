

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
  EXPECT_TRUE(true);
}

TEST_F(DBConnectionTest, DoesXyz) {
  EXPECT_TRUE(true);
}

} // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
