/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 *
 * https://leetcode.cn/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Medium (50.10%)
 * Total Accepted:    176.5K
 * Total Submissions: 352.1K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n ，返回 n! 结果中尾随零的数量。
 * 
 * 提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：0
 * 解释：3! = 6 ，不含尾随 0
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 5
 * 输出：1
 * 解释：5! = 120 ，有一个尾随 0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：你可以设计并实现对数时间复杂度的算法来解决此问题吗？
 * 
 */
class Solution {
public:
    int trailingZeroes(int n) {
      int res = 0;

      for (size_t i = 1; i <= n; ++i) {
        int num = i;
        while (num % 5 == 0) {
          res++;
          num /= 5;
        }
      }

      return res;
    }
};
