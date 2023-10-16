#include "leetcode.h"
#include <gtest/gtest.h>

#include "222.count-complete-tree-nodes.cpp"

#define FunName countNodes

TEST(testname, subname) {
  VERIFY(0, {});
  VERIFY(1, {1});
  VERIFY(2, {1, 2});
  VERIFY(3, {1, 2, 3});
  VERIFY(4, {1, 2, 3, 4});
  VERIFY(7, {1, 2, 3,4,5,6,7});
}
