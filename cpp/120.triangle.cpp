/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (66.92%)
 * Total Accepted:    214.7K
 * Total Submissions: 313.6K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形 triangle ，找出自顶向下的最小路径和。
 * 
 * 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1
 * 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * 输出：11
 * 解释：如下面简图所示：
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：triangle = [[-10]]
 * 输出：-10
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？
 * 
 * 
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if (triangle.empty()) return 0;
      int N = triangle.size();
      vector<int> dp(N, 0);
      dp[0] = triangle[0][0];

      for (int i = 1; i < N; ++i) {
        int K = triangle[i].size();
        vector<int> dp2(K, 0);
        for (int j = 0; j < K; ++j) {
          if (j == 0) {
            dp2[j] = dp[j] + triangle[i][j];
          } else if (j == K - 1) {
            dp2[j] = dp[j-1] + triangle[i][j];
          } else {
            dp2[j] = std::min(dp[j], dp[j-1]) + triangle[i][j];
          }
        }
        swap(dp, dp2);
      }

      int res = dp[0];
      for (int i = 1; i < dp.size(); ++i) {
        res = std::min(res, dp[i]);
      }

      return res;
    }
};
