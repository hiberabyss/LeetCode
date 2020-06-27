/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.82%)
 * Total Accepted:    440.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int res = 0;
      unordered_map<char, int> m;

      int begin = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (m.find(s[i]) != m.end() && m[s[i]] >= begin) {
          res = max(res, i - begin);
          begin = m[s[i]] + 1;
          // std::cout << "begin: " << begin << ", res: " << res << std::endl;
        }
        m[s[i]] = i;
      }

      res = max(res, (int)(s.size() - begin));

      return res;
    }
};
