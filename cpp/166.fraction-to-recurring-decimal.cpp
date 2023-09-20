/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode.cn/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (33.44%)
 * Total Accepted:    65.8K
 * Total Submissions: 196.8K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 如果存在多个答案，只需返回 任意一个 。
 * 
 * 对于所有给定的输入，保证 答案字符串的长度小于 10^4 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：numerator = 1, denominator = 2
 * 输出："0.5"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：numerator = 2, denominator = 1
 * 输出："2"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：numerator = 4, denominator = 333
 * 输出："0.(012)"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 <= numerator, denominator <= 2^31 - 1
 * denominator != 0
 * 
 * 
 */
class Solution {
public:
  string getFracStr(long numerator, long denominator) {
    string res;
    std::unordered_map<int, int> num_str_idx;

    while (numerator != 0 && !num_str_idx.contains(numerator)) {
      num_str_idx[numerator] = res.size();
      numerator *= 10;
      while (numerator < denominator) {
        numerator *= 10;
        res += '0';
      }

      int n1 = numerator / denominator;
      res += n1 + '0';
      numerator %= denominator;
    }

    if (numerator == 0) {
      return res;
    }

    res.insert(num_str_idx[numerator], "(");
    res += ')';

    return res;
  }

    string fractionToDecimal(int numerator, int denominator) {
      string res;

      long num1 = (long)numerator / denominator;

      res = std::to_string(num1);

      long n1 = numerator;
      long n2 = denominator;

      if ((long)numerator % denominator == 0) {
        return res;
      }

      bool positive = true;
      if (n1 < 0) {
        n1 = -n1;
        positive = !positive;
      }

      if (n2 < 0) {
        n2 = -n2;
        positive = !positive;
      }

      if (!positive && num1 == 0) {
        res = '-' + res;
      }

      res += '.';
      res += getFracStr(n1 % n2, n2);

      return res;
    }
};
