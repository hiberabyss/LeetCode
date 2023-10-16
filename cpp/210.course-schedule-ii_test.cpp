#include "leetcode.h"
#include <gtest/gtest.h>

#include "210.course-schedule-ii.cpp"

#define FunName findOrder

TEST(testname, subname) {
  VERIFY({0}, 1, {});
  VERIFY({0, 1}, 2, {});
  VERIFY({0,1,2,3}, 4, {{1,0},{2,0},{3,1},{3,2}});
}
