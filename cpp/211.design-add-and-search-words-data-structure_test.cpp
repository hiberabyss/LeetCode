#include "leetcode.h"
#include <gtest/gtest.h>

#include "211.design-add-and-search-words-data-structure.cpp"

#define FunName search

TEST(testname, subname) {
  WordDictionary dict;

  dict.addWord("bad");
  dict.addWord("dad");
  dict.addWord("mad");

  EXPECT_FALSE(dict.search("pad")); // 返回 False
  EXPECT_TRUE(dict.search("bad"));; // 返回 True
  EXPECT_TRUE(dict.search(".ad"));; // 返回 True
  EXPECT_TRUE(dict.search("b.."));; // 返回 True
}
