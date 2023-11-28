/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode.cn/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (58.43%)
 * Total Accepted:    165.6K
 * Total Submissions: 283.6K
 * Testcase Example:  '10'
 *
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 * 
 * 丑数 就是质因子只包含 2、3 和 5 的正整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 10
 * 输出：12
 * 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 解释：1 通常被视为丑数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 1690
 * 
 * 
 */
class Solution {
public:
    int nthUglyNumber(int n) {
      std::vector<int> dp(n+1);
      dp[1] = 1;

      int p2 = 1;
      int p3 = 1;
      int p5 = 1;
      for (int i = 2; i <= n; i++) {
        int v2 = dp[p2] * 2;
        int v3 = dp[p3] * 3;
        int v5 = dp[p5] * 5;
        dp[i] = min({v2, v3, v5});
        if (dp[i] == v2) {
          p2++;
        }

        if (dp[i] == v3) {
          p3++;
        }

        if (dp[i] == v5) {
          p5++;
        }
      }

      return dp[n];
    }

    int nthUglyNumber1(int n) {
      if (n <= 0) {
        return 0;
      }

      std::priority_queue<long, std::vector<long>, std::greater<long>> que;
      std::unordered_set<int> visited{1};

      que.push(1);

      for (int i = 0; i < n-1; i++) {
        int cur = que.top();
        que.pop();
        std::vector<long> values = {2l * cur, 3l * cur, 5l * cur};
        for (auto val : values) {
          if (!visited.contains(val)) {
            que.push(val);
            visited.insert(val);
          }
        }
      }

      return que.top();
    }
};
