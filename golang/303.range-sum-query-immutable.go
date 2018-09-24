package main
/*
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (32.90%)
 * Total Accepted:    99K
 * Total Submissions: 300.6K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
type NumArray struct {
	Accumulation []int
}


func Constructor(nums []int) NumArray {
	var array NumArray

	sum := 0
	for _, num := range nums {
		sum += num
		array.Accumulation = append(array.Accumulation, sum)
	}

	return array
}


func (this *NumArray) SumRange(i int, j int) int {
	if i <= 0 {
		return this.Accumulation[j]
	}

	return this.Accumulation[j] - this.Accumulation[i-1]
}


/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
