package main
/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (44.22%)
 * Total Accepted:    116.2K
 * Total Submissions: 263K
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two arrays, write a function to compute their intersection.
 * 
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 * 
 * 
 * Note:
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * 
 * Follow up:
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */
func intersect(nums1 []int, nums2 []int) []int {
	nmap := make(map[int]int)

	for _, num := range nums1 {
		nmap[num]++
	}

	res := []int {}
	for _, num := range nums2 {
		if nmap[num] > 0 {
			nmap[num]--
			res = append(res, num)
		}
	}

	return res
}
