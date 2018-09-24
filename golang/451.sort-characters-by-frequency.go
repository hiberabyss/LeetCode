package main

import (
	"sort"
	"strings"
)

/*
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (52.14%)
 * Total Accepted:    57.2K
 * Total Submissions: 109.7K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 *
 * Example 1:
 *
 * Input:
 * "tree"
 *
 * Output:
 * "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * "cccaaa"
 *
 * Output:
 * "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 *
 *
 *
 * Example 3:
 *
 * Input:
 * "Aabb"
 *
 * Output:
 * "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 *
 *
 */
func frequencySort(s string) string {
	chMap := make(map[byte]int)

	for _, ch := range s {
		chMap[byte(ch)]++
	}

	strArr := []string{}
	for key, cnt := range chMap {
		strArr = append(strArr, strings.Repeat(string(key), cnt))
	}

	sort.Slice(strArr, func(i, j int) bool {
		return len(strArr[i]) > len(strArr[j])
	})

	return strings.Join(strArr, "")
}
