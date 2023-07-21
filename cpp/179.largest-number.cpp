/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (37.56%)
 * Total Accepted:    143.1K
 * Total Submissions: 348.5K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 * 
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,2]
 * 输出："210"
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,30,34,5,9]
 * 输出："9534330"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */
class Solution {
public:
  static bool Compare(int x, int y) {
    long xbase = 10;
    long ybase = 10;

    while (xbase <= x) xbase *= 10;
    while (ybase <= y) ybase *= 10;

    return x * ybase + y > y * xbase + x;
  }

    string largestNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end(), Compare);

      if (nums[0] == 0) return "0";

      string res;
      for (auto n : nums) {
        res += to_string(n);
      }

      return res;
    }
};
