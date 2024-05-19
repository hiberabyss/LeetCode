/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (52.56%)
 * Total Accepted:    90.4K
 * Total Submissions: 171.9K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
 * 
 * 如果不存在这样的子字符串，则返回 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aaabb", k = 3
 * 输出：3
 * 解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "ababbc", k = 2
 * 输出：5
 * 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由小写英文字母组成
 * 1 <= k <= 10^5
 * 
 * 
 */
class Solution {
public:
  int mysub(const string& s, int b, int e, int k) {
    std::unordered_map<char, int> cnts;
    for (int i = b; i < e; ++i) {
      cnts[s[i]]++;
    }

    char split = 0;
    for (auto [ch, cnt] : cnts) {
      if (cnt < k) {
        split = ch;
        break;
      }
    }

    if (split == 0) {
      return e - b;
    }

    int res = 0;
    while (b < e) {
      while (b < e && s[b] == split) {
        b++;
      }

      int j = b;
      while (j < e && s[j] != split) {
        j++;
      }
      int len = mysub(s, b, j, k);
      res = max(res, len);
      b = j;
    }

    return res;
  }

    int longestSubstring(string s, int k) {
      return mysub(s, 0, s.size(), k);
    }
};
