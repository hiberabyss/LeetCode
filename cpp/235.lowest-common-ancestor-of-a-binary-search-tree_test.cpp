#include "leetcode.h"
#include <gtest/gtest.h>

#include "235.lowest-common-ancestor-of-a-binary-search-tree.cpp"

#define FunName lowestCommonAncestor

TEST(testname, subname) {
  auto* tree1 = v2t({6,2,8,0,4,7,9,null,null,3,5});
  VERIFY(find(tree1, 6), tree1, find(tree1, 8), find(tree1, 2));
}
