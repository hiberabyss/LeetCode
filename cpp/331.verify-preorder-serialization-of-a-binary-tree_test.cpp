#include "leetcode.h"
#include <gtest/gtest.h>

#include "331.verify-preorder-serialization-of-a-binary-tree.cpp"

#define FunName isValidSerialization

TEST(testname, subname) {
  VERIFY(false, "9,#,#,1");
  VERIFY(true, "9,3,4,#,#,1,#,#,2,#,6,#,#");
}
