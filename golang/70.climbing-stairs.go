package main
/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (41.62%)
 * Total Accepted:    262.4K
 * Total Submissions: 630.5K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */

func climbStairs(n int) int {
	dp := []int {1, 1}

	for i := 2; i <= n; i++ {
		dp = append(dp, dp[i-2]+dp[i-1])
	}

	return dp[n]
}

func climbStairs1(n int) int {
	if n < 0 {
		return 0
	}

	if n == 0 {
		return 1
	}

	return climbStairs(n-1) + climbStairs(n-2)
}
