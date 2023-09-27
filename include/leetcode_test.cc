#include <gtest/gtest.h>
#include "leetcode.h"

TEST(s2v, subname) {
  vector<int> res = {1, 2, 3};
  EXPECT_EQ(res, s2v("[1 ,2,3]"));

  vector<int> empty = {};
  EXPECT_EQ(empty, s2v("[]"));
  EXPECT_EQ(empty, s2v(""));

  vector<string> strs = {"a", "b", "c", "def"};
  EXPECT_EQ(strs, s2v<string>("[a,b,c,def]"));
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

  vector<vector<int>> test2 = {
    {1, 2, 3},
  };
  EXPECT_EQ(test2, s2vv("[[1,2,3]]"));
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

TEST(l2v, List_to_vec) {
  auto* res = s2l("[1,2,3]");
  vector<int> expect = {1,2,3};
  EXPECT_EQ(expect, l2v(res));
}

TEST(v2t, TreeNode) {
  auto* root = v2t({1, 2, 3, 4});
  EXPECT_EQ(1, root->val);
  EXPECT_EQ(2, root->left->val);
  EXPECT_EQ(4, root->left->left->val);
}

TEST(v2l, subname) {
  auto* l = v2l({1, 2, 3});
  vector<int> expect = {1,2,3};

  EXPECT_EQ(expect, l2v(l));
}

TEST(ListNode, equal) {
  auto* l1 = v2l({});
  auto* l2 = v2l({});

  EXPECT_TRUE(Equal(l1, l2));
}

TEST(l2s, subname) {
  auto* res = s2l("[2,3,4]");
  EXPECT_EQ("[2,3,4]", l2s(res));
}
