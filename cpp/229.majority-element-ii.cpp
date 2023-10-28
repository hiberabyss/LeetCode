/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II
 *
 * https://leetcode.cn/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (54.11%)
 * Total Accepted:    100.7K
 * Total Submissions: 186.1K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,2,3]
 * 输出：[3]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2]
 * 输出：[1,2]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * 
 * 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。
 * 
 */
class Solution {
public:
    vector<int> majorityElementHelper(vector<int>& nums, int k) {
      int N = nums.size();
      std::vector<int> candidates(k-1);
      std::vector<int> votes(k-1);

      for (auto n : nums) {
        bool do_skip = false;
        for (int i = 0; i < k-1; i++) {
          if (votes[i] > 0 && n == candidates[i]) {
            votes[i]++;
            do_skip = true;
            break;
          }
        }

        if (do_skip) {
          continue;
        }

        for (int i = 0; i < k-1; i++) {
          if (votes[i] == 0) {
            candidates[i] = n;
            votes[i] = 1;
            do_skip = true;
            break;
          }
        }

        if (do_skip) {
          continue;
        }

        for (int i = 0; i < k-1; i++) {
          votes[i]--;
        }
      }

      std::vector<int> cnts(k-1, 0);
      for (auto n : nums) {
        for (int i = 0; i < k-1; i++) {
          if (votes[i] > 0 && n == candidates[i]) {
            cnts[i]++;
          }
        }
      }

      std::vector<int> res;
      for (int i = 0; i < k-1; i++) {
        if (cnts[i] > N/k) {
          res.push_back(candidates[i]);
        }
      }

      return res;
    }

    vector<int> majorityElement(vector<int>& nums) {
      return majorityElementHelper(nums, 3);
    }

    vector<int> majorityElement1(vector<int>& nums) {
      int N = nums.size();
      int candidate1;
      int candidate2;
      int vote1 = 0;
      int vote2 = 0;

      for (auto n : nums) {
        if (vote1 > 0 && n == candidate1) {
          vote1++;
        } else if (vote2 > 0 && n == candidate2) {
          vote2++;
        } else if (vote1 == 0) {
          candidate1 = n;
          vote1 = 1;
        } else if (vote2 == 0) {
          candidate2 = n;
          vote2 = 1;
        } else {
          vote1--;
          vote2--;
        }
      }

      int cnt1 = 0;
      int cnt2 = 0;
      for (auto n : nums) {
        if (vote1 > 0 && n == candidate1) {
          cnt1++;
        }

        if (vote2 > 0 && n == candidate2) {
          cnt2++;
        }
      }

      std::vector<int> res;
      if (cnt1 > N/3) {
        res.push_back(candidate1);
      }

      if (cnt2 > N/3) {
        res.push_back(candidate2);
      }

      return res;
    }
};
