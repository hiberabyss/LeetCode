//
// Copyright (C) 2018 Hongbo Liu <lhbf@qq.com>
// URL: https://leetcode.com/problems/two-sum
//
// Distributed under terms of the MIT license.
//

package main

func hashMapSum(nums []int, target int) []int {
	numMap := map[int]int {}

	for i := 0; i < len(nums); i++ {
		if val, ok := numMap[target - nums[i]]; ok {
			return []int {val, i}
		}
		numMap[nums[i]] = i
	}

	return []int {}
}

// bruce
func bruceTwoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i+1; j < len(nums); j++ {
			if nums[i] + nums[j] == target {
				return []int {i, j}
			}
		}
	}

	return []int {}
}


func twoSum(nums []int, target int) []int {
	return hashMapSum(nums, target)
}
