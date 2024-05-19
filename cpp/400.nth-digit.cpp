/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 *
 * https://leetcode.cn/problems/nth-digit/description/
 *
 * algorithms
 * Medium (45.59%)
 * Total Accepted:    61.8K
 * Total Submissions: 135.6K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n
 * 位上的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 11
 * 输出：0
 * 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */
class Solution {
public:
    int findNthDigit(int n) {
      if (n < 10) {
        return n;
      }

      int i = 1;
      long base = 9;
      while (n > i * base) {
        n -= i * base;
        base *= 10;
        i++;
      }

      long num = (n-1) / i + base / 9;
      int idx = (n-1) % i;
      for (size_t k = 0; k < i - 1 - idx; ++k) {
        num /= 10;
      }

      return num % 10;
    }
};
