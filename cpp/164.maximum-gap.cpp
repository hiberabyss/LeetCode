/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 *
 * https://leetcode.cn/problems/maximum-gap/description/
 *
 * algorithms
 * Medium (60.09%)
 * Total Accepted:    86.7K
 * Total Submissions: 144.4K
 * Testcase Example:  '[3,6,9,1]'
 *
 * 给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0 。
 * 
 * 您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
      if (nums.size() < 2) {
        return 0;
      }

      int N = nums.size();
      int min_val = *std::min_element(nums.begin(), nums.end());
      int max_val = *std::max_element(nums.begin(), nums.end());
      int delta = max_val - min_val;

      int d = max(1, (max_val - min_val) / (N-1));
      vector<pair<int,int>> buckets(delta / d + 1, {INT_MAX, INT_MIN});
      for (auto n : nums) {
        int idx = (n - min_val) / d;
        auto& buck = buckets[idx];
        buck.first = min(buck.first, n);
        buck.second = max(buck.second, n);
      }

      int res = 0;

      int pre = -1;
      for (size_t i = 0; i < buckets.size(); ++i) {
        if (buckets[i].first == INT_MAX) {
          continue;
        }

        if (pre >= 0) {
          res = max(res, buckets[i].first - buckets[pre].second);
        }

        pre = i;
      }

      return res;
    }
};
