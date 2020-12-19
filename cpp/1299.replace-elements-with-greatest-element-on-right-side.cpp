/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] K 次串联后最大子数组之和
 *
 * https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side/description/
 *
 * algorithms
 * Easy (76.00%)
 * Total Accepted:    22K
 * Total Submissions: 28.4K
 * Testcase Example:  '[17,18,5,4,6,1]'
 *
 * 给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。
 * 
 * 完成所有替换操作后，请你返回这个数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：arr = [17,18,5,4,6,1]
 * 输出：[18,6,6,6,1,-1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i] <= 10^5
 * 
 * 
 */
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int N = arr.size();
        vector<int> res(N, -1);
        for (int i = N-2; i >= 0; i--) {
            if (i + 2 >= N) {
                res[i] = arr[i+1];
            } else {
                res[i] = max(arr[i+1], res[i+1]);
            }
        }

        return res;
    }
};
