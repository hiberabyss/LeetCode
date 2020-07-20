/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 *
 * [1360] 串联字符串的最大长度
 *
 * https://leetcode-cn.com/problems/number-of-days-between-two-dates/description/
 *
 * algorithms
 * Easy (45.69%)
 * Total Accepted:    4.4K
 * Total Submissions: 9.5K
 * Testcase Example:  '"2019-06-29"\n"2019-06-30"'
 *
 * 请你编写一个程序来计算两个日期之间隔了多少天。
 * 
 * 日期以字符串形式给出，格式为 YYYY-MM-DD，如示例所示。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：date1 = "2019-06-29", date2 = "2019-06-30"
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：date1 = "2020-01-15", date2 = "2019-12-31"
 * 输出：15
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定的日期是 1971 年到 2100 年之间的有效日期。
 * 
 * 
 */
#include <stdio.h>
class Solution {
public:
    bool isLeap(int year) {
        return ((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0;
    }

    int getDays(string date) {
        static const vector<int> monthDays = {
            -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };

        int year = 0, month = 0, day = 0;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        int res = 0;
        for (int i = 1970; i < year; ++i) {
            res += 365;
            if (isLeap(i)) {
                res += 1;
            }
        }

        for (int j = 1; j < month; ++j) {
            res += monthDays[j];
            if (isLeap(year) && j == 2) {
                res += 1;
            }
        }

        res += day;

        return res;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(getDays(date1) - getDays(date2));
    }
};
