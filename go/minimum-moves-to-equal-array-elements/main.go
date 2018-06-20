package main

import "sort"

func minMoves(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	min := nums[0]
	for _, v := range nums {
		if v < min {
			min = v
		}
	}

	res := 0
	for _, v := range nums {
		res += v - min
	}

	return res
}

func minMoves1(nums []int) int {
	cnt := 0

	sort.Ints(nums)
	for nums[0] != nums[len(nums)-1] {
		cnt++
		for i := 0; i < len(nums)-1; i++ {
			nums[i]++
		}
		sort.Ints(nums)
	}

	return cnt
}
