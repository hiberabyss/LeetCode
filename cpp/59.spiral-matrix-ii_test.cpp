#include "leetcode.h"
#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#include "59.spiral-matrix-ii.cpp"

#define FunName generateMatrix

TEST(testname, subname) {
  Verify_I_VV("[[1]]", 1);
  Verify_I_VV("[[1,2,3],[8,9,4],[7,6,5]]", 3);
}
