/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (62.38%)
 * Total Accepted:    273.2K
 * Total Submissions: 424.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> res(1);
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); ++i) {
        int len = res.size();
        for (int j = 0; j < len; ++j) {
          auto cur = res[j];
          res[j].push_back(nums[i]);
          for (int k = 0; k < nums.size(); ++k) {
          }
        }
      }
    }
};
