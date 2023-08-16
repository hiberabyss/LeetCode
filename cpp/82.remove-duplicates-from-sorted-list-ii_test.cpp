#include "leetcode.h"
#include <gtest/gtest.h>

#include "82.remove-duplicates-from-sorted-list-ii.cpp"

#define FunName deleteDuplicates

TEST(testname, subname) {
  Verify_L_L("[]", "[1,1]");
  Verify_L_L("[2,3]", "[1,1,1,2,3]");
  Verify_L_L("[1,2,5]", "[1,2,3,3,4,4,5]");
}
