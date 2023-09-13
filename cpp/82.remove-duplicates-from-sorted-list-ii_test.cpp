#include "leetcode.h"
#include <gtest/gtest.h>

#include "82.remove-duplicates-from-sorted-list-ii.cpp"

#define FunName deleteDuplicates

TEST(testname, subname) {
  VERIFY(v2l({}), v2l({1,1}));
  VERIFY(v2l({2,3}), v2l({1,1,1,2,3}));
  VERIFY(v2l({1,2,5}), v2l({1,2,3,3,4,4,5}));
}
