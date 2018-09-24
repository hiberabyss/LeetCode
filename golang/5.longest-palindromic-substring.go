package main

/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.49%)
 * Total Accepted:    337.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */
func longestPalindrome(s string) string {
	maxLen := 0
	start := 0

	for i := range s {
		len1 := expandPalindromes(s, i, i)
		len2 := expandPalindromes(s, i, i+1)
		len := max(len1, len2)

		if len > maxLen {
			maxLen = len
			start = i - (len-1)/2
		}
	}

	// fmt.Printf("S: %d, Len: %d\n", start, maxLen)
	return s[start : start+maxLen]
}

func expandPalindromes(s string, left int, right int) int {
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++
	}

	return right - left - 1
}

func max(x, y int) int {
	if x >= y {
		return x
	}

	return y
}
