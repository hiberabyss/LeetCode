/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (57.05%)
 * Total Accepted:    377.5K
 * Total Submissions: 628.3K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 
 * 
 * 
 * 必须在不使用库的sort函数的情况下解决这个问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] 为 0、1 或 2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以不使用代码库中的排序函数来解决这道题吗？
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
      int cnt0 = 0;
      int cnt1 = 0;
      int cnt2 = 0;

      for (auto num : nums) {
        switch (num) {
          case 0:
            cnt0++;
            break;
          case 1:
            cnt1++;
            break;
          case 2:
            cnt2++;
            break;
        }
      }

      int idx = 0;
      for (int i = 0; i < cnt0; ++i) {
        nums[idx] = 0;
        idx++;
      }

      for (int i = 0; i < cnt1; ++i) {
        nums[idx] = 1;
        idx++;
      }

      for (int i = 0; i < cnt2; ++i) {
        nums[idx++] = 2;
      }
    }
};
