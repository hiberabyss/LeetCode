package main
/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (40.65%)
 * Total Accepted:    327.6K
 * Total Submissions: 805.8K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
func maxSubArray(nums []int) int {
	if len(nums) <= 0 {
		return 0
	}

	res := nums[0]

	curSum := 0
	for _, num := range nums {
		curSum += num
		res = max(res, curSum)

		if curSum < 0 {
			curSum = 0
		}
	}

	return res
}

func max(x, y int) int {
    if x >= y {
        return x
    }

    return y
}
