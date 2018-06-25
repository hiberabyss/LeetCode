/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (48.51%)
 * Total Accepted:    138.9K
 * Total Submissions: 286.4K
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two arrays, write a function to compute their intersection.
 * 
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * 
 * 
 * Note:
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 */

package main

func intersection(nums1 []int, nums2 []int) []int {
	res := []int {}

	map1 := make(map[int]bool)
	for _, val := range nums1 {
		map1[val] = true
	}

	visited := make(map[int]bool)
	for _, val := range nums2 {
		if !map1[val] {
			continue
		}

		if visited[val] {
			continue
		}

		visited[val] = true
		res = append(res, val)
	}

	return res
}
