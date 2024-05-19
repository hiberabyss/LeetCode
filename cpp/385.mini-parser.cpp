/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 *
 * https://leetcode.cn/problems/mini-parser/description/
 *
 * algorithms
 * Medium (54.86%)
 * Total Accepted:    32.8K
 * Total Submissions: 59.8K
 * Testcase Example:  '"324"'
 *
 * 给定一个字符串 s 表示一个整数嵌套列表，实现一个解析它的语法分析器并返回解析的结果 NestedInteger 。
 * 
 * 列表中的每个元素只可能是整数或整数嵌套列表
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "324",
 * 输出：324
 * 解释：你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "[123,[456,[789]]]",
 * 输出：[123,[456,[789]]]
 * 解释：返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
 * 1. 一个 integer 包含值 123
 * 2. 一个包含两个元素的嵌套列表：
 * ⁠   i.  一个 integer 包含值 456
 * ⁠   ii. 一个包含一个元素的嵌套列表
 * ⁠        a. 一个 integer 包含值 789
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s 由数字、方括号 "[]"、负号 '-' 、逗号 ','组成
 * 用例保证 s 是可解析的 NestedInteger
 * 输入中的所有值的范围是 [-10^6, 10^6]
 * 
 * 
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
      if (s.empty()) {
        return NestedInteger();
      }

      if (isdigit(s[0]) || s[0] == '-') {
        return NestedInteger(std::stol(s));
      }

      NestedInteger res;
      int N = s.size();
      int i = 1;
      while (i < N) {
        if (isdigit(s[i]) || s[i] == '-') {
          int j = i;
          while (j < N && (isdigit(s[j]) || s[j] == '-')) {
            j++;
          }
          res.add(NestedInteger(std::stoul(s.substr(i, j))));
          i = j+1;
          continue;
        }

        if (s[i] == '[') {
          int j = i+1;
          int cnt = 1;
          while (cnt > 0 && j < N) {
            if (s[j] == ']') {
              cnt--;
            } else if (s[j] == '[') {
              cnt++;
            }
            j++;
          }

          res.add(deserialize(s.substr(i, j-i)));
          i = j;
          continue;
        }

        i++;
      }
      return res;
    }
};
