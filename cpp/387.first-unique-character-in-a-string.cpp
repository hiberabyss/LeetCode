/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (44.52%)
 * Total Accepted:    73.8K
 * Total Submissions: 165.4K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */
class Solution {
public:
    int firstUniqChar1(string s) {
        int N = s.size();
        unordered_map<char, bool> m;
        for (int i = 0; i < N; ++i) {
            if (m.find(s[i]) != m.end()) {
                continue;
            }

            bool doExist = false;
            for (int j = i+1; j < N; ++j) {
                if (s[j] == s[i]) {
                    doExist = true;
                    break;
                }
            }
            m[s[i]] = true;

            if (!doExist) {
                return i;
            }
        }

        return  -1;
    }

    int firstUniqChar2(string s) {
        unordered_map<char, int> m;
        for (auto& c : s) {
            m[c]++;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }

    int firstUniqChar(string s) {
        return firstUniqChar2(s);
    }
};
