/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (54.33%)
 * Total Accepted:    431.8K
 * Total Submissions: 795.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> num_set;
      for (auto n : nums) {
        num_set.insert(n);
      }

      int res = 0;
      for (auto n : nums) {
        if (num_set.contains(n-1)) {
          continue;
        }

        int cur = 0;
        while (num_set.contains(n)) {
          n++;
          cur++;
        }

        res = max(res, cur);
      }

      return res;
    }

    int longestConsecutive1(vector<int>& nums) {
      unordered_map<int, bool> num_states;
      for (auto n : nums) {
        num_states[n] = false;
      }

      int res = 0;
      for (auto n : nums) {
        if (num_states[n]) {
          continue;
        }

        int cur = 0;
        while (num_states.contains(n)) {
          cur++;
          num_states[n] = true;
          n--;
        }

        n += cur + 1;
        while (num_states.contains(n)) {
          cur++;
          num_states[n] = true;
          n++;
        }

        res = max(res, cur);
      }

      return res;
    }
};
