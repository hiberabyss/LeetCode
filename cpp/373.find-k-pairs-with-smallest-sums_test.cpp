#include "leetcode.h"
#include <gtest/gtest.h>

#include "373.find-k-pairs-with-smallest-sums.cpp"

#define FunName kSmallestPairs

TEST(testname, subname) {
  VERIFY({{1,1}, {1,1}}, {1,1,2}, {1,2,3}, 2);
  VERIFY({{1,3},{2,3},{1,5}}, {1,2,4,5,6}, {3,5,7,9}, 3);
}
