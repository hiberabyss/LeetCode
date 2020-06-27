/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.49%)
 * Total Accepted:    38.1K
 * Total Submissions: 81.8K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int N = s.size();
        vector<string> res;
        if (N < 4 || N > 12) {
            return res;
        }

        for (int i = 1; i < 4; ++i) {
            int p1 = stoi(s.substr(0, i));
            if (p1 > 255) {
                break;
            }

            for (int j = i+1; j < i + 4; ++j) {
                int p2 = stoi(s.substr(i, j - i));
                if (p2 > 255) {
                    break;
                }

                for (int k = j + 1; k < j + 4 && k < N; ++k) {
                    int p3 = stoi(s.substr(j, k - j));
                    if (p3 > 255) {
                        break;
                    }

                    int p4 = stoi(s.substr(k, N - k));
                    if (p4 <= 255) {
                        auto tmpRes = (to_string(p1) + "." +
                                       to_string(p2) + "." +
                                       to_string(p3) + "." +
                                       to_string(p4));
                        if (tmpRes.size() == N + 3) {
                            res.push_back(tmpRes);
                        }
                    }
                }
            }
        }

        return res;
    }
};
