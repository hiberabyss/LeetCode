/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 *
 * https://leetcode.cn/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (40.88%)
 * Total Accepted:    65K
 * Total Submissions: 159K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * 给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
 * 
 * 你可以假设所有输入数组都可以得到满足题目要求的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,1,1,6,4]
 * 输出：[1,6,1,5,1,4]
 * 解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,3,2,2,3,1]
 * 输出：[2,3,1,3,1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 题目数据保证，对于给定的输入 nums ，总能产生满足题目要求的结果
 * 
 * 
 * 
 * 
 * 进阶：你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
 * 
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
      int N = nums.size();
      auto dump = nums;

      std::sort(dump.begin(), dump.end());
      int x = (N+1) / 2;
      if (N % 2) {
        for (size_t i = 0; i < N; ++i) {
          if (i % 2) {
            nums[i] = dump[x + i / 2];
          } else {
            nums[i] = dump[i/2];
          }
        }
      } else {
        for (size_t i = 0; i < N; ++i) {
          if (i % 2) {
            nums[i] = dump[i/2];
          } else {
            nums[i] = dump[x + i / 2];
          }
        }
      }

      std::reverse(nums.begin(), nums.end());
    }
};
