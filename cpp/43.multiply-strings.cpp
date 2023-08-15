/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode.cn/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.65%)
 * Total Accepted:    305.1K
 * Total Submissions: 687.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
 * 
 * 
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty()) {
            return num2;
        }

        if (num2.empty()) {
            return num1;
        }

        auto m = num1.size();
        auto n = num2.size();

        vector<int> res(m+n, 0);

        vector<int> arr1;
        vector<int> arr2;

        for (int i = m - 1; i >= 0; i--) {
            arr1.push_back(num1[i] - '0');
        }

        for (int i = n - 1; i >= 0; i--) {
            arr2.push_back(num2[i] - '0');
        }

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                res[i+j] += arr1[i] * arr2[j];
                res[i+j+1] += res[i+j] / 10;
                res[i+j] %= 10;
            }
        }

        int idx = m+n-1;
        while (idx >= 0 && res[idx] == 0) {
            idx--;
        }

        if (idx < 0) {
            return "0";
        }

        string str_res;
        for (int i = idx; i >= 0; i--) {
            str_res += res[i] + '0';
        }

        return str_res;
    }
};
