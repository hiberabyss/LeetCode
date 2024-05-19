/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 *
 * https://leetcode.cn/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (74.69%)
 * Total Accepted:    73.9K
 * Total Submissions: 98.9K
 * Testcase Example:  '13'
 *
 * 给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。
 * 
 * 你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 13
 * 输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 2
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 5 * 10^4
 * 
 * 
 */
class Solution {
public:
    vector<int> lexicalOrder(int n) {
      std::vector<int> res(n);

      int num = 1;
      for (int i = 0; i < n; i++) {
        res[i] = num;
        if (num * 10 <= n) {
          num *= 10;
          continue;
        }

        while (num % 10 == 9 || num + 1 > n) {
          num /= 10;
        }
        num++;
      }

      return res;
    }
};
