/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (37.31%)
 * Total Accepted:    176.5K
 * Total Submissions: 473K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();

        int k = (N1 + N2) / 2 + 1;
        int num1 = 0, num2 = 0;

        int i = 0, j = 0;
        while (i < N1 || j < N2) {
            num2 = num1;
            if (j == N2 || (i < N1 && nums1[i] <= nums2[j])) {
                num1 = nums1[i];
                i++;
            } else {
                num1 = nums2[j];
                j++;
            }

            k--;
            if (k <= 0) {
                break;
            }
        }

        if ((N1 + N2) % 2) {
            return num1;
        }

        return (num1 + num2) / 2.0;
    }
};
