/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (59.18%)
 * Total Accepted:    54.8K
 * Total Submissions: 92.7K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2：
 * 
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 */
class Solution {
public:
    int minDistance1(string word1, string word2) {
        if (word1.empty()) {
            return word2.size();
        }

        if (word2.empty()) {
            return word1.size();
        }

        auto& s1 = word1;
        auto& s2 = word2;
        if (s1.size() < s2.size()) {
            swap(s1, s2);
        }

        if (word1[0] == word2[0]) {
            return minDistance(word1.substr(1), word2.substr(1));
        }

        return 1 + min(minDistance(s1.substr(1), s2.substr(1)),
                       minDistance(s1.substr(1), s2));
    }

    int minDistance(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

        for (int i = 1; i <= N; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= M; ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        return dp[M][N];
    }
};
