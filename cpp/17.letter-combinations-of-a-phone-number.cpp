/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (53.23%)
 * Total Accepted:    105.8K
 * Total Submissions: 198.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const vector<string> alphs = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };

        vector<string> res;
        if (digits.empty()) {
            return res;
        }

        res.push_back("");
        for (auto c : digits) {
            if (c < '2' || c > '9') {
                continue;
            }

            int N = res.size();
            for (int i = 0; i < N; ++i) {
                string curStr = res[i];
                const auto& al = alphs[c - '2'];

                res[i] += al[0];
                for (int j = 1; j < al.size(); ++j) {
                    res.push_back(curStr + al[j]);
                }
            }
        }

        return res;
    }
};
