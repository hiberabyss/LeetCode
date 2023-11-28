/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (64.70%)
 * Total Accepted:    295.2K
 * Total Submissions: 456.3K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: prices = [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 * 示例 2:
 * 
 * 
 * 输入: prices = [1]
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if (prices.empty()) {
        return 0;
      }

      int N = prices.size();

      // max profilt when has stock
      int s0 = -prices[0];
      // max profit when freeze in next day (sold on the day)
      int s1 = 0;
      // max profit when no stock
      int s2 = 0;

      for (int i = 1; i < N; i++) {
        int tmp_s0 = s0;
        int tmp_s1 = s1;

        s0 = max(s2 - prices[i], s0);
        s1 = tmp_s0 + prices[i];
        s2 = max(tmp_s1, s2);
      }

      return max({s0, s1, s2});
    }
};
