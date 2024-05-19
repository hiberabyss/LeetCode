#include "leetcode.h"
#include <gtest/gtest.h>

#include "399.evaluate-division.cpp"

#define FunName calcEquation

TEST(testname, subname) {
  VERIFY(
    {6.00000,0.50000,-1.00000,1.00000,-1.00000},
    {{"a","b"},{"b","c"}},
    {2.0,3.0},
    // {{"a","c"}}
    // {{"b","a"}}
    {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}}
  );
}
