/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode.cn/problems/maximal-square/description/
 *
 * algorithms
 * Medium (49.86%)
 * Total Accepted:    291.3K
 * Total Submissions: 584.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      if (matrix.empty()) {
        return 0;
      }

      int M = matrix.size();
      int N = matrix[0].size();

      std::vector<std::vector<int>> dp(M, vector<int>(N, 0));

      int res = 0;
      for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
          if (matrix[i][j] == '0') {
            continue;
          }

          if (i == 0 || j == 0) {
            dp[i][j] = 1;
          } else {
            dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
          }
          res = max(res, dp[i][j]);
        }
      }

      return res * res;
    }
};
