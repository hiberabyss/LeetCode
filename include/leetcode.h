#ifndef LEETCODE_H
#define LEETCODE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution;

// Input: "[1,2,3]", "1,2,3", "1, 2, 3"
// Output vector: {1, 2, 3}
template<typename T = int>
vector<T> s2v(const string& s) {
  vector<T> res;

  int idx = 0;
  while (idx < s.size()) {
    while (idx < s.size() && !isdigit(s[idx])) idx++;
    int begin = idx;

    if (begin >= s.size()) {
      break;
    }

    while (idx < s.size() && isdigit(s[idx])) idx++;
    auto subs = s.substr(begin, idx - begin);
    res.push_back(stoll(subs));
  }

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

    pos = next_pos + 1;
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
