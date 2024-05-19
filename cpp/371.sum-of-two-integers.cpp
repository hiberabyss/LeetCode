/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 *
 * https://leetcode.cn/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Medium (62.02%)
 * Total Accepted:    116.7K
 * Total Submissions: 187.7K
 * Testcase Example:  '1\n2'
 *
 * 给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：a = 1, b = 2
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = 2, b = 3
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -1000 <= a, b <= 1000
 * 
 * 
 */
class Solution {
public:
    int getSum(int a, int b) {
      while (b != 0) {
        unsigned int carray = (unsigned int)(a & b) << 1;
        a = a ^ b;
        b = carray;
      }

      return a;
    }
};
