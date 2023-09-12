#include "leetcode.h"
#include <gtest/gtest.h>

#include "142.linked-list-cycle-ii.cpp"

#define FunName detectCycle

ListNode* GenList(const string& input, int pos) {
  auto* res = s2l(input);

  auto* pos_node = res;
  auto* cur = res;

  while (cur->next != nullptr) {
    if (pos == 0) {
      pos_node = cur;
    }
    pos--;
    cur = cur->next;
  }

  cur->next = pos_node;

  return res;
}

ListNode* GetListPos(ListNode* l, int pos) {
  for (size_t i = 0; i < pos; ++i) {
    l = l->next;
  }

  return l;
}

TEST(testname, subname) {
  auto* l = GenList("[3,2,0,-4]", 1);

  // EXPECT_EQ(GetListPos(l, 1), Solution().detectCycle1(l));
  EXPECT_EQ(GetListPos(l, 1), SolFun(l));
}
