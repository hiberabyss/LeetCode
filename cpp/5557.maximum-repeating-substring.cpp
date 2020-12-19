/*
 * @lc app=leetcode.cn id=5557 lang=cpp
 *
 * [5557] Maximum Repeating Substring
 *
 * https://leetcode-cn.com/problems/maximum-repeating-substring/description/
 *
 * algorithms
 * Easy (41.19%)
 * Total Accepted:    2K
 * Total Submissions: 4.8K
 * Testcase Example:  '"ababc"\n"ab"'
 *
 * 给你一个字符串 sequence ，如果字符串 word 连续重复 k 次形成的字符串是 sequence 的一个子字符串，那么单词 word 的
 * 重复值为 k 。单词 word 的 最大重复值 是单词 word 在 sequence 中最大的重复值。如果 word 不是 sequence
 * 的子串，那么重复值 k 为 0 。
 * 
 * 给你一个字符串 sequence 和 word ，请你返回 最大重复值 k 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：sequence = "ababc", word = "ab"
 * 输出：2
 * 解释："abab" 是 "ababc" 的子字符串。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：sequence = "ababc", word = "ba"
 * 输出：1
 * 解释："ba" 是 "ababc" 的子字符串，但 "baba" 不是 "ababc" 的子字符串。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：sequence = "ababc", word = "ac"
 * 输出：0
 * 解释："ac" 不是 "ababc" 的子字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * sequence 和 word 都只包含小写英文字母。
 * 
 * 
 */
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        int N = sequence.size();
        int M = word.size();
        for (int i = 0; i < N;) {
            int curK = 0;
            int j = i;
            while (j + M <= N && sequence.substr(j, M) == word) {
                curK++;
                j += M;
            }
            i = j + 1;
            k = max(k, curK);
        }

        return k;
    }
};
