/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (61.57%)
 * Total Accepted:    175K
 * Total Submissions: 276K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
  vector<vector<int>> res;
  vector<int> tmp;

  void dfs(int cur, const vector<int>& nums, bool choose_last) {
    if (cur >= nums.size()) {
      res.push_back(tmp);
      return;
    }

    dfs(cur + 1, nums, false);

    if (!choose_last && cur > 0 && nums[cur] == nums[cur-1]) {
      return;
    }

    tmp.push_back(nums[cur]);
    dfs(cur + 1, nums, true);
    tmp.pop_back();
  }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      dfs(0, nums, false);
      return res;
    }
};
