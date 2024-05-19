/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 *
 * https://leetcode.cn/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (60.76%)
 * Total Accepted:    41.2K
 * Total Submissions: 67.8K
 * Testcase Example:  '"owoztneoer"'
 *
 * 给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "owoztneoer"
 * 输出："012"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "fviefuro"
 * 输出："45"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]
 * 这些字符之一
 * s 保证是一个符合题目要求的字符串
 * 
 * 
 */
class Solution {
public:
    string originalDigits(string s) {
      std::unordered_map<char, int> ch_cnts;
      for (auto ch : s) {
        ch_cnts[ch]++;
      }

      int num_cnts[10] = {0};

      num_cnts[0] = ch_cnts['z'];
      num_cnts[2] = ch_cnts['w'];
      num_cnts[6] = ch_cnts['x'];
      num_cnts[4] = ch_cnts['u'];
      num_cnts[8] = ch_cnts['g'];

      num_cnts[5] = ch_cnts['f'] - ch_cnts['u'];
      num_cnts[3] = ch_cnts['h'] - num_cnts[8];
      num_cnts[7] = ch_cnts['s'] - num_cnts[6];

      num_cnts[1] = ch_cnts['o'] - num_cnts[0] - num_cnts[2] - num_cnts[4];
      num_cnts[9] = (ch_cnts['n'] - num_cnts[1] - num_cnts[7]) / 2;

      string res;
      for (int i = 0; i < 10; i++) {
        for (size_t j = 0; j < num_cnts[i]; ++j) {
          res += i + '0';
        }
      }

      return res;
    }
};
