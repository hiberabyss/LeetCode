/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 *
 * https://leetcode.cn/problems/elimination-game/description/
 *
 * algorithms
 * Medium (59.67%)
 * Total Accepted:    38.7K
 * Total Submissions: 64.9K
 * Testcase Example:  '9'
 *
 * 列表 arr 由在范围 [1, n] 中的所有整数组成，并按严格递增排序。请你对 arr 应用下述算法：
 * 
 * 
 * 
 * 
 * 从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。
 * 重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。
 * 不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
 * 
 * 
 * 给你整数 n ，返回 arr 最后剩下的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 9
 * 输出：6
 * 解释：
 * arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
 * arr = [2, 4, 6, 8]
 * arr = [2, 6]
 * arr = [6]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^9
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lastRemaining(int n) {
      int step = 1;
      int cnt = n;
      int a0 = 1;
      int k = 1;

      while (cnt > 1) {
        if (cnt % 2 || k % 2) {
          a0 += step;
        }

        k++;
        step *= 2;
        cnt /= 2;
      }

      return a0;
    }
};