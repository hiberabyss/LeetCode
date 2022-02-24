/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (69.66%)
 * Total Accepted:    141.7K
 * Total Submissions: 203.4K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows < 1) {
            return res;
        }

        res.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; ++i) {
            vector<int> cur;

            for (int j = 0; j <= i; ++j) {
                int N = res[i-1].size();
                int l = j - 1;
                int r = j;

                if (l < 0) {
                    cur.push_back(res[i-1][r]);
                } else if (j >= N) {
                    cur.push_back(res[i-1][l]);
                } else {
                    cur.push_back(res[i-1][l] + res[i-1][r]);
                }
            }

            res.push_back(cur);
        }

        return res;
    }
};
