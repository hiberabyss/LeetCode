package main
/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.25%)
 * Total Accepted:    224.1K
 * Total Submissions: 852K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−231, 231 − 1]
 * 
 * 
 */
func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1
	}

	negFlag := false
	if n < 0 {
		negFlag = true
		n = -n
	}

	res := 1.0
	base := x
	for n > 0 {
		if n % 2 == 1 {
			res *= base
		}
		base *= base
		n >>= 1
	}

	if negFlag {
		return 1 / res
	}

	return res
}

func myPow1(x float64, n int) float64 {
	if n == 0 {
		return 1
	}

	negFlag := false
	if n < 0 {
		negFlag = true
		n = -n
	}

	res := myPow(x, n/2)
	res *= res

	if n % 2 == 1 {
		res *= x
	}

	if negFlag {
		return 1 / res
	}

	return res
}

