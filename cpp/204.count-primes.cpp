/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (38.11%)
 * Total Accepted:    126.4K
 * Total Submissions: 331.1K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 0
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 1
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 5 * 10^6
 * 
 * 
 */
class Solution {
public:
    bool isPrime(const vector<int>& nums, int n) {
        for (auto p : nums) {
            if (n % p == 0) {
                return false;
            }
        }

        return true;
    }

    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<int> primes = {2};
        for (int i = 3; i < n; ++i) {
            if (isPrime(primes, i)) {
                primes.push_back(i);
            }
        }

        return primes.size();
    }
};
