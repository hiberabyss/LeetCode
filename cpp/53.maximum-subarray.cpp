/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (50.25%)
 * Total Accepted:    212.5K
 * Total Submissions: 422.2K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray2(nums);
    }

    int maxSubArray2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int res = nums[0], sum = res;
        for (int i = 1; i < nums.size(); ++i) {
            sum = max(nums[i], nums[i] + sum);
            res = max(sum, res);0
        }

        return res;
    }

    int maxSubArray1(vector<int>& nums) {
        int N = nums.size();
        if (N <= 0) {
            return 0;
        }

        int res = nums[0];
        int sum = nums[0];

        for (int i = 1; i < N; ++i) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            res = max(res, sum);
        }

        return res;
    }
};
