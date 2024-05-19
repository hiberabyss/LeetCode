/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 *
 * https://leetcode.cn/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (56.31%)
 * Total Accepted:    93K
 * Total Submissions: 165.1K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
 * 
 * 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c)
 * 上单元格 高于海平面的高度 。
 * 
 * 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
 * 
 * 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动
 * 既可流向太平洋也可流向大西洋 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: heights = [[2,1],[1,2]]
 * 输出: [[0,0],[0,1],[1,0],[1,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 * 
 * 
 */
class Solution {
  int M;
  int N;

  std::unordered_set<int> top_lefts;
  std::unordered_set<int> bot_rights;

public:

  void dfs(
    const vector<vector<int>>& heights,
    int x,
    int y,
    std::unordered_set<int>& nodes
  ) {
    int idx = x * N + y;
    if (nodes.contains(idx)) {
      return;
    }

    nodes.insert(idx);

    std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto& dir : dirs) {
      int i = x + dir[0];
      int j = y + dir[1];
      if (i < 0 || i >= M || j < 0 || j >= N) {
        continue;
      }

      if (heights[i][j] >= heights[x][y]) {
        dfs(heights, i, j, nodes);
      }
    }
  }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      std::vector<std::vector<int>> res;
      if (heights.empty()) {
        return res;
      }

      M = heights.size();
      N = heights[0].size();

      for (int i = 0; i < M; i++) {
        dfs(heights, i, 0, top_lefts);
        dfs(heights, i, N-1, bot_rights);
      }

      for (int j = 0; j < N; j++) {
        dfs(heights, 0, j, top_lefts);
        dfs(heights, M-1, j, bot_rights);
      }

      for (auto idx : top_lefts) {
        if (bot_rights.contains(idx)) {
          int x = idx / N;
          int y = idx % N;
          res.push_back({x, y});
        }
      }

      return res;
    }
};
