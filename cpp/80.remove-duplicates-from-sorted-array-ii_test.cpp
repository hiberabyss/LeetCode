#include <cctype>
#include <gtest/gtest.h>
#include "leetcode.h"

#include "80.remove-duplicates-from-sorted-array-ii.cpp"

#define FunName removeDuplicates

TEST(testname, subname) {
  VERIFY_TRUNC_REF({1,1,2,2,3}, {1,1,1,2,2,3});
  VERIFY_TRUNC_REF({1,1,2,2,3}, {1,1,1,2,2,3});
  VERIFY_TRUNC_REF({1,1,2,2,3,3}, {1,1,1,2,2,3,3});
}
