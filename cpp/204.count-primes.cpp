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
  // linear filter
  int countPrimes(int n) {
    vector<int> numbers(n, 1);
    std::vector<int> primes;

    for (int i = 2; i < n; i++) {
      if (numbers[i]) {
        primes.push_back(i);
      }

      for (auto p : primes) {
        if ((long)(p * i) >= n) {
          break;
        }

        numbers[p*i] = 0;
        if (i % p == 0) {
          break;
        }
      }
    }

    return primes.size();
  }

  // Eratosthenes filter
  int countPrimes2(int n) {
    vector<int> primes(n, 1);
    int res = 0;

    for (int i = 2; i < n; ++i) {
      if (primes[i]) {
        res += 1;

        for (long j = (long) i*i; j < n; j += i) {
          primes[j] = 0;
        }
      }
    }

    return res;
  }

  bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }

    return true;
  }

  int countPrimes1(int n) {
    int res = 0;
    for (int i = 2; i < n; i++) {
      res += isPrime(i);
    }
    return res;
  }
};
