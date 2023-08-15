#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#include "47.permutations-ii.cpp"

Solution sol;

TEST(permutation, subname) {
  vector<vector<int>> res1 = {
    {1,2,3},
    {1,3,2},
    {2,1,3},
    {2,3,1},
    {3,1,2},
    {3,2,1},
  };
  vector<int> nums1 = {1, 2, 3};
  EXPECT_EQ(res1, sol.permuteUnique(nums1));
}
