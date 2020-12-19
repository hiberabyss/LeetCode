/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] 加密数字
 *
 * https://leetcode-cn.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (63.29%)
 * Total Accepted:    12.1K
 * Total Submissions: 19K
 * Testcase Example:  '"nlaebolko"'
 *
 * 给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
 * 
 * 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：text = "nlaebolko"
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：text = "loonbalxballpoon"
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：text = "leetcode"
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.length <= 10^4
 * text 全部由小写英文字母组成
 * 
 * 
 */
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> ballon = {
            {'b', 1},
            {'a', 1},
            {'l', 2},
            {'o', 2},
            {'n', 1},
        };

        vector<int> textBuf(256, 0);
        for (auto ch : text) {
            textBuf[ch]++;
        }

        int res = textBuf['b'];
        for (auto& item : ballon) {
            res = min(res, textBuf[item.first] / item.second);
        }

        return res;
    }
};
