/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 *
 * https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (61.92%)
 * Total Accepted:    133.9K
 * Total Submissions: 216.2K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * 给定一个二维矩阵 matrix，以下类型的多个请求：
 * 
 * 
 * 计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
 * 
 * 
 * 实现 NumMatrix 类：
 * 
 * 
 * NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
 * int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1)
 * 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: 
 * ["NumMatrix","sumRegion","sumRegion","sumRegion"]
 * 
 * [[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
 * 输出: 
 * [null, 8, 11, 12]
 * 
 * 解释:
 * NumMatrix numMatrix = new
 * NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]);
 * numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
 * numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
 * numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * -10^5 <= matrix[i][j] <= 10^5
 * 0 <= row1 <= row2 < m
 * 0 <= col1 <= col2 < n
 * 最多调用 10^4 次 sumRegion 方法
 * 
 * 
 */
class NumMatrix {
  int M = 0;
  int N = 0;
  std::vector<vector<int>> cache_sums;

public:
    NumMatrix(vector<vector<int>>& matrix) {
      M = matrix.size();
      N = matrix[0].size();

      cache_sums.resize(M, vector<int>(N, 0));
      cache_sums[0][0] = matrix[0][0];
      for (int i = 1; i < M; i++) {
        cache_sums[i][0] = matrix[i][0] + cache_sums[i-1][0];
      }

      for (int j = 1; j < N; ++j) {
        cache_sums[0][j] = matrix[0][j] + cache_sums[0][j-1];
      }

      for (size_t i = 1; i < M; ++i) {
        for (size_t j = 1; j < N; ++j) {
          cache_sums[i][j] = matrix[i][j] +
              cache_sums[i-1][j] + cache_sums[i][j-1] - cache_sums[i-1][j-1];
        }
      }
    }

    int getAreaSum(int x, int y) {
      if (x < 0 || y < 0) {
        return 0;
      }

      return cache_sums[x][y];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      int res = cache_sums[row2][col2] -
          (getAreaSum(row2, col1 - 1) + getAreaSum(row1-1, col2) - getAreaSum(row1-1, col1-1));

      return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
