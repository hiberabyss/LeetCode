#include <gtest/gtest.h>
#include <vector>

using namespace std;

#include "43.multiply-strings.cpp"

Solution sol;

TEST(multiply, normal) {
  EXPECT_EQ("6", sol.multiply("2", "3"));

  EXPECT_EQ("56088", sol.multiply("123", "456"));

  EXPECT_EQ("0", sol.multiply("0", "0"));
}
