/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.44%)
 * Total Accepted:    238.9K
 * Total Submissions: 811.3K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome1(string s) {
      int maxLen = 0;
      int max_begin = 0;
      int max_end = 0;

      for (int i = 0; i < s.size(); ++i) {
          for (int j = 0; j < s.size(); ++j) {
              if (isPalindrome(s, i, j) && (j -i + 1) > maxLen) {
                  maxLen = j -i + 1;
                  max_begin = i;
                  max_end = j;
              }
          }
      }

      return s.substr(max_begin, maxLen);
    }

    void expandStr(const string& s, int& i, int& j) {
        while (i > 0 && j + 1 < s.size() && s[i-1] == s[j+1]) {
            i--;
            j++;
        }
    }

    string longestPalindrome2(const string& s) {
        int maxLen = 0;
        int maxBegin = 0;
        int maxEnd = 0;
        for (int i = 0; i < s.size(); ++i) {
            int tmpi = i;
            int tmpj = i;
            expandStr(s, tmpi, tmpj);
            if (tmpj - tmpi + 1 > maxLen) {
                maxLen = tmpj - tmpi + 1;
                maxBegin = tmpi;
                maxEnd = tmpj;
            }

            if (i + 1 < s.size() && s[i] == s[i+1]) {
                tmpi = i;
                tmpj = i+1;
                expandStr(s, tmpi, tmpj);
                if (tmpj - tmpi + 1 > maxLen) {
                    maxLen = tmpj - tmpi + 1;
                    maxBegin = tmpi;
                    maxEnd = tmpj;
                }
            }
        }

        return s.substr(maxBegin, maxLen);
    }

    string longestPalindrome(string s) {
        return longestPalindrome2(s);
    }
};
