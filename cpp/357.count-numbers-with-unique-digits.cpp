/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 统计各位数字都不同的数字个数
 *
 * https://leetcode.cn/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (60.55%)
 * Total Accepted:    70.8K
 * Total Submissions: 116.9K
 * Testcase Example:  '2'
 *
 * 给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10^n^ 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：91
 * 解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围内的所有数字。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 0
 * 输出：1
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 8
 * 
 * 
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
      const int vals[] = {1, 10};
      if (n < 2) {
        return vals[n];
      }

      int res = 10;
      int cur = 9;
      for (int i = 0; i < n-1; i++) {
        cur *= 9 - i;
        res += cur;
      }

      return res;
    }

    int countNumbersWithUniqueDigits1(int n) {
      if (n == 0) {
        return 1;
      }

      if (n == 1) {
        return 10;
      }

      int res = 10;
      for (size_t i = 2; i <= n; ++i) {
        int cur = 9;
        for (size_t j = 0; j < i-1; ++j) {
          cur *= 9 - j;
        }

        res += cur;
      }

      return res;
    }
};
