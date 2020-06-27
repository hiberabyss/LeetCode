/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.48%)
 * Total Accepted:    78.5K
 * Total Submissions: 149.5K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int M = a.size();
        int N = b.size();

        int counter = 0;
        int i = M - 1;
        int j = N - 1;
        while (i >= 0 || j >= 0) {
            int sum = counter;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            counter = sum / 2;
            // std::cout << "sum: " << sum << std::endl;
            res = (char)((sum % 2) + '0') + res;
        }

        if (counter > 0) {
            res = '1' + res;
        }

        return res;
    }
};
