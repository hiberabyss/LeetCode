/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 *
 * https://leetcode.cn/problems/super-pow/description/
 *
 * algorithms
 * Medium (56.93%)
 * Total Accepted:    48.2K
 * Total Submissions: 84.6K
 * Testcase Example:  '2\n[3]'
 *
 * 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：a = 2, b = [3]
 * 输出：8
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = 2, b = [1,0]
 * 输出：1024
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：a = 1, b = [4,3,3,8,5,2]
 * 输出：1
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：a = 2147483647, b = [2,0,0]
 * 输出：1198
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 0 
 * b 不含前导 0
 * 
 * 
 */
class Solution {
  const int M = 1337;

  int pow(int x, int y) {
    x = x % M;
    int res = 1;
    while (y) {
      if (y % 2) {
        res = (res * x) % M;
      }
      x = (x * x) % M;
      y /= 2;
    }

    return res;
  }

public:
    int superPow(int a, vector<int>& b) {
      int res = 1;
      for (auto e : b) {
        res = pow(res, 10) * pow(a, e) % M;
      }
      return res;
    }

    int superPow1(int a, vector<int>& b) {
      a = a % M;
      int res = 1;
      int N = b.size();
      for (int i = N-1; i >= 0; i--) {
        res *= pow(a, b[i]);
        res %= M;
        a = pow(a, 10);
      }
      return res;
    }
};
