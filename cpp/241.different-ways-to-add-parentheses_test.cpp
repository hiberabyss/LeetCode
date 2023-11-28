#include "leetcode.h"
#include <gtest/gtest.h>

#include "241.different-ways-to-add-parentheses.cpp"

#define FunName diffWaysToCompute

TEST(testname, subname) {
  VERIFY({1}, "1");
  VERIFY({2}, "1+1");
  VERIFY({3,3}, "1+1+1");
}
