/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.56%)
 * Total Accepted:    206.4K
 * Total Submissions: 774.2K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        unordered_set<string> exist;

        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            int j = i + 1;
            int k = N - 1;
            while (j < k) {
                int target = -1 * nums[i];
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    auto key = to_string(nums[i]) + to_string(nums[j]) + to_string(nums[k]);
                    if (exist.find(key) == exist.end()) {
                        res.push_back({nums[i], nums[j], nums[k]});
                        exist.insert(key);
                    }
                    j++; k--;
                } else if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return res;
    }
};
