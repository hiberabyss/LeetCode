/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (47.35%)
 * Total Accepted:    138.9K
 * Total Submissions: 293.3K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums1.size() < m + n) {
            return;
        }
        vector<int> num1Copy(nums1.begin(), nums1.begin() + m);

        int i = 0, j = 0;
        while (i < m || j < n) {
            if (j == n || (i < m && num1Copy[i] <= nums2[j])) {
                nums1[i + j] = num1Copy[i];
                i++;
            } else {
                nums1[i + j] = nums2[j];
                j++;
            }
        }

        return;
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 || j >= 0) {
            if (i < 0 || (j >= 0 && nums1[i] < nums2[j])) {
                nums1[i+j+1] = nums2[j];
                j--;
            } else {
                nums1[i+j+1] = nums1[i];
                i--;
            }
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        merge2(nums1, m, nums2, n);
    }
};
