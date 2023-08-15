#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#include "415.add-strings.cpp"

Solution sol;

TEST(testname, subname) {
  EXPECT_EQ("134", sol.addStrings("11", "123"));
}
