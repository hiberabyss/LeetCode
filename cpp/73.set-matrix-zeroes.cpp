/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (55.93%)
 * Total Accepted:    165.5K
 * Total Submissions: 269.8K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 * 
 * 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      if (matrix.empty()) return;
      int M = matrix.size();
      int N = matrix[0].size();

      int zero_row = -1;
      int zero_col = -1;

      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
          if (matrix[i][j] == 0) {
            zero_row = i;
            zero_col = j;
            break;
          }
        }
      }

      if (zero_row < 0) return;
      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
        }
      }
    }

    void setZeroes1(vector<vector<int>>& matrix) {
      if (matrix.empty()) return;
      int M = matrix.size();
      int N = matrix[0].size();

      vector<bool> zero_rows(M, false);
      vector<bool> zero_columns(N, false);

      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
          if (matrix[i][j] == 0) {
            zero_rows[i] = true;
            zero_columns[j] = true;
          }
        }
      }

      for (int i = 0; i < M; ++i) {
        if (!zero_rows[i]) continue;
        for (int j = 0; j < N; ++j) {
          matrix[i][j] = 0;
        }
      }

      for (int j = 0; j < N; ++j) {
        if (!zero_columns[j]) continue;
        for (int i = 0; i < M; ++i) {
          matrix[i][j] = 0;
        }
      }
    }
};
