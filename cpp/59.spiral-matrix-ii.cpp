/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (72.52%)
 * Total Accepted:    341.1K
 * Total Submissions: 471K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */
class Solution {
public:
  vector<vector<int>> res;

  void buildMatrix(int k, int n, int idx) {
    if (n <= 0) {
      return;
    }

    if (n == 1) {
      res[k][k] = idx;
      return;
    }

    for (int j = k; j < k + n - 1; ++j) {
      res[k][j] = idx++;
    }

    for (int i = k; i < k+n-1; ++i) {
      res[i][k+n-1] = idx++;
    }

    for (int j = k+n-1; j >= k+1; j--) {
      res[k+n-1][j] = idx++;
    }

    for (int i = k+n-1; i >= k+1; i--) {
      res[i][k] = idx++;
    }

    buildMatrix(k+1, n-2, idx);
  }

    vector<vector<int>> generateMatrix(int n) {
      res = vector<vector<int>>(n, vector<int>(n, 0));
      buildMatrix(0, n, 1);
      return res;
    }
};
