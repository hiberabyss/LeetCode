#ifndef LEETCODE_H
#define LEETCODE_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution;

 struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Input: "[1,2,3]", "1,2,3", "1, 2, 3"
// Output vector: {1, 2, 3}
template<typename T = int>
vector<T> s2v(const string& s) {
  vector<T> res;
  if (s.size() <= 2) {
    return res;
  }

  int pos = 1;
  while (pos < s.size()) {
    auto next_pos = s.find(',', pos);
    if (next_pos == string::npos) {
      next_pos = s.size() - 1;
    }
    
    auto subs = s.substr(pos, next_pos - pos);

    if constexpr (is_integral_v<T>) {
      res.push_back(stoll(subs));
    } else {
      res.push_back(subs);
    }

    pos = next_pos + 1;
  }

  return res;
}

ListNode* s2l(const string& s) {
  ListNode res;

  auto* pre = &res;
  for (auto n : s2v(s)) {
    pre->next = new ListNode(n);
    pre = pre->next;
  }

  return res.next;
}

string l2s(const ListNode* head) {
  string res = "[";

  while (head != nullptr) {
    res += to_string(head->val);
    if (head->next != nullptr) {
      res += ',';
    }
    head = head->next;
  }

  res += ']';
  return res;
}

template<typename T = int>
vector<vector<T>> s2vv(const string& s) {
  vector<vector<T>> res;

  // assume string should start with "["
  size_t pos = 1;
  while (pos < s.size()) {
    auto next_pos = s.find(']', pos);
    if (next_pos == string::npos) {
      break;
    }

    string s_sub_vec = s.substr(pos, next_pos - pos + 1);
    if (s_sub_vec.size() >= 2) {
      res.push_back(s2v<T>(s_sub_vec));
    }

    pos = next_pos + 2;
  }

  return res;
}

#define SolFun Solution().FunName

// Name Pattern: Verify_INPUT_OUTPUT
// V: vector
// I: int
#define Verify_I_VV(expect, input) { \
  auto res = SolFun(input); \
  EXPECT_EQ(s2vv(expect), res); \
}

// support verify list input and list return
#define Verify_L_L(expect, input) { \
  auto* l_in = s2l(input); \
  auto* res = SolFun(l_in); \
  EXPECT_EQ(expect, l2s(res)); \
}

// With _Ref means result also returned via input
#define Verify_V_I_Ref(expect, input) { \
  auto nums = s2v(input); \
  auto expect_vec = s2v(expect); \
  auto cnt = SolFun(nums); \
  EXPECT_EQ(expect_vec.size(), cnt); \
  nums.resize(cnt); \
  EXPECT_EQ(expect_vec, nums); \
}

#endif /* end of include guard: LEETCODE_H */
