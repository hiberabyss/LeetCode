/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.42%)
 * Total Accepted:    318.4K
 * Total Submissions: 433.7K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 
 * 回文串 是正着读和反着读都一样的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：[["a"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 
 * 
 */
class Solution {
  vector<vector<string>> res;
public:
  bool isPalindrome(const string& s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }

    return true;
  }

  void subPartition(const string& s, vector<string> parts, int idx) {
    int N = s.size();
    if (idx >= N) {
      res.push_back(parts);
      return;
    }

    for (size_t i = idx; i < N; ++i) {
      auto str = s.substr(idx, i - idx + 1);
      if (isPalindrome(str)) {
        auto tmp_parts = parts;
        tmp_parts.push_back(str);
        subPartition(s, tmp_parts, i+1);
      }
    }
  }

    vector<vector<string>> partition(string s) {
      subPartition(s, {}, 0);
      return res;
    }

    // wrong understaning for find all palindrome substring
    vector<vector<string>> partition1(string s) {
      vector<vector<string>> res;
      int N = s.size();
      vector<pair<int,int>> parts;

      for (int i = 0; i < N; ++i) {
        parts.push_back({i, i});
        if (i+1 < N && s[i] == s[i+1]) {
          parts.push_back({i, i+1});
        }
      }

      while (!parts.empty()) {
        decltype(parts) next_parts;
        vector<string> odd;
        vector<string> even;
        for (const auto& idx : parts) {
          int i = idx.first;
          int j = idx.second;

          int len = j - i + 1;
          if (len % 2) {
            odd.push_back(s.substr(i, len));
          } else {
            even.push_back(s.substr(i, len));
          }

          if (0 <= i-1 && j+1 < N && s[i-1] == s[j+1]) {
            next_parts.push_back({i-1, j+1});
          }
        }

        res.push_back(odd);
        res.push_back(even);
        swap(parts, next_parts);
      }

      return res;
    }
};
