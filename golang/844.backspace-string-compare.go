package main
/*
 * [874] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (47.22%)
 * Total Accepted:    17.9K
 * Total Submissions: 40.8K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 * 
 * 
 * Follow up:
 * 
 * 
 * Can you solve it in O(N) time and O(1) space?
 * 
 * 
 * 
 * 
 * 
 */
func backspaceCompare(S string, T string) bool {
	M := len(S)
	N := len(T)

	i, j := M-1, N-1
	cnt1 := 0
	cnt2 := 0
	for i >= 0 || j >= 0 {
		for i >= 0 && S[i] == '#' {
			cnt1++
			i--
		}

		for j >= 0 && T[j] == '#' {
			cnt2++
			j--
		}

		if cnt1 == 0 && cnt2 == 0 {
			if i >= 0 && j < 0 {
				return false
			}

			if j >= 0 && i < 0 {
				return false
			}

			if S[i] != T[j] {
				return false
			}

			i--
			j--
			continue
		}

		if cnt1 > 0 {
			cnt1--
			i--
		}

		if cnt2 > 0 {
			cnt2--
			j--
		}
	}

	return true
}
