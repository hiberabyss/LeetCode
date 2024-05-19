/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 *
 * https://leetcode.cn/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (42.33%)
 * Total Accepted:    71.3K
 * Total Submissions: 168.5K
 * Testcase Example:  '8'
 *
 * 给定一个正整数 n ，你可以做如下操作：
 * 
 * 
 * 如果 n 是偶数，则用 n / 2替换 n 。
 * 如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
 * 
 * 
 * 返回 n 变为 1 所需的 最小替换次数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 8
 * 输出：3
 * 解释：8 -> 4 -> 2 -> 1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 7
 * 输出：4
 * 解释：7 -> 8 -> 4 -> 2 -> 1
 * 或 7 -> 6 -> 3 -> 2 -> 1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 4
 * 输出：2
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
    int integerReplacement(int n) {
      if (n == 1) {
        return 0;
      }

      if (n == INT_MAX) {
        return 32;
      }

      if (n % 2 == 0) {
        return 1 + integerReplacement(n/2);
      }

      return 1 + min(integerReplacement(n+1), integerReplacement(n-1));
    }
};
