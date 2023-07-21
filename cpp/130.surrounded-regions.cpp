/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode.cn/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (45.52%)
 * Total Accepted:    174.8K
 * Total Submissions: 383.7K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X'
 * 填充。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * 解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["X"]]
 * 输出：[["X"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 
 * board[i][j] 为 'X' 或 'O'
 * 
 * 
 * 
 * 
 */
class Solution {
public:
  unordered_map<int, bool> visited;
  int M = 0;
  int N = 0;

  unordered_set<int> cur_o;
  bool surrounded = true;

  void bfs(vector<vector<char>>& board, int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) {
      surrounded = false;
      return;
    }

    if (board[x][y] != 'O') {
      return;
    }

    int idx = x * N + y;
    if (visited[idx]) {
      return;
    }

    visited[idx] = true;
    cur_o.insert(idx);
    bfs(board, x-1, y);
    bfs(board, x+1, y);
    bfs(board, x, y-1);
    bfs(board, x, y+1);
  }

    void solve(vector<vector<char>>& board) {
      M = board.size();
      if (board.empty()) {
        return;
      }
      N = board[0].size();

      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
          if (board[i][j] == 'O' && !visited[i*N + j]) {
            cur_o.clear();
            surrounded = true;
            bfs(board, i, j);

            if (surrounded) {
              for (auto idx : cur_o) {
                int x = idx / N;
                int y = idx % N;

                board[x][y] = 'X';
              }
            }
          }
        }
      }
    }
};
