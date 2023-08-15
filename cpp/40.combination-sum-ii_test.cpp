/**
 * Author: Hongbo Liu <lhbf@qq.com>
 * Date  : 2023-08-10 14:18:19
 */

#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#include "40.combination-sum-ii.cpp"

Solution sol;

TEST(testname, subname) {
  std::vector<std::vector<int>> expect = {
    {1,1,6}, {1,2,5}, {1,7}, {2,6}
  };

  std::vector<int> candidates = {10,1,2,7,6,1,5};
  auto actual = sol.combinationSum2(candidates, 8);

  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());

  EXPECT_EQ(expect, actual);
}
