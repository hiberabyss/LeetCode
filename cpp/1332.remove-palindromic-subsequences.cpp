/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 统计元音字母序列的数目
 *
 * https://leetcode-cn.com/problems/remove-palindromic-subsequences/description/
 *
 * algorithms
 * Easy (62.49%)
 * Total Accepted:    4K
 * Total Submissions: 6.3K
 * Testcase Example:  '"ababa"'
 *
 * 给你一个字符串 s，它仅由字母 'a' 和 'b' 组成。每一次删除操作都可以从 s 中删除一个回文 子序列。
 * 
 * 返回删除给定字符串中所有字符（字符串为空）的最小删除次数。
 * 
 * 「子序列」定义：如果一个字符串可以通过删除原字符串某些字符而不改变原字符顺序得到，那么这个字符串就是原字符串的一个子序列。
 * 
 * 「回文」定义：如果一个字符串向后和向前读是一致的，那么这个字符串就是一个回文。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "ababa"
 * 输出：1
 * 解释：字符串本身就是回文序列，只需要删除一次。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "abb"
 * 输出：2
 * 解释："abb" -> "bb" -> "". 
 * 先删除回文子序列 "a"，然后再删除 "bb"。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "baabb"
 * 输出：2
 * 解释："baabb" -> "b" -> "". 
 * 先删除回文子序列 "baab"，然后再删除 "b"。
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 1000
 * s 仅包含字母 'a'  和 'b'
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(const string& s) {
        if (s.empty()) {
            return true;
        }

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++; j--;
        }

        return true;
    }

    int removePalindromeSub(string s) {
        if (s.empty()) {
            return 0;
        }

        if (isPalindrome(s)) {
            return 1;
        }

        return 2;
    }
};
