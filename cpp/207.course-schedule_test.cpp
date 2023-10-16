#include "leetcode.h"
#include <gtest/gtest.h>

#include "207.course-schedule.cpp"

#define FunName canFinish

TEST(testname, subname) {
  VERIFY(true, 2, {{1, 0}});
  VERIFY(false, 2, {{1, 0}, {0, 1}});
  VERIFY(false, 20, {{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}});

  VERIFY(true, 1, {});
  VERIFY(true, 5, {{1,4},{2,4},{3,1},{3,2}});

  VERIFY(true, 3, {{0,1},{0,2},{1,2}});
  VERIFY(false, 8, {{1,0},{2,6},{1,7},{5,1},{6,4},{7,0},{0,5}});
}
