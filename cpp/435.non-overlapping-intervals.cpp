/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 *
 * https://leetcode.cn/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (51.33%)
 * Total Accepted:    255.8K
 * Total Submissions: 498K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回
 * 需要移除区间的最小数量，使剩余区间互不重叠 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * 输出: 1
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: intervals = [ [1,2], [1,2], [1,2] ]
 * 输出: 2
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: intervals = [ [1,2], [2,3] ]
 * 输出: 0
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 * 
 * 
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      if (intervals.empty()) {
        return 0;
      }
      int N = intervals.size();
      std::sort(intervals.begin(), intervals.end(),
                [](const auto& v1, const auto& v2) {
                  return v1[1] < v2[1];
                });

      int max_cnt = 1;
      int right = intervals[0][1];
      for (size_t i = 1; i < N; ++i) {
        if (intervals[i][0] >= right) {
          max_cnt++;
          right = intervals[i][1];
        }
      }

      return N - max_cnt;
    }

    int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
      if (intervals.empty()) {
        return 0;
      }

      int N = intervals.size();

      auto interval_less = [](const auto& v1, const auto& v2) {
        return v1[0] < v2[0];
      };

      std::sort(intervals.begin(), intervals.end(), interval_less);
      int max_cnt = 0;
      std::vector<int> dp(N+1, 0);

      for (int i = 0; i < N; i++) {
        for (size_t j = 0; j < i; ++j) {
          if (intervals[j][1] <= intervals[i][0]) {
            dp[i] = max(dp[i], dp[j]);
          }
        }
        dp[i] += 1;

        max_cnt = max(max_cnt, dp[i]);
      }

      return N - max_cnt;
    }
};
