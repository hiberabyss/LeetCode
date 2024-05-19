#include "leetcode.h"
#include <gtest/gtest.h>

#include "419.battleships-in-a-board.cpp"

#define FunName countBattleships

TEST(testname, subname) {
  VERIFY(0, {{'.'}});
  VERIFY(2, {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}});
}
