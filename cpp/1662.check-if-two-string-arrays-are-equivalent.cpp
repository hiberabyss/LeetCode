/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 得到目标数组的最少函数调用次数
 *
 * https://leetcode-cn.com/problems/check-if-two-string-arrays-are-equivalent/description/
 *
 * algorithms
 * Easy (84.10%)
 * Total Accepted:    8.4K
 * Total Submissions: 10K
 * Testcase Example:  '["ab", "c"]\n["a", "bc"]'
 *
 * 给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。
 * 
 * 数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
 * 输出：true
 * 解释：
 * word1 表示的字符串为 "ab" + "c" -> "abc"
 * word2 表示的字符串为 "a" + "bc" -> "abc"
 * 两个字符串相同，返回 true
 * 
 * 示例 2：
 * 
 * 
 * 输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * word1[i] 和 word2[i] 由小写字母组成
 * 
 * 
 */
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        std::pair<int, int> idx1(0, 0);
        auto idx2 = idx1;

        for (int i = 0; i < word1.size(); ++i) {
            idx1.first = i;
            for (int j = 0; j < word1[i].size(); ++j) {
                idx1.second = j;
                if (idx2.first >= word2.size() || idx2.second >= word2[idx2.first].size()) {
                    return false;
                }

                if (word1[i][j] != word2[idx2.first][idx2.second]) {
                    return false;
                }

                idx2.second++;
                if (idx2.second == word2[idx2.first].size()) {
                    idx2.first++;
                    idx2.second = 0;
                }
            }
        }

        if (idx2.first != word2.size()) {
            return false;
        }

        return true;
    }
};
