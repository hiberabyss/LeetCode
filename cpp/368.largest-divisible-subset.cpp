/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 *
 * https://leetcode.cn/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (45.93%)
 * Total Accepted:    59.3K
 * Total Submissions: 129.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i],
 * answer[j]) 都应当满足：
 * 
 * answer[i] % answer[j] == 0 ，或
 * answer[j] % answer[i] == 0
 * 
 * 
 * 如果存在多个有效解子集，返回其中任何一个均可。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[1,2]
 * 解释：[1,3] 也会被视为正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,4,8]
 * 输出：[1,2,4,8]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * nums 中的所有整数 互不相同
 * 
 * 
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int N = nums.size();
      std::vector<int> dp(N, 1);

      std::sort(nums.begin(), nums.end());
      for (size_t i = 1; i < N; ++i) {
        for (size_t j = 0; j < i; ++j) {
          if (!(nums[i] % nums[j])) {
            dp[i] = max(dp[i], dp[j] + 1);
          }
        }
      }

      std::vector<int> res;
      auto it = std::max_element(dp.begin(), dp.end());
      int max_cnt = *it;
      int max_val = nums[it - dp.begin()];

      while (true) {
        int val = nums[it - dp.begin()];

        if (*it == max_cnt && !(max_val % val)) {
          res.push_back(val);
          max_val = val;
          max_cnt--;
        }
        if (it == dp.begin()) {
          break;
        }
        it--;
      }

      return res;
    }
};
