/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 *
 * https://leetcode.cn/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (48.56%)
 * Total Accepted:    126.9K
 * Total Submissions: 261.2K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 * 
 * 
 * 
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 * 
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
      std::unordered_set<char> in_stk;
      std::unordered_map<char, int> cnts;

      for (auto ch : s) {
        cnts[ch]++;
      }

      string stk;
      for (auto ch : s) {
        cnts[ch]--;
        if (in_stk.contains(ch)) {
          continue;
        }

        while (!in_stk.empty() && stk.back() > ch && cnts[stk.back()] > 0) {
          in_stk.erase(stk.back());
          stk.pop_back();
        }

        stk.push_back(ch);
        in_stk.insert(ch);
      }

      return stk;
    }
};
