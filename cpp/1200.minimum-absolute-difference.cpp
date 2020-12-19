/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 删除区间
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference/description/
 *
 * algorithms
 * Easy (65.98%)
 * Total Accepted:    9.9K
 * Total Submissions: 14.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你个整数数组 arr，其中每个元素都 不相同。
 * 
 * 请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [4,2,1,3]
 * 输出：[[1,2],[2,3],[3,4]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,3,6,10,15]
 * 输出：[[1,3]]
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [3,8,-10,23,19,-4,-14,27]
 * 输出：[[-14,-10],[19,23],[23,27]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        if (arr.size() < 2) {
            return res;
        }

        sort(arr.begin(), arr.end());
        int minDiff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i) {
            minDiff = min(minDiff, arr[i] - arr[i-1]);
        }

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] - arr[i-1] == minDiff) {
                res.push_back({arr[i-1], arr[i]});
            }
        }

        return res;
    }
};
