/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode.cn/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (44.62%)
 * Total Accepted:    157.5K
 * Total Submissions: 352.8K
 * Testcase Example:  '"3+2*2"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 * 
 * 整数除法仅保留整数部分。
 * 
 * 你可以假设给定的表达式总是有效的。所有中间结果将在 [-2^31, 2^31 - 1] 的范围内。
 * 
 * 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "3+2*2"
 * 输出：7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = " 3/2 "
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = " 3+5 / 2 "
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
 * s 表示一个 有效表达式
 * 表达式中的所有整数都是非负整数，且在范围 [0, 2^31 - 1] 内
 * 题目数据保证答案是一个 32-bit 整数
 * 
 * 
 */
class Solution {
  stack<int> nums;
  std::stack<char> ops;

public:
  void do_calc() {
    int n2 = nums.top(); nums.pop();
    int n1 = nums.top(); nums.pop();

    char op = ops.top(); ops.pop();
    switch (op) {
      case '*':
        nums.push(n1 * n2);
        break;
      case '/':
        nums.push(n1 / n2);
        break;
      case '-':
        nums.push(n1 - n2);
        break;
      case '+':
        nums.push(n1 + n2);
        break;
    }
  }

    int calculate(string s) {

      static const std::unordered_map<char, int> kOps = {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2},
      };

      int N = s.size();
      for (int i = 0; i < N; ) {
        while (i< N && s[i] == ' ') {
          i++;
        }

        if (isdigit(s[i])) {
          int j = i;

          while (j < N && isdigit(s[j])) {
            j++;
          }

          int num = stoi(s.substr(i, j - i));

          nums.push(num);

          i = j;
          continue;
        }

        if (kOps.contains(s[i])) {
          int cur_prio = kOps.at(s[i]);
          while (!ops.empty() && cur_prio <= kOps.at(ops.top())) {
            do_calc();
          }

          ops.push(s[i]);

          i++;
          continue;
        }
      }

      while (!ops.empty()) {
        do_calc();
      }

      return nums.top();
    }
};
