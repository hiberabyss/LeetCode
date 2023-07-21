/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (43.82%)
 * Total Accepted:    309.9K
 * Total Submissions: 670.3K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */
class Solution {
public:
  vector<vector<bool>> visited;
  int M = 0;
  int N = 0;

  bool do_exist(const vector<vector<char>>& board, int x, int y,
                const string& word, int idx) {
    if (board[x][y] != word[idx]) {
      return false;
    }

    if (idx + 1 == word.size()) {
      return true;
    }

    visited[x][y] = true;
    if (x > 0 && !visited[x-1][y] && do_exist(board, x-1, y, word, idx + 1)) return true;
    if (x < M - 1 && !visited[x+1][y] && do_exist(board, x+1, y, word, idx + 1)) return true;
    if (y > 0 && !visited[x][y-1] && do_exist(board, x, y - 1, word, idx + 1)) return true;
    if (y < N - 1 && !visited[x][y+1] && do_exist(board, x, y + 1, word, idx + 1)) return true;
    visited[x][y] = false;

    return false;
  }

    bool exist(vector<vector<char>>& board, string word) {
      if (board.empty()) return false;
      if (word.empty()) return true;

      M = board.size();
      N = board[0].size();
      visited.resize(M, vector<bool>(N, false));

      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
          if (do_exist(board, i, j, word, 0)) {
            return true;
          }
        }
      }

      return false;
    }
};
