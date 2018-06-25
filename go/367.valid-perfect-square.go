/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (38.78%)
 * Total Accepted:    75.9K
 * Total Submissions: 195.7K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * 
 * Example 1:
 * 
 * Input: 16
 * Returns: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 14
 * Returns: False
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
func isPerfectSquare(num int) bool {
	i := 0
	j := num

	for i <= j {
		mid := i + (j-i)/2

		square := int64(mid * mid)

		if square == int64(num) {
			return true
		} else if square > int64(num) {
			j = mid - 1
		} else {
			i = mid + 1
		}
	}

	return false
}
