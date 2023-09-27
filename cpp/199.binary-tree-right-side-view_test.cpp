#include "leetcode.h"
#include <gtest/gtest.h>

#include "199.binary-tree-right-side-view.cpp"

#define FunName rightSideView

TEST(testname, subname) {
  VERIFY({1, 3}, {1, 2, 3});
  VERIFY({1, 3, 4}, {1,2,3,null,5,null,4});
  VERIFY({1, 3, 4}, {1, 2, 3, 4});
  VERIFY({1, 3}, {1,null,3});
}
