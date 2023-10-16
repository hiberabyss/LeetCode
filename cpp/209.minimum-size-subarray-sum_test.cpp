#include "leetcode.h"
#include <gtest/gtest.h>

#include "209.minimum-size-subarray-sum.cpp"

#define FunName minSubArrayLen

TEST(testname, subname) {
  VERIFY(1, 4, {1,4,4});
  VERIFY(2, 7, {2,3,1,2,4,3});
  VERIFY(3, 11, {1,2,3,4,5});
  VERIFY(0, 11, {1,1,1,1,1,1,1,1});
}
