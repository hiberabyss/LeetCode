#include <gtest/gtest.h>
#include "leetcode.h"

TEST(s2v, subname) {
  vector<int> res = {1, 2, 3};
  EXPECT_EQ(res, s2v("[1,2,3]"));
  EXPECT_EQ(res, s2v("1,2,3"));

  vector<int> empty = {};
  EXPECT_EQ(empty, s2v("[]"));
  EXPECT_EQ(empty, s2v(""));
}

TEST(s2vv, subname) {
  vector<vector<int>> empty = {};
  EXPECT_EQ(empty, s2vv("[]"));

  vector<vector<int>> one_empty = {{}};
  EXPECT_EQ(one_empty, s2vv("[[]]"));

  vector<vector<int>> test1 = {
    {1, 2, 3},
    {4, 5, 6},
  };
  EXPECT_EQ(test1, s2vv("[[1,2,3],[4,5,6]]"));
}

TEST(s2l, five) {
  auto* res = s2l("[1,2,3]");

  EXPECT_EQ(1, res->val);
  res = res->next;
  EXPECT_EQ(2, res->val);
  res = res->next;
  EXPECT_EQ(3, res->val);
  res = res->next;
  EXPECT_EQ(nullptr, res);
}

TEST(l2s, subname) {
  auto* res = s2l("[2,3,4]");
  EXPECT_EQ("[2,3,4]", l2s(res));
}
