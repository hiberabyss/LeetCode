/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (40.05%)
 * Total Accepted:    52.7K
 * Total Submissions: 131.6K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
 * 
 * 
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * 
 * 
 * 示例:
 * 
 * 现有矩阵 matrix 如下：
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * 给定 target = 5，返回 true。
 * 
 * 给定 target = 20，返回 false。
 * 
 */
class Solution {
public:
    bool binSearch(const vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            int mid = (i+j) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else j = mid - 1;
        }

        return false;
    }

    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int M = matrix.size();
        int N = matrix[0].size();
        for (const auto& v : matrix) {
            if (binSearch(v, target)) {
                return true;
            }
        }

        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int M = matrix.size();
        int N = matrix[0].size();

        int x = M - 1;
        int y = 0;
        while (x >= 0 && y < N) {
            if (matrix[x][y] == target) {
                return true;
            }

            if (matrix[x][y] > target) {
                x--;
            } else {
                y++;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix2(matrix, target);
    }
};
