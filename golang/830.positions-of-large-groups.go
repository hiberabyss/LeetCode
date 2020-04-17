package main
/*
 * [857] Positions of Large Groups
 *
 * https://leetcode.com/problems/positions-of-large-groups/description/
 *
 * algorithms
 * Easy (46.86%)
 * Total Accepted:    13.9K
 * Total Submissions: 30.2K
 * Testcase Example:  '"abbxxxxzzy"'
 *
 * In a string S of lowercase letters, these letters form consecutive groups of
 * the same character.
 * 
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb",
 * "xxxx", "z" and "yy".
 * 
 * Call a group large if it has 3 or more characters.  We would like the
 * starting and ending positions of every large group.
 * 
 * The final answer should be in lexicographic order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the single large group with starting  3 and ending
 * positions 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "abc"
 * Output: []
 * Explanation: We have "a","b" and "c" but no large group.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "abcdddeeeeaabbbcd"
 * Output: [[3,5],[6,9],[12,14]]
 * 
 * 
 * 
 * Note:  1 <= S.length <= 1000
 */
func largeGroupPositions(S string) [][]int {
	res := [][]int{}
	N := len(S)

	for i := 0; i < N; {
		start := i
		i++
		for i < N && S[i] == S[i-1] {
			i++
		}

		if i - start >= 3 {
			res = append(res, []int{start, i-1})
		}
	}

	return res
}
