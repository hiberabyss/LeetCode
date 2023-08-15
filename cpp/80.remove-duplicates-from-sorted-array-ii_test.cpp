#include <cctype>
#include <gtest/gtest.h>
#include "leetcode.h"

#include "80.remove-duplicates-from-sorted-array-ii.cpp"

Solution sol;

TEST(testname, subname) {
  vector<int> nums = {1,1,1,2,2,3};
  EXPECT_EQ(5, sol.removeDuplicates(nums));
  nums.resize(5);

  EXPECT_EQ(s2v("[1, 1, 2, 2, 3]"), nums);
}
