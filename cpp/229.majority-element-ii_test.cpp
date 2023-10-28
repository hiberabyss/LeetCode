#include "leetcode.h"
#include <gtest/gtest.h>

#include "229.majority-element-ii.cpp"

#define FunName majorityElement

TEST(testname, subname) {
  VERIFY({1}, {1});
  VERIFY({1, 2}, {1, 2});
  VERIFY({3}, {3, 2, 3});
  VERIFY({1}, {2,1,1,3,1,4,5,6});
}
