/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 *
 * https://leetcode.cn/problems/insert-interval/description/
 *
 * algorithms
 * Medium (41.50%)
 * Total Accepted:    108.9K
 * Total Submissions: 262.5K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
 * 
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出：[[1,5],[6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出：[[1,2],[3,10],[12,16]]
 * 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 * 
 * 示例 3：
 * 
 * 
 * 输入：intervals = [], newInterval = [5,7]
 * 输出：[[5,7]]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：intervals = [[1,5]], newInterval = [2,3]
 * 输出：[[1,5]]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：intervals = [[1,5]], newInterval = [2,7]
 * 输出：[[1,7]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * intervals[i].length == 2
 * 0 
 * intervals 根据 intervals[i][0] 按 升序 排列
 * newInterval.length == 2
 * 0 
 * 
 * 
 */
class Solution {
public:
  int findPos(const vector<vector<int>>& intervals, int x) {
    int N = intervals.size();
    int i = 0;
    int j = 2 * N - 1;
    while (i <= j) {
      int mid = (i + j) / 2;

      int m = mid / 2;
      int n = mid % 2;
      if (intervals[m][n] == x) {
        return mid;
      } else if (intervals[m][n] < x) {
        j = mid - 1;
      } else {
        i = mid + 1;
      }
    }

    return i;
  }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> res;
      bool placed = false;
      for (const auto& inter : intervals) {
        if (inter[1] < newInterval[0]) {
          res.push_back(inter);
          continue;
        }

        if (newInterval[1] < inter[0]) {
          if (!placed) {
            res.push_back(newInterval);
            placed = true;
          }
          res.push_back(inter);
          continue;
        }

        newInterval[0] = min(inter[0], newInterval[0]);
        newInterval[1] = max(inter[1], newInterval[1]);
      }

      if (!placed) {
        res.push_back(newInterval);
      }

      return res;
    }

    /* vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int N = intervals.size();

      int x = findPos(intervals, newInterval[0]);
      int y = findPos(intervals, newInterval[1]);

      if (x >= 2 * N) {
        intervals.push_back(newInterval);

        return intervals;
      }

      int x_i = x / 2;
      int x_j = x % 2;

      int y_i = y / 2;
      int y_j = y % 2;

      if (y == 0 && intervals[y_i][y_j] < newInterval[0]) {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
      }

      if (x == y && :se) {
      }

      if (intervals[x_i][x_j] == newInterval[0]) {
      }
    } */
};
