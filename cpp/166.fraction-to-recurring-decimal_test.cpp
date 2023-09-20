#include "leetcode.h"
#include <gtest/gtest.h>

#include "166.fraction-to-recurring-decimal.cpp"

#define FunName fractionToDecimal

TEST(testname, subname) {
  VERIFY("-0.58(3)", 7, -12);
  VERIFY("2147483648", -2147483648, -1);
}
