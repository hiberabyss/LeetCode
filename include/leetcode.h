#ifndef LEETCODE_H
#define LEETCODE_H

#include <climits>
#include <functional>
#include <iostream>
#include <type_traits>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <algorithm>
#include <stack>
#include <gtest/gtest.h>

using namespace std;

struct ListNode;

template<typename T>
concept NotVoid = !is_same_v<T, void>;

// extract function arguments type {{{
template<typename T> struct function_traits;  

template<typename R, typename ...Args> 
struct _function_traits {
  static const size_t nargs = sizeof...(Args);

  using result_type = R;
  using args_tuple = std::tuple<Args...>;

  template <size_t i> struct arg {
    typedef typename std::tuple_element<i, args_tuple>::type type;
  };
};

template<typename R, typename ...Args> 
struct function_traits<std::function<R(Args...)>> {
  using traits = _function_traits<R, Args...>;

  inline constexpr static const size_t nargs = sizeof...(Args);
  using result_type = R;
  template<size_t i>
  using arg = typename traits::template arg<i>::type;

  constexpr static string get_signature() {
    return "";
  }
};

template<typename ClassType, typename R, typename...Args>
struct function_traits<R(ClassType::*)(Args...)> {
  using traits = _function_traits<R, Args...>;

  inline constexpr static size_t nargs = sizeof...(Args);
  using result_type = R;
  template<size_t i>
  using arg = typename traits::template arg<i>::type;
};
// }}}

// custom type traits {{{
template<typename T>
struct is_container :
  bool_constant<requires(const T& t) {t.empty();}> {};

template<typename T>
inline constexpr bool is_container_v = is_container<T>::value;
// }}}

class Solution;

extern Solution g_sol;

#define GsolFun g_sol.FunName

ListNode* v2l(const vector<int>& v);

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> l2v(const ListNode* l) {
  vector<int> res;
  while (l != nullptr) {
    res.push_back(l->val);
    l = l->next;
  }
  return res;
}

