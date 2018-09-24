package main
/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.22%)
 * Total Accepted:    354.5K
 * Total Submissions: 1M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

func isValid(s string) bool {
	stack := []rune {}
	pair := map[rune]rune { ']': '[', ')': '(', '}':'{' }

	for _, ch := range s {
		switch ch {
		case '[', '{', '(':
			stack = append(stack, ch)
		default:
			N := len(stack)
			if N == 0 {
				return false
			}

			last := stack[N-1]
			stack = stack[:N-1]

			if last != pair[ch] {
				return false
			}
		}
	}

	return len(stack) == 0
}
