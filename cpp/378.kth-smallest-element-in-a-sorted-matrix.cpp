/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 *
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (58.96%)
 * Total Accepted:    19.1K
 * Total Submissions: 32.4K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
 * 请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。
 * 
 * 
 * 
 * 示例:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * 返回 13。
 * 
 * 
 * 
 * 
 * 提示：
 * 你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n^2 。
 * 
 */
class Solution {
public:
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int M = matrix.size();
        int N = matrix[0].size();

        priority_queue<int> que;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                que.push(matrix[i][j]);
                if (que.size() > k) {
                    que.pop();
                }
            }
        }

        return que.top();
    }

    int getMinNum(vector<vector<int>>& matrix, int x) {
        if (matrix.empty()) return false;
        int M = matrix.size();
        int N = matrix[0].size();
        int i = M - 1;
        int j = 0;

        int res = 0;
        while (i >= 0 && j < N) {
            if (matrix[i][j] <= x) {
                res += i + 1;
                j++;
            } else {
                i--;
            }
        }

        return res;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int M = matrix.size();
        int N = matrix[0].size();

        int l = matrix[0][0];
        int e = matrix[M-1][N-1];
        while (l < e) {
            auto mid = (l+e) / 2;
            if (getMinNum(matrix, mid) < k) {
                l = mid + 1;
            } else {
                e = mid;
            }
        }

        return l;
    }
};
