#include "leetcode.h"
#include <gtest/gtest.h>

#include "208.implement-trie-prefix-tree.cpp"

#define FunName startsWith

TEST(testname, subname) {
  Trie trie;

  trie.insert("apple");

  EXPECT_TRUE(trie.search("apple"));
  EXPECT_FALSE(trie.search("app"));
  EXPECT_TRUE(trie.startsWith("app"));

  trie.insert("app");
  EXPECT_TRUE(trie.search("app"));
}

TEST(test2, subname) {
  Trie trie;
  trie.insert("app");
  trie.insert("apple");
  trie.insert("beer");
  trie.insert("add");
  trie.insert("jam");
  trie.insert("rental");

  EXPECT_FALSE(trie.search("apps"));
  EXPECT_TRUE(trie.search("app"));
  EXPECT_FALSE(trie.search("ad"));
// trie.search("applepie")
// trie.search("rest")
// trie.search("jan")
// trie.search("rent")
// trie.search("beer")
// trie.search("jam")
  // ||   ✘ testcase: '["Trie","insert","insert","insert","insert","insert","insert","search","search","search","search","search","search","search","search","search","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith"
  //     || ,"startsWith","startsWith","startsWith"]\n' +
  //     ||   '[[],["app"],["apple"],["beer"],["add"],["jam"],["rental"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"]]'
}
