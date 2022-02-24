/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (51.11%)
 * Total Accepted:    57.9K
 * Total Submissions: 113.1K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 
 * 输入："leetcode"
 * 输出："leotcede"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 元音字母不包含字母 "y" 。
 * 
 * 
 */
class Solution {
public:
    bool isVowel(char ch) {
        static set<char> kVowels = {'a', 'e', 'i', 'o', 'u'};
        return kVowels.find(tolower(ch)) != kVowels.end();
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) {
                i++;
            }
            while (i < j && !isVowel(s[j])) {
                j--;
            }
            if (i >= j) {
                break;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};
