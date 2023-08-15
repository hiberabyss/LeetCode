/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode.cn/problems/add-strings/description/
 *
 * algorithms
 * Easy (54.81%)
 * Total Accepted:    293.3K
 * Total Submissions: 535.2K
 * Testcase Example:  '"11"\n"123"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
 * 
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：num1 = "0", num2 = "0"
 * 输出："0"
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 10^4
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        vector<int> sum_vec(max(m, n) + 1, 0);

        int i = 0;
        while (i < m || i < n) {
            int n1 = 0;
            int n2 = 0;
            if (i < m) {
                n1 = num1[m - 1 - i] - '0';
            }

            if (i < n) {
                n2 = num2[n - 1 - i] - '0';
            }

            sum_vec[i] += n1 + n2;
            sum_vec[i+1] += sum_vec[i] / 10;
            sum_vec[i] %= 10;

            i++;
        }

        if (sum_vec[i] == 0) {
            i--;
        }

        string res;
        for (int j = i; j >= 0; j--) {
            res += sum_vec[j] + '0';
        }
        return res;
    }
};
