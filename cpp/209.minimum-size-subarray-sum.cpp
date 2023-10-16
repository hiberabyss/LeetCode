/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (46.53%)
 * Total Accepted:    624.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 
 * 找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr]
 * ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
 * 
 * 
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int N = nums.size();

      int i = 0, j = 0;
      int sum = 0;
      int res = INT_MAX;
      while (i <= j && j < N) {
        sum += nums[j];
        if (sum >= target) {
          while (sum >= target) {
            res = min(res, j-i+1);
            sum -= nums[i];
            i++;
          }
        }
        j++;
      }

      if (res > N) {
        res = 0;
      }

      return res;
    }

    int minSubArrayLen1(int target, vector<int>& nums) {
      int N = nums.size();
      std::vector<long> sums(N+1, 0);

      for (int i = 0; i < N; i++) {
        sums[i+1] = sums[i] + nums[i];
      }

      int res = INT_MAX;
      for (int i = 0; i < N; i++) {
        int target_sum = target + sums[i];
        auto j = std::lower_bound(sums.begin(), sums.end(), target_sum);
        if (j == sums.end()) {
          continue;
        }

        int len = j - sums.begin() - i;
        res = std::min(res, len);
      }

      if (res > N) {
        res = 0;
      }

      return res;
    }
};
