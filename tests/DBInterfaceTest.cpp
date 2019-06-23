

#include "gtest/gtest.h"

namespace {

class DBInterfaceTest : public ::testing::Test {
protected:
  DBInterfaceTest() {}

  ~DBInterfaceTest() override {}

  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(DBInterfaceTest, ExampleTest) { EXPECT_TRUE(true); }

TEST_F(DBInterfaceTest, DoesXyz) {}

} // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
