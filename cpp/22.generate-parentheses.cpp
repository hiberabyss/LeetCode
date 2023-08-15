/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.62%)
 * Total Accepted:    210.2K
 * Total Submissions: 274.4K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */
class Solution {
public:
    void buildParenthesis(const string& p,
                          int left,
                          int right,
                          vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(p);
            return;
        }

        if (left == 0) {
            res.push_back(p + string(right, ')'));
            return;
        }

        if (left <= right) {
            buildParenthesis(p + '(', left - 1, right, res);
        }
        
        if (left < right) {
            buildParenthesis(p + ')', left, right - 1, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        buildParenthesis("", n, n, res);

        return res;
    }
};
