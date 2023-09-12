#include "leetcode.h"
#include <gtest/gtest.h>

#include "150.evaluate-reverse-polish-notation.cpp"

#define FunName evalRPN

TEST(testname, subname) {
  Verify_Vs_I(6, ("4","13","5","/","+"));
}
