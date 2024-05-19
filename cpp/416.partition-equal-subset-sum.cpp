/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.32%)
 * Total Accepted:    491.3K
 * Total Submissions: 938.9K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
class Solution {
public:

  std::vector<int> sums;

  bool hasSum(const std::vector<int>& nums, int i, int sum) {
    if (sum == 0) {
      return true;
    }

    if (sum < 0) {
      return false;
    }

    if (sums[i] < sum) {
      return false;
    }

    if (i >= nums.size()) {
      return false;
    }

    return hasSum(nums, i+1, sum) || hasSum(nums, i+1, sum - nums[i]);
  }

    bool canPartition(vector<int>& nums) {
      int N = nums.size();
      int sum = std::accumulate(nums.begin(), nums.end(), 0);
      if (sum % 2) {
        return false;
      }

      int target = sum/2;
      std::vector<std::vector<bool>> dp(N, std::vector<bool>(target + 1, false));
      for (size_t i = 0; i < N; ++i) {
        dp[i][0] = true;
      }
      if (nums[0] > target) {
        return false;
      }
      dp[0][nums[0]] = true;

      for (int i = 1; i < N; i++) {
        for (int j = 1; j <= target; j++) {
          if (j < nums[i]) {
            dp[i][j] = dp[i-1][j];
          } else {
            dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
          }
        }
      }

      return dp[N-1][target];
    }

    bool canPartition1(vector<int>& nums) {
      int sum = std::accumulate(nums.begin(), nums.end(), 0);

      int N = nums.size();
      sums.resize(N+1, 0);
      for (int i = N-1; i >= 0; i--) {
        sums[i] = sums[i+1] + nums[i];
      }

      if (sum % 2) {
        return false;
      }

      return hasSum(nums, 0, sum / 2);
    }
};
