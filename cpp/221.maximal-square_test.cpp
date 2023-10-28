#include "leetcode.h"
#include <gtest/gtest.h>

#include "221.maximal-square.cpp"

#define FunName maximalSquare

TEST(testname, subname) {
  VERIFY(4, {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'},
  });

  VERIFY(1, {{'0','1'},{'1','0'}});
}
