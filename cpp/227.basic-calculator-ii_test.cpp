#include "leetcode.h"
#include <gtest/gtest.h>

#include "227.basic-calculator-ii.cpp"

#define FunName calculate

TEST(testname, subname) {
  VERIFY(3, "1 + 2");
  VERIFY(5, "3+5 /2");
  VERIFY(0, "1-1");
  VERIFY(1, "1-1+1");
}
