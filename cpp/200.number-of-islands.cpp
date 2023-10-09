/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (59.49%)
 * Total Accepted:    707.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * grid[i][j] 的值为 '0' 或 '1'
 * 
 * 
 */
class Solution {
public:
  std::unordered_set<int> visited;
  int N;
  void traverse(const vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= N) {
      return;
    }

    if (grid[i][j] == '0') {
      return;
    }

    if (visited.contains(i * N + j)) {
      return;
    }
    visited.insert(i * N + j);

    traverse(grid, i-1, j);
    traverse(grid, i, j - 1);
    traverse(grid, i, j+1);
    traverse(grid, i+1, j);
  }

    int numIslands(vector<vector<char>>& grid) {
      if (grid.empty()) {
        return 0;
      }

      int res = 0;

      int M = grid.size();
      N = grid[0].size();
      for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
          if (grid[i][j] == '0' || visited.contains(i * N + j)) {
            continue;
          }

          res++;
          traverse(grid, i, j);
        }
      }

      return res;
    }
};
