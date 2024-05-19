#include "leetcode.h"
#include <gtest/gtest.h>

#include "435.non-overlapping-intervals.cpp"

#define FunName eraseOverlapIntervals

TEST(testname, subname) {
  VERIFY(0, {{1,2}, {2, 3}});
  VERIFY(1, {{1,2},{2,3},{3,4},{1,3}});
}
