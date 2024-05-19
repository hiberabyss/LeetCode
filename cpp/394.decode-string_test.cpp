#include "leetcode.h"
#include <gtest/gtest.h>

#include "394.decode-string.cpp"

#define FunName decodeString

TEST(testname, subname) {
  VERIFY("abccdcdcdxyz", "abc3[cd]xyz");
}
