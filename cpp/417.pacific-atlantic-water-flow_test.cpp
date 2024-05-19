#include "leetcode.h"
#include <gtest/gtest.h>

#include "417.pacific-atlantic-water-flow.cpp"

#define FunName pacificAtlantic

TEST(testname, subname) {
  // VERIFY({{0,0},{0,1},{1,0},{1,1}}, {{2,1},{1,2}});
  VERIFY({{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{1,0},{1,2},{1,3},{1,5},{2,0},{2,1},{2,2},{2,3},{2,4},{2,5}}, {{3,3,3,3,3,3},{3,0,3,3,0,3},{3,3,3,3,3,3}});
}
