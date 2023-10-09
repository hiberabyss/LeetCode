#include "leetcode.h"
#include <gtest/gtest.h>

#include "200.number-of-islands.cpp"

#define FunName numIslands

TEST(testname, subname) {
  VERIFY(3, {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
  });

  VERIFY(1, {
    {'1','1','1'},
    {'0','1','0'},
    {'1','1','1'},
  });
}
