/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (41.91%)
 * Total Accepted:    255.7K
 * Total Submissions: 525.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
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
 * -100 
 * 
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      if (matrix.empty() || matrix[0].empty()) {
        return res;
      }

      int M = matrix.size();
      int N = matrix[0].size();

      int i = (min(M, N) + 1) / 2;
      for (int k = 0; k < i; ++k) {
        // std::cout << "k: " << k << std::endl;

        for (int j = k; j < N - k; ++j) {
          res.push_back(matrix[k][j]);
        }

        for (int j = k+1; j < M - k - 1; ++j) {
          res.push_back(matrix[j][N - k - 1]);
        }

        if (M - k - 1 != k) {
          for (int j = N - k - 1; j >= k; --j) {
            res.push_back(matrix[M - k - 1][j]);
          }
        }

        if (k != N - k - 1) {
          for (int j = M - k - 2; j >= k + 1; --j) {
            res.push_back(matrix[j][k]);
          }
        }
      }

      return res;
    }
};
