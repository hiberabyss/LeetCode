#include "leetcode.h"
#include <gtest/gtest.h>

#include "304.range-sum-query-2d-immutable.cpp"

#define FunName NumMatrix

TEST(testname, subname) {
  vector<vector<int>> nums = {
    {3,0,1,4,2},
    {5,6,3,2,1},
    {1,2,0,1,5},
    {4,1,0,1,7},
    {1,0,3,0,5}
  };

  NumMatrix matrix(nums);

  EXPECT_EQ(8, matrix.sumRegion(2,1,4,3));
  EXPECT_EQ(11, matrix.sumRegion(1,1,2,2));
  EXPECT_EQ(12, matrix.sumRegion(1,2,2,4));
}
