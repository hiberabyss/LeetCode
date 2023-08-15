#include "leetcode.h"
#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#include "59.spiral-matrix-ii.cpp"

Solution sol;

TEST(testname, subname) {
  EXPECT_EQ(s2vv("[[1]]"), Solution().generateMatrix(1));
  EXPECT_EQ(s2vv("[[1,2,3],[8,9,4],[7,6,5]]"), Solution().generateMatrix(3));
}
