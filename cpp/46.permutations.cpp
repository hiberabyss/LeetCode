/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.34%)
 * Total Accepted:    523.9K
 * Total Submissions: 667.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      if (nums.empty()) return res;
      res.push_back(vector<int>{nums[0]});

      for (int i = 1; i < nums.size(); ++i) {
        auto cur_size = res.size();
        for (int j = 0; j < cur_size; ++j) {
          auto cur = res[j];
          res[j].push_back(nums[i]);
          for (int k = cur.size() - 1; k >= 0; --k) {
            auto tmp = cur;
            tmp.insert(tmp.begin() + k, nums[i]);
            res.push_back(std::move(tmp));
          }
        }
      }

      return res;
    }
};
