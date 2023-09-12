#ifndef LEETCODE_H
#define LEETCODE_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <algorithm>
#include <stack>

using namespace std;

class Solution;

 struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Graph or Tree Node
class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node* random = nullptr;

  // added for graph in 133
  vector<Node*> neighbors;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {
    neighbors = vector<Node*>();
  }

  explicit Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// Input: "[1,2,3]"
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

#define BRACED_INIT_LIST(...) {__VA_ARGS__}

#define SolFun Solution().FunName

// Name Pattern: Verify_INPUT_OUTPUT
// V: vector
// I: int
#define Verify_I_VV(expect, input) { \
  auto res = SolFun(input); \
  EXPECT_EQ(s2vv(expect), res); \
}

#define Verify_V(type, expect, input) { \
  vector<type> vec_input = BRACED_INIT_LIST input; \
  auto res = SolFun(vec_input); \
  EXPECT_EQ(expect, res); \
}

#define Verify_Vs(expect, input) Verify_V(string, expect, input)
#define Verify_Vi(expect, input) Verify_V(int, expect, input)

// support verify list input and list return
#define Verify_L_L(expect, input) { \
  auto* l_in = s2l(input); \
  auto* res = SolFun(l_in); \
  EXPECT_EQ(expect, l2s(res)); \
}

#define Verify_I_I(expect, input) { \
  EXPECT_EQ(expect, SolFun(input)); \
}

#define Verify(expect, input) { \
  EXPECT_EQ(expect, SolFun(input)); \
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
