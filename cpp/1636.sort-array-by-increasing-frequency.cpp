/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 仅含 1 的子串数
 *
 * https://leetcode-cn.com/problems/sort-array-by-increasing-frequency/description/
 *
 * algorithms
 * Easy (72.07%)
 * Total Accepted:    3.9K
 * Total Submissions: 5.3K
 * Testcase Example:  '[1,1,2,2,2,3]'
 *
 * 给你一个整数数组 nums ，请你将数组按照每个值的频率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。 
 * 
 * 请你返回排序后的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,1,2,2,2,3]
 * 输出：[3,1,1,2,2,2]
 * 解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,3,1,3,2]
 * 输出：[1,3,3,2,2]
 * 解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [-1,1,-6,4,5,-6,1,4,1]
 * 输出：[5,-1,4,4,-6,-6,1,1,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * -100 <= nums[i] <= 100
 * 
 * 
 */
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> numMap;
        for (auto n : nums) {
            numMap[n]++;
        }

        vector<pair<int, int>> nodes;
        for (auto& item : numMap) {
            nodes.push_back({item.first, item.second});
        }

        sort(nodes.begin(), nodes.end(), [](const auto& x1, const auto& x2) {
               if (x1.second < x2.second) {
                 return true;
               } else if (x1.second == x2.second) {
                 return x1.first > x2.first;
               }

               return false;
             });

        vector<int> res;
        for (auto& item : nodes) {
            for (int i = 0; i < item.second; ++i) {
                res.push_back(item.first);
            }
        }

        return res;
    }
};
