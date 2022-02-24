/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 设计地铁系统
 *
 * https://leetcode-cn.com/problems/number-of-good-pairs/description/
 *
 * algorithms
 * Easy (85.02%)
 * Total Accepted:    37.6K
 * Total Submissions: 44.2K
 * Testcase Example:  '[1,2,3,1,1,3]'
 *
 * 给你一个整数数组 nums 。
 * 
 * 如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。
 * 
 * 返回好数对的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,1,1,3]
 * 输出：4
 * 解释：有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1,1,1]
 * 输出：6
 * 解释：数组中的每组数字都是好数对
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,2,3]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 * 
 * 
 */
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> M;
        for (auto n : nums) {
            M[n]++;
        }

        int res = 0;
        for (auto& item : M) {
            int N = item.second;
            if (N < 2) {
                continue;
            }

            res += N * (N-1) / 2;
        }

        return res;
    }

    int numIdenticalPairs1(vector<int>& nums) {
        int res = 0;
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if (nums[i] == nums[j]) {
                    res++;
                }
            }
        }

        return res;
    }
};
