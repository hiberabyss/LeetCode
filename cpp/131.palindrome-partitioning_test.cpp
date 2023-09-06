#include "leetcode.h"
#include <gtest/gtest.h>

#include "131.palindrome-partitioning.cpp"

#define FunName partition

TEST(partition, subname) {
  vector<vector<string>> res = {
    {"a","a","b"},{"aa","b"},
  };

  EXPECT_EQ(res, SolFun("aab"));
}
