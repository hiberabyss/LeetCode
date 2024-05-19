#include "leetcode.h"
#include <gtest/gtest.h>

#include "406.queue-reconstruction-by-height.cpp"

#define FunName reconstructQueue

TEST(testname, subname) {
  VERIFY(
    {{4,0},{5,0},{2,2},{3,2},{1,4},{6,0}},
    {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}}
  );
}
