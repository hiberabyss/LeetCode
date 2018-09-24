package main
/*
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (47.30%)
 * Total Accepted:    147.1K
 * Total Submissions: 311K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
func twoSum(numbers []int, target int) []int {
	return twoSumBinarySearch(numbers, target)
}

func twoSumBinarySearch(numbers []int, target int) []int {
	i := 0
	j := len(numbers) - 1

	for i < j {
		if numbers[i] + numbers[j] < target {
			i++
		} else if numbers[i] + numbers[j] > target {
			j--
		} else {
			return []int {i+1, j+1}
		}
	}

	return []int {0, 0}
}

func twoSumMap(numbers []int, target int) []int {
	visited := make(map[int]int)
	for i, num := range numbers {
		if idx, ok := visited[target - num]; ok {
			return []int {idx + 1, i+1}
		} else {
			visited[num] = i
		}
	}

	return []int {0, 0}
}