bool Equal(const ListNode* l, const ListNode* l2) {
  if (l == l2) {
    return true;
  }

  while (l && l2 && l->val == l2->val) {
    l = l->next;
    l2 = l2->next;
  }

  if (l == nullptr && l2 == nullptr) {
    return true;
  }

  return false;
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#define null (INT_MIN)

// vector to TreeNode*
TreeNode* v2t(const vector<long>& data) {
  if (data.empty()) {
    return nullptr;
  }

  int N = data.size();
  int idx = 1;
  TreeNode* root = new TreeNode(data[0]);
  std::queue<TreeNode*> nodes({root});
  while (!nodes.empty()) {
    while (!nodes.empty()) {
      auto* cur = nodes.front();
      nodes.pop();
      int l_idx = 2 * idx - 1;
      int r_idx = 2 * idx;

      idx++;

      if (l_idx < N) {
        if (data[l_idx] > null) {
          cur->left = new TreeNode(data[l_idx]);
          nodes.push(cur->left);
        } else {
          nodes.push(nullptr);
        }
      }

      if (r_idx < N && data[r_idx] > null) {
        if (data[r_idx] > null) {
          cur->right = new TreeNode(data[r_idx]);
          nodes.push(cur->right);
        } else {
          nodes.push(nullptr);
        }
      }
    }
  }

  return root;
}

TreeNode* find(TreeNode* root, long val) {
  if (root == nullptr) {
    return nullptr;
  }

  if (root->val == val) {
    return root;
  }

  auto* left_res = find(root->left, val);
  if (left_res != nullptr) {
    return left_res;
  }

  return find(root->right, val);
}

// Graph or Tree Node
class Node {
public:
  int val;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* next = nullptr;
  Node* random = nullptr;

  // added for graph in 133
  vector<Node*> neighbors = vector<Node*>();

  Node() : val(0), left(NULL), right(NULL), next(NULL) {
  }

  explicit Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {
  }

  Node(int _val, const vector<Node*>& _neighbors)
      : val(_val), neighbors(_neighbors) {
  }

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// Input: "[1,2,3]"
// Output vector: {1, 2, 3}
template<typename T = int>
vector<T> s2v(string s) {
  vector<T> res;

	if (s.empty()) {
		return res;
	}

	if (s[0] == '[') {
		s = s.substr(1, s.size() - 2);
	}

  int pos = 0;
  while (pos < s.size()) {
    auto next_pos = s.find(',', pos);
    if (next_pos == string::npos) {
      next_pos = s.size();
    }
    
    auto subs = s.substr(pos, next_pos - pos);

    if constexpr (is_integral_v<T>) {
      if (subs == "null") {
        res.push_back(null);
      } else {
        res.push_back(stoll(subs));
      }
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

ListNode* v2l(const vector<int>& v) {
  ListNode res;

  auto* pre = &res;
  for (auto n : v) {
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
#define SolMem (&Solution::FunName)
#define SolMemType decltype(SolMem)

#define FunTraits function_traits<SolMemType>
#define FunArg0Type remove_reference<FunTraits::arg<0>>::type
#define FunArgc FunTraits::nargs

template<typename T>
struct clear_const_ref {
  typedef remove_const_t<remove_reference_t<T>> type;
};
template<typename T>
using clear_const_ref_t = typename clear_const_ref<T>::type;

template<typename T> struct verify;

template<typename Class, typename R, typename ...Args>
class _Verifier {
public:
  template <std::size_t N>
  using ArgsType = typename tuple_element<N, tuple<Args...>>::type;

  using Arg0Type = remove_cvref_t<ArgsType<0>>;
  using mem_func = R(Class::*)(Args...);

  _Verifier(Solution* s, mem_func f) : sol(s), func(f) {}
  unique_ptr<Solution> sol;
  mem_func func;
};

template<typename Class, typename ...Args>
struct verify<void(Class::*)(Args...)> : public _Verifier<Class, void, Args...> {
  using Base = _Verifier<Class, void, Args...>;

  explicit verify(Solution* s, Base::mem_func f) : Base(s, f) {}

  void do_verify(const Base::Arg0Type& expect, const Base::Arg0Type& input) {
    auto val = input;
    mem_fn(Base::func)(Base::sol, val);

    EXPECT_EQ(expect, val);
  }
};

template<typename Class, typename R, typename ...Args>
struct verify<R(Class::*)(Args...)> {
  using mem_func = R(Class::*)(Args...);
  unique_ptr<Solution> sol;
  mem_func func;

  inline constexpr static const size_t nargs = sizeof...(Args);

  explicit verify(Solution* s, mem_func f) : sol(s), func(f) {}

  using args_tuple = std::tuple<Args...>;

  template <size_t i> struct arg {
    typedef typename std::tuple_element<i, args_tuple>::type type;
  };
  template <size_t i> using arg_t = typename arg<i>::type;

  // using Arg0Type = typename remove_reference<typename arg<0>::type>::type;
  using Arg0Type = remove_cvref_t<arg_t<0>>;
  using ResultType = remove_cvref_t<R>;

  void do_verify_trunc_ref(Arg0Type expect, remove_reference_t<Args>... args) {
    auto nums(args...);
    auto cnt = mem_fn(func)(sol, nums);
    EXPECT_EQ(expect.size(), cnt);
    nums.resize(cnt);
    EXPECT_EQ(expect, nums);
  }

  void do_verify(R expect, remove_cvref_t<Args> ...args) {
    if constexpr (is_same_v<ListNode*, ResultType> &&
                  is_same_v<ResultType, Arg0Type>) {
      auto actual = mem_fn(func)(sol, args...);
      EXPECT_EQ(l2v(expect), l2v(actual));
      return;
    }

    auto actual = mem_fn(func)(sol, std::forward<Args>(args)...);
    EXPECT_EQ(expect, actual);
  }

  template<same_as<TreeNode*> T = Arg0Type>
  void do_verify(R expect, const vector<long>& input) {
    auto* root = v2t(input);
    auto actual = mem_fn(func)(sol, root);

    EXPECT_EQ(expect, actual);
  }

  // requires is_same_v<T, ListNode*>
  template<same_as<ListNode*> T = ResultType>
  void do_verify(const vector<int>& expect, const vector<int>& input) {
    auto actual = mem_fn(func)(sol, v2l(input));
    EXPECT_EQ(expect, l2v(actual));
    return;
  }

};

#define _VERIFIER verify<SolMemType>(new Solution, SolMem)

#define VERIFY \
    printf("%s:%d:\n", __FILE__, __LINE__); \
    _VERIFIER.do_verify

#define VERIFY_TRUNC_REF _VERIFIER.do_verify_trunc_ref

#endif /* end of include guard: LEETCODE_H */
