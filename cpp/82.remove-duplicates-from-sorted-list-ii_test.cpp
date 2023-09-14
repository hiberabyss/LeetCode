#include "leetcode.h"
#include <gtest/gtest.h>

#include "82.remove-duplicates-from-sorted-list-ii.cpp"

#define FunName deleteDuplicates

TEST(testname, subname) {
  VERIFY({}, {1,1});
  VERIFY({2,3}, {1,1,1,2,3});
  VERIFY({1,2,5}, {1,2,3,3,4,4,5});
}
