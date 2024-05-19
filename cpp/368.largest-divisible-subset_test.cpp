#include "leetcode.h"
#include <gtest/gtest.h>

#include "368.largest-divisible-subset.cpp"

#define FunName largestDivisibleSubset

TEST(testname, subname) {
  VERIFY({8, 4, 2, 1}, {1, 2, 4, 8});
  VERIFY({8,4,2}, {2,3,4,8});
  VERIFY({240,8,4}, {4,8,10,240});
}
